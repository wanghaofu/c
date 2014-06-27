# Makefile for the socket programming example
#

simple_server_objects = ServerSocket.o Socket.o simple_server_main.o
simple_client_objects = ClientSocket.o Socket.o simple_client_main.o


all : simple_server simple_client

simple_server: $(simple_server_objects)
	g++ -o simple_server $(simple_server_objects)


simple_client: $(simple_client_objects)
	g++ -o simple_client $(simple_client_objects)

Socket.o: Socket.cpp
ServerSocket.o: ServerSocket.cpp
ClientSocket.o: ClientSocket.cpp
simple_server_main.o: simple_server_main.cpp
simple_client_main.o: simple_client_main.cpp

.PHONY:clean
clean:
	rm -f *.o 
