#export PATH=/home/arm/buildroot-2009.11-fri/output/staging/usr/bin/:$PATH
CC=arm-linux-gcc
#CFLAGS=-pthread -I. -DBUF_ELEMENT="struct cmd_t"
CFLAGS=-pthread -I. -DBUF_ELEMENT="struct cmd_t" --sysroot=/home/arm/buildroot-2009.11-fri/output/staging
SERVER_OBJ= server.o buf.o
#BUFFER_OBJ= KrozniVmesnik.o buf.o 

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

#buf: $(BUFFER_OBJ)
#	$(CC) $^ -o $@ $(CFLAGS)

server: $(SERVER_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
all: server

.PHONY: clean

clean:
	rm -f *.o *~ server

