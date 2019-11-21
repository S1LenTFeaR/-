#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <string>
#include <iostream> // Библиотека ввода-вывода.
#include <fstream> // Библиотека файлового ввода-вывода.
#include <iomanip> // Библиотека для использования манипуляторов ввода-вывода.

using std::string;
using std::ifstream;
using std::ofstream;
using std::istream;

class document
{
	private:
		int account, count;								//Номер личного счета (account), Количество проживающих (count);
		double total_area, living_area, total_price;	//Общая площадь, кв.м. (total_area), Жилая площадь, кв.м. (living_area), Общая сумма оплаты, руб (total_price);
		string name;									//Плательщик (name), ;
		string address;									//Адрес(address)
	public:
		int ReadInt(istream & stream);					// Функция для чтения int из отдельной строки текстового потока
		void ReadDocument(ifstream & stream);			//Функция чтения из файлы
		void ReadDocument();							//Функция чтения из программы
		void display();							//Функция вывода на экран
		void infile(ofstream & file, int k);			//Функция записи в файл
		double get_total_price();
		int get_count();
		double get_total_area();
		double get_living_area();
};

void Head();




#endif