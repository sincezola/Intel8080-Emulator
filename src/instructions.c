#include "machine.h"
#include "bool.h"
#include "flags.h"

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

static void vIncrPC(PSTRUCT_CPU pstCPU);

#define CHECK_POINTER_AND_INCR(ptr, cpu) \
  do {                                    \
    if (!ptr)                              \
    {                                       \
      vIncrPC(cpu);                          \
      return;                                 \
    }                                          \
  } while (0x00)

static void vIncrPC(PSTRUCT_CPU pstCPU)
{
  CHECK_CPU

  pstCPU->u16PC += au8InstructionSize[u8MemoryReadByte(pstCPU->u16PC)];
}

// Does nothing
void vInstrNOP(PSTRUCT_CPU pstCPU)
{
  CHECK_CPU

  vIncrPC(pstCPU);
}

// Movs pu8rSrc to pu8rDst
void vInstrMOV(PSTRUCT_CPU pstCPU, uint8_t *pu8rDst, uint8_t *pu8rSrc)
{
  CHECK_CPU

  CHECK_POINTER_AND_INCR(pu8rDst, pstCPU);
  CHECK_POINTER_AND_INCR(pu8rSrc, pstCPU);

  *pu8rDst = *pu8rSrc;

  vIncrPC(pstCPU);
}

// Adds pu8value to Accumulator (u8a)
void vInstrADD(PSTRUCT_CPU pstCPU, uint8_t *pu8value, bool bUseCarry)
{
  uint16_t u16Temp = 0x0000;

  CHECK_CPU
  CHECK_POINTER_AND_INCR(pu8value, pstCPU);

  u16Temp = pstCPU->u8A + *pu8value;

  if (bUseCarry)
    u16Temp += bCPUGetFlag(pstCPU, FLAG_CY);

  pstCPU->u8A = (uint8_t)u16Temp;

  if (u16Temp > 0xFF)
    vCPUSetFlag(pstCPU, FLAG_CY);
  else
    vCPUResetFlag(pstCPU, FLAG_CY);
}
