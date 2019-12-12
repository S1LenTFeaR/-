#include "stdafx.h"
#include "pch.h"
#include "Documents.h"
#include <iostream>
#include <iomanip> // Библиотека для использования манипуляторов ввода-вывода.
#include <Windows.h> // решение проблем кодировки текста
using namespace std;

//Геттер
double document::get_total_price()
{
	return total_price;
}

//Геттер
int document::get_count()
{
	return count;
}

//Геттер
double document::get_total_area()
{
	return total_area;
}

//Геттер
double document::get_living_area()
{
	return living_area;
}

//Чтение документа из файла
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

//Чтение документа с клавиатуры
void document::read_document()
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

//Вывод документа на экран
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

//Запись документа в файл
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
