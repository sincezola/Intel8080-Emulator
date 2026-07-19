#ifndef FLAGS_H
#define FLAGS_H

// always: 

//    pCpu->u8F &= 0xD7;
//    pCpu->u8F |= 0x02;

#define FLAG_CY 0x01
#define FLAG_P  0x04
#define FLAG_AC 0x10
#define FLAG_Z  0x40
#define FLAG_S  0x80

#endif