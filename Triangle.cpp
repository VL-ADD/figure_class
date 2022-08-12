#include "Triangle.h"

Triangle::Triangle(Vertices_List Points)
{
	if (Points.size() != 3)
	{
		throw std::exception("вершин должно быть 3");
	}
	else
	{
		auto i = Points.begin();
		double A = sqrt( pow(std::next(i)->X - i->X, 2) + pow(std::next(i)->Y - i->Y, 2));
		i++;
		double B = sqrt(pow(std::next(i)->X - i->X, 2) + pow(std::next(i)->Y - i->Y, 2));
		double C = sqrt(pow(Points.back().X - Points.front().X, 2) + pow(Points.back().Y - Points.front().Y, 2));

		
		if (A+B <= C || A+C <= B || C+B <= A)
		{
			throw std::exception("точки лежат на одной прямой");
		}
		else
		{
			//Vertices.merge(Points);
			Vertices = Points;
		}
	}
}