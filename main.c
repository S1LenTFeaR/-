#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
int Arr[9],i,O[10],C[10],c=0,o=0,cc=0,oo=0;
srand(time(NULL));
for(i=0;i<9;i++)
{
    Arr[i]=rand()%5;
    printf("%d ",Arr[i]);
}
printf("\n");
for(i=0;i<9;i++)
{
    if(Arr[i]==0)
    {
        O[o]=Arr[i];
        o++;
    }
    else
    {
        C[c]=Arr[i];
        c++;

    }
}
cc=c;
oo=o;
for(c=0;c<cc;c++)
{
    printf("%d ",C[c]);
}
for(o=0;o<oo;o++)
{
    printf("%d ",O[o]);
}

return 0;
}
