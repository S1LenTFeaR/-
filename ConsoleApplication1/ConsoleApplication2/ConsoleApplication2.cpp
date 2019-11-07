#include "stdafx.h"
#include "pch.h"
#include <locale> // поддержка русского алфавита
#include <iostream> // потоковый ввод/вывод с консоли
#include <fstream> // файловые потоки
#include <string> // текстовые строки С++
#include <iomanip> // Библиотека для использования манипуляторов ввода-вывода.
#include <Windows.h> // решение проблем кодировки текста

using namespace std;

struct document
{
	int account, count;								//Номер личного счета (account), Количество проживающих (count);
	double total_area, living_area, total_price;	//Общая площадь, кв.м. (total_area), Жилая площадь, кв.м. (living_area), Общая сумма оплаты, руб (total_price);
	string name;									//Плательщик (name), ;
	string address;									//Адрес(address)
};

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
	cout << "|" << left << setw(11) << Document.name;
	cout << "|" << left << setw(11) << Document.account;
	cout << "|" << left << setw(11) << Document.address;
	cout << "|" << left << setw(11) << Document.count;
	cout << "|" << left << setw(11) << Document.total_area;
	cout << "|" << left << setw(11) << Document.living_area;
	cout << "|" << left << setw(11) << Document.total_price << "|" << endl;
	cout << "+--+-----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
}

void First(int N, document *arr) //Первое задание
{
	int k;
	ofstream first("First.txt");
	Head();

	first << "+--+-----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
	first << left << setw(3) << "|№";
	first << left << setw(12) << "|Имя";
	first << left << setw(12) << "|Л.Счет";
	first << left << setw(12) << "|Адрес";
	first << left << setw(12) << "|Проживающих";
	first << left << setw(12) << "|S общая";
	first << left << setw(12) << "|S жилая";
	first << left << setw(12) << "|Оплата" << "|" << endl;
	first << "+--+-----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
	for (k = 0; k < N; k++)
	{
		if (arr[k].total_area > 50 || arr[k].living_area > 50)
		{

			cout << "|" << left << setw(2) << k + 1;
			PrintDocuments(arr[k]);

			first << "|" << left << setw(2) << k + 1;
			first << "|" << left << setw(11) << arr[k].name;
			first << "|" << left << setw(11) << arr[k].account;
			first << "|" << left << setw(11) << arr[k].address;
			first << "|" << left << setw(11) << arr[k].count;
			first << "|" << left << setw(11) << arr[k].total_area;
			first << "|" << left << setw(11) << arr[k].living_area;
			first << "|" << left << setw(11) << arr[k].total_price << "|" << endl;
			first << "+--+-----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
		}
	}
	first.close();
	cout << "\nЗадание - 1 успешно выполнено в файле First" << endl;
}

void Second(int N, document *arr) //Второе задание
{
	int k;
	ofstream second("Second.txt");
	Head();
	second << "+--+-----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
	second << left << setw(3) << "|№";
	second << left << setw(12) << "|Имя";
	second << left << setw(12) << "|Л.Счет";
	second << left << setw(12) << "|Адрес";
	second << left << setw(12) << "|Проживающих";
	second << left << setw(12) << "|S общая";
	second << left << setw(12) << "|S жилая";
	second << left << setw(12) << "|Оплата" << "|" << endl;
	second << "+--+-----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
	for (k = 0; k < N; k++)
	{
		if (arr[k].total_price > 3000 && arr[k].count == 0)
		{

			cout << "|" << left << setw(2) << k + 1;
			PrintDocuments(arr[k]);

			second << "|" << left << setw(2) << k + 1;
			second << "|" << left << setw(11) << arr[k].name;
			second << "|" << left << setw(11) << arr[k].account;
			second << "|" << left << setw(11) << arr[k].address;
			second << "|" << left << setw(11) << arr[k].count;
			second << "|" << left << setw(11) << arr[k].total_area;
			second << "|" << left << setw(11) << arr[k].living_area;
			second << "|" << left << setw(11) << arr[k].total_price << "|" << endl;
			second << "+--+-----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
		}
	}
	second.close();
	cout << "\nЗадание - 2 успешно выполнено в файле Second" << endl;
}



int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N, K;
	document *arr;

	ifstream file;
	file.open("Documents.txt");

	int i;
	file >> N; //Считываем количество участников
	arr = new document[N]; //Динамическое выделение памяти под массив размером N


	for (i = 0; i < N; i++) // в цикле считываем из файла
		arr[i] = ReadDocuments(file);

	Head();



	for (i = 0; i < N; i++) // в цикле выводим на экран
	{
		cout << "|" << left << setw(2) << i + 1;
		PrintDocuments(arr[i]);
	}


	cout << "Нажмите '1', если хотите вывести всех участников, площадь квартиры которых больше 50." << endl;
	cout << "Нажмите '2', если хотите вывести всех участников, суммарная оплата жилья которых превышает 3000 и в их квартирах нет зарегестрированных жильцов." << endl;
	cin >> K;
	if (K == 1)
	{
		First(N, arr);
	}
	else if (K == 2)
	{
		Second(N, arr);
	}

	file.close();

	delete[] arr;
	return 0;
}
