#include "stdafx.h"
#include "pch.h"
#include "Documents.h"
#include <locale> // поддержка русского алфавита
#include <iostream> // потоковый ввод/вывод с консоли
#include <fstream> // файловые потоки
#include <string> // текстовые строки С++
#include <iomanip> // Библиотека для использования манипуляторов ввода-вывода.
#include <Windows.h> // решение проблем кодировки текста

using namespace std;



int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int N, K1, K2;
	document *arr;

	

	int i;

	ifstream file;
	file.open("Documents.txt");

	cout << "Нажмите '1', если хотите вывести всех участников, из текстового файла." << endl;
	cout << "Нажмите '2', если хотите ввести участников с клавиатуры." << endl;
	cin >> K1;
	if (K1 == 1)
	{
		file >> N; //Считываем количество участников

	}
	else if (K1 == 2)
	{
		cout << "Введите количество участнков." << endl;
		cin >> N;
	}
	else
	{
		return 0;
	}

	arr = new document[N]; //Динамическое выделение памяти под массив размером N


	if (K1 == 1)
	{
		for (i = 0; i < N; i++) // в цикле считываем из файла
			arr[i].ReadDocuments(file);

		Head();



		for (i = 0; i < N; i++) // в цикле выводим на экран
		{
			cout << "|" << left << setw(2) << i + 1;
			arr[i].PrintDocuments();
		}

	}
	else if (K1 == 2) //В цикле считываем из программы
	{
		for (i = 0; i < N; i++) 
			arr[i].ReadDocuments();

		Head();

		for (i = 0; i < N; i++) // в цикле выводим на экран
		{
			cout << "|" << left << setw(2) << i + 1;
			arr[i].PrintDocuments();
		}
	}
	else
	{
		return 0;
	}


	cout << "Нажмите '1', если хотите вывести всех участников, площадь квартиры которых больше 50." << endl;
	cout << "Нажмите '2', если хотите вывести всех участников, суммарная оплата жилья которых превышает 3000 и в их квартирах нет зарегестрированных жильцов." << endl;

	cin >> K2;
	if (K2 == 1)
	{
		First(N, arr);
	}
	else if (K2 == 2)
	{
		Second(N, arr);
	}

		file.close();

	delete[] arr;
	return 0;
}