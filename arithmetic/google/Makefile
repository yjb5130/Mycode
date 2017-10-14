CFLAGS=-g3
LDFLAGS=-lpthread

TARGET=google
SOURCE=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SOURCE))

$(TARGET):$(OBJS)
	$(CC) -o $@ $^
%.o:%.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY:clean
clean:
	rm -rf *.o $(TARGET)

