from classparser import StackState

proc eachInt*(k: string, a: seq[StackState], sink: NimNode): NimNode
  {.compileTime.}
proc makePseudoMethods*(): NimNode {.compileTime.}

proc eachInt(k: string, a: seq[StackState], sink: NimNode): NimNode =
  discard
proc makePseudoMethods(): NimNode =
  discard

