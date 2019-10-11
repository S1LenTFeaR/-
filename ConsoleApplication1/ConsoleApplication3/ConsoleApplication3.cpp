#include "pch.h"
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#define dt 0.05

struct tmp
{
	float Vx, Vy;
	float X, Y;
}tmp;

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	float a, X = 0, Y = 0, V, v0x, v0y, t, m, t1, b, k, Vx, Vy;
	float g = 9.80665, pi = 3.14159;
	ofstream Polet("Polet.txt");

	/* a - угол к горизонту в начале выстрела
		x,y - координаты
		V - начальная скорость
		t,t1 - общее время движения, текущее время
		b - угол к горизонту в радианах
		g - ускорение свободного падения
		pi - число пи
	*/

	cout << "Введите коэффициент сопротивления ветра k: ";
	cin >> k;
	cout << "Введите массу тела m, кг: ";
	cin >> m;
	cout << "Угол броска a, град: ";
	cin >> a;
	cout << "Введите начальную скорость тела V0: ";
	cin >> V;
	cout << endl;

	b = pi * a / 180;  // угол в радианах
	t = (2 * V*sin(b)) / g; // общее время движения

	v0x = V * cos(b);
	v0y = V * sin(b);



	tmp.Vx = v0x;
	tmp.Vy = v0y;
	tmp.X = 0;
	tmp.Y = 0;

	cout << "x: " << X << "\t\t" << "y: " << Y << endl;
	Polet << X << ";" << Y << endl;

	for (t1 = 0; t1 <= t; t1 += dt) // вывод координат
	{
		if (Y < 0)
			t1 += t;
		else
		{
			Vx = tmp.Vx - (k / m) * tmp.Vx * dt;
			Vy = tmp.Vy - (g + (k / m) * tmp.Vy) * dt;

			X = tmp.X + tmp.Vx * dt;
			Y = tmp.Y + tmp.Vy * dt;

			if (Y < 0)
			{
				cout << "x: " << X << "\t" << "y: " << "0" << endl;
				Polet << X << ";" << "0" << endl;
			}
			else
			{
				cout << "x: " << X << "\t" << "y: " << Y << endl;
				Polet << X << ";" << Y << endl;

				tmp.Vx = Vx;
				tmp.Vy = Vy;
				tmp.X = X;
				tmp.Y = Y;
			}

		}
	}

	printf("\n");
	Polet.close();
	return 0;
}
