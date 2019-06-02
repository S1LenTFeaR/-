#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>
#include<locale.h>
#include "Base.h"
#define YEAR 1900



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
