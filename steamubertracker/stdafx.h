// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently

#pragma once

#ifdef UNICODE
#undef UNICODE
#endif

#ifdef _UNICODE
#undef _UNICODE
#endif

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <Inaddr.h>
#include <string.h>
#include <io.h>
#include <Windef.h>
#include <Ws2tcpip.h>
#include <WinNT.h>
#include <Windows.h>
#include <tchar.h>

void pause(void);  //defined in stdafx.cpp