#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>
#include<locale.h>
#include "Base.h"
#define YEAR 1900



int note(int s, struct NOTE *arr) //¬вод с клавиатуры в блокнот без стирани€ предыдущего содержимого
{
    setlocale(LC_ALL, "Rus");
    FILE *file;
    file = fopen("NOTE.txt", "a+");
    if (file==NULL)
        printf("‘айл не удаетс€ открыть\n");
    else
        printf("‘айл успешно открыт\n");
    int k=0;

     for(k = 0 ; k < s ; k++)
    {
        printf("”частник %d:\n",k+1);
        printf("¬ведите им€: ");
        scanf("%8s",arr[k].First_Name);
        printf("¬ведите фамилию: ");
        scanf("%8s",arr[k].Second_Name);
        printf("¬ведите день рождени€: ");
        scanf("%8d",&arr[k].date[0]);
        printf("¬ведите мес€ц рождени€: ");
        scanf("%8d",&arr[k].date[1]);
        printf("¬ведите год рождени€: ");
        scanf("%8d",&arr[k].date[2]);
        printf("¬ведите номер телефона: ");
        scanf("%8d",&arr[k].Number);
    }

    for(k = 0 ; k < s ; k++)
    fprintf(file, "%s %s %d %d %d %d\n", arr[k].First_Name, arr[k].Second_Name, arr[k].date[0], arr[k].date[1], arr[k].date[2], arr[k].Number);

    fclose(file);
    return arr;
}
