#include "flags.h"
#include "machine.h"

#define FLAGS_REG pstCPU->u8F

void vEnsureFRegCorrectFormat(PSTRUCT_CPU pstCPU)
{
  FLAGS_REG &= 0xD7;
  FLAGS_REG |= 0x02;
}

bool bCPUGetFlag(PSTRUCT_CPU pstCPU, E_CPU_Flags eCpuFlag)
{
  return (FLAGS_REG & eCpuFlag) != 0;
}

void vCPUSetFlag(PSTRUCT_CPU pstCPU, E_CPU_Flags eCpuFlag)
{
  FLAGS_REG |= eCpuFlag;

  vEnsureFRegCorrectFormat(pstCPU);
}

void vCPUResetFlag(PSTRUCT_CPU pstCPU, E_CPU_Flags eCpuFlag)
{
  FLAGS_REG &= ~eCpuFlag;

  vEnsureFRegCorrectFormat(pstCPU);
}
