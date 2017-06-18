#!/usr/bin/python

year = 2017
week = 23
height = 1209
width = 680
name = "ELEKTA TV"

WEEK_INDEX = 0x10
YEAR_INDEX = 0x11
H_IMAGE_INDEX = 0x15
V_IMAGE_INDEX = 0x16
H_LOW_INDEX1 = 0x42
V_LOW_INDEX1 = 0x43
SIZE_HIGH_INDEX1 = 0x44

H_LOW_INDEX2 = 0x54
V_LOW_INDEX2 = 0x55
SIZE_HIGH_INDEX2 = 0x56

NAME_INDEX = 0x5f
NAME_LENGTH = 11

file = open('vga.txt', 'r')
edid = file.read()
temps = edid.replace("\n","").split(',')
#for temp in temps:
#    print temp
file.close()

# week and year
temps[WEEK_INDEX] = hex(week)
temps[YEAR_INDEX] = hex(year - 1990)

# width and height
temps[H_IMAGE_INDEX] = hex(int(round(float(height) / 10)))
temps[V_IMAGE_INDEX] = hex(int(round(float(width) / 10)))

# detail size1
temps[H_LOW_INDEX1] = hex(height & 0xff)
temps[V_LOW_INDEX1] = hex(width & 0xff)
temps[SIZE_HIGH_INDEX1] = hex((height >> 8 << 4) + (width >> 8))

# detail size2
temps[H_LOW_INDEX2] = hex(height & 0xff)
temps[V_LOW_INDEX2] = hex(width & 0xff)
temps[SIZE_HIGH_INDEX2] = hex((height >> 8 << 4) + (width >> 8))

# edid name
for i in range(0, len(name)):
    temps[NAME_INDEX + i] = hex(ord(name[i]))
    #print temps[NAME_INDEX + i]
temps[NAME_INDEX + len(name)] = '0x0A'

# cks
sum = 0
for i in range(0, 127):
    sum = (sum + int(temps[i], 16)) & 0xff
temps[127] = hex(256 - sum)


for i in range(0, 128):
    if ((i + 1) % 8 == 0):
        print temps[i] + ','
    else:
        print temps[i] + ',',

