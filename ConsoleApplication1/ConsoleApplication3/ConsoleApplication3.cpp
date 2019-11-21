#include <iostream>
#include <iomanip>
#include "Books.h"

#define FilePath "list.txt" // Макроопределение: Путь к файлу со списком книг.

using namespace std;

// Функция для чтения списка книг из потока.
bool ReadBooks(Books & books, const string filepath)
{
	bool read = books.Read(filepath); // Чтение книг из файла.
	if (read)
		cout << "File " << filepath << " was read." << endl; // Файл успешно прочитан.
	else
		cout << "File " << filepath << " wasn't read." << endl; // Файл не был прочитан.
	return read; // Вернуть true, если файл прочитан, иначе - false.
}

// Функция для чтения списка книг из потока.
bool ReadBooks(Books & books)
{
	string filepath;
	cout << "Enter path: ";
	getline(cin, filepath);
	return ReadBooks(books, filepath);
}

// Функция для записи списка книг в файл.
bool WriteBooks(const Books & books, const string filepath)
{
	bool written = books.Write(filepath);
	if (written)
		cout << "File " << filepath << " was written." << endl;
	else
		cout << "File " << filepath << " wasn't written." << endl;
	return written; // Вернуть true, если файл записан, иначе - false.
}

// Функция для записи списка книг в файл.
bool WriteBooks(const Books & books)
{
	string filepath;
	cout << "Enter path: ";
	getline(cin, filepath);
	return WriteBooks(books, filepath);
}

// Функция для добавления книги в контейнер с удалением объекта в случае неудачи.
void AddBook(Books & books, Book * book)
{
	book->Read(); // Прочитать книгу с клавиатуры.
	bool added = books.Add(book); // Добавить книгу в контейнер.
	if (added)
	{ // Если книга добавлена.
		Book::WriteTableHeader();
		book->WriteToTable(); // Вывести книгу в строку таблицы.
		cout << "The book was added." << endl;
	}
	else
	{ // Книгу добавить не удалось.
		delete book; // Освободить память.
		cout << "The book wasn't added." << endl;
	}
}

// Функция для удаления книги из списка.
void RemoveBook(Books & books)
{
	int index;
	string ordered;
	cout << "Enter index: ";
	index = Book::ReadInt(cin); // Получить индекс удаляемой книги.
	Book * removedBook = books.Remove(index); // Удалить книгу из списка.
	if (removedBook)
	{ // Если книга удалена.
		cout << "Book was removed." << endl;
		Book::WriteTableHeader();
		removedBook->WriteToTable(); // Вывести книгу на экран.
		delete removedBook; // Удалить объект книги.
	}
	else
		cout << "Book wasn't removed." << endl;
}

// Поиск всех книг заданного пользователем автора.
void SearchByAuthor(const Books & books)
{
	cout << "Enter author to select books: ";
	string author;
	getline(cin, author); // Ввод искомого автора.
	books.SearchByAuthor(author);
}

// Функция для выбора действия пользователем.
int SelectAction()
{
	cout << "----- ----- ----- -----" << endl;
	cout << "Menu:" << endl;
	cout << setw(2) << 1 << " / " << "Add book." << endl;
	cout << setw(2) << 2 << " / " << "Show books." << endl;
	cout << setw(2) << 3 << " / " << "Read books from file." << endl;
	cout << setw(2) << 4 << " / " << "Write books to default file." << endl;
	cout << setw(2) << 5 << " / " << "Write books to file." << endl;
	cout << setw(2) << 6 << " / " << "Remove book." << endl;
	cout << setw(2) << 7 << " / " << "Search books by author." << endl;
	cout << setw(2) << 8 << " / " << "Search the newest book." << endl;
	cout << setw(2) << 9 << " / " << "Exit." << endl;
	cout << "Enter the number: ";
	return Book::ReadInt(cin);
}

int main()
{
	Books books(20);
	ReadBooks(books, FilePath); // Чтение книг из файла.
	int action;
	do
	{
		action = SelectAction();
		cout << "----- ----- ----- -----" << endl;
		switch (action)
		{
		case 1: // Добавить книгу.
			AddBook(books, new Book()); // В функцию добавления передаётся новый объект.
			break;
		case 2: // Вывод таблицы книг.
			books.WriteToTable();
			break;
		case 3: // Чтение книг из файла
			ReadBooks(books);
			break;
		case 4: // Запись книг в стандартный файл.
			WriteBooks(books, FilePath);
			break;
		case 5: // Запись книг в файл.
			WriteBooks(books);
			break;
		case 6: // Удалить книгу.
			RemoveBook(books);
			break;
		case 7:
			SearchByAuthor(books);
			break;
		case 8:
			books.FindNewest();
			break;
		default:
			action = -1;
		}
	} while (action != -1);
	books.DeleteAll(); // Удалить все книги, освободив память.
	// Деструктор контейнера будет вызван автоматически.
	return 0;
}
