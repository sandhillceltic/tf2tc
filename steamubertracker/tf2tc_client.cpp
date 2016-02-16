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



	int connection_success = -1;
	SOCKADDR client_connection;
	client_connection.sa_family = AF_INET;

	//turning the print address into something the computer can understand
	char connection_address[14] = "192.168.1.1";
	char na_converted[sizeof(in_addr)];
	inet_pton(AF_INET, (PCSTR)&connection_address, &na_converted);

	client_connection.sa_data = na_converted;    //not sure why this value isn't modifiable
	connection_success = connect(client_socket, (SOCKADDR *)&client_connection, sizeof(client_connection));
	if (connection_success != 0)
	{
		printf("Error %d in client while instantiating socket\n", WSAGetLastError());
		pause();
		return 2;
	}


	pause();
	return 0;
}