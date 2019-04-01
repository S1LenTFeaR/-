#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main()
{
int C, O=0, o=0, i, N=10, Arr[N];
srand(time(NULL));
for(i=0;i<N;i++)
{
    Arr[i]=rand()%5;
    printf("%d ",Arr[i]);
}

for(i=0;i<N;i++)
{
    if(Arr[i]==0)
    {
        o++;
    }
    else
    {
    }
}
C=i-1;
for(i=0;i<(N-o);i++)
{
    if(Arr[i]==0)
    {
        if(Arr[C-O]!=0)
        {
            Arr[i]=Arr[C-O];
            Arr[C-O]=0;
            O++;
        }
        else
        {
            O++;
            i--;
        }
    }
    else
    {

    }
}
    printf("\n");
for(i=0;i<N;i++)
{
    printf("%d ",Arr[i]);
}
return 0;
}
