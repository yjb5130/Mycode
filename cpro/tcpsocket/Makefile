CFLAGS=-g3
LDFLAGS=-lpthread

all:tcpserver tcpclient

tcpserver:tcpserver.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
tcpserver.o:tcpserver.c
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

tcpclient:tcpclient.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
tcpclient.o:tcpclient.c
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

.PHONY:clean
clean:
	rm -rf *.o *~ tcpserver tcpclient
