#include "stdafx.h"
#include "MSH.h"

namespace LibSWBF2
{
	MSH::MSH()
	{

	}

	MSH::~MSH()
	{

	}

	void MSH::WriteToStream(ofstream& stream)
	{
		BaseChunk::WriteToStream(stream);
		shvo.WriteToStream(stream);
	}

	void MSH::ReadFromStream(ifstream& stream)
	{
		BaseChunk::ReadFromStream(stream);
		shvo.ReadFromStream(stream);
	}
}