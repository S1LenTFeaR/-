#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
int C=8, O=0, o=0, i, Arr[9];
srand(time(NULL));
for(i=0;i<9;i++)
{
    Arr[i]=rand()%5;
    printf("%d ",Arr[i]);
}

for(i=0;i<9;i++)
{
    if(Arr[i]==0)
    {
        o++;
    }
    else
    {
    }
}
for(i=0;i<(9-o);i++)
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
            Arr[i]=Arr[C-O];
            Arr[C-O]=0;
        }
    }
    else
    {

    }
}
    printf("\n");
for(i=0;i<9;i++)
{
    printf("%d ",Arr[i]);
}
return 0;
}
