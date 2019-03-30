#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
int C=0, i, Arr[20];
printf("\n Array containing 20 Random Numbers\n");
srand(time(NULL));
for(i=0;i<20;i++)
{
    Arr[i]=rand();
    printf("%d\n",Arr[i]);
    if(abs(C) >= abs(Arr[i]))
    {
    }
    else
    {
        C=Arr[i];
    }
}
printf("MAX=%d", C);
return 0;
}
