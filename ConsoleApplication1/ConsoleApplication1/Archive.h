#include <string> 
#include <fstream> 
#include "Documents.h" 

class archive
{
private:
	int Max_Num_Documents;				// максимальное кол-во документов в архиве (вместимость) 
	int Num_Documents;					// текущее число документов в архиве 
	document *documents;				// массив объектов класса document
public:
	archive(unsigned int max_nd);		// конструктор класса archive                  
	~archive();							// деструктор класса archive 
	
	void add_document(ifstream & file);
	void read_documents(ifstream & file);
	void Second();
	void First();
	void display_all();
	void remove();
	void in_file();
};
