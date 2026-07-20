#include "memory.h"
#include "machine.h"
#include <string.h>
#include <stdlib.h>

uint8_t *pau8InitMemory(void)
{
  uint8_t *au8Memory = (uint8_t *)malloc(MEMORY_SIZE);

  if (!au8Memory) return ((void *)0x00);

  return &au8Memory[0];
}

void vMemoryClear(void)
{
  memset(g_pstMachine->pau8Memory, 0x00, MEMORY_SIZE);
}

void vFreeMemory(void)
{
  free(g_pstMachine->pau8Memory);
}

uint8_t u8MemoryReadByte(uint16_t u16Address) {
  return g_pstMachine->pau8Memory[u16Address];
}

void vMemoryWriteByte(uint16_t u16Address, uint8_t u8Value)
{
  g_pstMachine->pau8Memory[u16Address] = u8Value;
}

uint16_t u16MemoryReadWord(uint16_t u16Address)
{
  return (uint16_t)g_pstMachine->pau8Memory[u16Address] |
         ((uint16_t)g_pstMachine->pau8Memory[u16Address + 1] << 8);
}

void vMemoryWriteWord(uint16_t u16Address, uint16_t u16Value)
{
  g_pstMachine->pau8Memory[u16Address] = (uint8_t)(u16Value & 0xFF);
  g_pstMachine->pau8Memory[u16Address + 1] = (uint8_t)((u16Value >> 8) & 0xFF);
}