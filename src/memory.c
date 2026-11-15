#include "memory.h"
#include "machine.h"
#include <stdlib.h>
#include <string.h>

#define G_MEMORY g_pstMachine->pau8Memory

uint8_t *pau8InitMemory(void) {
  uint8_t *au8Memory = (uint8_t *)malloc(MEMORY_SIZE);

  if (!au8Memory)
    return ((void *)0x00);

  return &au8Memory[0];
}

void vMemoryClear(void) { memset(G_MEMORY, 0x00, MEMORY_SIZE); }

void vFreeMemory(void) { free(G_MEMORY); }

uint8_t u8MemoryReadByte(uint16_t u16Address) { return G_MEMORY[u16Address]; }

void vMemoryWriteByte(uint16_t u16Address, uint8_t u8Value) {
  G_MEMORY[u16Address] = u8Value;
}

uint16_t u16MemoryReadWord(uint16_t u16Address) {
  return (uint16_t)G_MEMORY[u16Address] |
         ((uint16_t)G_MEMORY[u16Address + 1] << 8);
}

void vMemoryWriteWord(uint16_t u16Address, uint16_t u16Value) {
  G_MEMORY[u16Address] = (uint8_t)(u16Value & 0xFF);
  G_MEMORY[u16Address + 1] = (uint8_t)((u16Value >> 8) & 0xFF);
}