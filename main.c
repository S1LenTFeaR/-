#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define N 6
#define M 6
int main()
{
    setlocale(LC_ALL, "Rus");
    int i, j, C=0, sum=0, SUM=0;
    int Arr[N][M];
    for(i=0;i<N;i++)
    {
        printf("������ %d|", i+1);
        for(j=0;j<M;j++)
        {
            Arr[i][j]=rand()%2;
            printf("%4d",Arr[i][j]);
        }
        printf("\n");
    }
    C+=Arr[0][0];
    for (i = 0; i<N-1; i++)
    {
        sum=0;
        for (j = 0; j<M; j++)
        {
            C = Arr[i][j]*Arr[i+1][j];
            sum+=abs(C);
        }
        SUM+=sum;
        printf("\n��������� ������������  %d � %d ����� �� ������ = %d", i+1, i+2, sum);
    }
    printf("\n");
    printf("\n����� ��������� ������������ �� ������ = %d\n", SUM);
    if(SUM==0)
        printf("\n������� - �����������������");
    else
        printf("\n������� - �������������������\n");
    return 0;
}
