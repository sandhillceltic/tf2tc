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

	const CHAR addr[15] = "192.168.1.1";
	char buffer [sizeof(in_addr)];

	sock_CONNECTION = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	ADDRESS.sin_addr.s_addr = inet_pton(AF_INET, (const CHAR*)&addr, &buffer);
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(444);


	bind(sock_CONNECTION, (SOCKADDR *)&ADDRESS, AddressSize);

	listen(sock_CONNECTION, 5);

	printf("Last error code was: %d", WSAGetLastError());   
	//note to self: don't use %x when referring to WSAGetLastError, returns untrue value outside WSAerror regular field
	pause();
	return 0;
}