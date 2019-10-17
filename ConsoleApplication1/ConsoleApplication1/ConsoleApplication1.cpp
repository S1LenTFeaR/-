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
};

document ReadDocuments(ifstream & file)
{
	document Document;
	file >> Document.name;
	file >> Document.account;
	file >> Document.address;
	file >> Document.count;
	file >> Document.total_area;
	file >> Document.living_area;
	file >> Document.total_price;
	return Document;
}

void PrintDocuments(document Document)
{
	cout << "\n Имя - " << Document.name << endl;
	cout << " Номер лицевого счета - " << Document.account << endl;
	cout << " Адрес - " << Document.address << endl;
	cout << " Количество проживающих - " << Document.count << endl;
	cout << " Общая площадь, кв.м. - " << Document.total_area << endl;
	cout << " Жилая площадь, кв.м. - " << Document.living_area << endl;
	cout << " Сумма оплаты, руб - " << Document.total_price << endl;
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

int N;
document *arr;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	ifstream file;
	file.open("Documents.txt");

	int i;
	file >> N; //Считываем количество участников
	arr = new document[N]; //Динамическое выделение памяти под массив размером N


	for (i = 0; i < N; i++) // в цикле считываем из файла
		arr[i] = ReadDocuments(file);

	for (i = 0; i < N; i++) // в цикле выводим на экран
		PrintDocuments(arr[i]);


	First(N, arr);
	Second(N, arr);

	file.close();

	delete[] arr;
	return 0;
}