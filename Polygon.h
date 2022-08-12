#pragma once
#include "Figure.h"
#include <list>
#include <iostream>
#include <exception>
#include <string>

typedef std::list<Point> Vertices_List; //��������� ����


class MyPolygon : public Figure
{
public:

	MyPolygon(Vertices_List listPoint);

	~MyPolygon();

	MyPolygon() {

	}

	double GetSquare() override;

	double GetPerimeter() override;

	void DrowForWindows(HWND hwnd) override;

	Vertices_List GetPoints();

	void ConvertForAPI(Vertices_List li, POINT *p);

protected:

	std::list<Point> Vertices; // ������ ��������� ������ ���������������

	double Square;
};

