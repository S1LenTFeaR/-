#include<stdio.h>
#define M 7
#define N 7
#include <time.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Rus");
    int Arr[M][N];
    int i, j, s, R, C=0, n=0;
    srand(time(NULL));
    printf("Начальная матрица\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            Arr[i][j]=rand()%20+1;
            printf("%6d",Arr[i][j]);
        }
        printf("\n");
    }
    printf("\nВведите кратное номера строк R = ");
    scanf("%d", &R);
    printf("\nВведите кратное номера столбцов s = ");
    scanf("%d", &s);
    printf("\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            if((j%s==0) && (i%R==0))
            {
                C+=Arr[i][j];
                printf("[%d][%d] C=%d\n", i, j, C);
                n++;
            }
            else
            {

            }
        }
    }
    printf("\nСумма = %d\n", C/n);
return 0;
}
