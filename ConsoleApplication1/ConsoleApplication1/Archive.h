#pragma once
#include "pch.h"
#include <string> 
#include <iostream> 
#include <fstream> 
#include "IssuedDocument.h" 

using namespace std;

class archive
{
private:
	int Max_Num_Documents;				// ������������ ���-�� ���������� � ������ (�����������) 
	int Num_Documents;					// ������� ����� ���������� � ������ 
	document * * documents;				// ������ �������� ������ document
public:
	archive(unsigned int max_nd);		// ����������� ������ archive                  
	~archive();							// ���������� ������ archive 
	
	void add_document(const document * adocument);
	void read_documents(istream & stream);
	void Second();
	void First();
	void display_all();
	document * remove(int index); // ������� �����, �������� ������� ���������� ����.
	document * remove(const document * adocument); // ������� �����, �������� ������� ���������� ����.
	void in_file();

	// ��������������� ����������.
	// �������� ��������.
	archive & operator +=(const document * adocument) { add_document(adocument); return *this; }
	// ������� ��������.
	archive & operator -=(const document * adocument) { remove(adocument); return *this; }
	// ��������� (&) � ���� ��������, ��� �������� �� ������� ����� ���������� �� ������ (��� �����������).
	// ����� �������, ����� ��������� ��� �� ����� ���������, � �� ��� �����.
};
