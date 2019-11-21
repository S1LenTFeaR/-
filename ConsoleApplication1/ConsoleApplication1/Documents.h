#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <string>
#include <iostream> // ���������� �����-������.
#include <fstream> // ���������� ��������� �����-������.
#include <iomanip> // ���������� ��� ������������� ������������� �����-������.

using std::string;
using std::ifstream;
using std::ofstream;
using std::istream;

class document
{
	private:
		int account, count;								//����� ������� ����� (account), ���������� ����������� (count);
		double total_area, living_area, total_price;	//����� �������, ��.�. (total_area), ����� �������, ��.�. (living_area), ����� ����� ������, ��� (total_price);
		string name;									//���������� (name), ;
		string address;									//�����(address)
	public:
		int ReadInt(istream & stream);					// ������� ��� ������ int �� ��������� ������ ���������� ������
		void ReadDocument(ifstream & stream);			//������� ������ �� �����
		void ReadDocument();							//������� ������ �� ���������
		void display();							//������� ������ �� �����
		void infile(ofstream & file, int k);			//������� ������ � ����
		double get_total_price();
		int get_count();
		double get_total_area();
		double get_living_area();
};

void Head();




#endif