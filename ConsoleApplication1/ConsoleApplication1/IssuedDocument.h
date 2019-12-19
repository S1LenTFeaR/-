#pragma once

#include "pch.h"
#include "Documents.h"

using namespace std;

class IssuedDocument : public document
{
	private:
		string Place; // Место выдачи.
		int Year; // Год выдачи.
	public:
		IssuedDocument() : document(), Place(""), Year(0) {};
		IssuedDocument(string, int, string, int, double, double, double, string, int);
		
		~IssuedDocument(); // Пустой деструктор.
		virtual void read_document(istream & stream);
		virtual void read_document();
		virtual void infile(ostream & stream) const;
		virtual void display();
		bool operator==(const IssuedDocument & another);
};



