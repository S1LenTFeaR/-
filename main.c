#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main()
{
int C=0, i, N=0, Arr[50];
 srand(time(NULL));
for(i=0;i<50;i++)
{
    Arr[i]=(2+rand()%4);
    printf("%d ",Arr[i]);
    if(Arr[i]>2)
    {
    }
    else
    {
        N+=1;
    }
}
printf("\nN=%d",N);
return 0;
}
