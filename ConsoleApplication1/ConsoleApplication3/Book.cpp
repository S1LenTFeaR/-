#include <iostream>
#include "pch.h"
#include "Book.h"

// ������ �������.

// ������� ��� ������ ����� ����� �� ������.
// ������ ���� ������ ������������� � ��������� ������.
void Book::Read(istream & stream)
{
    getline(stream, Title);
    getline(stream, Author);
    getline(stream, Publisher);
    Year = ReadInt(stream);
    PagesCount = ReadInt(stream);
}

// ������� ��� ������ ����� � ����������.
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

// ������� ��� ������ ����� ����� � �����.
void Book::Write(ostream & file) const
{
    file
        << Title << endl
        << Author << endl
        << Publisher << endl
        << Year << endl
        << PagesCount << endl;
}


// ������� ��� ������ ����� � ������� �������.
// (������ ������ ��� ������� ���� ������ ��������������� ��������� � ������ WriteTableHeader).
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
// ����������� ������.

// ������� ��� ������ int �� ��������� ������ ���������� ������.
int Book::ReadInt(istream & stream)
{
    int value;
    stream >> value;
    stream.ignore(256, '\n'); // ������� ���� �������� �� �������� �� ����� ������.
    return value;
}

// ������� ��� ������ ��������� �������.
// (������ ������ ��� ������� ���� ������ ��������������� ��������� � ������ WriteToTable).
void Book::WriteTableHeader()
{
    cout
        << left << setw(32) << "Title"
        << left << setw(20) << "Author"
        << left << setw(15) << "Publisher"
        << left << setw(5) << "Year"
        << left << setw(6) << "Pages"
        << endl;
    // ����������� left ������������ ������������ �� ������ ����.
    // ����������� setw ����� ������ ������.
    // ������ ����
    // cout << left << setw(8) << "Title";
    // �������
    // "Title   "
}
