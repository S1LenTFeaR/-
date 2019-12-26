#pragma once
#include "pch.h"
#include <string>
#include <iostream> // Библиотека ввода-вывода.
#include <fstream> // Библиотека файлового ввода-вывода.
#include <iomanip> // Библиотека для использования манипуляторов ввода-вывода.

using namespace std;

class document
{
private:
	int account, count;								//Номер личного счета (account), Количество проживающих (count);
	double total_area, living_area, total_price;	//Общая площадь, кв.м. (total_area), Жилая площадь, кв.м. (living_area), Общая сумма оплаты, руб (total_price);
	string name;									//Плательщик (name), ;
	string address;									//Адрес(address)
public:
	document() : name(""), account(0), address(""), count(0), total_area(0), living_area(0), total_price(0) {};
	document(string, int, string, int, double, double, double);
	~document();
	virtual void read_document(istream & stream);			//Функция чтения из файлы
	virtual void read_document();							//Функция чтения из программы
	virtual void display();									//Функция вывода на экран
	virtual void infile(ostream & stream) const;			//Функция записи в файл
	double get_total_price();
	int get_count();
	double get_total_area();
	double get_living_area();
	// Оператор проверки равенства.
	bool operator==(const document & another);
};

void Head();

