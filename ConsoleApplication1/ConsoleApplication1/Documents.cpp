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
	cout << "|" << left << setw(11) << address;
	cout << "|" << left << setw(11) << count;
	cout << "|" << left << setw(11) << total_area;
	cout << "|" << left << setw(11) << living_area;
	cout << "|" << left << setw(11) << total_price << "|" << endl;
	cout << "+--+-----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
}


void Head()
{
	cout << "+--+-----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
	cout << left << setw(3) << "|�";
	cout << left << setw(12) << "|���";
	cout << left << setw(12) << "|�.����";
	cout << left << setw(12) << "|�����";
	cout << left << setw(12) << "|�����������";
	cout << left << setw(12) << "|S �����";
	cout << left << setw(12) << "|S �����";
	cout << left << setw(12) << "|������" << "|" << endl;
	cout << "+--+-----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
}

void First(int N, document *arr) //������ �������
{
	int k;
	Head();
	for (k = 0; k < N; k++)
	{
		if (arr[k].get_total_area() > 50 || arr[k].get_living_area() > 50)
		{

			cout << "|" << left << setw(2) << k + 1;
			arr[k].PrintDocuments();
		}
	}
}

void Second(int N, document *arr) //������ �������
{
	int k;
	Head();
	for (k = 0; k < N; k++)
	{
		if (arr[k].get_total_price() > 3000 && arr[k].get_count() == 0)
		{

			cout << "|" << left << setw(2) << k + 1;
			arr[k].PrintDocuments();
		}
	}
}