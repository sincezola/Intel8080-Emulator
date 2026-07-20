#include "flags.h"
#include "machine.h"
#include <stdlib.h>

PSTRUCT_CPU pstCPUInit(void)
{
  PSTRUCT_CPU pstCPU = (PSTRUCT_CPU)calloc(1, sizeof(STRUCT_CPU));

  if (!pstCPU) return ((void *)0x00);

  vEnsureFRegCorrectFormat(pstCPU);

  return pstCPU;
}

void vFreeCPU()
{
  free(g_pstMachine->pstCPU);
}