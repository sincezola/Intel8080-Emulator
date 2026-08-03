#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include "bool.h"

#define g_CPU g_pstMachine->pstCPU

#define CHECK_CPU \
  do {             \
    if (!pstCPU)    \
      return;        \
  } while (0x00)      \

typedef struct STRUCT_CPU {
  uint8_t u8A;

  uint8_t u8B;
  uint8_t u8C;

  uint8_t u8D;
  uint8_t u8E;

  uint8_t u8H;
  uint8_t u8L;

  uint8_t u8F;

  uint16_t u16PC;
  uint16_t u16SP;

  uint64_t u64Cycles;

  bool bInterruptEnabled;
  bool bHalted;
} STRUCT_CPU, *PSTRUCT_CPU;

PSTRUCT_CPU pstCPUInit(void);
uint8_t *pu8GetCPUReg(PSTRUCT_CPU pstCPU, uint8_t u8RegId);
void vFreeCPU();

int iCPUStep();

#endif