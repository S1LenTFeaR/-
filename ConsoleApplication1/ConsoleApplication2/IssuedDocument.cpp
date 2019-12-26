#include "pch.h"
#include "IssuedDocument.h"

IssuedDocument::IssuedDocument(string nme, int acc, string adr, int cou, double tar, double lir, double tpr, string plc, int yer) : document(nme, acc, adr, cou, tar, lir, tpr), Place(plc), Year(yer)
{
	cout << "\n������ ����������� ������ IssuedDocument" << endl;
}

IssuedDocument::~IssuedDocument()
{
	cout << "\n������ ������������� ������ IssuedDocument" << endl;
}
// ������� ��� ������ ������ ��������� �� ������.
void IssuedDocument::read_document(istream & stream)
{
	document::read_document(stream);
	stream
		>> Place
		>> Year;
}

// ������� ��� ������ ��������� � ����������.
void IssuedDocument::read_document()
{
	document::read_document();
	cout << "����� ������: ";
	cin >> Place;
	cout << "��� ������: ";
	cin >> Year;
}

//������ ��������� � ����
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


// �������� �������� ���������.
bool IssuedDocument::operator==(const IssuedDocument & another)
{
	return
		document::operator==(another) &&
		another.Place.compare(Place) == 0 &&
		another.Year == Year;
}


