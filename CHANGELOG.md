# 0.4.1

### Project status
- Since Valve introduced their new SteamPlay feature that allows linux users to
  run windows games directly from Steam, I have stopped the active developement of
  the project. SteamPlay does almost the same thing that SteamForwarder but better,
  because Valve has all the source code of their product and understanding how the
  Steam works. Moreover, Valve provides their own build of WINE, called Proton
  which includes some patches for better gaming experience (and the steamclient
  implementation as well). So it probably will be last release of SteamForwarder
  so far.

### Installation script
- `win32` arch no longer being forced while applying registry file for the game
  installation

# 0.4.0

### Installation script:
- 64-bit `steam_api64.dll` handling support
- The script now prints a list of all DLCs and is able to download them if
  they are available
- The script now prints a list of all depots related to the game, so
  user can see if MSVC++ runtime or directX needs to be installed
- Fixed some issues related to the steamnative mode answer reading
- Fixed SteamApps folder name register (#2)
- Improved some error messages
- The `--overlay-dir` option was replaced by `--steam-dir` option, which should
  point to the steam installation folder in the system (`$HOME/.steam` usually)
  **Please ensure that you set up the steampath option in the config file
  (located in `$HOME/.config/SteamForwarder/config.json`) to make the steam
  overlay working**

### Build system:
- The 64-bit libraries now are being built by default. To make only 32-bit
  libraries use ARCH=32 flag passed to make

### Forwarding code:
- 64-bit `steam_api64.dll.so` implementation
- Reduced the Nim's GC influence on the memory by using static storage
  for wrappers, callbacks and vtables

### Packaging:
- The main repository has been moved to gitlab.com, but github is left as
  a mirror
- GitLab CI was configured to build and deploy the project every week,
  so the binary packages are available as artifacts in devel branch at gitlab
- Fixed the supplying of `libsteam_api.so` of wrong version (#22)
- The 64-bit `libsteam_api.so` libraries now are being deployed

# 0.3.1

### Installation script:
- The `--steamapps` option has been brought back to allow user to point
  the steamapps location not related to a steam volume.
- Installation script now able to select suitable version of the
  `steam_api.dll.so` libraries from existing ones without compilation.
- Fixed shebang string in the script header (#18)
- Fixed the language selection problem (#19)

### Dependecies:
- Nim compiler dependency has been removed for user. It might be necessary only
  if user want to build their own version of the `steam_api.dll.so` library.

### Forwarding code
- Fixed incorrect wrapped object passing to the C interface method-like
  function emulators.

### Packaging:
- Package now is being supplied with precompiled `steam_api.dll.so` files,
  so no more compilation needed for user for all known Steam API versions.
  The compilation (and compilation dependencies) might be necessary only when
  user will encounter unsupported version of `steam_api.dll`.
- Changed the folder layout inside the package. Now it has a bin folder with
  symlink to the installation script and a share folder with the SteamForwarder
  subfolder containing all other files.

### From the user perspective:
- Some subset of games won't crash anymore
- Less packets need to be installed to use SteamForwarder
- `sf_install` will show an error a bit less frequently
- `sf_install` will show another errors a bit more frequently =)
- Games can be placed everywhere user wants

# 0.3.0

### Architecture:
- `steam_api.dll.so` is being compiled for each game at installation step
  instead of one `steam_api.dll.so` for all games.
- `steam_api.dll.so` is being created for corresponding version of `steam_api.dll`
  and uses `libsteam_api.so` of the same version, so `libsteam_api.so` libraries of
  various versions is being supplied with SteamForwarder.
- The installation script now also manages `steam_api.dll.so` creation instead of
  just installing the game.
- Code generation tools has been removed in favor to code generation by macros
  of Nim language.
- All code was rewritten to the Nim language.

### Installation script:
- The installation script has been renamed from `app_install.py` to `sf_install`.
- The installation script now saves configuration to `$XDG_CONFIG/SteamForwarder`.
- The installation script also launches `steam_api.dll.so` compilation, so added
  new command line options to control it.
- Added possibility to use native steam client instead of steamcmd to download
  games (experimental flag `--steamnative`).
- Initial support of registry modification (as game demands it) when
  installation is being performed via `--depot`.

### Dependencies:
- Removed dependency from Steam API headers
- Added dependency from Nim compiler v0.18.0 or higher
- Dependency from steamcmd became optional

### Build system:
- Added install target for make to perform installation of SteamForwarder.
- Added dll analysis tools to implement `steam_api.dll.so` building for
  particular `steam_api.dll`.
- Removed the code generation step.
- The continuous integration system was attached to the project to check if it
  compiles for a test sample.

### Documentation:
- A little usage video example was added.
- Some implementation details was added to the project Wiki.
- Added a bit more detailed description to the README.md.

### From the user perspective:
- More games should work without the "Hard way". There is no more hard or easy
  ways anymore.
- The fresh Nim compiler now is required for user. Users from slowly updating
  distros may suffer this.
- There is a possibility to use native steam. So some games may be installed
  even if they were not able to with steamcmd. The steamcmd itself is not
  necessary anymore.
- The tool can be installed to the system or packed for the packet manager.
- Compilation steps is being performed on the users computer. So the tool
  became less fool-proof but more applyable. May be fixed by #17 in future.

# 0.2.3

- Added option for downloading games via steam depot (may help if the normal
  way of downloading does not work)
- The steam password now being asked via getpass instead of command line

# 0.2.2

- Full reimplementation of code generator. Should fix numerous of class
  layout errors.
- the installer script now depends only on steamcmd, the https://steamdb.info
  site parsing remains as a fallback

# 0.2.1

- AppId environment variable support in the generated runscript
- Added option to pass password to steamcmd
- Added support for multiple launch scenarios
- Some bugfixes

# 0.2

- Added installer script on Python
- Fixed problem with CallbackResult
- Fixed Makefile to avoid problems with make v4.1

# 0.1

First working implementaion on C++