#pragma once
#include <iostream>

class Cbox
{
protected:
	int m_Length;
	int m_Width;
	int m_Height;

public:
	Cbox(int length = 1, int width = 1, int height = 1):
	                         m_Length(length), m_Width(width),m_Height(height) 
	{
		std::cout<< "......." <<std::endl;
	}

	int GetV(void) const
	{
		return  m_Length * m_Width * m_Height;
	}

	Cbox & operator=(const Cbox & box)
	{
		m_Length = box.m_Length;
		m_Width  = box.m_Width;
		m_Height = box.m_Height;

		return *this;
	}

	Cbox operator+(const Cbox & box)
	{
		Cbox t;
		t.m_Length = m_Length + box.m_Length;
		t.m_Width  = m_Width  + box.m_Width;
		t.m_Height = m_Height + box.m_Height;

		return 0;
	}

	~Cbox(void)
	{
		std::cout<<"*********"<<std::endl;
	}
};
