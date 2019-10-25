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
	float a, x = 0, y = 0, V, t, m, t1, b;
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

	cout << "Угол броска a, град: ";
	cin >> a;
	cout << "Введите начальную скорость тела V0: ";
	cin >> V;
	cout << endl;

	b = pi * a / 180;  // угол в радианах
	t = (2 * V*sin(b)) / g; // общее время движения

	for (t1 = 0; t1 <= t; t1 += 0.05) // вывод координат
	{
		x = V * cos(b)*t1;
		y = V * sin(b)*t1 - g * t1*t1 / 2;
		cout << "x: " << x << "\t" << "y: " << y << endl;
		Polet << x << ";" << y << endl;
	}
	cout << "x: " << "0.0" << "\t\t" << "y: " << "0.0" << endl;
	Polet << "0.0" << ";" << y << "0.0" << endl;
	/*
	for (t1, t; t1 <= t; t1 = t1 + 0.01) // вывод координат
	{
		x = V * cos(b)*t1;
		printf("x: %f\t", x);
		fprintf(koord, "%lf;", x);
		y = V * sin(b)*t1 - g * t1*t1 / 2;
		printf("y: %f\n", y);
		fprintf(koord, "%lf\n", y);
	}*/

	printf("\n");
	Polet.close();
	return 0;
}