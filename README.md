# SteamForwarder
steam_api.dll implementation for wine. Your windows games now can interact with your linux steam!

# !DISCLAMER!
**The author is not liable for any damage resulting from the use of this software. User might broke his games, steam, OS or even computer. Users account might to be banned by Valve. EVERYTHING THAT YOU DOING, YOU DOING ON YOUR OWN RISK!**

## Compilation
1. Obtain [somewhere](https://partner.steamgames.com/home) latest steam api headers and put them into the **steam** folder. (They cannot be included to this repo due to licensing issues.)
2. Obtain libsteam_api.so from any of your linux games or from the sdk obtained in p.1, then put it to the repo root.
3. Open the terminal in the repo root and type *make*.
4. If something went wrong - go to the Hard way section.
5. When compilation will be completed you will see **steam_api.dll.so** in the repo root.

## Usage
1. Put your **libsteam_api.so** into LD_LIBRARY_PATH accessable location.
2. Put created **steam_api.dll.so** into WINEDLLPATH accessable location.
3. Once per WINEPREFIX set "*steam_api" as buildin via winecfg
4. Run the **steam**
5. Run your windows game through the wine.

## Hard way
//TODO
