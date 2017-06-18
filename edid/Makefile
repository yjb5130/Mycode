SOURCE=$(wildcard *.c)
OBJS=$(patsubst %.c,%,$(SOURCE))

all:$(OBJS)
%:%.c
	gcc -o $@ $<

.PHONY:clean
clean:
	rm -rf *.o $(OBJS)
