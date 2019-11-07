#ifndef DOCUMENTS_H
#define DOCUMENTS_H
#include <string>
#include <fstream>

using std::string;
using std::ifstream;

class document
{
	private:
		int account, count;								//����� ������� ����� (account), ���������� ����������� (count);
		double total_area, living_area, total_price;	//����� �������, ��.�. (total_area), ����� �������, ��.�. (living_area), ����� ����� ������, ��� (total_price);
		string name;									//���������� (name), ;
		string address;									//�����(address)
	public:
		void ReadDocuments(ifstream & file);
		void ReadDocuments();
		void PrintDocuments();
		double get_total_price();
		int get_count();
		double get_total_area();
		double get_living_area();
};

void Head();
void First(int N, document *arr); //������ �������
void Second(int N, document *arr); //������ �������



#endif