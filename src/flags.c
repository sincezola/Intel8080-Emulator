#include "flags.h"
#include "machine.h"

void vEnsureFRegCorrectFormat(PSTRUCT_CPU pstCPU) {
  pstCPU->u8F &= 0xD7;
  pstCPU->u8F |= 0x02;
}

void vCPUSetFlag(E_CPU_Flags eCpuFlag)
{
  g_pstMachine->pstCPU->u8F |= eCpuFlag;

  vEnsureFRegCorrectFormat(g_pstMachine->pstCPU);
}

void vCPUResetFlag(E_CPU_Flags eCpuFlag)
{
  g_pstMachine->pstCPU->u8F &= ~eCpuFlag;

  vEnsureFRegCorrectFormat(g_pstMachine->pstCPU);
}
