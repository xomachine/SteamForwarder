{.deadCodeElim: on.}
from genmacros.wine import trace
from genmacros.cdecls import generateLinuxDecls, generateWineDecls
from genmacros.utils import parseFullSpec
const specname {.strdefine.} = "steam_api.auto.spec"
{.passL: "'" & specname & "'".}


#{.link: "callbacks.o".}
#{.compile: "callbacks.cpp".}
#{.compile: "steam_api.cpp".}
#{.link: "steam_api.o".}
#{.passL: "-lstdc++".}
#{.passC: "-I.".}
#{.passC: "-g".}
#{.passC: "-Iautoclass".}
#{.passC: "-Isteam".}
#{.passC: "-fpermissive".}
#{.passC: "-DVERSION_SAFE_STEAM_API_INTERFACES".}
#{.passC: "-DUSE_BREAKPAD_HANDLER".}

const spec = parseFullSpec(specname)
generateLinuxDecls(spec)
generateWineDecls(spec)

{.emit:["""
BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, void *reserved)
{
    """, trace, """("(%p, %u, %p)\n", instance, reason, reserved);

    switch (reason)
    {
        case DLL_WINE_PREATTACH:
            return FALSE;    /* prefer native version */
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(instance);
            NimMain();
            break;
    }

    return TRUE;
}
"""].}
