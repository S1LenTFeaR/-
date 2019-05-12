#include<stdio.h>
#define i 3
struct stars {
    char Class;
    double m;
    double Share;
    int Number;
} arr[i];

int main()
{
    int k;
    arr[0].Class = 'O';
    arr[0].m = 32;
    arr[0].Share = 0.00002;
    arr[0].Number = 55000;

    arr[1].Class = 'F';
    arr[1].m = 1.25;
    arr[1].Share = 2.9;
    arr[1].Number = 12000000000;

    arr[i-1].Class = 'M';
    arr[i-1].m = 0.2;
    arr[i-1].Share = 73.2;
    arr[i-1].Number = 293000000000;
    printf("Spectral classes:\n--------------------\n");
    for(k = 0; k<= i-1; k++)
    {
        printf("Class - %c\n", arr[k].Class);
        printf("m = %lf\n", arr[k].m);
        printf("Share = %lf\n", arr[k].Share);
        printf("Number = %d\n", arr[k].Number);
        printf("--------------------\n");
    }
        return 0;
}
