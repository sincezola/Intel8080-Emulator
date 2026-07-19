#ifndef CPU_H
#define CPU_H

#include <inttypes.h>
#include "bool.h"

typedef struct Cpu8080 {
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
} Cpu8080;

#endif