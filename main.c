#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>
#include<locale.h>
#include "Base.h"
#define YEAR 1900 //Год, с которого начинается сортировка

int note(int s, struct NOTE *arr);
int Sort(int s, int i, struct NOTE *arr, struct NOTE tmp);
int pomeshaem(int s, int i, struct NOTE *arr);
int vivod(int s, int i, struct NOTE *arr);






int main()
{
    int i=0;
    setlocale(LC_ALL, "Rus");
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




    system("pause");
    return 0;
}





