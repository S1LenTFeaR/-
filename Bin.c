#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>
#include<locale.h>

struct NOTE
{
    char First_Name[30], Second_Name[30];
    int Number;
    int date[3];
};

void VivodStroki(struct NOTE * arr, int row);
FILE* Binar(char* filename, int * count);
void ReadFiles(FILE* bin, struct NOTE* arr, char* answer);
int ReadStrok(FILE* bin, struct NOTE * arr, int row);

int main()
{
    setlocale(LC_ALL, "Rus");
	int count = 0, i = 0; // счетчики
	FILE* bin = Binar("NOTE.txt", &count);
	struct NOTE * arr = (struct NOTE *)calloc(count, sizeof(struct NOTE)); // выделяем память под структуры с файла, count будет равен первой строчки с файла, и считывается он в прошлой функции
    int row = 0; // номер участника
    char answer[12];
	ReadFiles(bin, arr, answer); // Перемещение по файлу
	printf("Введите № участника: ");  //Извлечение строки по номеру
	scanf("%u", &row);
	if (ReadStrok(bin, arr, row) == 0) // функция чтения строки, если возвращает 0, значит row > больше количества структур
		printf("\nОшибка: № участника больше максимального значения.");
	else
	{
		VivodStroki(arr, row); // Вывести считанную строку под номером row
	}

	char First_Name[30]; // Массив для имени
	int output = 0; // Переменная для определения, был ли вывод хотя бы одной структуры NOTE
	printf("Введите имя: ");
	scanf("%20s", &First_Name); // Считываем тип в переменную тип (First_Name)
	printf("Результат:\n");
	fseek(bin, sizeof(int), SEEK_SET); // курсор в бинарном файле в самом начале, передвигаем его на sizeof(int), тогда указатель будет на начале первой структуры
	fread(arr, sizeof(struct NOTE), count, bin); // читаем count (все структуры) с файла, указатель будет уже в конце файла
	for (i = 0; i < count; i++)
		if (strcmp(arr[i].First_Name, First_Name) == 0)
		{
			printf("%s %s %d.%d.%d\n", arr[i].First_Name,arr[i].Second_Name, arr[i].date[0], arr[i].date[1], arr[i].date[2]); // Вывод структуры у которой совпало имя с именем, которое мы ввели
            if(arr[i].Number!=0)
            	printf("%d\n", arr[i].Number);
            else
                printf("Номер телефона отсутствует\n");
            if (output == 0)
                output = 1; // Ставим 1, означающую, что была найдена как минимум одна подходящая структура и выведена на экран
		}
	if (output == 0) // Если выводов подходящих структур не было, выводим что подходящих людей нет
		printf("Таких результатов нет\n");

	fclose(bin); // Закрываем файл
	return 0; //
}



void VivodStroki(struct NOTE * arr, int row)
{
    setlocale(LC_ALL, "Rus");
	printf("%s ", arr[row - 1].First_Name);
	printf("%s ", arr[row - 1].Second_Name);
	printf("%d.%d.%d\n", arr[row - 1].date[0], arr[row - 1].date[1], arr[row - 1].date[2]);
	if(arr[row - 1].Number!=0)
	printf("%d\n", arr[row - 1].Number);
	else
    printf("Номер телефона отсутствует\n");
}



FILE* Binar(char* filename, int * count)
{
    setlocale(LC_ALL, "Rus");
    int ch, i;
    FILE * file = fopen(filename, "r");
    if (file == NULL) // Не открылось, ошибка, закрываем программу
	{
		printf("%s", strerror(errno));
		exit(0);
	}
	fscanf(file, "%u", count); // Считываем форматированным вводом с файла количество структур
    struct NOTE * arr = (struct NOTE *)calloc(*count, sizeof(struct NOTE)); // Выделяем память
    for (i = 0; i < *count; i++)
	{
		fscanf(file, "%s", arr[i].First_Name);
		fscanf(file, "%s", arr[i].Second_Name);
		fscanf(file, "%d", &arr[i].date[0]);
		fscanf(file, "%d", &arr[i].date[1]);
		fscanf(file, "%d", &arr[i].date[2]);
		fscanf(file, "%d", &arr[i].Number);
	}
    fclose(file);
    FILE* bin = fopen("Bin.txt", "w+b"); // открываем бинарный файл
    fwrite(count, sizeof(int), 1, bin); // записываем count
    for (i = 0; i < *count; i++)
		fwrite(&arr[i], sizeof(struct NOTE), 1, bin);// позиция потока файла в после count. Записываем все структуры
    fseek(bin, 0, SEEK_SET); // Возвращаемся на начало.
    free(arr); // Высвобождаем выделенную память под массив
	return bin;
}

void ReadFiles(FILE* bin, struct NOTE* arr, char* answer)
{
    setlocale(LC_ALL, "Rus");
	// указатель в файле в начале
	int i, count = 0;
	fread(&count, sizeof(int), 1, bin); // чтение количества структур с бинарного файла
	for(i = 0; answer[i]; i++)
		answer[i] = tolower(answer[i]); // string.h нужна для tolower. делает строку в нижнем регистре, пример, ввели TyPE результат type
	for (i = 0; i < count; i++)
	{ // в зависимости от того что мы запросили считывается с бинарного файла и записывается в массив из main
		if (strcmp(answer, "SecondName") == 0)
		{
			fread(arr[i].Second_Name, sizeof(char), 30, bin); // считываем 1 столбик
			fseek(bin, 2 + sizeof(int) + 20*sizeof(char), SEEK_CUR); // перепрыгиваем второй и третий столбик
		}
		else if (strcmp(answer, "FirstName") == 0)
		{
			fseek(bin, 30*sizeof(char), SEEK_CUR); // перепрыгиваем первый столбик
			fread(arr[i].First_Name, sizeof(char), 20, bin); // читаем второй
			fseek(bin, 2 + sizeof(int), SEEK_CUR); // перепрыгиваем 3 столбик
		}
		else if (strcmp(answer, "Year") == 0)
		{
			fseek(bin, 52*sizeof(char), SEEK_CUR); // перепрыгиваем второй и третий столбик
			fread(&arr[i].date[2], sizeof(int), 1, bin); // читаем 3, указатель уже будет в начале следующей структуры
		}
	}
	fseek(bin, 0, SEEK_SET); // После каждой функции работающей с бинарным файлом, я прыгаю в начало бинарного файла
}

int ReadStrok(FILE* bin, struct NOTE * arr, int row)
{
    setlocale(LC_ALL, "Rus");
	// указатель в файле в начале
	int count = 0;
	fread(&count, sizeof(int), 1, bin); // чтение количества структур с бинарного файла
	if (row > count)
		return 0; // Если row больше количества структур, возвращаем 0 - ложь
	// Допустим человек захотел вывести 1 строчку, но в массиве она под индексом 0, значит row-1
	// Например человек хочет 3 строчку, индекс 2, в бинарном файле она по счету третья
	// Значит мы перескакиваем fseek'ом две структуры (row-1) и считываем третью
	fseek(bin, (row-1)*sizeof(struct NOTE), SEEK_CUR); // перескочили row-1
	fread(arr + row-1, sizeof(struct NOTE), 1, bin); // Считали по сути уже row и записали в массив под индексом [row-1]
	fseek(bin, 0, SEEK_SET); // Указатель в начало бинарного файла
	return 1; // Возвращаем true правда
}


