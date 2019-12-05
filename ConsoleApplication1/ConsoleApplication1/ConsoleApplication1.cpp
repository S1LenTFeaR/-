#include "stdafx.h"
#include "pch.h"
#include "Archive.h"
#include <locale> // поддержка русского алфавита
#include <iostream> // потоковый ввод/вывод с консоли
#include <fstream> // файловые потоки
#include <string> // текстовые строки С++
#include <iomanip> // Библиотека для использования манипуляторов ввода-вывода.
#include <Windows.h> // решение проблем кодировки текста

using namespace std;

int SelectAction()
{
	int action;
	cout << "------------- ------------- -------------" << endl;
	cout << "Меню:" << endl;
	cout << " 1" << " / " << "Вывести содержимое архива на экран." << endl;
	cout << " 2" << " / " << "Добавить книгу." << endl;
	cout << " 3" << " / " << "Удалить книгу." << endl;
	cout << " 4" << " / " << "Задание 1." << endl;
	cout << " 5" << " / " << "Задание 2." << endl;
	cout << " 6" << " / " << "Выход из программы." << endl;
	cout << "Введите номер действия: ";
	cin >> action;
	return action;
}

void Head()
{
	cout << "+--+-----------+-----------+-----------------+----+-------+-------+------+" << endl;
	cout << left << setw(3) << "|№";
	cout << left << setw(12) << "|Имя";
	cout << left << setw(12) << "|Л.Счет";
	cout << left << setw(18) << "|Адрес";
	cout << left << setw(5) << "|Уч-в";
	cout << left << setw(8) << "|S общая";
	cout << left << setw(8) << "|S жилая";
	cout << left << setw(7) << "|Оплата" << "|" << endl;
	cout << "+--+-----------+-----------+-----------------+----+-------+-------+------+" << endl;
}

void in_file(archive & my_archive)
{
	int n;
	cout << "Перезаписать получившуюся таблицу в файл?" << endl;
	cout << "Нажмите 1, чтобы перезаписать." << endl;
	cout << "Нажмите другую кнопку, чтобы выйти из программы." << endl;
	cin >> n;
	switch (n)
	{
	case 1: // Запись в файл.
		my_archive.in_file();
		break;
	default:
		n = -1;
	}
}

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	archive my_archive(25);
	ifstream file;
	file.open("Documents.txt");
	my_archive.read_documents(file);
	int action;
	do
	{
		action = SelectAction();
		cout << "------------- ------------- -------------" << endl;
		switch (action)
		{
		case 1: // Вывести на экран.
			my_archive.display_all();
			break;
		case 2: // Добавить книги в коллекцию.
			my_archive.add_document(file);
			break;
		case 3: // Удалить книгу из коллекции 
			my_archive.remove();
			break;
		case 4: // Вывести задание 1
			my_archive.First();
			break;
		case 5: // Вывести задание 2
			my_archive.Second();
			break;
		default:
			action = -1;
		}
	}
	while (action != -1);
	file.close();
	in_file(my_archive);
}



