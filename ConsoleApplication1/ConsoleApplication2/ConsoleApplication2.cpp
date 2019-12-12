#include "pch.h"
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#define Z 79

using namespace std;

//Задаем начальные значение
double xmin = -3;
double x = xmin;
double xmax = 1;
double ymin = 0.1;
double y = ymin;
double ymax = 5;
double dt = 0.01;
double t = 0;
double tk = 5;
double Vx = 3;
double Vy = 0;


int main()
{
	ofstream file("Polet.txt");
	double e = 1.602189246 * pow(10, -19);
	double k = 8.987551777 * pow(10, 9);
	double Ma = 6.638 * pow(10, -27);
	double kof = (2 * k * Z * e * e) / Ma;
	while ((t <= tk) && (x <= xmax) && (y <= ymax))
	{
		Vx = Vx + kof * abs(x) * pow(x * x + y * y, -1.5) * dt;
		Vy = Vy + kof * abs(y) * pow(x * x + y * y, -1.5) * dt;
		x += Vx * dt;
		y += Vy * dt;
		t += dt;
		if ((x <= xmax) && (y <= ymax))
			file << x << ";" << y << endl;
	}
	/*Vx = 3;
	Vy = 0;
	x = -3;
	y = 0.3;
	t = 0;
	while ((t <= tk) && (x <= xmax) && (y <= ymax))
	{
		Vx = Vx + kof * abs(x) * pow(x * x + y * y, -1.5) * dt;
		Vy = Vy + kof * abs(y) * pow(x * x + y * y, -1.5) * dt;
		x += Vx * dt;
		y += Vy * dt;
		t += dt;
		if ((x <= xmax) && (y <= ymax))
			file << x << ";" << y << endl;
	}
	Vx = 3;
	Vy = 0;
	x = -3;
	y = 0.5;
	t = 0;
	while ((t <= tk) && (x <= xmax) && (y <= ymax))
	{
		Vx = Vx + kof * abs(x) * pow(x * x + y * y, -1.5) * dt;
		Vy = Vy + kof * abs(y) * pow(x * x + y * y, -1.5) * dt;
		x += Vx * dt;
		y += Vy * dt;
		t += dt;
		if ((x <= xmax) && (y <= ymax))
			file << x << ";" << y << endl;
	}*/

	system("pause");
	return 0;
}