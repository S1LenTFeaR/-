#include <iostream>
#include "pch.h"
#include "Book.h"

// Методы объекта.

// Функция для чтения одной книги из потока.
// Каждое поле должно располагаться в отдельной строке.
void Book::Read(istream & stream)
{
    getline(stream, Title);
    getline(stream, Author);
    getline(stream, Publisher);
    Year = ReadInt(stream);
    PagesCount = ReadInt(stream);
}

// Функция для чтения книги с клавиатуры.
void Book::Read()
{
    cout << "Title: ";
    getline(cin, Title);
    cout << "Author: ";
    getline(cin, Author);
    cout << "Publisher: ";
    getline(cin, Publisher);
    cout << "Year: ";
    Year = ReadInt(cin);
    cout << "Pages Count: ";
    PagesCount = ReadInt(cin);
}

// Функция для записи одной книги в поток.
void Book::Write(ostream & file) const
{
    file
        << Title << endl
        << Author << endl
        << Publisher << endl
        << Year << endl
        << PagesCount << endl;
}


// Функция для вывода книги в строчку таблицы.
// (Ширина вывода для каждого поля должна соответствовать указанной в методе WriteTableHeader).
void Book::WriteToTable() const
{
    cout
        << left << setw(32) << Title
        << left << setw(20) << Author
        << left << setw(15) << Publisher
        << left << setw(5) << Year
        << left << setw(6) << PagesCount
        << endl;
}

// ----- ----- ----- -----
// Статические методы.

// Функция для чтения int из отдельной строки текстового потока.
int Book::ReadInt(istream & stream)
{
    int value;
    stream >> value;
    stream.ignore(256, '\n'); // Пропуск всех символов до перехода на новую строку.
    return value;
}

// Функция для вывода заголовка таблицы.
// (Ширина вывода для каждого поля должна соответствовать указанной в методе WriteToTable).
void Book::WriteTableHeader()
{
    cout
        << left << setw(32) << "Title"
        << left << setw(20) << "Author"
        << left << setw(15) << "Publisher"
        << left << setw(5) << "Year"
        << left << setw(6) << "Pages"
        << endl;
    // Манипулятор left обеспечивает выравнивание по левому краю.
    // Манипулятор setw задаёт ширину вывода.
    // Строка кода
    // cout << left << setw(8) << "Title";
    // выводит
    // "Title   "
}
