#pragma once
#include "BaseChunk.h"

namespace LibSWBF2::Chunks::MSH
{
	struct FRAM : public BaseChunk
	{
		FRAM();
		~FRAM();

		void WriteToStream(ofstream& stream) override;
		void ReadFromStream(ifstream& stream) override;

	private:
		int32_t FrameRangeStart;
		int32_t FrameRangeEnd;
		float_t FramesPerSecond;
	};
}