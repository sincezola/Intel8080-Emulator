#include <stdio.h>
#include "utils.h"
#include "memory.h"
#include "flags.h"
#include "machine.h"
#include "trace.h"

// by that time, tests only..
int main(void)
{
  int iMachineState = iInitMachine();
  uint8_t *pu8RegD;

  vInitLogs("./log/intel_logs", "trace");

  if (iMachineState) return 1;
  // tests ->>
  vMemoryWriteByte(0x00, 0x74);

  g_CPU->u8H = 0x10;
  g_CPU->u8L = 0x12;

  iCPUStep();

  // g_CPU->u8D = 0xFD;
  // pu8RegD = pu8GetCPUReg(g_CPU, 0x02);

  // vMemoryWriteByte(*pu8RegD, 0xAF);
  printf("0x%4X\n", u8MemoryReadByte(0x1012));
  // printf("0x%2X\n", g_CPU->u8B);

  vMemoryWriteByte(*pu8RegD, 0xAF);

  vFreeMachine();
  return 0;
}