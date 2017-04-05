#include <stdio.h>
#include "crc16.h"

//#define UCHAR unsigned char
//#define UWORD unsigned short int

UWORD CRC_TABLE[16] = {
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7,
    0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
};

UWORD CRCCalculate(UCHAR *pBuffer, UCHAR ucLength)
{
    UWORD uwCRC;
    UCHAR ucTemp;

    uwCRC = 0xFFFF;
    while (ucLength--)
    {
        ucTemp = (UCHAR)(uwCRC >> 0x0C);
        //printf("ucTemp: %x\n", ucTemp);
        uwCRC <<= 4;
        //printf("uwCRC: %x\n", uwCRC);
        uwCRC ^= CRC_TABLE[ucTemp ^ ((*pBuffer) >> 0x04)];
        //printf("uwCRC: %x\n", uwCRC);
        ucTemp = (UCHAR)(uwCRC >> 0x0C);
        //printf("ucTemp: %x\n", ucTemp);
        uwCRC <<= 4;
        //printf("uwCRC: %x\n", uwCRC);
        uwCRC ^= CRC_TABLE[ucTemp ^ ((*pBuffer) & 0x0F)];
        //printf("uwCRC: %x\n", uwCRC);
        pBuffer++;
    }
    return uwCRC;
}

#if 0
int main(void)
{
    //UCHAR data[4] = {0xAA, 0x06, 0xBE, 0x30};
    //UCHAR data[] = {0xAA, 0x0A, 0xBE, 0x31, 0x31, 0x32, 0x33, 0x34};
    //UCHAR data[] = {0xAA, 0x0B, 0xB3, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55};
    UCHAR data[] = {0xAA, 0x06, 0x1D, 0x31};
    //UCHAR data[] = {0xAA, 0x15, 0xBE, 0x31, 0x33, 0x31, 0x36, 0x30, 0x31, 0x32, 0x36, 0x30, 0x32, 0x31, 0x30, 0x30, 0x30, 0x31, 0x32};
    //UCHAR data[] = {0xAA, 0x06, 0x17, 0x40};
    UWORD result = CRCCalculate(data, sizeof(data));
    printf("result: %x\n", result);
    return 0;
}
#endif