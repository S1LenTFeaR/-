#include <string> 
#include <fstream> 
#include "Documents.h" 

class archive
{
private:
	int Max_Num_Documents;				// ������������ ���-�� ���� � �������� (�����������) 
	int Num_Documents;					// ������� ����� ���� � �������� 
	document *documents;				// ������ �������� ������ book 



public:
	archive(unsigned int max_nd);		// ����������� ������ bookstore  ~bookstore();                   
	~archive();							// ���������� ������ bookstore 
	
	void add_document(ifstream & file);
	void read_documents(ifstream & file);
	void Second();
	void First();
	void display_all();
	void remove();
	void in_file();
};
