/*
Author - Thomas "Starfroot!" Woods
Program - Team Fortress Team Coordinator (TFTC)
Build - Alpha 0.2.0
Desc - Setting up a socket system that isn't using deperciated functions (thanks MSDN >:()
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
	long SUCCESSFUL;
	WSAData WinSockData;
	WORD DLLVERSION;

	DLLVERSION = MAKEWORD(2, 1);

	SUCCESSFUL = WSAStartup(DLLVERSION, &WinSockData);

	SOCKADDR_IN ADDRESS;
	int AddressSize = sizeof(ADDRESS);

	SOCKET sock_LISTEN;
	SOCKET sock_CONNECTION;

	const CHAR addr[15] = "127.0.0.1";
	char buffer [sizeof(in_addr)];

	printf("Last error code was(1): %d\n", WSAGetLastError());

	sock_CONNECTION = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	ADDRESS.sin_addr.s_addr = INADDR_ANY;   //fixed to accept any network interface
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(444);

	printf("Last error code was(2): %d\n", WSAGetLastError());


	bind(sock_CONNECTION, (SOCKADDR *)&ADDRESS, AddressSize);

	printf("Last error code was(3): %d\n", WSAGetLastError());

	listen(sock_CONNECTION, 5);

	printf("Last error code was(4): %d\n", WSAGetLastError());
	//note to self: don't use %x when referring to WSAGetLastError, returns untrue value outside WSAerror regular field
	pause();
	return 0;
}