#include "pch.h"
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	float a, x=0, y=0, V, v0x, v0y, t, m, t1, b, k, kof;
	float g = 9.80665, pi = 3.14159, e = 2.71828;
	ofstream Polet("Polet.txt");

	/* a - угол к горизонту в начале выстрела
		x,y - координаты
		V - начальная скорость
		t,t1 - общее время движения, текущее время
		b - угол к горизонту в радианах
		g - ускорение свободного падения
		pi - число пи
	*/

	cout << "k: ";
	cin >> k;
	cout << "m: ";
	cin >> m;
	cout << "Angle: ";
	cin >> a;
	cout << "V: ";
	cin >> V;
	cout << endl;

	b = pi * a / 180;  // угол в радианах
	t = (2 * V*sin(b)) / g; // общее время движения
	v0x = V * cos(b);
	v0y = V * sin(b);

	for (t1 = 0; t1 <= t; t1 += 0.005) // вывод координат
	{
		if (y < 0)
			t1 += t;
		else
		{
			kof = -k * t1 / m;
			x = v0x * (m / k)*(1 - pow(e, kof));
			cout << "x: " << x << "\t";
			Polet << x << ";";
			y = (m / k)*(((v0y + m * g / k)*((1 - pow(e, kof)))) - g * t1);
			cout << "y: " << y << endl;
			Polet << y << endl;
		}
	}

	printf("\n");
	Polet.close();
	return 0;
}
