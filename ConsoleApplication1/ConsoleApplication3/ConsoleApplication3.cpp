#include "pch.h"
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#define dt 0.2	//Шаг времени [с]
#define r 0.2	//Радиус шарика [м]
#define km 0.53	//Коэффициент динамической вязкости среды [Н∙с/м2]
#define p 4500	//Плотность титана [кг/м^3]
#define P 900	//Плотность бензина [кг/м^3]
#define t 1000	//Суммарное время полёта [с]
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	float g = 9.807, pi = 3.142;
	float V, T, k1, m, h, Ft, Vi = 0, hi = 0;
	/*
		V - скорость тела [м/с]
		T - время, которое шар находится в полёте [с]
		m - масса тела [кг]
		h - расстояние, которое пролетел шар [м]
		Ft - сила тяжести [Н]
		Vi и hi - скорость и расстояние на предыдущем шаге
	*/
	ofstream PoletV("PoletV.txt");
	ofstream Poleth("Poleth.txt");

	k1 = 6 * pi * km * r;
	m = 4 * pi * p * pow(r, 3)/3;
	Ft = (4 * pi * pow(r, 3) * (p - P)) / 3 * g;

	cout << "k1: " << k1 << "\tm: " << m << endl;

	for (T = 0; T <= t; T += dt) 
	{
		V = Vi + dt / 2 * ((Ft - k1 * Vi) / m + (Ft - k1 * (Vi + dt * (Ft - k1 * Vi) / m) ) / m);
		h = hi + V * dt;
		
		Vi = V;
		hi = h;
		
		cout << fixed << setprecision(3) << "t: " << T << "\t" << "V: " << V << "\t" << "h: " << h << endl;
		PoletV << fixed << setprecision(3)<< T << ";" << V << endl;
		Poleth << fixed << setprecision(3)<< T << ";" << h << endl;
	}

	PoletV.close();
	Poleth.close();
	
	system("pause");
	return 0;
}
