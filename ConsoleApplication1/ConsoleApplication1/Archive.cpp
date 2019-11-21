#include "pch.h"
#include <iostream> 
#include "Archive.h"

using namespace std;

//Конструктор
archive::archive(unsigned int max_nd)
{
	Max_Num_Documents = max_nd;  
	documents = new document[Max_Num_Documents];
	Num_Documents = 0;
	cout << "\nВызван конструктор класса bookstore:";  
	cout << "\n    выделено объектов - " << Max_Num_Documents;
	cout << "\n    загружено документов - " << Num_Documents << endl;
}

//Деструктор
archive::~archive()
{
	Max_Num_Documents = 0;
	delete[] documents;
	Num_Documents = 0;
	cout << "\nВызван деструктор класса archive:";  
	cout << "\n    выделенная память освобождена";
}


void archive::ReadDocuments(ifstream & file)
{ 
	if (!file.is_open()) 
	{ 
		cout << "\n\nФайл данных не найден!" << endl;   
		system("pause");   
		exit(1); 
	}
	int Count_File = 0 ,Count_Keyboard = 0, max_nd = 0;
	file >> Count_File;
	max_nd = Count_File + Count_Keyboard;
	for (int i = 0; i < Count_File; i++)
	{
		documents[i].ReadDocument(file);
	}
}

void archive::add_document(ifstream & file)
{
	int Count_File;
	int Count_Keyboard;
	int max_nd;
	cout << "Введите количество документов, которые хотите добавить: ";
	file >> Count_File;
	cin >> Count_Keyboard;
	max_nd = Count_File + Count_Keyboard;
	for (int i = Count_File; i < Max_Num_Documents; i++)
	{
		documents[i].ReadDocument();
	}
}

void archive::display_all(unsigned int max_nd)
{ 
	cout << "\n\nПОЛНЫЙ АССОРТИМЕНТ КНИЖНОГО МАГАЗИНА \n";  
	for (int i = 0; i < Max_Num_Documents; i++)   
		documents[i].display(); 
}

int archive::get_nmd()
{
	return Max_Num_Documents;
}


void archive::First() //Первое задание
{
	int i;
	
	Head();
	for (i = 0; i < Max_Num_Documents; i++)
	{
		if (documents[i].get_total_area() > 50 || documents[i].get_living_area() > 50)
		{

			cout << "|" << left << setw(2) << i + 1;
			documents[i].display();
		}
	}
}

void archive::Second() //Второе задание
{
	int i;
	
	Head();
	for (i = 0; i < Max_Num_Documents; i++)
	{
		if (documents[i].get_total_price() > 3000 && documents[i].get_count() == 0)
		{

			cout << "|" << left << setw(2) << i + 1;
			documents[i].display();
		}
	}
}


