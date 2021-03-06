#include "stdafx.h"
#include "Vector2.h"

namespace LibSWBF2::Types
{
	Vector2::Vector2() : m_X(m_X), m_Y(m_Y) 
	{
	
	}

	Vector2::Vector2(const float_t& x, const float_t& y) : m_X(x), m_Y(y) 
	{
	
	}

	Vector2::~Vector2()
	{

	}

	void Vector2::WriteToStream(FileWriter& stream)
	{
		stream.WriteFloat(m_X);
		stream.WriteFloat(m_Y);
	}

	void Vector2::ReadFromStream(FileReader& stream)
	{
		m_X = stream.ReadFloat();
		m_Y = stream.ReadFloat();
	}
}