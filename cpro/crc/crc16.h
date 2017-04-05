#ifndef __CRC16_H__
#define __CRC16_H__

#define UCHAR unsigned char
#define UWORD unsigned short int

extern UWORD CRCCalculate(UCHAR *pBuffer, UCHAR ucLength);

#endif