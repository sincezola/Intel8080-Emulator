#include <stdio.h>
#include "memory.h"

int main()
{
  vMemoryWriteWord(0x1000, 0x1234);
  printf("%d\n", u16MemoryReadWord(0x1000));

  return 0;
}