/*
Author - Thomas "Starfroot!" Woods
Program - Team Fortress Team Coordinator (TFTC) (server)
Copyright (c) 2015
This material may be used freely under the following conditions
	- This content is not used for gain, including but not limited to personal, professional, and monetary
	- This notice must remain at the top of this content in any form that it is used.
	- Credit must always be provided to the creator of this content, regardless of presentation or medium of usage
*/

#include "stdafx.h"

using namespace std;

int main()
{
	//starting message
	printf("Server is launching...\n");

	//setting up WSA
	WSADATA wsaData;
	int WSAcheck = WSAStartup(MAKEWORD(2, 2), &wsaData);

	//checking WSA
	if (WSAcheck != 0)
	{
		printf("WSA couldn't start correctly\n");
		pause();
		return 1;
	}

	//setting up the socket
	SOCKET serversock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//checking socket's validity
	if (serversock == INVALID_SOCKET)
	{
		printf("Socket isn't valid: %d\n", WSAGetLastError());
		pause();
		return 1;
	}

	//setting up the sockaddr_in for bind()
	sockaddr_in server_sockaddr;
	server_sockaddr.sin_family = AF_INET;
	server_sockaddr.sin_addr.s_addr = INADDR_ANY;
	server_sockaddr.sin_port = htons(25565);

	//binding the socket.
	int bindcheck = bind(serversock, (struct sockaddr *)&server_sockaddr, sizeof(server_sockaddr));

	//checking to see if the bind worked, and calling the error if it doesn't
	if (bindcheck != 0)
	{
		printf("Bind failed: %d\n", WSAGetLastError());
		pause();
		return 1;
	}

	//setting the socket to listen
	int listencheck = listen(serversock, 10);

	//checking to make sure the listen command was successful
	if (listencheck != 0)
	{
		printf("Listen failed: %d\n", WSAGetLastError());
		pause();
		return 1;
	}

	//telling that the socket is being set to listen
	printf("Socket established; Listening for incoming connections\n");

	//accepting any incoming connections
	SOCKET clientsocket = accept(serversock, NULL, NULL);

	//checking the socket
	if (clientsocket == INVALID_SOCKET)
	{
		printf("Connecting socket isn't valid or has timed out: %d\n", WSAGetLastError());
		pause();
		return 1;
	}

	//setting up to receive data from a connected client
	char recv_buffer[7];
	printf("The socket is ready to receive data...\n");
	int bytesreceived = recv(clientsocket, recv_buffer, sizeof(recv_buffer), NULL);

	if(bytesreceived == SOCKET_ERROR)
	{
		printf("Error in receiveing data from the client: %d\n", WSAGetLastError());
		pause();
		return 1;
	}
	printf("bytes received: %d | message: %s\n", bytesreceived, recv_buffer);
	
	//ending the program
	pause();
	return 0;
}