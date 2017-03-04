from streams import Stream, readChar, peekChar

proc ignoreTill*(source: Stream, terminator: set[char]) =
  var c: char
  while (c = source.readChar; c notin terminator):
    discard

proc parseTill*(source: Stream, terminator: set[char]): string =
  result = ""
  var c: char
  while (c = source.readChar(); c notin terminator):
    result.add(c)
    case c
    of '(':
      result &= source.parseTill({')'})
    of '{':
      result &= source.parseTill({'}'})
    of '/':
      if source.peekChar() == '/':
        source.ignoreTill({"\n"[0]})
    else:
      discard
  result.add(c)
