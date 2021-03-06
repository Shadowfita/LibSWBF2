#pragma once
#include "BaseChunk.h"

namespace LibSWBF2::Chunks::Mesh
{
	struct SEGM;

	struct LIBSWBF2_EXP POSL : public BaseChunk
	{
		POSL() = default;
		~POSL() = default;

		List<Vector3> m_Vertices;

	protected:
		friend SEGM;

		void RefreshSize() override;
		void WriteToStream(FileWriter& stream) override;
		void ReadFromStream(FileReader& stream) override;
	};
}
