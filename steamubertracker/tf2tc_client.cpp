/*
Author - Thomas "Starfroot!" Woods
Program - Team Fortress Team Coordinator (TFTC) (client)
Copyright (c) 2015
This material may be used freely under the following conditions
	- This content is not used for gain, including but not limited to personal, professional, and monetary
	- This notice must remain at the top of this content in any form that it is used.
	- Credit must always be provided to the creator of this content, regardless of presentation or medium of usage
*/

//make the code unicode friendly

#include "stdafx.h"

using namespace std;

int main()
{
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
	SOCKET clientsock = socket(AF_INET, SOCK_STREAM, 0);

	//checking socket's validity
	if (clientsock == INVALID_SOCKET)
	{
		printf("Socket isn't valid: %d\n", WSAGetLastError());
		pause();
		return 1;
	}

	//setting up the struct with the connection info
	sockaddr_in serverinfo;
	serverinfo.sin_family = AF_INET;
	serverinfo.sin_port = htons(25565);

	//putting the address to connect to into binary form
	const char outgoingaddress[INET_ADDRSTRLEN] = "127.0.0.1";
	int convertcheck = InetPton(AF_INET, (PCSTR)&outgoingaddress, (void*)&serverinfo.sin_addr.s_addr);

	//checking Inetpton() to make sure the function wrote the address to the variable
	if (convertcheck != 1)
	{
		printf("The convertion of the address from P to N failed\n");
		pause();
		return 1;
	}

	//connecting
	printf("Attemping to connect...\n");
	int connectcheck = connect(clientsock, (SOCKADDR *)&serverinfo, sizeof(serverinfo));

	//checking the connection
	if (connectcheck == SOCKET_ERROR)
	{
		printf("Connection to server failed: %d\n", WSAGetLastError());
		pause();
		return 1;
	}

	printf("Connection to server established, press [ENTER] to send data...\n");
	pause();

	//sending data to the server
	const char info_tobesent[7] = "Thomas";
	int sendcheck = send(clientsock, (const char*)&info_tobesent, sizeof(info_tobesent), NULL);
	if (sendcheck == SOCKET_ERROR)
	{
		printf("Data failed to send to server: %d\n", WSAGetLastError());
		pause();
		return 1;
	}
	printf("Data sent successfully!");

	//ending the program
	pause();
	return 0;
}