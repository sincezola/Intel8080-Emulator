#include "machine.h"

static const uint8_t au8InstructionSize[256] =
{
  /* 0x00 */ 1, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 1, 1, 1, 2, 1,
  /* 0x10 */ 1, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 1, 1, 1, 2, 1,
  /* 0x20 */ 1, 3, 3, 1, 1, 1, 2, 1, 1, 3, 3, 1, 1, 1, 2, 1,
  /* 0x30 */ 1, 3, 3, 1, 1, 1, 2, 1, 1, 3, 3, 1, 1, 1, 2, 1,
  /* 0x40 */ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  /* 0x50 */ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  /* 0x60 */ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  /* 0x70 */ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  /* 0x80 */ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  /* 0x90 */ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  /* 0xA0 */ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  /* 0xB0 */ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  /* 0xC0 */ 1, 1, 3, 3, 3, 1, 2, 1, 1, 1, 3, 1, 3, 3, 2, 1,
  /* 0xD0 */ 1, 1, 3, 2, 3, 1, 2, 1, 1, 1, 3, 2, 3, 3, 2, 1,
  /* 0xE0 */ 1, 1, 3, 1, 3, 1, 2, 1, 1, 1, 3, 1, 3, 1, 2, 1,
  /* 0xF0 */ 1, 1, 3, 1, 3, 1, 2, 1, 1, 1, 3, 1, 3, 1, 2, 1,
};

#define CHECK_CPU \
  do {             \
    if (!pstCPU)    \
      return;        \
  } while (0);

static void vIncrPC(PSTRUCT_CPU pstCPU) {
  CHECK_CPU

  pstCPU->u16PC += au8InstructionSize[u8MemoryReadByte(pstCPU->u16PC)];
}

void vInstrNOP(PSTRUCT_CPU pstCPU)
{
  CHECK_CPU

  vIncrPC(pstCPU);
}

void vInstrMOV(PSTRUCT_CPU pstCPU, uint8_t *pu8rDst, uint8_t *pu8rSrc)
{
  CHECK_CPU

  if (!pu8rDst || !pu8rSrc)
  {
    vIncrPC(pstCPU); // just to avoid infinite repetition
    return;
  }

  *pu8rDst = *pu8rSrc;

  vIncrPC(pstCPU);
}
