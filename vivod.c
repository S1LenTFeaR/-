#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>
#include<locale.h>
#include "Base.h"
#define YEAR 1900



int vivod(int s, int i, struct NOTE *arr) //Выводит в консоли информацию об участниках
{
    int k=0;

    FILE *file;
    file = fopen("NOTE.txt", "r");

    printf("-----------------------------\n");
    while (fscanf (file, "%s%s%d%d%d%d", arr[k].First_Name, arr[k].Second_Name, &(arr[k].date[0]), &(arr[k].date[1]), &(arr[k].date[2]), &(arr[k].Number)) != EOF)
    {
        printf("Участник №%d\nИмя - %s %s\nДата рождения - %d.%d.%d\n", k+1, arr[k].First_Name, arr[k].Second_Name, arr[k].date[0], arr[k].date[1], arr[k].date[2]);
		if(arr[k].Number!=0)
        printf("Номер телефона - %d\n-----------------------------\n", arr[k].Number);
        else
        printf("Номер телефона не указан\n-----------------------------\n");
		k++;
    }

    fclose(file);
}
