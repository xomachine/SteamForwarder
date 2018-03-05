# SteamForwarder
![https://travis-ci.org/xomachine/SteamForwarder](https://travis-ci.org/xomachine/SteamForwarder.svg?branch=master)

`steam_api.dll` implementation for WINE. Your windows games now can interact with your linux steam! What does it mean? It means this tool provides a component for WINE named `steam_api.dll`. It works like for example `opengl32.dll` provided by WINE which allows windows programms to access OpenGL API under linux. If `opengl32.dll` supplies interface to `libGL.so`, the `steam_api.dll` does the same thing but for `libsteam_api.so` (which is provided by Valve for linux steam games).

# ! DISCLAIMER !
**The author is not liable for any damage resulting from the use of this software. User might break his games, steam, OS or even computer. User account might to be banned by Valve. The legal status of the tool is uncertain and nobody have been banned so far but EVERYTHING THAT YOU'RE DOING, YOU'RE DOING ON YOUR OWN RISK!**

## Restrictions
There are a few known problems with this tool. Some of them will be solved in future, others are not solvable.

SteamForwarder is NOT able to run by design:

* Games what trying to detect steam process bypassing `steam_api.dll`
* Games with statically linked `steam_api.dll`

SteamForwarder is NOT able to download:

* Everything that steamcmd or steam are not able to download

For pre-2014 steam api it might be worthy to use
[SteamBrige](https://github.com/sirnuke/steambridge).

## Usage dependencies
* steamcmd (not required with experimental flag `--steamnative`)
* nim 0.18.0 or higher (to generate and compile a bunch of wrappers code)
* python3 (for installer script)
* wine-devel (including `winedump`, `winegcc` and headers)
* binutils (`libopcode.so` and `libbfd.so` in particular)

Addinional dependences to build:
* binutils-devel (including `bfd.h` and `dis-asm.h`)

## Usage

This is a common usage scenario of SteamForwarder for users.
Some hints for experts can be found in the section below.

* Download redist.tar.bz2 from latest release of SteamForwarder from releases page
* Unpack it to the folder you want
* Open the terminal in the folder SteamForwarder was unpacked
* Type `python3 sf_install --help` to learn command line options of installer tool.
* Launch your linux steam client if you decided to use `--steamnative` option, otherwise close the steam client if it is running (it may conflict with the steamcmd).
* Use `sf_install` to install your windows game. E.g. for Paladins it command might look like `python3 sf_install 444090`. The steam AppId of the game can be found in the url of the game page on the steam store site.
* For already installed games it is possible to use `--no-download` option to trigger `steam_api.dll.so` generation without actual game instalation.
* Launch your linux **steam** (don't allow it to update your windows games, in some cases the linux steam just erases the game and says that it is *updated*. Use `sf_install` to update windows games.)
* Run installed game via runscript generated. (Its location will be printed after `sf_install` will install the game.)

There is [a little video example](https://youtu.be/JDpusySP92s) that shows
typical use case.

**Some important tips**:
1. If you dont want to install steamcmd, it is possible to avoid it by using `--steamnative` flag in `sf_install`
2. If the game does not installing with standart method try to use `--depot` option
3. There is `install` target for `make`, so you can build a package or install SteamForwarder to your system. Don't forget about PREFIX and DESTDIR variables.
4. If `sf_install` can not write the run script or can not find `steam_api.dll` check the game installation, it may be not even installed (see 2). In other case, it might be incompatible with SteamForwarder.
5. There is no universal way to install any game. Keep trying other options and other aproaches.

## Found a bug?
Feel free to post the issue. Don't forget to attach the wine log with `WINEDEBUG=trace+steam_api` environment variable set and log from `sf_install` and the steam client (CONSOLE tab) if available.
If you're starting the game from the runscript generated by the `sf_install` the required log can be found in the
runscript folder (it's named `lastrun.log`).
If you know how to improve SteamForwarder or even already improved it in your fork, your Pull Request will be appreciated!
Any poor-languachisms, mistakes and other text-related issues found in the documentation also can be considered as bugs and can be reported or fixed by PR.

## Implementation details
The SteamForwarder may be represented as two almost independent parts:
`steam_api.dll.so` and service tools. Service tools may also be
devided to user tools and developer tools.

For a moment there is only one user tool - `sf_install`. This script
tells steam or steamcmd to download the game and prepares SteamForwarder to work
with this game, including the run scripts creation and `steam_api.dll.so` building.
It has arbitary user-friendly interface with many settings managed by command
line switches.

Another pair of tools can be related to developers tools. Their work invisible
for ordinal user. But before describing them, it is necessary to describe the
build process. So the target of whole build process is a `steam_api.dll.so`
library which implements everything implemented in `steam_api.dll` file from
the game installed. The target library should forward every call to the
`libsteam_api.so` library on linux side. The building of `steam_api.dll.so`
starts from gathering information about original `steam\_api.dll`. There are
two kinds of information: version dependent and version independent.

The version dependent information is represented by the library's exported
symbols and can be obtained via `winedump` tool from wine-devel.
As the result, there is `steam_api.spec` file will be created. But the
information from this file is not enough to build the library: there aren't
any information about the symbols arguments. In previous versions of
the SteamForwarder this problem was solved by parsing header files which
Valve supplies to game developer. But headers are only available for latest
steam API version and their usage for old steam games causes problems.
The solution of such a situation was found in parsing various versions
of `libsteam_api.so` and search for mostly compatible with original
`steam_api.dll`, then extract the information about amount of symbol arguments
via the `dllparser` tool.

Another part of information - version independent. This one should be extracted
from `steamclient.so` and does not dependent from `steam_api.dll`.
The extraction is
being performed by the `sigsearch` tool. The tool provides information about
steam API classes and their methods. As soon as this information does not
depend on game, it was included to this repository at file signatures.txt.

When both of information kinds is collected, the build stage begins.
Main job which is being done by `steam_api.dll.so` is
ABI conversion from MSVC calling conventions to GCC ones and vise versa.
It means that a little chunk of the wrapping code should be added to
each steam API function or method. The wrapping code in almost all cases
is very similiar. Implementing it by hands could make me crazy.
Thats why `steam_api.dll.so` is implemented in the Nim programming language.
Nim has wonderful metaprogramming abilities and compiles directly to C,
so I can rely on a few macros to generate the whole steam API.
