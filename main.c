#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
int C=0, i=0, Sum=0, Arr[20]={-5, 6, -8, -25, -35, -47, 12, 34, 78, -5987, 11, 12, 13, 14, 15, 16, 17, 18, -19, 20};
while (Arr[i] <= 0)
{
    i++;
}
i++;
while (Arr[i] <= 0)
{
    Sum += Arr[i];
    i++;
    printf("Sum+Arr[%d]=%d\t", i, Sum);
}
printf("\nSUM=%d", Sum);
return 0;
}
