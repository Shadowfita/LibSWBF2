#pragma once
#include "Vector2.h"

namespace LibSWBF2::Types
{
	struct LIBSWBF2_EXP Vector3 : public Vector2
	{
		static const ChunkSize SIZE = sizeof(float_t) * 3;

		Vector3();
		Vector3(const float_t& x, const float_t& y, const float_t& z);
		~Vector3();

		void WriteToStream(FileWriter& stream) override;
		void ReadFromStream(FileReader& stream) override;

		float_t m_Z = 0.0f;
	};
}