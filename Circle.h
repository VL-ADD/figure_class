#pragma once
#include "Figure.h"
#include <exception>
#include <string>
#include <math.h>
#include <Windows.h>

#define M_PI 3.14159265358979323846

class Circle : public Figure
{
public:

	Circle(uint32_t R, Point C);

	double GetSquare() override;

	double GetPerimeter() override;

	void DrowForWindows(HWND hwnd) override;

	Point GetCenter();

	uint32_t GetRadius();

private:

	uint32_t Radiuse;
	Point Center;
};

