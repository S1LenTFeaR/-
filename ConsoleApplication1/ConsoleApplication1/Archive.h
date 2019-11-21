#ifndef BOOKSTORE_H 
#define BOOKSTORE_H 
#include <string> 
#include <fstream> 
#include "Documents.h" 

class archive
{
private:
	int Max_Num_Documents;				// максимальное кол-во книг в магазине (вместимость) 
	int Num_Documents;					// текущее число книг в магазине 
	document *documents;				// массив объектов класса book 



public:
	archive(unsigned int max_nd);		// конструктор класса bookstore  ~bookstore();                   
	~archive();							// деструктор класса bookstore 
	
	void add_document(ifstream & file);
	void ReadDocuments(ifstream & file);
	void Second();
	void First();
	void display_all(unsigned int max_nd);
	int get_nmd();





};

#endif