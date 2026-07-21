#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

#define MEMORY_SIZE 65536

uint8_t  u8MemoryReadByte(uint16_t u16Address);
void     vMemoryWriteByte(uint16_t u16Address, uint8_t u8Value);

uint16_t u16MemoryReadWord(uint16_t u16Address);
void     vMemoryWriteWord(uint16_t u16Address, uint16_t u16Value);

uint8_t *pau8InitMemory(void);

void vMemoryClear(void);
void vFreeMemory(void);

#endif