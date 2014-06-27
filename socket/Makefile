# Makefile for the socket programming example
#

server_objects = ServerSocket.o Socket.o serverMain.o
client_objects = ClientSocket.o Socket.o clientMain.o


all : server client

server: $(server_objects)
	g++ -o server $(server_objects)


client: $(client_objects)
	g++ -o client $(client_objects)

Socket.o: Socket.cpp
ServerSocket.o: ServerSocket.cpp
ClientSocket.o: ClientSocket.cpp
serverMain.o: serverMain.cpp
clientMmain.o: clientMain.cpp

.PHONY:clean
clean:
	rm -f *.o 
