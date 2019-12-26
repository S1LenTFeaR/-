#pragma once

#include "pch.h"
#include "Documents.h"

using namespace std;

class IssuedDocument : public document
{
private:
	string Place; // ����� ������.
	int Year; // ��� ������.
public:
	IssuedDocument() : document(), Place(""), Year(0) {};
	IssuedDocument(string, int, string, int, double, double, double, string, int);

	~IssuedDocument(); // ������ ����������.
	void read_document(istream & stream);
	void read_document();
	void infile(ostream & stream) const;
	void display();
	bool operator==(const IssuedDocument & another);
};



