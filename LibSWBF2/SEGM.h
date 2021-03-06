#pragma once
#include "BaseChunk.h"
#include "MATI.h"
#include "POSL.h"
#include "WGHT.h"
#include "NRML.h"
#include "UV0L.h"
#include "STRP.h"

namespace LibSWBF2::Chunks::Mesh
{
	struct GEOM;

	struct LIBSWBF2_EXP SEGM : public BaseChunk
	{
		SEGM() = default;
		~SEGM() = default;

		MATI m_MaterialIndex;
		POSL m_VertexList;
		WGHT m_WeightList;
		NRML m_NormalList;
		UV0L m_UVList;
		STRP m_TriangleList;

	protected:
		friend GEOM;
		
		void RefreshSize() override;
		void WriteToStream(FileWriter& stream) override;
		void ReadFromStream(FileReader& stream) override;
	};
}