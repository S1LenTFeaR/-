#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>
#include<locale.h>
#include "Base.h"
#define YEAR 1900



int izvlekaem(int s, struct NOTE *arr)//Ќе задействована. ƒолжна извлекать все данные из блокнота в массив структур
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
