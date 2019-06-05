#include<stdio.h>
#include<math.h>
#include<locale.h>
int main()
{
    setlocale(LC_ALL, "Rus");
	double a,x,y,t,t1,b,A,X=0;
	double g=9.80665, pi=3.14159;
	int V=50;
    for(a = 0, x = 0, y = 0 ; a <= 90.0 ; a+=0.0001)
    {
        b=pi*a/180;
        t=(2*V*sin(b))/g;

        for(t1 = 0 ; t1 <= t ; t1 += 0.01)
        {
            x=V*cos(b)*t1;
            y=V*sin(b)*t1 - g*t1*t1/2;
        }
        if(X<x)
        {
            X=x;
            A=a;
        }
    }
    printf("\nСамое большое расстояние тело проходит при угле = %lf\n",A);
	return 0;
}
