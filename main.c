#include<stdio.h>
#include <stdlib.h>
#define i 5
struct NOTE {
    char *Second_Name, *First_Name;
    int Number;
    int *date[3];
} arr[i];

int main()
{
    int k, j=0, l=0, Arr[5], Date=1990;
    arr[0].Second_Name = "Gorbach";
    arr[0].First_Name = "Andrey";
    arr[0].date[0] = 1;
    arr[0].date[1] = 2;
    arr[0].date[2] = 2000;

    arr[1].Second_Name = "Sidorov";
    arr[1].First_Name = "Ivan";
    arr[1].date[0] = 3;
    arr[1].date[1] = 1;
    arr[1].date[2] = 2003;

    arr[2].Second_Name = "Ivanov";
    arr[2].First_Name = "Alexey";
    arr[2].date[0] = 30;
    arr[2].date[1] = 11;
    arr[2].date[2] = 1998;

    arr[3].Second_Name = "Andreev";
    arr[3].First_Name = "Andrey";
    arr[3].date[0] = 25;
    arr[3].date[1] = 9;
    arr[3].date[2] = 2000;

    arr[4].Second_Name = "Vasiliev";
    arr[4].First_Name = "Evgeniy";
    arr[4].date[0] = 7;
    arr[4].date[1] = 5;
    arr[4].date[2] = 1990;
    for(k = 0; k < i; k++)
    {
        printf("Enter mobile number by %s %s\n", arr[k].First_Name, arr[k].Second_Name);
        scanf("%int", &arr[k].Number);
    }
    printf("---------------------------------------------\n");
        for(k = 0; k < 100; k++)
        {
            if(arr[l].date[2] == Date)
            {
                while(l<i)
                {
                    if(arr[l].date[2] == Date)
                    {
                        printf("First_Name - %s, Second_Name - %s\n", arr[l].First_Name, arr[l].Second_Name);
                        if(arr[l].Number!=0)
                        {
                            printf("Number = %d\n", arr[l].Number);
                        }
                        else
                        printf("Unknown number\n");
                        printf("date = %d,%d,%d\n", arr[l].date[0], arr[l].date[1], arr[l].date[2]);
                        printf("---------------------------------------------\n");
                        l++;
                    }
                    else
                    {
                        l++;
                    }
                }
                Date++;
                l=0;
            }
            else
            {
                if(l<i)
                {
                    l++;
                }
                else
                {
                    Date++;
                    l=0;
                }
            }
        }
        return 0;
}


