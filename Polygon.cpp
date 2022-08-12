#include "Polygon.h"

MyPolygon::~MyPolygon()
{
	Vertices.clear();
}

MyPolygon::MyPolygon(Vertices_List listPoint)
{
	if (listPoint.size() < 3)
	{
		throw std::exception("вершин должно быть болше 2х");
	}
	else {
		
		double S = 0;


		auto i = listPoint.begin();
		while (std::next(i) != listPoint.end())
		{
			S = S + (i->X * std::next(i)->Y) - (std::next(i)->X * i->Y);
			i++;
		}




		S = S / 2;

		if (S == 0) {
			throw std::exception("все точки лежат на одной линии");
		}
		else {
			
		    Square = S;
			Vertices = listPoint;
		}
	}
}


double MyPolygon:: GetSquare() 
{
	return Square;
}

double MyPolygon::GetPerimeter()
{
	double P = 0;


	auto i = Vertices.begin();
	while (std::next(i) != Vertices.end())
	{
		P = P + sqrt(pow(std::next(i)->X - i->X, 2) + pow(std::next(i)->Y - i->Y, 2));
		i++;
	}

	P = P + sqrt(pow(Vertices.back().X - Vertices.front().X, 2) + pow(Vertices.back().Y - Vertices.front().Y, 2));

	P = P / Vertices.size();

	return P;
}


Vertices_List MyPolygon::GetPoints()
{
	return Vertices;
}

void MyPolygon::ConvertForAPI(Vertices_List li, POINT *p) {
	std::list<POINT> Points;
	int j = 0;
	for (auto i = li.begin(); i != li.end(); i++) {
		POINT a;
		a.x = i->X;
		a.y = i->Y;
		p[j] = a;
		j++;
	}
}

void MyPolygon::DrowForWindows(HWND hwnd)
{
	//HPEN Pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
	HDC dc = GetDC(hwnd);
	SelectObject(dc, GetStockObject(DC_BRUSH));
	SetDCBrushColor(dc, RGB(255, 0, 255));

	POINT *Points = new POINT[Vertices.size()];
	ConvertForAPI(Vertices, Points);

	Polygon(dc, Points, 4);

	delete Points;
}