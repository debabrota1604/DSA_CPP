CC=g++
all: server client
server: server.o
	${CC} -o server serverProg.cpp
client: client.o
	${CC} -o client clientProg.cpp
clean:
	rm server.o client.o server client