#pragma once
#include <Windows.h>


class Figure
{
public:
	virtual double GetSquare() = 0;
	virtual double GetPerimeter() = 0;
	virtual void DrowForWindows(HWND hwnd) = 0;
};


struct Point 
{
	unsigned int X;
	unsigned int Y;
};


