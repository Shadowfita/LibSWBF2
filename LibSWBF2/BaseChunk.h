#pragma once
#include "HeaderNames.h"
#include "FileWriter.h"
#include "FileReader.h"
#include "Logger.h"
#include "Color.h"
#include "Vector4.h"
#include "List.h"
#include "LibString.h"

namespace LibSWBF2::Chunks
{
	using Logging::Logger;
	using Logging::ELogType;
	using Types::Color;
	using Types::Vector2;
	using Types::Vector3;
	using Types::Vector4;
	using LibSWBF2::Types::List;
	using LibSWBF2::Types::String;

	struct LIBSWBF2_EXP BaseChunk
	{
		bool WriteToFile(const string& Path);
		bool ReadFromFile(const string& Path);

	protected:
		BaseChunk() = default;
		~BaseChunk() = default;

		// These MUST be overridden in subclasses!
		virtual void RefreshSize();
		virtual void WriteToStream(FileWriter& stream);
		virtual void ReadFromStream(FileReader& stream);

		bool PositionInChunk(const size_t& CurrentPosition);
		bool SkipChunk(FileReader& stream, const bool& printWarn = true);
		void EnsureEnd(FileReader& stream);

		ChunkHeader GetHeader();
		ChunkSize GetSize();

		// since these variables are critical
		// we should keep them protected
		ChunkHeader m_Header = 0;
		ChunkSize m_Size = 0;
		size_t m_ChunkDataPosition = 0;	// in File (for reading process)
	};
}