#include "stdafx.h"
#include "LibString.h"
#include "Logger.h"

namespace LibSWBF2::Types
{
	using LibSWBF2::Logging::ELogType;

	String::String()
	{
		buffer = new char[1] { 0 };
	}

	String::String(const char* cStr) : String()
	{
		if (cStr == nullptr)
		{
			return;
		}

		length = strnlen_s(cStr, MAX_LENGTH);

		if (length > WARN_LENGTH)
		{
			LOG("String length " + std::to_string(length) + " exceeds " + std::to_string(WARN_LENGTH) + " which is rather unusual. Max supported String length is " + std::to_string(MAX_LENGTH), ELogType::Warning);
		}
		else if (length > MAX_LENGTH)
		{
			LOG("String length " + std::to_string(length) + " exceeds max supported length of " + std::to_string(MAX_LENGTH) + "! String will end up empty!", ELogType::Warning);
			buffer = nullptr;
			length = 0;
			return;
		}

		if (length > 0)
		{
			delete[] buffer;
			buffer = new char[length + 1];
			memcpy_s(buffer, length, cStr, length);
			buffer[length] = 0;
		}
	}

	String::String(const String& other) : length(other.length)
	{
		if (other.buffer == nullptr)
		{
			LOG("Given String is invalid (buffer is NULL)! This should never happen!", ELogType::Warning);
			buffer = new char[1]{ 0 };
		}
		else
		{
			buffer = new char[length + 1];
			memcpy_s(buffer, length + 1, other.buffer, length + 1);
		}
	}

	String::String(String&& other) : length(other.length), buffer(other.buffer)
	{
		if (other.buffer == nullptr)
		{
			LOG("Given String is invalid (buffer is NULL)! This should never happen!", ELogType::Warning);
		}

		other.buffer = nullptr;
		other.length = 0;
	}

	String::~String()
	{
		delete[] buffer;
		buffer = nullptr;
	}

	const char* String::Buffer() const
	{
		return buffer;
	}

	size_t String::Length() const
	{
		return length;
	}

	String& String::operator=(const String& other)
	{
		if (&other != this)
		{
			if (other.buffer == nullptr)
			{
				LOG("Given String is invalid (buffer is NULL)! String won't be copied!", ELogType::Warning);
			}
			else
			{
				length = other.length;
				delete[] buffer;
				buffer = new char[length + 1];
				memcpy_s(buffer, length + 1, other.buffer, length + 1);
			}
		}
		return *this;
	}

	bool String::operator==(const String& other)
	{
		return buffer != nullptr && other.buffer != nullptr && length == other.length && memcmp(buffer, other.buffer, length) == 0;
	}

	bool String::operator!=(const String& other)
	{
		return buffer == nullptr || other.buffer == nullptr || length != other.length || memcmp(buffer, other.buffer, length) != 0;
	}
}