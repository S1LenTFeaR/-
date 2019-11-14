#ifndef DOCUMENTS_H
#define DOCUMENTS_H
#include <string>
#include <fstream>

using std::string;
using std::ifstream;
using std::ofstream;
class document
{
	private:
		int account, count;								//Номер личного счета (account), Количество проживающих (count);
		double total_area, living_area, total_price;	//Общая площадь, кв.м. (total_area), Жилая площадь, кв.м. (living_area), Общая сумма оплаты, руб (total_price);
		string name;									//Плательщик (name), ;
		string address;									//Адрес(address)
	public:
		void ReadDocuments(ifstream & file);			//Функция чтения из файлы
		void ReadDocuments();							//Функция чтения из программы
		void PrintDocuments();							//Функция вывода на экран
		void infile(ofstream & file, int k);			//Функция записи в файл
		double get_total_price();
		int get_count();
		double get_total_area();
		double get_living_area();
};

void Head();
void First(int N, document *arr); //Первое задание
void Second(int N, document *arr); //Второе задание



#endif