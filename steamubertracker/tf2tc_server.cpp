/*
Author - Thomas "Starfroot!" Woods
Program - Team Fortress Team Coordinator (TFTC) (server)
*/

/*
Error codes - 
1) WSA failed to start
2) Socket failed to instantiate
3) Socket failed to bind
4) Socket failed to listen

*/
#include "stdafx.h"

using namespace std;

int main()
{
	
	
	
	WSAData WinSockData;
	WORD DLLVERSION;
	DLLVERSION = MAKEWORD(2, 1);
	int wsa_success = WSAStartup(DLLVERSION, &WinSockData);
	if (wsa_success != 0)
	{	
		printf("Error %d while starting WSA\n", WSAGetLastError());
		pause();
		return 1;
	}



	SOCKET uc_socket;
	uc_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (uc_socket == INVALID_SOCKET)
	{
		printf("Error %d while creating socket\n", WSAGetLastError());
		pause();
		return 1;
	}
	


	SOCKADDR_IN ADDRESS;
	int AddressSize = sizeof(ADDRESS);
	


	ADDRESS.sin_addr.s_addr = INADDR_ANY;   //fixed to accept any network interface
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(444);



	int bind_success = bind(uc_socket, (SOCKADDR *)&ADDRESS, AddressSize);
	if (bind_success != 0)
	{
		printf("Error %d while binding socket\n", WSAGetLastError());
		pause();
		return 1;
	}



	int listen_success = listen(uc_socket, 12);
	if (listen_success != 0)
	{
		printf("Error %d while setting socket to listen\n", WSAGetLastError());
		pause();
		return 1;
	}


	SOCKET c_socket;
	SOCKADDR_IN client_sock;   //changed SOCKADDR to SOCKADDR_IN
	int client_sock_size = sizeof(client_sock);
	printf("Socket created; Set to listen for incoming connections\n");
	c_socket = accept(uc_socket, (SOCKADDR *)&client_sock, &client_sock_size);
	if (c_socket == INVALID_SOCKET)
	{
		printf("Error %d while accepting connection request\n", WSAGetLastError());
		pause();
		return 1;
	}
	else
	{
		printf("Connection established!\n");
	}

	pause();
	return 0;
}