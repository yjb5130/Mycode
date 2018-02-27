CFLAGS=-g3
LDFLAGS=-lpthread

all:test_strtok

test_strtok:strtok.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
strtok.o:strtok.c
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

.PHONY:clean
clean:
	rm -rf *.o *~ test_strtok
