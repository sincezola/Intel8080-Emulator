#ifndef MACHINE_H
#define MACHINE_H
  #include "cpu.h"
  #include "memory.h"

  typedef struct STRUCT_MACHINE
  {
    PSTRUCT_CPU pstCPU;
    uint8_t     *pau8Memory;
  } STRUCT_MACHINE, *PSTRUCT_MACHINE;

  extern PSTRUCT_MACHINE g_pstMachine;

  int iInitMachine(void);
  void vFreeMachine(void);
#endif