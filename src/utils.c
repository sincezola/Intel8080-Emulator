#include "utils.h"
#include <stdio.h>

void vPrintBitsOfByte(uint8_t u8Byte) {
  int iBit;

  for (iBit = 7; iBit >= 0; iBit--) {
    printf("%d", (u8Byte >> iBit) & 0x1);
  }

  printf("\n");
}