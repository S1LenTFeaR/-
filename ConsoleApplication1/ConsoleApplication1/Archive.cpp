#include "pch.h"
#include "Archive.h"

using namespace std;

//Конструктор
archive::archive(unsigned int max_nd)
{
	Max_Num_Documents = max_nd;  
	documents = new document * [Max_Num_Documents];
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
	cout << "\nЗагружены данные из файла " << "Documents.txt" << ":";  cout << "\nчисло загруженных документов - " << Num_Documents << endl;
}

//Вывести таблицу на экран
void archive::display_all()
{ 
	Head();
	for (int i = 0; i < Num_Documents; i++)
	{ 
		cout << "|" << left << setw(2) << i+1;
		documents[i]->display(); 
	}
}

//Добавление документа
void archive::add_document(const document * adocument)
{
	if (Num_Documents + 1 <= Max_Num_Documents)
	{
		documents[Num_Documents] = const_cast<document *>(adocument);
		// const_cast "снимает" с переменной const.
		Num_Documents++;
	}
}

document * archive::remove(int index)
{
	document * adocument = nullptr;
	if (index > -1 && index < Num_Documents) // Проверка корректности индекса.
	{
		adocument = documents[index]; // Сохранение указателя в возвращаемой переменной.
		Num_Documents--;
		for (int i = index; i < Num_Documents; i++)
			documents[i] = documents[i + 1];
	}
	return adocument;
}

//Удаление документа
document * archive::remove(const document * adocument)
{
	int index = -1;
	for (int i = 0; i < Num_Documents && index == -1; i++) // Поиск индекса удаляемой книги.
		if (*(documents[i]) == *adocument)
			index = i;
	return remove(index); // Корректность индекса проверяется в методе удаления по индексу.
}

//Перезапись файла
void archive::in_file()
{
	ofstream file;
	file.open("Documents.txt");
	file << Num_Documents << endl;
	for (int i = 0; i < Num_Documents; i++)
	{
		file << documents[i];
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
		if (documents[i]->get_total_area() > 50 || documents[i]->get_living_area() > 50)
		{
			cout << "|" << left << setw(2) << i + 1;
			documents[i]->display();
		}
	}
}

//Второе задание
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





