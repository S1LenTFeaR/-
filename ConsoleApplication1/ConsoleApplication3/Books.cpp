#include "Books.h"

// Конструктор.
Books::Books(int capacity)
{
    Capacity = capacity;
    List = new Book * [capacity]; // Выделить память под массив.
    Count = 0; // Начальное количество вниг.
    cout << "Memory was allocated for " << capacity << " books." << endl;
}

// Деструктор.
Books::~Books()
{
    if(List) // Если указатель отличен от нуля.
    {
        // Объекты книг не удаляются.
        delete [] List; // Освободить память.
        List = nullptr; // Обнулить указатель.
        Capacity = 0; // Ёмкость равна нулю.
        Count = 0; // Количество книг равно нулю.
        cout << "Memory was freed." << endl;
    }
}

// Прочитать список книг из потока.
bool Books::Read(istream & stream)
{
    int countToAdd = Book::ReadInt(stream); // Чтение количества книг в файле.
    int newCount = Count + countToAdd; // Будущее количество книг в списке.
    bool read = newCount <= Capacity; // true, если прочитанные книги поместятся в контейнер.
    if(read)
    {
        for(int i = Count; i < newCount; i++)
        {
            List[i] = new Book(); // Создать объект книги.
            List[i]->Read(stream); // Прочитать книгу из потока.
        }
        Count = newCount; // Новое количество книг в списке.
    }
    return read;
}

// Прочитать список книг из файла.
bool Books::Read(string filepath)
{
    bool read = false;
    ifstream file(filepath); // Открытие файла для чтения текста.
    // Чтобы в CodeBlocks включить поддержку string в конструкторе ifstream, нужно установить флаг:
    // Settings -> Compiler... -> Global compiler settings -> Compiler settings -> Compiler flags ->
    // Have g++ foloow the C++11 ISO C++ language standard [-std=c++11]
    if(file)
    { // Файл успешно открыт.
        read = Read(file); // Прочитать список книг из потока.
        file.close(); // Закрытие файла.
    }
    return read; // Вернуть true, если файл прочитан, иначе - false.
}

// Записать список книг в поток.
void Books::Write(ostream & stream) const
{
    stream << Count << endl; // Запись количества книг в поток.
    for(int i = 0; i < Count; i++)
        List[i]->Write(stream); // Записать книгу в поток.
}

// Записать список книг в файл.
bool Books::Write(string filepath) const
{
    bool written = false;
    ofstream file(filepath); // Открытие файла для записи текста.
    if(file)
    { // Файл успешно открыт.
        Write(file); // Записать список книг в поток.
        file.close(); // Закрыть файл.
        written = true; // Функция должна вернуть true при успешном записи.
    }
    return written; // Вернуть true, если файл записан, иначе - false.
}

// Вывести список книг на экран в виде таблицы.
void Books::WriteToTable() const
{
    Book::WriteTableHeader(); // Вывод заголовка таблицы книг.
    for(int i = 0; i < Count; i++)
        List[i]->WriteToTable(); // Вывести книгу в строку таблицы.
    if(Count == 0)
        cout << "There are no books." << endl;
}

// Добавить книгу.
bool Books::Add(Book * book)
{
    bool added = Count + 1 <= Capacity; // true, если есть место для ещё одной книги.
    if(added)
    {
        List[Count] = book; // Записать новую книгу.
        Count++; // Увеличить текущее количество.
    }
    return added;
}

// Удалить книгу, сохранив порядок оставшихся книг.
Book * Books::Remove(int index)
{
    Book * book = nullptr;
    if(index > -1 && index < Count) // Проверка корректности индекса.
    {
        book = List[index]; // Сохранение указателя в возвращаемой переменной.
        Count--;
        for(int i = index; i < Count; i++)
            List[i] = List[i + 1]; // Смещение книг, стоящих после удаляемой, на одну позицию назад.
    }
    return book;
}

// Удалить, освободив память, все книги из контейнера.
void Books::DeleteAll()
{
    for(int i = 0; i < Count; i++) // Удаление книг.
        delete List[i];
}

// Найти все книги заданного автора.
void Books::SearchByAuthor(string author) const
{
    int found = false; // Переменная, показывающая, найдена ли хотя бы одна книга.
    Book::WriteTableHeader(); // Вывод заголовка таблицы книг.
    for(int i = 0; i < Count; i++)
    {
        if(List[i]->GetAuthor().compare(author) == 0) // Сравнение искомого автора с автором книги.
        { // Автор книги - искомый.
            List[i]->WriteToTable(); // Вывод книги в строку таблицы.
            found = true; // Хотя бы одна книга найдена.
        }
    }
    if(!found)
        // Если ни одной книги не найдено, вывести сообщение.
        cout << "There are no books of " << author << "." << endl;
}

// Найти наиболее новую книгу (с наибольшим годом публикации).
void Books::FindNewest() const
{
    int year = -1; // Переменная для хранения максимального найденного года.
    // Предполагаем, что отрицательного значения года публикации ни у одной книги нет.
    int index = -1; // Переменная для хранения индекса книги с максимальным годом.
    for(int i = 0; i < Count; i++)
        if(List[i]->GetYear() > year)
        { // Год публикации книги превышает текущее значение максимального года.
            year = List[i]->GetYear(); // Сохраняем новое значение максимального года.
            index = i; // Сохраняем индекс книги с максимальным годом.
        }
    if(index != -1)
    { // Индекс был изменён, значит, новейшая книга найдена.
        cout << "The newest book:" << endl;
        Book::WriteTableHeader();
        List[index]->WriteToTable(); // Используем сохранённый индекс для доступа к книге.
    }
    else
        // Первоначальное значение индекса говорит о том, что либо список кни пуст, либо года в списке меньше -1.
        cout << "Can't find the newest book." << endl;
}
