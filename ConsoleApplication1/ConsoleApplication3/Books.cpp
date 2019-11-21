#include "Books.h"

// �����������.
Books::Books(int capacity)
{
    Capacity = capacity;
    List = new Book * [capacity]; // �������� ������ ��� ������.
    Count = 0; // ��������� ���������� ����.
    cout << "Memory was allocated for " << capacity << " books." << endl;
}

// ����������.
Books::~Books()
{
    if(List) // ���� ��������� ������� �� ����.
    {
        // ������� ���� �� ���������.
        delete [] List; // ���������� ������.
        List = nullptr; // �������� ���������.
        Capacity = 0; // ������� ����� ����.
        Count = 0; // ���������� ���� ����� ����.
        cout << "Memory was freed." << endl;
    }
}

// ��������� ������ ���� �� ������.
bool Books::Read(istream & stream)
{
    int countToAdd = Book::ReadInt(stream); // ������ ���������� ���� � �����.
    int newCount = Count + countToAdd; // ������� ���������� ���� � ������.
    bool read = newCount <= Capacity; // true, ���� ����������� ����� ���������� � ���������.
    if(read)
    {
        for(int i = Count; i < newCount; i++)
        {
            List[i] = new Book(); // ������� ������ �����.
            List[i]->Read(stream); // ��������� ����� �� ������.
        }
        Count = newCount; // ����� ���������� ���� � ������.
    }
    return read;
}

// ��������� ������ ���� �� �����.
bool Books::Read(string filepath)
{
    bool read = false;
    ifstream file(filepath); // �������� ����� ��� ������ ������.
    // ����� � CodeBlocks �������� ��������� string � ������������ ifstream, ����� ���������� ����:
    // Settings -> Compiler... -> Global compiler settings -> Compiler settings -> Compiler flags ->
    // Have g++ foloow the C++11 ISO C++ language standard [-std=c++11]
    if(file)
    { // ���� ������� ������.
        read = Read(file); // ��������� ������ ���� �� ������.
        file.close(); // �������� �����.
    }
    return read; // ������� true, ���� ���� ��������, ����� - false.
}

// �������� ������ ���� � �����.
void Books::Write(ostream & stream) const
{
    stream << Count << endl; // ������ ���������� ���� � �����.
    for(int i = 0; i < Count; i++)
        List[i]->Write(stream); // �������� ����� � �����.
}

// �������� ������ ���� � ����.
bool Books::Write(string filepath) const
{
    bool written = false;
    ofstream file(filepath); // �������� ����� ��� ������ ������.
    if(file)
    { // ���� ������� ������.
        Write(file); // �������� ������ ���� � �����.
        file.close(); // ������� ����.
        written = true; // ������� ������ ������� true ��� �������� ������.
    }
    return written; // ������� true, ���� ���� �������, ����� - false.
}

// ������� ������ ���� �� ����� � ���� �������.
void Books::WriteToTable() const
{
    Book::WriteTableHeader(); // ����� ��������� ������� ����.
    for(int i = 0; i < Count; i++)
        List[i]->WriteToTable(); // ������� ����� � ������ �������.
    if(Count == 0)
        cout << "There are no books." << endl;
}

// �������� �����.
bool Books::Add(Book * book)
{
    bool added = Count + 1 <= Capacity; // true, ���� ���� ����� ��� ��� ����� �����.
    if(added)
    {
        List[Count] = book; // �������� ����� �����.
        Count++; // ��������� ������� ����������.
    }
    return added;
}

// ������� �����, �������� ������� ���������� ����.
Book * Books::Remove(int index)
{
    Book * book = nullptr;
    if(index > -1 && index < Count) // �������� ������������ �������.
    {
        book = List[index]; // ���������� ��������� � ������������ ����������.
        Count--;
        for(int i = index; i < Count; i++)
            List[i] = List[i + 1]; // �������� ����, ������� ����� ���������, �� ���� ������� �����.
    }
    return book;
}

// �������, ��������� ������, ��� ����� �� ����������.
void Books::DeleteAll()
{
    for(int i = 0; i < Count; i++) // �������� ����.
        delete List[i];
}

// ����� ��� ����� ��������� ������.
void Books::SearchByAuthor(string author) const
{
    int found = false; // ����������, ������������, ������� �� ���� �� ���� �����.
    Book::WriteTableHeader(); // ����� ��������� ������� ����.
    for(int i = 0; i < Count; i++)
    {
        if(List[i]->GetAuthor().compare(author) == 0) // ��������� �������� ������ � ������� �����.
        { // ����� ����� - �������.
            List[i]->WriteToTable(); // ����� ����� � ������ �������.
            found = true; // ���� �� ���� ����� �������.
        }
    }
    if(!found)
        // ���� �� ����� ����� �� �������, ������� ���������.
        cout << "There are no books of " << author << "." << endl;
}

// ����� �������� ����� ����� (� ���������� ����� ����������).
void Books::FindNewest() const
{
    int year = -1; // ���������� ��� �������� ������������� ���������� ����.
    // ������������, ��� �������������� �������� ���� ���������� �� � ����� ����� ���.
    int index = -1; // ���������� ��� �������� ������� ����� � ������������ �����.
    for(int i = 0; i < Count; i++)
        if(List[i]->GetYear() > year)
        { // ��� ���������� ����� ��������� ������� �������� ������������� ����.
            year = List[i]->GetYear(); // ��������� ����� �������� ������������� ����.
            index = i; // ��������� ������ ����� � ������������ �����.
        }
    if(index != -1)
    { // ������ ��� ������, ������, �������� ����� �������.
        cout << "The newest book:" << endl;
        Book::WriteTableHeader();
        List[index]->WriteToTable(); // ���������� ���������� ������ ��� ������� � �����.
    }
    else
        // �������������� �������� ������� ������� � ���, ��� ���� ������ ��� ����, ���� ���� � ������ ������ -1.
        cout << "Can't find the newest book." << endl;
}
