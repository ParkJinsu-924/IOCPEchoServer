#pragma once
#include "CLanServer\CLanServer.h"

struct stHEADER
{
	short length;
};

struct stPACKET
{
	long long packet;
};

class CIOCPEchoServer : public CLanServer
{
	void OnClientJoin(UINT64 sessionID) override
	{
		stPACKET packet;

		packet.packet = 0x7fffffffffffffff;

		CSerializationBuffer* packetBuf = CSerializationBuffer::Alloc();

		packetBuf->PutContentData((char*)&packet, sizeof(packet));

		SendPacket(sessionID, packetBuf);

		packetBuf->DeqRef();
	}

	void OnClientLeave(UINT64) override
	{
		//TODO
	}

	bool OnConnectionRequest(PWCHAR, short) override
	{
		//TODO
		return true;
	}

	VOID OnRecv(UINT64 sessionID, CSerializationBuffer* buf) override
	{
		//buf는 데이터
		stPACKET packet;

		buf->GetContentData((char*)&packet, sizeof(packet));

		CSerializationBuffer* packetBuf = CSerializationBuffer::Alloc();

		packetBuf->PutContentData((char*)&packet, sizeof(packet));

		SendPacket(sessionID, packetBuf);

		packetBuf->DeqRef();
	}

	VOID OnError() override
	{
	}
};