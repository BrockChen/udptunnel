INCLUDE = -I./include
CC = gcc -g 
#CC = /home/felipe/Sources/OpenWrt-SDK-brcm47xx-2.6-for-Linux-i686/staging_dir_mipsel/bin/mipsel-linux-gcc
CFLAGS = -Wall -g 

all: socket.o tun.o util.o client.o server.o main.o
	$(CC) socket.o tun.o util.o client.o server.o main.o -o mtunnel
	#$(CC) socket.o tun.o util.o server.o -o server

socket.o: socket.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $?

tun.o: tun.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $?

main.o: main.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $?

util.o: util.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $?

client.o: client.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $?

server.o: server.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $?

clean:
	rm -f *.o client server mtunnel
