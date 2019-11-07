#include "stdafx.h"
#include "pch.h"
#include "Documents.h"
#include <iostream>
#include <iomanip> // Библиотека для использования манипуляторов ввода-вывода.
using namespace std;



double document::get_total_price()
{
	return total_price;
}

int document::get_count()
{
	return count;
}

double document::get_total_area()
{
	return total_area;
}


double document::get_living_area()
{
	return living_area;
}

void document::ReadDocuments(ifstream & file)
{
	file >> name;
	file >> account;
	file >> address;
	file >> count;
	file >> total_area;
	file >> living_area;
	file >> total_price;
}

void document::ReadDocuments()
{
	cout << "Введите имя: ";
	cin >> name;
	cout << "Введите номер лицевого счета: ";
	cin >> account;
	cout << "Введите город: ";
	cin >> address;
	cout << "Введите количество проживающих: ";
	cin >> count;
	cout << "Введите общую площадь: ";
	cin >> total_area;
	cout << "Введите жилую площадь: ";
	cin >> living_area;
	cout << "Введите суммарную стоимость: ";
	cin >> total_price;
}

void document::PrintDocuments()
{
	cout << "|" << left << setw(11) << name;
	cout << "|" << left << setw(11) << account;
	cout << "|" << left << setw(11) << address;
	cout << "|" << left << setw(11) << count;
	cout << "|" << left << setw(11) << total_area;
	cout << "|" << left << setw(11) << living_area;
	cout << "|" << left << setw(11) << total_price << "|" << endl;
	cout << "+--+-----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
}


void Head()
{
	cout << "+--+-----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
	cout << left << setw(3) << "|№";
	cout << left << setw(12) << "|Имя";
	cout << left << setw(12) << "|Л.Счет";
	cout << left << setw(12) << "|Адрес";
	cout << left << setw(12) << "|Проживающих";
	cout << left << setw(12) << "|S общая";
	cout << left << setw(12) << "|S жилая";
	cout << left << setw(12) << "|Оплата" << "|" << endl;
	cout << "+--+-----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
}

void First(int N, document *arr) //Первое задание
{
	int k;
	Head();
	for (k = 0; k < N; k++)
	{
		if (arr[k].get_total_area() > 50 || arr[k].get_living_area() > 50)
		{

			cout << "|" << left << setw(2) << k + 1;
			arr[k].PrintDocuments();
		}
	}
}

void Second(int N, document *arr) //Второе задание
{
	int k;
	Head();
	for (k = 0; k < N; k++)
	{
		if (arr[k].get_total_price() > 3000 && arr[k].get_count() == 0)
		{

			cout << "|" << left << setw(2) << k + 1;
			arr[k].PrintDocuments();
		}
	}
}