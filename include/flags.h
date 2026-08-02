#ifndef FLAGS_H
#define FLAGS_H

#include "cpu.h"

//    default format:
//      pCPU->u8F &= 0xD7;
//      pCPU->u8F |= 0x02;

typedef enum E_CPU_Flags {
  FLAG_CY = 0x01,
  FLAG_P  = 0x04,
  FLAG_AC = 0x10,
  FLAG_Z  = 0x40,
  FLAG_S  = 0x80,
} E_CPU_Flags;

bool bCPUGetFlag(PSTRUCT_CPU pstCPU, E_CPU_Flags eCpuFlag);
void vCPUSetFlag(PSTRUCT_CPU pstCPU, E_CPU_Flags eCpuFlag);
void vCPUResetFlag(PSTRUCT_CPU pstCPU, E_CPU_Flags eCpuFlag);
void vEnsureFRegCorrectFormat(PSTRUCT_CPU pstCPU);

#endif