#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <string> 
#include <fstream> 
#include "Documents.h" 

class archive                   // книжный магазин 
{ 
private: 
	int max_num_books;            // максимальное кол-во книг в магазине (вместимость)  
	int num_books;                // текущее число книг в магазине  
	document *documents;                  // массив объектов класса book 

public:          
	archive(unsigned int max_nd);         // конструктор класса bookstore  
	~archive();                           // деструктор класса bookstore 

	void add_document(document adocument);	// добавить документ   
	void read_from_file(string file);		// ввести данные из файла   
	void write_to_file(string file);		// записать данные в файл  
	void display_all();						// вывести на экран   
};