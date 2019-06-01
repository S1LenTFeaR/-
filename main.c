#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>
#include<locale.h>
#define YEAR 1900 //Год, с которого начинается сортировка
struct NOTE
{
    char First_Name[9], Second_Name[9];
    int Number;
    int date[3];
    int Date
} *arr, tmp;

int note(int s, struct NOTE *arr) //Ввод с клавиатуры в блокнот без стирания предыдущего содержимого
{
    setlocale(LC_ALL, "Rus");
    FILE *file;
    file = fopen("NOTE.txt", "a+");
    if (file==NULL)
        printf("Файл не удается открыть\n");
    else
        printf("Файл успешно открыт\n");
    int k=0;

     for(k = 0 ; k < s ; k++)
    {
        printf("Участник %d:\n",k+1);
        printf("Введите имя: ");
        scanf("%8s",arr[k].First_Name);
        printf("Введите фамилию: ");
        scanf("%8s",arr[k].Second_Name);
        printf("Введите номер телефона: ");
        scanf("%8d",&arr[k].Number);
        printf("Введите день рождения: ");
        scanf("%8d",&arr[k].date[0]);
        printf("Введите неделю рождения: ");
        scanf("%8d",&arr[k].date[1]);
        printf("Введите год рождения: ");
        scanf("%8d",&arr[k].date[2]);
    }

    for(k = 0 ; k < s ; k++)
    fprintf(file, "%s %s %d %d %d %d\n", arr[k].First_Name, arr[k].Second_Name, arr[k].date[0], arr[k].date[1], arr[k].date[2], arr[k].Number);

    fclose(file);
    return arr;
}

int izvlekaem(int s, struct NOTE *arr)//Не задействована. Должна извлекать все данные из блокнота в массив структур
{
    int i=0;
    FILE *file;
    file = fopen("NOTE.txt", "r");
    while (fscanf (file, "%s%s%d%d%d%d", arr[i].First_Name, arr[i].Second_Name, &(arr[i].date[0]), &(arr[i].date[1]), &(arr[i].date[2]), &(arr[i].Number)) != EOF)
    {
		i++;
    }
    fclose(file);
    return arr;
}

int Sort(int s, int i, struct NOTE *arr, struct NOTE tmp) //Сортирует участников по датам
{
    int k, j=0, n=0;
    for(k = 0 ; k < i ; k++)
    {
        arr[k].Date = (arr[k].date[0]) + (arr[k].date[1]*30) + ((arr[k].date[2]-YEAR)*360);
    }
    //Счетчик итераций (сортировка на протяжении n дней после года YEAR)
    for(n = 0; n < 200000 ; n++)
    {
        //Проверка каждого человека (родился ли человекв n-ный день)
        for(k = 0 ; k < i ; k++)
        {
            if(arr[k].Date == n)
            {
                //Делаем копию заменяемого элемента массива структуры
                strcpy(tmp.First_Name,arr[j].First_Name );
                strcpy(tmp.Second_Name,arr[j].Second_Name);
                tmp.Number = arr[j].Number;
                tmp.date[0] = arr[j].date[0];
                tmp.date[1] = arr[j].date[1];
                tmp.date[2] = arr[j].date[2];
                tmp.Date = arr[j].Date;
                //Заменяем элемент массива структуры
                strcpy(arr[j].First_Name , arr[k].First_Name);
                strcpy(arr[j].Second_Name , arr[k].Second_Name);
                arr[j].Number = arr[k].Number;
                arr[j].date[0] = arr[k].date[0];
                arr[j].date[1] = arr[k].date[1];
                arr[j].date[2] = arr[k].date[2];
                arr[j].Date = arr[k].Date;
                j++;
                //Возвращаем значение замененного элемента массива структуры на место k
                strcpy(arr[k].First_Name , tmp.First_Name);
                strcpy(arr[k].Second_Name , tmp.Second_Name);
                arr[k].Number=tmp.Number;
                arr[k].date[0]=tmp.date[0];
                arr[k].date[1]=tmp.date[1];
                arr[k].date[2]=tmp.date[2];

                arr[k].Date=tmp.Date;
            }
            else
            {
            }
        }
    }
    return arr;
}

int pomeshaem(int s, int i, struct NOTE *arr) //Заменяет содержимое блокнота на его отсортированный по датам вариант
{
    int k;
    FILE *file;
    file = fopen("NOTE.txt", "w");
    for(k = 0 ; k < i ; k++)
    {
        fprintf(file, "%s %s %d %d %d %d\n", arr[k].First_Name, arr[k].Second_Name, arr[k].date[0], arr[k].date[1], arr[k].date[2], arr[k].Number);
    }
    fclose(file);
}

int vivod(int s, int i, struct NOTE *arr) //Выводит в консоли информацию об участниках
{
    int k=0;

    FILE *file;
    file = fopen("NOTE.txt", "r");

    printf("-----------------------------\n");
    while (fscanf (file, "%s%s%d%d%d%d", arr[k].First_Name, arr[k].Second_Name, &(arr[k].date[0]), &(arr[k].date[1]), &(arr[k].date[2]), &(arr[k].Number)) != EOF)
    {
        printf("Участник №%d\nИмя - %s %s\nДата рождения - %d.%d.%d\nНомер телефона - %d\n-----------------------------\n", k+1, arr[k].First_Name, arr[k].Second_Name, arr[k].date[0], arr[k].date[1], arr[k].date[2], arr[k].Number);
		k++;
    }

    fclose(file);
}


int main()
{
    int i=0;
    setlocale(LC_ALL, "Rus");
    typedef struct NOTE;
    int s;
    printf("Введите количество участников: ");
    scanf("%d", &s);
    arr = (int*)malloc(s * sizeof(int));
    note(s, arr);

    FILE *file;
    file = fopen("NOTE.txt", "r");
    while (fscanf (file, "%s%s%d%d%d%d", arr[i].First_Name, arr[i].Second_Name, &(arr[i].date[0]), &(arr[i].date[1]), &(arr[i].date[2]), &(arr[i].Number)) != EOF)
    {
		i++;
    }
    fclose(file);

    Sort(s, i, arr, tmp);
    pomeshaem(s,i, arr);
    vivod(s,i,arr);
    free(arr);

    return 0;
}





