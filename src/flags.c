#include "flags.h"
#include "machine.h"

#define FLAGS_REG pstCPU->u8F

void vEnsureFRegCorrectFormat(PSTRUCT_CPU pstCPU) {
  FLAGS_REG &= 0xD7;
  FLAGS_REG |= 0x02;
}

bool bCPUGetFlag(PSTRUCT_CPU pstCPU, E_CPU_Flags eCpuFlag) {
  return (FLAGS_REG & eCpuFlag) != 0x00;
}

void vCPUSetFlag(PSTRUCT_CPU pstCPU, E_CPU_Flags eCpuFlag, bool bEnsureFormat) {
  FLAGS_REG |= eCpuFlag;

  if (bEnsureFormat)
    vEnsureFRegCorrectFormat(pstCPU);
}

void vCPUResetFlag(PSTRUCT_CPU pstCPU, E_CPU_Flags eCpuFlag,
                   bool bEnsureFormat) {
  FLAGS_REG &= ~eCpuFlag;

  if (bEnsureFormat)
    vEnsureFRegCorrectFormat(pstCPU);
}

static bool bGetParity(uint8_t u8value) {
  bool bParity = FALSE;

  for (uint8_t u8bit = 0; u8bit < 8; u8bit++)
    if (u8value & (1 << u8bit))
      bParity = !bParity;

  return !bParity;
}

void vSetFlagsByValue(PSTRUCT_CPU pstCPU, uint8_t u8Value) {
  CHECK_CPU;

  u8Value == 0 ? vCPUSetFlag(pstCPU, FLAG_Z, FALSE)
               : vCPUResetFlag(pstCPU, FLAG_Z, FALSE);
  u8Value & 0x80 ? vCPUSetFlag(pstCPU, FLAG_S, FALSE)
                 : vCPUResetFlag(pstCPU, FLAG_S, FALSE);
  bGetParity(u8Value) ? vCPUSetFlag(pstCPU, FLAG_P, FALSE)
                      : vCPUResetFlag(pstCPU, FLAG_P, FALSE);

  vEnsureFRegCorrectFormat(pstCPU);
}