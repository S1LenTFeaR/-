#include "pch.h"
#include <string>
#include <iostream> // ���������� �����-������.
#include <fstream> // ���������� ��������� �����-������.
#include <iomanip> // ���������� ��� ������������� ������������� �����-������.

using namespace std;

class document
{
	private:
		int account, count;								//����� ������� ����� (account), ���������� ����������� (count);
		double total_area, living_area, total_price;	//����� �������, ��.�. (total_area), ����� �������, ��.�. (living_area), ����� ����� ������, ��� (total_price);
		string name;									//���������� (name), ;
		string address;									//�����(address)
	public:
		void read_document(istream & stream);			//������� ������ �� �����
		void read_document();							//������� ������ �� ���������
		void display();									//������� ������ �� �����
		void infile(ostream & stream) const;			//������� ������ � ����
		double get_total_price();
		int get_count();
		double get_total_area();
		double get_living_area();

		// �������� ������ � �����.
		friend ostream& operator<<(ostream & stream, const document & adocument);
		// �������� ������ �� ������.
		friend istream& operator>>(istream & stream, document & adocument);
		// �������� �������� ���������.
		bool operator==(const document & another);
};

void Head();

