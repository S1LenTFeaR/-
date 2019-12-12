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
	cout << "\nВызван конструктор класса archive:";  
	cout << "\nвыделено объектов - " << Max_Num_Documents;
	cout << " загружено документов - " << Num_Documents << endl;
}

//Деструктор
archive::~archive()
{
	Max_Num_Documents = 0;
	delete[] documents;
	Num_Documents = 0;
	cout << "\nВызван деструктор класса archive:";  
	cout << "\n выделенная память освобождена";
}

//Чтение документов из файла
void archive::read_documents(ifstream & file)
{ 
	if (!file.is_open()) 
	{ 
		cout << "\n\nФайл данных не найден!" << endl;   
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

//Добавление документов в файл
void archive::add_document(ifstream & file)
{
	int i;
	if (Num_Documents + 1 <= Max_Num_Documents) 
	{
		for (i = Num_Documents; i < Num_Documents + 1; i++)
		{
			documents[Num_Documents].read_document();
		}
	}
	Num_Documents = Num_Documents + 1;
}

//Вывести таблицу на экран
void archive::display_all()
{ 
	Head();
	for (int i = 0; i < Num_Documents; i++)
	{ 
		cout << "|" << left << setw(2) << i+1;
		documents[i].display(); 
	}
}

//Удаление документа
void archive::remove()
{
	int i, n;
	cin >> n;
	for (i = n-1; i < Num_Documents; i++)
	{
		documents[i] = documents[i + 1];
	}
	Num_Documents--;
}

//Перезапись файла
void archive::in_file()
{
	ofstream file;
	file.open("Documents.txt");
	file << Num_Documents << endl;
	for (int i = 0; i < Num_Documents; i++)
	{
		documents[i].infile(file);
	}
	cout << "\nДанные перезаписаны в файл " << "Documents.txt" << ":";  
	cout << "\n    число записанных документов - " << "Documents.txt" << endl;
	file.close();
}

//Первое задание
void archive::First() 
{
	Head();
	for (int i = 0; i < Num_Documents; i++)
	{
		if (documents[i].get_total_area() > 50 || documents[i].get_living_area() > 50)
		{
			cout << "|" << left << setw(2) << i + 1;
			documents[i].display();
		}
	}
}

//Второе задание
void archive::Second() 
{
	Head();
	for (int i = 0; i < Num_Documents; i++)
	{
		if (documents[i].get_total_price() > 3000 && documents[i].get_count() == 0)
		{
			cout << "|" << left << setw(2) << i + 1;
			documents[i].display();
		}
	}
}




