#include "memory.h"

uint8_t au8Memory[65536] = { 0x00000000 };

uint8_t u8MemoryReadByte(uint16_t u16Address) {
  return au8Memory[u16Address];
}

void vMemoryWriteByte(uint16_t u16Address, uint8_t u8Value)
{
  au8Memory[u16Address] = u8Value;
}

uint16_t u16MemoryReadWord(uint16_t u16Address)
{
  return (uint16_t)au8Memory[u16Address] |
         ((uint16_t)au8Memory[u16Address + 1] << 8);
}

void vMemoryWriteWord(uint16_t u16Address, uint16_t u16Value)
{
  au8Memory[u16Address] = u16Value;
  // au8Memory[u16Address + 1] = u16Value >> 8;
}