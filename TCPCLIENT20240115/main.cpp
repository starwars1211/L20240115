#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib, "ws2_32")

using namespace std;

int main()
{
	WSAData wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	HOSTENT* ServerInfo;
	//ServerInfo = gethostbyname("naver.com");
	/*
	if (ServerInfo)
	{
		if (ServerInfo->h_addrtype == AF_INET)
		{
			cout << ServerInfo->h_name << endl;
			int i = 0;
			IN_ADDR IP;
			for(int i = 0; i < ServerInfo->h_length; ++i)
			//ServerInfo->h_length
			//while (ServerInfo->h_addr_list[i] != 0)
			{
				// 시작위치
				IP.s_addr = *(u_long*)ServerInfo->h_addr_list[i];
				printf("ip : %s\n" , inet_ntoa(IP));
				i++;
			}
		}
	}
	*/
	char IPAddress[] = "223.130.200.107";
	ServerInfo = gethostbyaddr(IPAddress, strlen(IPAddress), AF_INET);
	if (ServerInfo)
	{
		if (ServerInfo->h_addrtype == AF_INET)
		{
			cout << ServerInfo->h_name << endl;
		}
		IN_ADDR IP;
		for (int i = 0; i < ServerInfo->h_length; ++i)
		{
			IP.s_addr = *(u_long*)ServerInfo->h_addr_list[i];
			printf("ip : %s\n", inet_ntoa(IP));
		}
	}

	WSACleanup();

	return 0;
};