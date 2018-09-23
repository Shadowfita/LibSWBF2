#include "stdafx.h"
#include "FileReader.h"
#include "Logger.h"

namespace LibSWBF2
{
	using LibSWBF2::Logging::Logger;
	using LibSWBF2::Logging::ELogType;

	FileReader::FileReader()
	{

	}

	FileReader::~FileReader()
	{

	}

	bool FileReader::Open(const string& File)
	{
		open(File, std::ofstream::in | std::ofstream::binary | std::ofstream::ate);
		bool success = good() && is_open();

		if (!success)
		{
			LOG("File '" + File + "' could not be found / opened!", ELogType::Error);
			m_FileName = "";
			close();
			return false;
		}

		m_FileSize = tellg();
		seekg(0);

		m_FileName = File;
		return true;
	}

	ChunkHeader FileReader::ReadChunkHeader(const bool& peek)
	{
		ChunkHeader value = 0;
		if (CheckGood(sizeof(ChunkHeader)))
		{
			auto pos = tellg();
			operator>>(value);

			// do not advance our reading position when peeking
			if (peek)
			{
				seekg(pos);
			}
		}
		return value;
	}

	ChunkSize FileReader::ReadChunkSize()
	{
		ChunkSize value = 0;
		if (CheckGood(sizeof(ChunkSize)))
		{
			operator>>(value);
		}
		return value;
	}

	uint8_t FileReader::ReadByte()
	{
		uint8_t value = 0;
		if (CheckGood(sizeof(uint8_t)))
		{
			read((char*)&value, 1);
		}
		return value;
	}

	int32_t FileReader::ReadInt32()
	{
		int32_t value = 0;
		if (CheckGood(sizeof(int32_t)))
		{
			operator>>(value);
		}
		return value;
	}

	uint32_t FileReader::ReadUInt32()
	{
		uint32_t value = 0;
		if (CheckGood(sizeof(uint32_t)))
		{
			operator>>(value);
		}
		return value;
	}

	float_t FileReader::ReadFloat()
	{
		float_t value = 0;
		if (CheckGood(sizeof(float_t)))
		{
			operator>>(value);
		}
		return value;
	}

	string FileReader::ReadString(size_t length)
	{
		string value = "";
		if (CheckGood(length))
		{
			char* str = new char[length];
			read(str, length);
			value = str;
			delete[] str;
		}
		return value;
	}

	void FileReader::Close()
	{
		if (!is_open())
		{
			LOG("Nothing has been opened yet!", ELogType::Error);
			return;
		}

		m_FileName = "";
		close();
	}

	size_t FileReader::GetPosition()
	{
		return tellg();
	}

	bool FileReader::CheckGood(size_t ReadSize)
	{
		if (!is_open())
		{
			LOG("Error during read process! File '" + m_FileName + "' is not open!", ELogType::Error);
			return false;
		}

		if (!good())
		{
			LOG("Error during read process in '" + m_FileName + "'!", ELogType::Error);
			return false;
		}

		size_t current = tellg();
		if (current + ReadSize >= m_FileSize)
		{
			LOG("Reading " + std::to_string(ReadSize) + " bytes will end up out of file!  Current position: " + std::to_string(current) + "  FileSize: " + std::to_string(m_FileSize), ELogType::Error);
			return false;
		}

		return true;
	}
}