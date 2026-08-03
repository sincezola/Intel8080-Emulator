#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
  #include "cpu.h"

  void vInstrNOP(PSTRUCT_CPU pstCPU);
  void vInstrMOV(PSTRUCT_CPU pstCPU, uint8_t *pu8rDst, uint8_t *pu8rSrc);
  void vInstrADD(PSTRUCT_CPU pstCPU, uint8_t *pu8value, bool bUseCarry);
  void vInstrSUB(PSTRUCT_CPU pstCPU, uint8_t *pu8value, bool bUseBorrow);
#endif