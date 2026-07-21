#include "flags.h"
#include "machine.h"
#include "instructions.h"
#include "trace.h"
#include <stdlib.h>

// REG -> [A.. M]
#define PTR_REG(REG) &pstCPU->u8##REG

PSTRUCT_CPU pstCPUInit(void)
{
  PSTRUCT_CPU pstCPU = (PSTRUCT_CPU)calloc(1, sizeof(STRUCT_CPU));

  if (!pstCPU) return ((void *)0x00);

  vEnsureFRegCorrectFormat(pstCPU);

  return pstCPU;
}

int iCPUStep()
{
  // fetch, decode, execute, repeat

  uint8_t u8Opcode = u8MemoryReadByte(g_pstMachine->pstCPU->u16PC);

  vTraceVarArgsFn("Current opcode: 0x%2X", u8Opcode);

  // if high nibble starts with 01 then its part of MOV family (one exception handled)
  if ((u8Opcode & 0xC0) == 0x40) {
    if (u8Opcode == 0x76)
    {
      // HLT
    } else {
      // MOV family
      vInstrMOV(g_pstMachine->pstCPU, pu8GetCPUReg(g_CPU, u8Opcode >> 3 & 0x07),
                pu8GetCPUReg(g_CPU, u8Opcode & 0x07));
    }
  }
  return 0;
}

uint8_t *pu8GetCPUReg(PSTRUCT_CPU pstCPU, uint8_t u8RegId)
{
  switch (u8RegId)
  {
    case 0x00:
      vTraceVarArgsFn("REG ID: 0x%X | REG: B", u8RegId);

      return PTR_REG(B);
    case 0x01:
      vTraceVarArgsFn("REG ID: 0x%X | REG: C", u8RegId);

      return PTR_REG(C);
    case 0x02:
      vTraceVarArgsFn("REG ID: 0x%X | REG: D", u8RegId);

      return PTR_REG(D);
    case 0x03:
      vTraceVarArgsFn("REG ID: 0x%X | REG: E", u8RegId);

      return PTR_REG(E);
    case 0x04:
      vTraceVarArgsFn("REG ID: 0x%X | REG: H", u8RegId);

      return PTR_REG(H);
    case 0x05:
      vTraceVarArgsFn("REG ID: 0x%X | REG: L", u8RegId);

      return PTR_REG(L);
    case 0x06:
      // REG M
      vTraceVarArgsFn("REG ID: 0x%X | REG: M", u8RegId);

      return &g_pstMachine->pau8Memory[((uint16_t)pstCPU->u8H) << 8 | (uint16_t)pstCPU->u8L]; // REG H + REG L
    case 0x07:
      vTraceVarArgsFn("REG ID: 0x%2X | REG: A", u8RegId);

      return PTR_REG(A);
    default:
      vTraceVarArgsFn("REG ID: 0x%2X | NO REG RELATED", u8RegId);

      return ((void *)0x00);
  }
}

void vFreeCPU()
{
  free(g_pstMachine->pstCPU);
}