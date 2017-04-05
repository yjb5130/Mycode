CFLAGS=-g3

TARGET=crc
SOURCE=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SOURCE))

$(TARGET):$(OBJS)
	gcc -o $@ $^ $(CFLAGS)

%.o:%.c
	gcc -o $@ -c $< $(CFLAGS)

.PHONY:clean
clean:
	rm -rf $(TARGET) *.o
