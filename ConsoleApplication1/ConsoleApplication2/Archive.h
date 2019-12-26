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
	int Max_Num_Documents;				// максимальное кол-во документов в архиве (вместимость) 
	int Num_Documents;					// текущее число документов в архиве 
	document * * documents;				// массив объектов класса document
public:
	archive(unsigned int max_nd);		// конструктор класса archive                  
	~archive();							// деструктор класса archive 

	void add_document(const document * adocument);
	void read_documents(istream & stream);
	void Second();
	void First();
	void display_all();
	document * remove(int index); // Удалить документ, сохранив порядок оставшихся докуметов.
	document * remove(const document * adocument); // Удалить книгу, сохранив порядок оставшихся документов.
	void in_file();

	// Переопределение операторов.
	// Добавить документ.
	archive & operator +=(const document * adocument) { add_document(adocument); return *this; }
	// Удалить документ.
	archive & operator -=(const document * adocument) { remove(adocument); return *this; }
	// Амперсанд (&) в типе означает, что значение из функции будет возвращено по ссылке (без копирования).
	// Иными словами, будет возвращён тот же самый контейнер, а не его копия.
private: // Поля и методы доступны только из методов данного класса.
	static string SimpleDocumentLabel; // Метка для документов базового типа.
	static string IssuedDocumentLable; // Метка для документов с известной информацией о выдаче.
};

