#include "stdafx.h"
#include "NRML.h"

namespace LibSWBF2::Chunks::Mesh
{
	void NRML::RefreshSize()
	{
		m_Size = (ChunkSize)(sizeof(uint32_t) + m_Normals.Size() * Vector3::SIZE);
	}

	void NRML::WriteToStream(FileWriter& stream)
	{
		BaseChunk::WriteToStream(stream);
		stream.WriteUInt32((uint32_t)m_Normals.Size());

		for (size_t i = 0; i < m_Normals.Size(); ++i)
		{
			m_Normals[i].WriteToStream(stream);
		}
	}

	void NRML::ReadFromStream(FileReader& stream)
	{
		BaseChunk::ReadFromStream(stream);
		uint32_t numVertices = stream.ReadUInt32();

		m_Normals.Clear();
		m_Normals.Resize(numVertices);

		for (uint32_t i = 0; i < numVertices; ++i)
		{
			Vector3& vertex = m_Normals.Emplace();
			vertex.ReadFromStream(stream);
		}

		BaseChunk::EnsureEnd(stream);
	}
}