#include <stdio.h>
#include "utils.h"
#include "memory.h"
#include "flags.h"
#include "machine.h"

// by that time, tests only..
int main(void)
{
  int iMachineState = iInitMachine();
  if (iMachineState) return 1;

  // tests ->>
  vMemoryWriteWord(0x1000, 0x1234);
  printf("0x%4X\n", u16MemoryReadWord(0x1000));

  printf("0x%4X\n", u16MemoryReadWord(0x10));

  vFreeMachine();
  return 0;
}