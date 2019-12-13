#include "pch.h"
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>


using namespace std;

float N = 0.0;

double I_0 = 0.0;
double I = 0.0;
double Beta = 0.0;
double Omega_0 = 0.0;
double q_0 = 0.0;
double E_max = 0.0;
double L = 0.0;
double Omega = 0.0;
double t = 0.0;
double dt = 0.00001;
double t_i = 0.0;
double q = 0.0;
double R = 0.0;
double C = 0.0;
double nu = 0.0;
double E = 0.0;

void polet(ofstream & kI, ofstream & kq)
{
	I = 0; //Сила тока [А]
	q = 2 * pow(10, -6); //Заряд конденсатора [Кл]
	R = 200;
	L = 0.5; //Индуктивность [Гн]
	C = 0.5 * pow(10, -6);
	t = 0;
	dt = 0.00001;
	E = 10;
	Beta = R / (2 * L); //Коэффицент затухания
	Omega_0 = sqrt(1 / (L * C));
	Omega = sqrt(Omega_0 * Omega_0 - Beta * Beta);
	double E_max = 220;
	I -= (2 * Beta * I + Omega_0 * Omega_0 * q - (E_max * cos(Omega * t) / L)) * (dt / 2.0);

	while (t <= 3)
	{
		I -= (2 * Beta * I + Omega_0 * Omega_0 * q - (E_max * cos(Omega * t) / L)) * dt;
		q = q + I * dt;
		E = E_max * cos(Omega * t);
		t += dt;
		kI << fixed << setprecision(3) << t * 2500 << ";" << setprecision(3) << I * 30 << endl;
		kq << fixed << setprecision(3) << t * 2500 << ";" << setprecision(3) << q * 6500 << endl;
	}
}

int main()
{
	ofstream kI("I.txt");
	ofstream kq("q.txt");
	polet(kI, kq);
	kI.close();
	kq.close();
	return 0;
}