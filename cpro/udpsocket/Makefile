CFLAGS=-g3
LDFLAGS=-lpthread

all:udpserver udpclient

udpserver:udpserver.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
udpserver.o:udpserver.c
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

udpclient:udpclient.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
udpclient.o:udpclient.c
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

.PHONY:clean
clean:
	rm -rf *.o *~ udpserver udpclient
