#include<stdio.h>
#define M 6
#define N 6
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    int Arr[M][N]={
    {1, -2, 3, -4, 5, -6},
    {-1, 2, -3, 4, -5, 6},
    {-1, 2, -3, -4, 5, 6},
    {-1, 2, 3, 4, -5, 6},
    {1, 2, -3, 4, 5, 6},
    {-1, 2, -3, 4, -5, 6}
    };
    int arr[M][N-1];
    int i, j, C;
        printf("Начальная матрица\n");
        for(i=0;i<M;i++)
        {
            printf("Строка %d| ", i+1);
            for(j=0;j<N;j++)
                {
                printf("%d ",Arr[i][j]);
                }
                printf("\n");
        }
        printf("\n");

        for(i=0;i<M;i++)
        {       for(j=0;j<(N-1);j++)
            {
                arr[i][j]=Arr[i][j]*Arr[i][j+1];
                printf("%d ",arr[i][j]);
            }
                printf("\n");
        }
        printf("\n");
        for(i=0;i<M;i++)
        {       for(j=0;j<(N-1);j++)
            {
                if(arr[i][j]<0)
                {
                    C=1;
                }
                else
                {
                    C=0;
                    i++;
                    j=0;
                }

            }
                if(C=1)
                {
                    if(i<M)
                    {
                    printf("Знаки чередуются в строке %d", i+1);
                    }
                }
                printf("\n");
        }


    return 0;
}
