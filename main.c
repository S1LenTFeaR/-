#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define N 3 //Максимальное количество участников
#define YEAR 1990 //Год, с которого начинается сортировка
struct NOTE
{
    char First_Name[9], Second_Name[9];
    int Number;
    int date[3];
    int Date
} arr[N], tmp;

int main()
{
    setlocale(LC_ALL, "Rus");

    int k, n, j = 0;


    for(k = 0 ; k < N ; k++)
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

    //Подсчет количества дней после года YEAR для каждого участника анкеты
    for(k = 0 ; k < N ; k++)
    {
        arr[k].Date = (arr[k].date[0]) + (arr[k].date[1]*30) + ((arr[k].date[2]-YEAR)*360);
    }
    //Счетчик итераций (сортировка на протяжении n дней после года YEAR)
    for(n = 0; n < 50000 ; n++)
    {
        //Проверка каждого человека (родился ли человекв n-ный день)
        for(k = 0 ; k < N ; k++)
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

    printf("\n---------------------------------------------\n");
    //Вывод отсортированной по датам анкеты
    for(k = 0 ; k < N ; k++)
    {
        printf("Имя - %s, Фамилия - %s\n", arr[k].First_Name, arr[k].Second_Name);
        //Проверка, был ли введен номер телефона (Если 0 -нет, если иное число - телефон введен)
        if(arr[k].Number!=0)
        {
            printf("Номер телефона: %d\n", arr[k].Number);
        }
        else
        {
            printf("Номер телефона не указан\n");
        }
        printf("Дата рождения: %d.%d.%d\n", arr[k].date[0], arr[k].date[1], arr[k].date[2]);
        printf("---------------------------------------------\n");
    }

    return 0;
}


