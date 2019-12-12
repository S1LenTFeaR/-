#include "pch.h"
#include "Archive.h"

using namespace std;

//�����������
archive::archive(unsigned int max_nd)
{
	Max_Num_Documents = max_nd;  
	documents = new document * [Max_Num_Documents];
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

//������ ���������� �� �����
void archive::read_documents()
{ 
	ifstream file("Documents.txt");
	int Count_File;
	file >> Count_File;
	for (int i = Num_Documents; i < Count_File; i++)
	{
		documents[i] = new document();
		file >> *(documents[i]);
	}
	file.close();
	Num_Documents = Count_File;
	cout << "\n��������� ������ �� ����� " << "Documents.txt" << ":";  cout << "\n����� ����������� ���������� - " << Num_Documents << endl;
}

//������� ������� �� �����
void archive::display_all()
{ 
	Head();
	for (int i = 0; i < Num_Documents; i++)
	{ 
		cout << "|" << left << setw(2) << i+1;
		documents[i]->display(); 
	}
}

//���������� ���������
void archive::add_document(const document * adocument)
{
	if (Num_Documents + 1 <= Max_Num_Documents)
	{
		documents[Num_Documents] = const_cast<document *>(adocument);
		// const_cast "�������" � ���������� const.
		Num_Documents++;
	}
}

document * archive::remove(int index)
{
	document * adocument = nullptr;
	if (index > -1 && index < Num_Documents) // �������� ������������ �������.
	{
		adocument = documents[index]; // ���������� ��������� � ������������ ����������.
		Num_Documents--;
		for (int i = index; i < Num_Documents; i++)
			documents[i] = documents[i + 1];
	}
	return adocument;
}

//�������� ���������
document * archive::remove(const document * adocument)
{
	int index = -1;
	for (int i = 0; i < Num_Documents && index == -1; i++) // ����� ������� ��������� �����.
		if (*(documents[i]) == *adocument)
			index = i;
	return remove(index); // ������������ ������� ����������� � ������ �������� �� �������.
}

//���������� �����
void archive::in_file()
{
	ofstream file;
	file.open("Documents.txt");
	file << Num_Documents << endl;
	for (int i = 0; i < Num_Documents; i++)
	{
		file << documents[i];
	}
	cout << "\n������ ������������ � ���� " << "Documents.txt" << ":";  
	cout << "\n    ����� ���������� ���������� - " << "Documents.txt" << endl;
	file.close();
}

//������ �������
void archive::First() 
{
	Head();
	for (int i = 0; i < Num_Documents; i++)
	{
		if (documents[i]->get_total_area() > 50 || documents[i]->get_living_area() > 50)
		{
			cout << "|" << left << setw(2) << i + 1;
			documents[i]->display();
		}
	}
}

//������ �������
void archive::Second() 
{
	Head();
	for (int i = 0; i < Num_Documents; i++)
	{
		if (documents[i]->get_total_price() > 3000 && documents[i]->get_count() == 0)
		{
			cout << "|" << left << setw(2) << i + 1;
			documents[i]->display();
		}
	}
}





