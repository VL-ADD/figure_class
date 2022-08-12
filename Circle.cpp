#include "Circle.h"


Circle::Circle(uint32_t R, Point C)
{
	if (R < 1)
	{
		throw std::exception("радиус не может быть меньше 1 (пикселя)");
	}
	else {

		Radiuse = R;
		Center = C;
	}
}

double Circle::GetPerimeter()
{
	return 2 * M_PI * Radiuse;
}

double Circle::GetSquare()
{
	return M_PI * pow(Radiuse, 2);
}


Point Circle::GetCenter()
{
	return Center;
}

uint32_t Circle::GetRadius()
{
	return Radiuse;
}

void Circle::DrowForWindows(HWND hwnd)
{
	HDC dc = GetDC(hwnd);
	SelectObject(dc, GetStockObject(DC_BRUSH));
	SetDCBrushColor(dc, RGB(255, 0, 255));

	Ellipse(dc, Center.X - Radiuse, Center.Y + Radiuse, Center.X + Radiuse, Center.Y - Radiuse);
}