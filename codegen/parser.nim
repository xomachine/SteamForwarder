from streams import Stream, readChar, peekChar, atEnd

proc ignoreTill*(source: Stream, terminator: set[char]) =
  var c: char
  while (c = source.readChar; c notin terminator and not source.atEnd()):
    discard

proc parseTill*(source: Stream, terminator: set[char]): string =
  result = ""
  var c: char
  while (c = source.readChar(); c notin terminator and not source.atEnd()):
    result.add(c)
    case c
    of '(':
      result &= source.parseTill({')'})
    of '{':
      result &= source.parseTill({'}'})
    of '"':
      source.ignoreTill({'"'})
    of '/':
      if source.peekChar() == '/':
        source.ignoreTill({"\n"[0]})
    else:
      discard
  result.add(c)
