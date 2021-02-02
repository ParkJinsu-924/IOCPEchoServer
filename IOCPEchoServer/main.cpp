
#include <iostream>
#include "CIOCPEchoServer.h"

CIOCPEchoServer myServer;

int main()
{
	if (!myServer.Start(L"0.0.0.0", 6000, 3, 3, false, 20000))
	{
		printf("adsf");
	}

	for (;;)
	{

	}
}

