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
	
	
	
	int wsasuccessful;
	WSAData WinSockData;
	WORD DLLVERSION;
	DLLVERSION = MAKEWORD(2, 1);
	wsasuccessful = WSAStartup(DLLVERSION, &WinSockData);
	if (wsasuccessful != 0)
	{
		printf("Error %d while starting WSA\n", wsasuccessful);
		pause();
		return 1;
	}



	SOCKADDR_IN ADDRESS;
	int AddressSize = sizeof(ADDRESS);
	SOCKET uc_socket;



	uc_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	ADDRESS.sin_addr.s_addr = INADDR_ANY;   //fixed to accept any network interface
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(444);
	if (WSAGetLastError() != 0)
	{
		printf("Error %d while establishing socket\n", WSAGetLastError());
		pause();
		return 1;
	}



	bind(uc_socket, (SOCKADDR *)&ADDRESS, AddressSize);
	if (WSAGetLastError() != 0)
	{
		printf("Error %d while binding socket\n", WSAGetLastError());
		pause();
		return 1;
	}



	listen(uc_socket, 12);
	if (WSAGetLastError() != 0)
	{
		printf("Error %d while binding socket\n", WSAGetLastError());
		pause();
		return 1;
	}


	SOCKET c_socket;
	SOCKADDR client_sock;
	int client_sock_size = sizeof(client_sock);
	c_socket = accept(uc_socket, (SOCKADDR *)&client_sock, &client_sock_size);



	//pause();
	return 0;
}