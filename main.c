/*Программа №2 с лабораторной работы №8*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int SUM(int *arr)
{
    int i=0, Sum=0;
    while (arr[i] <= 0)
    {
        i++;
    }
    i++;
    while (arr[i] <= 0)
    {
        Sum += arr[i];
        i++;
    }
    return Sum;
}
int main()
{
int Sum, Arr[20]={-5, 6, -8, -25, -35, -47, 12, 34, 78, -5987, 11, 12, 13, 14, 15, 16, 17, 18, -19, 20}, *arr;
arr=&Arr;
printf("\nSUM=%d\n",SUM(&Arr));
return 0;
}
