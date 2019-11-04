#include "pch.h"
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#define m 80	//Масса парашютиста [кг]
#define dt 0.05 //Шаг [с]
#define c 1.22	//Коэффициент лобового сопротивления 
#define p 1.29	//Плотность среды [кг/м^3]
#define h1 1.8	//Рост [м]
#define z 0.45	//Полуобхват грудной клетки [м]
#define t 15	//Суммарное время полёта [с]

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	float g = 9.8;
	float V = 0, T = 0, Vi = 0, S, k2, k1;
	
	ofstream Polet("Polet.txt");

	S = h1 * z; 
	k2 = 0.5 * c * S * p;

	cout << fixed << setprecision(3) << "t: " << T << "\t" << "V: " << V << endl;
	Polet << fixed << setprecision(3) << T << ";" << V << endl;

	for (T = 0; T <= t; T += dt)
	{

		k1 = pow((Vi + dt * (m * g - k2 * Vi * Vi) / m), 2);

		V = Vi + dt / 2 * ((m*g - k2 * Vi * Vi) / m + (m * g - k2 * k1) / m);
		Vi = V;
		
		cout << fixed << setprecision(3) << "t: " << T << "\t" << "V: " << V << endl;
		Polet << fixed << setprecision(3) << T << ";" << V << endl;

	}
	
	Polet.close();
	system("pause");
	return 0;
}

