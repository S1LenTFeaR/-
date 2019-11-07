



//                            РОСТИК КРУУУУУТИИТСЯ УИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИ


/*#include "stdafx.h"
#include "pch.h"*/
#include "pch.h"
#include <locale>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std; //пространство имен для того чтобы переменные в библиотеках не конфликтовали

struct file
{
	int dpi, depth, S;					//dpi-разрешение, depth-глубина цвета, S-площадь
	double size, width, height;			//size-размер файла в байтах, width-ширина в пикселях, height-высота в пикселях
	string name;						//name-название файла
	string format;						//format-формат данных
};

file ReadFiles(ifstream& files)         //функция для считывания полей структуры с файла
{
	file File;                          //создаю переменную типа File
	files >> File.name;                   //из файла считывается в структуру
	files >> File.format;
	files >> File.size;
	files >> File.height;
	files >> File.width;
	files >> File.dpi;
	files >> File.depth;
	return File;
}

void PrintFiles(file File)             //функция для вывода структур на консоль (Которая была считана с ReadFiles)
{
	cout << "----------------------------------------------------------------------\n";
	cout << File.name << "\t" << File.format << File.size << File.height << File.width << File.dpi << File.depth << "\n";
	/*cout << "\nназвание файла: " << File.name << endl;
	cout << "формат файла: " << File.format << endl;
	cout << "размер файла: " << File.size << endl;
	cout << "высота файла (в пикселях): " << File.height << endl;
	cout << "ширина файла (в пикселях): " << File.width << endl;
	cout << "разрешение: " << File.dpi << endl;
	cout << "глубина цвета: " << File.depth << endl;*/
}

void first(int N, file* arr)           //функция вывода на экран всех файлов, начинающихся на symbol
{
	int i;                            //cчетчик
	char Symbol;                      //первый символ, который вводится с клавиатуры
	cout << "\n symbol: ";
	cin >> Symbol;
	for (i = 0; i < N; i++)
	{
		if (arr[i].name[0] == Symbol)
		{
			cout << "файл №" << i + 1 << endl;
			cout << "имя файла: " << arr[i].name << endl;
			cout << "формат файла: " << arr[i].format << "\n" << endl;
		}
		else
		{
		}
	}
}

void second(int N, file* arr)                                     //функция нахождения изображения с самой большой площадью
{
	int i;
	int j = 0;                                                    //переменная фиксирует файл с самым большим изображением
	arr[j].S = arr[j].height * arr[j].width / arr[j].dpi / arr[j].dpi;         //считаем площадь 1-го файла
	for (i = 1; i < N; i++)
	{
		arr[i].S = arr[i].height * arr[i].width / arr[i].dpi;     //нахожу размер файла
		if (arr[i].S > arr[j].S)                                  //сравниваю файл k с предидущим самым большим файлом
		{
			j = i;
		}
		else
		{
		}
	}
	cout << "наибольшая площадь изображения с именем: " << arr[j].name << endl;
}

file* arr;

int main()
{
	int N;                                   //переменная, отвечающая за количество файлов
                              //указатель на массив структур

	setlocale(LC_ALL, "rus");
	ifstream files;                          //открываю файл для чтения в структуру
	files.open("Files.txt");                 //открываю файл Files.txt
	int i;
	files >> N;                              //считываю количество структур из блокнота
	arr = new file[N];                       //динамическое выделение памяти под массив размером N

	for (i = 0; i < N; i++)                  //в цикле считываю из файла
		arr[i] = ReadFiles(files);
	cout << "\t\tformat\tsize\theight\twidth\tdpi\tdepth\n";
	for (i = 0; i < N; i++)                  //в цикле вывожу на консоль
		PrintFiles(arr[i]);

	first(N, arr);
	second(N, arr);

	files.close();                           //закрытие файла, который был прочтен

	delete[] arr;                            //освобождение памяти
	system("pause");
	return 0;
}