#include "Circle.h"
#include "Polygon.h"
#include "Triangle.h"
#include <list>
#include <iostream>
#include<Windows.h>

#define _WIN32_WINNT 0x0A00
using namespace std;
//сложение строк как чисел
void SUM_STR(char a[], char b[], int BigestSize)
{
	short unsigned int E = 0; //перенос

	int size = 0;

	if (_msize(a) > _msize(b))
	{
		size = _msize(a) / sizeof(char) + 1;
	}
	else {
		size = _msize(b) / sizeof(char) + 1;
	}
	
	char *SUM = new char[size];

	SUM[size - 1] = 



}



int factorial(unsigned int n)
{
	if ( n == 0)
	{
		return 1;
	}
	else
	{





		int result = 1;
		for (int i = 1; i <= n; i++)
		{
			result *= i;
		}

		return result;
	}
}


int main()
{

	std::list<Point> li;


	Point A, B, C, D;
	A.X = 1; A.Y = 4;
	B.X = 10; B.Y = 10;
	C.X = 50; C.Y = 10;
	D.X = 330; D.Y = 450;

	li.push_front(A);
	li.push_front(B);
	li.push_front(C);
	li.push_front(D);

	Figure *e = new  MyPolygon(li);
	Figure *a = new  Circle(33, A);
	

	HWND hwnd = GetConsoleWindow();

	
	a->DrowForWindows(hwnd);
	e->DrowForWindows(hwnd);

	std::cout << "	" << factorial(123456);
	
	Sleep(20000);
}