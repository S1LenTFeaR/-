#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int N=0, i=0;
    char *A, *B, C, Arr[]="If we cannot do as we would we";
    N = strlen(Arr);
    N--;
    A=&Arr[0];
    B=&Arr[N];
    printf("%s\n", Arr);
    for(i=0;i<N;i++)
    {
        if(i<N-i)
        {
            C=*A;
            *A=*B;
            *B=C;
            A++;
            B--;
        }
        else
        {
            i++;
        }
    }
    printf("%s\n", Arr);
    return 0;
}
