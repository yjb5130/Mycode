#include <stdio.h>
#include "crc16.h"

int main(void)
{
    UCHAR data[] = {0xAA, 0x06, 0x1D, 0x31};
    //UCHAR data[] = {0xAA, 0x15, 0xBE, 0x31, 0x33, 0x31, 0x36, 0x30, 0x31, 0x32, 0x36, 0x30, 0x32, 0x31, 0x30, 0x30, 0x30, 0x31, 0x32};
    UWORD result = CRCCalculate(data, sizeof(data));
    printf("result: %x\n", result);
    return 0;
}

