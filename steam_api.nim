{.deadCodeElim: on.}
from genmacros.cdecls import generateLinuxDecls, generateWineDecls
from genmacros.utils import parseFullSpec
const specname {.strdefine.} = "steam_api.auto.spec"
{.passL: specname.}
const spec = parseFullSpec(specname)
generateLinuxDecls(spec)
generateWineDecls(spec)


