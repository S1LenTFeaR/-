#include "pch.h"
#include "Documents.h"
using namespace std;

//Геттер
double document::get_total_price()
{
	return total_price;
}

//Геттер
int document::get_count()
{
	return count;
}

//Геттер
double document::get_total_area()
{
	return total_area;
}

//Геттер
double document::get_living_area()
{
	return living_area;
}

//Чтение документа из файла
void document::read_document(istream & stream)
{
	stream
		>> name
		>> account
		>> address
		>> count
		>> total_area
		>> living_area
		>> total_price;
}

//Чтение документа с клавиатуры
void document::read_document()
{
	cout << "Введите имя: ";
	cin >> name;
	cout << "Введите номер лицевого счета: ";
	cin >> account;
	cout << "Введите город: ";
	cin >> address;
	cout << "Введите количество проживающих: ";
	cin >> count;
	cout << "Введите общую площадь: ";
	cin >> total_area;
	cout << "Введите жилую площадь: ";
	cin >> living_area;
	cout << "Введите суммарную стоимость: ";
	cin >> total_price;
}

//Вывод документа на экран
void document::display()
{
	cout << "|" << left << setw(11) << name;
	cout << "|" << left << setw(11) << account;
	cout << "|" << left << setw(17) << address;
	cout << "|" << left << setw(4) << count;
	cout << "|" << left << setw(7) << total_area;
	cout << "|" << left << setw(7) << living_area;
	cout << "|" << left << setw(6) << total_price << "|" << endl;
	cout << "+--+-----------+-----------+-----------------+----+-------+-------+------+" << endl;
}

//Запись документа в файл
void document::infile(ostream & stream) const
{
	stream
		<< name << endl
		<< account << endl
		<< address << endl
		<< count << endl
		<< total_area << endl
		<< living_area << endl
		<< total_price << endl;
}

// Переопределение операторов.
// Оператор проверки равенства.
bool document::operator==(const document & another)
{
	return
		another.name == name &&
		another.account == account &&
		another.address == address &&
		another.count == count &&
		another.total_area == total_area &&
		another.living_area == living_area &&
		another.total_price == total_price;
}

ostream& operator<<(ostream & stream, const document & adocument)
{
	adocument.infile(stream);
	return stream;
}

// Оператор чтения из потока.
istream& operator>>(istream & stream, document & adocument)
{
	adocument.read_document(stream);
	return stream;
}
