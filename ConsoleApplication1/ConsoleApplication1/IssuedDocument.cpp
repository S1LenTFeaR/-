#include "pch.h"
#include "IssuedDocument.h"

IssuedDocument::IssuedDocument(string nme, int acc, string adr, int cou, double tar, double lir, double tpr, string plc, int yer) : document(nme, acc, adr, cou, tar, lir, tpr), Place(plc), Year(yer)
{
	cout << "\nВызван конструктор класса IssuedDocument" << endl;
}

IssuedDocument::~IssuedDocument()
{
	cout << "\nВызван деконструктор класса IssuedDocument" << endl;
}
// Функция для чтения одного документа из потока.
void IssuedDocument::read_document(istream & stream)
{
	document::read_document(stream);
	stream
		>> Place
		>> Year;
}

// Функция для чтения документа с клавиатуры.
void IssuedDocument::read_document()
{
	document::read_document();
	cout << "Место выдачи: ";
	cin >> Place;
	cout << "Год выдачи: ";
	cin >> Year;
}

//Запись документа в файл
void IssuedDocument::infile(ostream & stream) const
{
	document::infile(stream);
	stream
		<< Place << endl
		<< Year << endl;
}

void IssuedDocument::display()
{
	document::display();
	cout << left << setw(6) << Place;
	cout << "|" << left << setw(4) << Year << "|";
}


// Оператор проверки равенства.
bool IssuedDocument::operator==(const IssuedDocument & another)
{
	return
		document::operator==(another) &&
		another.Place.compare(Place) == 0 &&
		another.Year == Year;
}


