#include "stdafx.h"
#include "pch.h"
#include "Documents.h"
#include <iostream>
#include <iomanip> // ���������� ��� ������������� ������������� �����-������.
using namespace std;



double document::get_total_price()
{
	return total_price;
}

int document::get_count()
{
	return count;
}

double document::get_total_area()
{
	return total_area;
}


double document::get_living_area()
{
	return living_area;
}

void document::ReadDocuments(ifstream & file)
{
	file >> name;
	file >> account;
	file >> address;
	file >> count;
	file >> total_area;
	file >> living_area;
	file >> total_price;
}

void document::ReadDocuments()
{
	cout << "������� ���: ";
	cin >> name;
	cout << "������� ����� �������� �����: ";
	cin >> account;
	cout << "������� �����: ";
	cin >> address;
	cout << "������� ���������� �����������: ";
	cin >> count;
	cout << "������� ����� �������: ";
	cin >> total_area;
	cout << "������� ����� �������: ";
	cin >> living_area;
	cout << "������� ��������� ���������: ";
	cin >> total_price;
}

void document::PrintDocuments()
{
	cout << "|" << left << setw(11) << name;
	cout << "|" << left << setw(11) << account;
	cout << "|" << left << setw(17) << address;
	cout << "|" << left << setw(4) << count;
	cout << "|" << left << setw(7) << total_area;
	cout << "|" << left << setw(7) << living_area;
	cout << "|" << left << setw(6) << total_price << "|" << endl;
	cout << "+--+-----------+---------------+-------------+----+-------+-------+------+" << endl;
}


void Head()
{
	cout << "+--+-----------+---------------+-------------+----+-------+-------+------+" << endl;
	cout << left << setw(3) << "|�";
	cout << left << setw(12) << "|���";
	cout << left << setw(12) << "|�.����";
	cout << left << setw(18) << "|�����";
	cout << left << setw(5) << "|��-�";
	cout << left << setw(8) << "|S �����";
	cout << left << setw(8) << "|S �����";
	cout << left << setw(7) << "|������" << "|" << endl;
	cout << "+--+-----------+---------------+-------------+----+-------+-------+------+" << endl;
}

void First(int k, document *arr) //������ �������
{
	int i;
	Head();
	for (i = 0; i < k; i++)
	{
		if (arr[i].get_total_area() > 50 || arr[i].get_living_area() > 50)
		{

			cout << "|" << left << setw(2) << i + 1;
			arr[i].PrintDocuments();
		}
	}
}

void Second(int k, document *arr) //������ �������
{
	int i;
	Head();
	for (i = 0; i < k; i++)
	{
		if (arr[i].get_total_price() > 3000 && arr[i].get_count() == 0)
		{

			cout << "|" << left << setw(2) << i + 1;
			arr[i].PrintDocuments();
		}
	}
}

void document::infile(ofstream & file, int k)
{
	file << name << endl;
	file << account << endl;
	file << address << endl;
	file << count << endl;
	file << total_area << endl;
	file << living_area << endl;
	file << total_price << endl;
}