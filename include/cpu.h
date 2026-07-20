#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include "bool.h"

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

  BOOL bInterruptEnabled;
  BOOL bHalted;
} STRUCT_CPU, *PSTRUCT_CPU;

PSTRUCT_CPU pstCPUInit(void);
void vFreeCPU();

#endif