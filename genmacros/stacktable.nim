type
  AddrTable*[TSize: static[int], T] = tuple
    size: int
    origins: array[TSize, pointer]
    wrapped: array[TSize, T]

proc getByWrapped[TSize, T](self: AddrTable[TSize, T], wrapped: pointer): int =
  for i in 0..<self.size:
    if self.wrapped[i].unsafeaddr == wrapped:
      return i
  return -1

proc getByOrigin[TSize, T](self: AddrTable[TSize, T], origin: pointer): int =
  for i in 0..<self.size:
    if self.origins[i] == origin:
      return i
  return -1

proc convertToWrapped*[TSize, T](self: AddrTable[TSize, T],
                                 origin: pointer): ptr T =
  let pos = self.getByOrigin(origin)
  if pos == -1: nil
  else: self.wrapped[pos].unsafeaddr

proc convertToOrigin*[TSize, T](self: AddrTable[TSize, T],
                                wrapped: pointer): pointer =
  let pos = self.getByWrapped(wrapped)
  if pos == -1: nil
  else: self.origins[pos]

proc associate*[TSize, T](self: var AddrTable[TSize, T],
                          origin: pointer): ptr T =
  self.origins[self.size] = origin
  self.wrapped[self.size].reset()
  result = self.wrapped[self.size].addr
  inc(self.size)

proc removeByPos[TSize, T](self: var AddrTable[TSize, T], pos: int) =
  if pos != -1:
    if pos < self.size - 1:
      self.wrapped[pos] = self.wrapped[self.size-1]
      self.origins[pos] = self.origins[self.size-1]
    dec(self.size)

proc removeByOrigin*[TSize, T](self: var AddrTable[TSize, T], origin: pointer) =
  self.removeByPos(self.getByOrigin(origin))

proc removeByWrapped*[TSize, T](self: var AddrTable[TSize, T], wrap: pointer) =
  self.removeByPos(self.getByWrapped(wrap))
