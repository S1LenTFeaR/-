#ifndef BOOKSTORE_H 
#define BOOKSTORE_H 
#include <string> 
#include <fstream> 
#include "Documents.h" 

class archive
{
private:
	int Max_Num_Documents;				// ������������ ���-�� ���� � �������� (�����������) 
	int Num_Documents;					// ������� ����� ���� � �������� 
	document *documents;				// ������ �������� ������ book 



public:
	archive(unsigned int max_nd);		// ����������� ������ bookstore  ~bookstore();                   
	~archive();							// ���������� ������ bookstore 
	
	void add_document(ifstream & file);
	void ReadDocuments(ifstream & file);
	void Second();
	void First();
	void display_all(unsigned int max_nd);
	int get_nmd();





};

#endif