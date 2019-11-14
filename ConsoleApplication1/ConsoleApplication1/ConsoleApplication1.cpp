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

	int N = 0, K1, K = 0, k;
	document *arr;



	int i;

	ifstream file;
	file.open("Documents.txt");

	cout << "Нажмите '1', если хотите вывести всех участников, из текстового файла." << endl;
	cout << "Нажмите '2', если хотите ввести участников с клавиатуры." << endl;
	cin >> K1;
	if (K1 == 1) //Случай вывода текстового файла
	{
		file >> N; //Считываем количество участников

	}
	else if (K1 == 2) //Случай добавления в текстовый файл и вывода всех участников
	{
		file >> N;
		cout << "Введите количество участнков." << endl;
		cin >> K;
	}
	else //Выход из программы
	{
		return 0;
	}

	k = N + K; //Высчитывание количества участников

	arr = new document[k]; //Динамическое выделение памяти под массив размером k


	if (K1 == 1) //Случай вывода текстового файла
	{
		for (i = 0; i < k; i++) // в цикле считываем из файла
			arr[i].ReadDocuments(file);

		Head();



		for (i = 0; i < N; i++) //В цикле выводим на экран
		{
			cout << "|" << left << setw(2) << i + 1;
			arr[i].PrintDocuments();
		}

	}
	else if (K1 == 2) //Случай добавления в текстовый файл и вывода всех участников
	{
		for (i = 0; i < N; i++) //В цикле считываем из файла
			arr[i].ReadDocuments(file);
		
		for (i; i < k; i++)	//В цикле считываем из программы
			arr[i].ReadDocuments();
		
		ofstream file("Documents.txt");	//Перезаписываем измененный файл
		file << k << endl;
		for (i = 0; i < k; i++)
		{ 
			arr[i].infile(file, k);
		}


		Head();

		for (i = 0; i < k; i++) //В цикле выводим на экран
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

	cin >> K1;
	if (K1 == 1)
	{
		First(k, arr); //Выполняем задание 1
	}
	else if (K1 == 2) //Выполняем задание 2
	{
		Second(k, arr);
	}

	file.close();

	delete[] arr;
	return 0;
}