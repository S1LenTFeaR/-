#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <string> 
#include <fstream> 
#include "Documents.h" 

class archive                   // ������� ������� 
{ 
private: 
	int max_num_books;            // ������������ ���-�� ���� � �������� (�����������)  
	int num_books;                // ������� ����� ���� � ��������  
	document *documents;                  // ������ �������� ������ book 

public:          
	archive(unsigned int max_nd);         // ����������� ������ bookstore  
	~archive();                           // ���������� ������ bookstore 

	void add_document(document adocument);	// �������� ��������   
	void read_from_file(string file);		// ������ ������ �� �����   
	void write_to_file(string file);		// �������� ������ � ����  
	void display_all();						// ������� �� �����   
};