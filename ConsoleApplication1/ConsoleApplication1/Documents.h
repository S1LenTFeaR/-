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
		void read_document(ifstream & stream);			//������� ������ �� �����
		void read_document();							//������� ������ �� ���������
		void display();							//������� ������ �� �����
		void infile(ofstream & file);			//������� ������ � ����
		double get_total_price();
		int get_count();
		double get_total_area();
		double get_living_area();
};

void Head();

