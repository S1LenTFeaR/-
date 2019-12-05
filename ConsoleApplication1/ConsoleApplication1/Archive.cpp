#include "pch.h"
#include <iostream> 
#include "Archive.h"

using namespace std;

//�����������
archive::archive(unsigned int max_nd)
{
	Max_Num_Documents = max_nd;  
	documents = new document[Max_Num_Documents];
	Num_Documents = 0;
	cout << "\n������ ����������� ������ archive:";  
	cout << "\n�������� �������� - " << Max_Num_Documents;
	cout << " ��������� ���������� - " << Num_Documents << endl;
}

//����������
archive::~archive()
{
	Max_Num_Documents = 0;
	delete[] documents;
	Num_Documents = 0;
	cout << "\n������ ���������� ������ archive:";  
	cout << "\n ���������� ������ �����������";
}


void archive::read_documents(ifstream & file)
{ 
	if (!file.is_open()) 
	{ 
		cout << "\n\n���� ������ �� ������!" << endl;   
		system("pause");   
		exit(1); 
	}
	int Count_File;
	file >> Count_File;
	for (int i = Num_Documents; i < Count_File; i++)
	{
		documents[i].read_document(file);
	}
	Num_Documents = Count_File;
}

void archive::add_document(ifstream & file)
{
	int i;
	int Count_Keyboard;
	cout << "������� ���������� ����������, ������� ������ ��������: ";
	cin >> Count_Keyboard;
	if (Num_Documents + Count_Keyboard <= Max_Num_Documents)     // ����� �������� ��� ���� ��������? 
	{
		for (i = Num_Documents; i < Num_Documents + Count_Keyboard; i++)
		{
			documents[Num_Documents].read_document();
		}
	}
	Num_Documents = Num_Documents + Count_Keyboard;
}

void archive::display_all()
{ 
	Head();
	for (int i = 0; i < Num_Documents; i++)
	{ 
		cout << "|" << left << setw(2) << i+1;
		documents[i].display(); 
	}
}

void archive::remove() //�������� ���������
{
	int i, n;
	cin >> n;
	for (i = n-1; i < Num_Documents; i++)
	{
		documents[i] = documents[i + 1]; //�������� ���������� �� 1 ������� �����
	}
	Num_Documents--;
}

void archive::in_file()
{
	ofstream file;
	file.open("Documents.txt");
	file << Num_Documents << endl;
	for (int i = 0; i < Num_Documents; i++)
	{
		documents[i].infile(file);
	}
	cout << "\n������ ������������ � ���� " << "Documents.txt" << ":";  
	cout << "\n    ����� ���������� ���������� - " << "Documents.txt" << endl;
	file.close();
}

void archive::First() //������ �������
{
	int i;
	
	Head();
	for (i = 0; i < Num_Documents; i++)
	{
		if (documents[i].get_total_area() > 50 || documents[i].get_living_area() > 50)
		{

			cout << "|" << left << setw(2) << i + 1;
			documents[i].display();
		}
	}
}

void archive::Second() //������ �������
{
	int i;
	
	Head();
	for (i = 0; i < Num_Documents; i++)
	{
		if (documents[i].get_total_price() > 3000 && documents[i].get_count() == 0)
		{

			cout << "|" << left << setw(2) << i + 1;
			documents[i].display();
		}
	}
}




