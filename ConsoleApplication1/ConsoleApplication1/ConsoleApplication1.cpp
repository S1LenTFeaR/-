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
	cout << "----- ----- ----- -----" << endl;
	cout << "Menu:" << endl;
	cout << setw(2) << 1 << " / " << "Add book." << endl;
	cout << setw(2) << 2 << " / " << "Show books." << endl;
	cout << setw(2) << 3 << " / " << "Read books from file." << endl;
	cout << setw(2) << 4 << " / " << "Write books to default file." << endl;
	cout << setw(2) << 5 << " / " << "Write books to file." << endl;
	cout << setw(2) << 6 << " / " << "Remove book." << endl;
	cout << setw(2) << 7 << " / " << "Search books by author." << endl;
	cout << setw(2) << 8 << " / " << "Search the newest book." << endl;
	cout << setw(2) << 9 << " / " << "Exit." << endl;
	cout << "Enter the number: ";
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

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	archive my_archive(1);
	ifstream file;
	file.open("Documents.txt");
	my_archive.ReadDocuments(file);
	int action;
	action = SelectAction();
	cout << "----- ----- ----- -----" << endl;
	switch (action)
	{
		case 1: // Добавить книги в коллекцию.
			my_archive.add_document(file);
			break;
		case 2: // Вывести задание 1
			my_archive.First();
			break;
		case 3: // Вывести задание 2
			my_archive.Second();
			break;
		//case 4: // Удалить книгу из коллекции .my_archive.;
			break;
		default:
			action = -1;
	}
	file.close();
	return 0;

}



