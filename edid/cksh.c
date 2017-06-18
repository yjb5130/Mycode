#include <stdio.h>

int main(void)
{
    int i = 0;
    unsigned char sum1 = 0;
    unsigned char sum2 = 0;
    unsigned char array[] = {
    0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,
    0x22,0x69,0x01,0x00,0x01,0x00,0x00,0x00,
    0x17,0x1B,0x01,0x03,0x80,0x79,0x44,0x78,
    0x0A,0xD7,0xA5,0xA2,0x59,0x4A,0x96,0x24,
    0x14,0x50,0x54,0xA3,0x08,0x00,0xD1,0xC0,
    0xB3,0x00,0x81,0x00,0x81,0x80,0x81,0x40,
    0x81,0xC0,0x01,0x01,0x01,0x01,0x04,0x74,
    0x00,0x30,0xF2,0x70,0x5A,0x80,0xB0,0x58,
    0x8A,0x00,0xB9,0xA8,0x42,0x00,0x00,0x1E,
    0x66,0x21,0x50,0xB0,0x51,0x00,0x1B,0x30,
    0x40,0x70,0x36,0x00,0xB9,0xA8,0x42,0x00,
    0x00,0x1E,0x00,0x00,0x00,0xFD,0x00,0x1E,
    0x4C,0x1E,0x50,0x1E,0x00,0x0A,0x20,0x20,
    0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xFC,
    0x00,0x48,0x69,0x54,0x56,0x0A,0x20,0x20,
    0x20,0x20,0x20,0x20,0x20,0x20,0x01,0xBA,
    0x02,0x03,0x38,0x73,0x53,0x90,0x05,0x04,
    0x03,0x07,0x02,0x06,0x01,0x1F,0x14,0x13,
    0x12,0x16,0x11,0x15,0x5F,0x5E,0x5D,0x20,
    0x29,0x09,0x07,0x03,0x57,0x07,0x00,0x15,
    0x07,0x50,0x6D,0x03,0x0C,0x00,0x10,0x00,
    0x00,0x3C,0x20,0x00,0x60,0x01,0x02,0x03,
    0xE3,0x0E,0x60,0x61,0x83,0x01,0x00,0x00,
    0x01,0x1D,0x00,0xBC,0x52,0xD0,0x1E,0x20,
    0xB8,0x28,0x55,0x40,0xC4,0x8E,0x21,0x00,
    0x00,0x1E,0x01,0x1D,0x80,0xD0,0x72,0x1C,
    0x16,0x20,0x10,0x2C,0x25,0x80,0xC4,0x8E,
    0x21,0x00,0x00,0x9E,0x8C,0x0A,0xD0,0x8A,
    0x20,0xE0,0x2D,0x10,0x10,0x3E,0x96,0x00,
    0x13,0x8E,0x21,0x00,0x00,0x18,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xAA,
    };

    for (i = 0; i < 127; i++)
    {
        sum1 = sum1 + array[i];
    }
    sum1 = -sum1;
    printf("sum1: %x\n", sum1);
    
    for (i = 128; i < 254; i++)
    {
        sum2 = sum2 + array[i];
    }
    sum2 = -sum2;
    printf("sum2: %x\n", sum2);
    
    return 0;
}
