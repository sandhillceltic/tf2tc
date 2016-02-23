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
	int wsasuccessful = -1;
	WSAData WinSockData;
	WORD DLLVERSION;
	DLLVERSION = MAKEWORD(2, 1);
	wsasuccessful = WSAStartup(DLLVERSION, &WinSockData);
	if (wsasuccessful != 0)
	{
		printf("Error %d in client while starting WSA\n", WSAGetLastError());
		pause();
		return 1;
	}



	SOCKET client_socket;
	client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (WSAGetLastError() != 0)
	{
		printf("Error %d in client while instantiating socket\n", WSAGetLastError());
		pause();
		return 1;
	}



	SOCKADDR_IN client_connection;
	client_connection.sin_family = AF_INET;
	client_connection.sin_port = (USHORT)(444);

	client_connection.sin_addr.S_un.S_addr = (unsigned long)("0.0.0.0");
	//S_un contains several children that take the address in different forms


	int connection_success = -1;
	printf("Connection started!");
	connection_success = connect(client_socket, (SOCKADDR *)&client_connection, sizeof(client_connection));
	if (connection_success != 0)
	{
		printf("Error %d in client while instantiating socket\n", WSAGetLastError());
		pause();
		return 2;
	}
	printf("The client has found a server!");
	printf("The last WSA error was: %d", WSAGetLastError());


	pause();
	return 0;
}