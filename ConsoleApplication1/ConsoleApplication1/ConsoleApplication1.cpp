
#include "pch.h"
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#define m 60 //Масса Ростика
#define R 2 //Радиус парашюта
#define dt 0.05 
#define c 1.33
#define p 0.5
#define h1 0.5
#define z 0.5

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	float k2, g = 9.8, V, yi, h, t, Vi = 0, ti, T, S;
	S = h1 * z;

	k2 = 0.5 * c * S * p;
	//t = V * m / (k2 * V * V - m * g);
	for (T = 0; T <= (t = 60); T += dt) // вывод координат
	{
		//T = t - ti;
		V = Vi + T / 2 * ((m*g - k2 * Vi * Vi) / m + (m * g - k2 * (Vi + T * (m * g - k2 * Vi * Vi) / m)*(Vi + T * (m * g - k2 * Vi * Vi) / m)) / m);
		Vi = V;
		cout << V << endl;
	}

	return 0;
}