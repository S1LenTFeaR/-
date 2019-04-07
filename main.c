#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int I,*i,Size;
    short S,*s;
    char C,*c;
    long L,*l;
    float F,*f;
    double D,*d;
    long double Ld,*ld;
    i=&I;
    s=&S;
    c=&C;
    l=&L;
    f=&F;
    d=&D;
    ld=&Ld;
    Size=sizeof(I);
    printf("Size int = %d\n\n",Size);
    Size=sizeof(*i);
    printf("Size *int = %d\n\n",Size);
    Size=sizeof(S);
    printf("Size short = %d\n\n",Size);
    Size=sizeof(*s);
    printf("Size *short = %d\n\n",Size);
    Size=sizeof(C);
    printf("Size char = %d\n\n",Size);
    Size=sizeof(*c);
    printf("Size *char = %d\n\n",Size);
    Size=sizeof(L);
    printf("Size long = %d\n\n",Size);
    Size=sizeof(l);
    printf("Size *long = %d\n\n",Size);
    Size=sizeof(F);
    printf("Size float = %d\n\n",Size);
    Size=sizeof(*f);
    printf("Size *float = %d\n\n",Size);
    Size=sizeof(D);
    printf("Size double = %d\n\n",Size);
    Size=sizeof(*d);
    printf("Size *double = %d\n\n",Size);
    Size=sizeof(Ld);
    printf("Size long double = %d\n\n",Size);
    Size=sizeof(*ld);
    printf("Size *long double = %d\n\n",Size);
    return 0;
}
