#include "stdafx.h"
#include "pch.h"
#include <locale> // поддержка русского алфавита
#include <iostream> // потоковый ввод/вывод с консоли
#include <fstream> // файловые потоки
#include <string> // текстовые строки С++
#include <Windows.h> // решение проблем кодировки текста

using namespace std;

struct document
{
	int account, count;								//Номер личного счета (account), Количество проживающих (count);
	double total_area, living_area, total_price;	//Общая площадь, кв.м. (total_area), Жилая площадь, кв.м. (living_area), Общая сумма оплаты, руб (total_price);
	string name;									//Плательщик (name), ;
	string address;									//Адрес(address)
} *arr;

void Vivod(int N, document *arr)  //Вывод на экран
{
	int k;
	for (k = 0; k < N; k++)
	{
		cout << "\nУчастник №" << k + 1 << endl;
		cout << "Имя - " << arr[k].name << endl;
		cout << "Номер лицевого счета - " << arr[k].account << endl;
		cout << "Адрес - " << arr[k].address << endl;
		cout << "Количество проживающих - " << arr[k].count << endl;
		cout << "Общая площадь, кв.м. - " << arr[k].total_area << endl;
		cout << "Жилая площадь, кв.м. - " << arr[k].living_area << endl;
		cout << "Сумма оплаты, руб - " << arr[k].total_price << endl;
	}
}

void First(int N, document *arr) //Первое задание
{
	int k;
	ofstream first("First.txt");
	for (k = 0; k < N; k++)
	{
		if (arr[k].total_area > 50 || arr[k].living_area > 50)
		{
			first << "Участник №" << k + 1 << endl;
			first << "Имя - " << arr[k].name << endl;
			first << "Номер лицевого счета - " << arr[k].account << endl;
			first << "Адрес - " << arr[k].address << endl;
			first << "Количество проживающих - " << arr[k].count << endl;
			first << "Общая площадь, кв.м. - " << arr[k].total_area << endl;
			first << "Жилая площадь, кв.м. - " << arr[k].living_area << endl;
			first << "Сумма оплаты, руб - " << arr[k].total_price << "\n" << endl;
		}
		else
		{

		}
	}
	first.close();
	cout << "\nЗадание - 1 успешно выполнено в файле First" << endl;
}

void Second(int N, document *arr) //Второе задание
{
	int k;
	ofstream second("Second.txt");
	for (k = 0; k < N; k++)
	{
		if (arr[k].total_price > 3000 && arr[k].count == 0)
		{
			second << "квартира по адресу: " << arr[k].address << endl;
		}
		else
		{

		}
	}
	second.close();
	cout << "\nЗадание - 2 успешно выполнено в файле Second" << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");

	int k, N;
	cout << "Введите количество участников - ";
	cin >> N;
	arr = new document[N];
	
	for (k = 0; k < N; k++)
	{
		cout << "\nУчастник №" << k + 1 << endl;
		cout << "Введите имя - ";
		cin >> arr[k].name;
		cout << "Введите номер лицевого счета - ";
		cin >> arr[k].account;
		cout << "Введите адрес - ";
		cin >> arr[k].address;
		cout << "Введите количество проживающих - ";
		cin >> arr[k].count;
		cout << "Введите общую площадь, кв.м. - ";
		cin >> arr[k].total_area;
		cout << "Введите жилую площадь, кв.м. - ";
		cin >> arr[k].living_area;
		cout << "Введите общую сумму оплаты, руб - ";
		cin >> arr[k].total_price;
	}
	
	Vivod(N, arr);
	First(N, arr);
	Second(N, arr);

	delete[] arr;

	return 0;
}