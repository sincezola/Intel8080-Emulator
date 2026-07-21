#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
  #include "cpu.h"

  void vInstrNOP(PSTRUCT_CPU pstCPU);
  void vInstrMOV(PSTRUCT_CPU, uint8_t *pu8rDst, uint8_t *pu8rSrc);
#endif