#include "stdafx.h"
#include "pch.h"
#include "Documents.h"
#include <iostream>
#include <iomanip> // Ѕиблиотека дл€ использовани€ манипул€торов ввода-вывода.
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

void document::read_document(ifstream & file)
{
	file >> name;
	file >> account;
	file >> address;
	file >> count;
	file >> total_area;
	file >> living_area;
	file >> total_price;
}

void document::read_document()
{
	cout << "¬ведите им€: ";
	cin >> name;
	cout << "¬ведите номер лицевого счета: ";
	cin >> account;
	cout << "¬ведите город: ";
	cin >> address;
	cout << "¬ведите количество проживающих: ";
	cin >> count;
	cout << "¬ведите общую площадь: ";
	cin >> total_area;
	cout << "¬ведите жилую площадь: ";
	cin >> living_area;
	cout << "¬ведите суммарную стоимость: ";
	cin >> total_price;
}

void document::display()
{
	cout << "|" << left << setw(11) << name;
	cout << "|" << left << setw(11) << account;
	cout << "|" << left << setw(17) << address;
	cout << "|" << left << setw(4) << count;
	cout << "|" << left << setw(7) << total_area;
	cout << "|" << left << setw(7) << living_area;
	cout << "|" << left << setw(6) << total_price << "|" << endl;
	cout << "+--+-----------+-----------+-----------------+----+-------+-------+------+" << endl;
}

void document::infile(ofstream & file)
{
	file << name << endl;
	file << account << endl;
	file << address << endl;
	file << count << endl;
	file << total_area << endl;
	file << living_area << endl;
	file << total_price << endl;
}
