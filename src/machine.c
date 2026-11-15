#include "machine.h"
#include <stdlib.h>

PSTRUCT_MACHINE g_pstMachine = ((void *)0x00);

int iInitMachine(void) {
  g_pstMachine = (PSTRUCT_MACHINE)calloc(1, sizeof(STRUCT_MACHINE));

  if (!g_pstMachine)
    return 1;

  g_CPU = pstCPUInit();

  if (!g_CPU)
    return 1;

  g_pstMachine->pau8Memory = pau8InitMemory();

  if (!g_pstMachine->pau8Memory) {
    vFreeCPU();

    return 1;
  }

  vMemoryClear();
  return 0;
}

void vFreeMachine(void) {
  vFreeCPU();
  vFreeMemory();

  free(g_pstMachine);
}