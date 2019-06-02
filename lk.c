#include<stdio.h>
#include<math.h>
int main()
{
	float a,x,y,V,t,t1=0,b,r;
	float g=9.80665, pi=3.14159;

	/* a - угол к горизонту в начале выстрела
	    x,y - координаты
	    V - начальная скорость
	    t,t1 - общее время движения, текущее время
	    b - угол к горизонту в радианах
	    g - ускорение свободного падения
	    pi - число пи
	*/

	printf("\nthe angle of the shot: ");
	scanf("%f",&a);
	printf("initial speed: ");
	scanf("%f",&V);

	b=pi*a/180;  // угол в радианах
	t=(2*V*sin(b))/g; // общее время движения

	if(V==50) // если скорость 50, то барьер не работает
	{
		for(t1,t;t1<=t;t1=t1+0.1) // вывод координат
		{
			x=V*cos(b)*t1;
			printf("x: %f\t",x);
			y=V*sin(b)*t1 - g*t1*t1/2;
			printf("y: %f\n",y);
		}
	}
	else // если скорость не 50, активируется барьер
	{
		for(t1,t;t1<=t/3;t1=t1+0.1) // вывод координат
		{
			x=V*cos(b)*t1;
			printf("x: %f\t",x);
			y=V*sin(b)*t1 - g*t1*t1/2;
			printf("y: %f\n",y);
			r=x; // запомнить последнюю координату
		}
			printf("x: %f\t",r);
			printf("y: 0.000000");
	}

	a=0;x=0;y=0;V=0;t=0;t1=0;b=0;r=0; // очистка переменых

	printf("\nthe angle of the shot: ");
	scanf("%f",&a);
	printf("initial speed: ");
	scanf("%f",&V);

	b=pi*a/180;  // угол в радианах
	t=(2*V*sin(b))/g; // общее время движения

	if(a==50) // если угол 50, то барьер не работает
	{
		for(t1,t;t1<=t;t1=t1+0.1) // вывод координат
		{
			x=V*cos(b)*t1;
			printf("x: %f\t",x);
			y=V*sin(b)*t1 - g*t1*t1/2;
			printf("y: %f\n",y);
		}
	}
	else  // если угол не 50, активируется барьер
	{
		for(t1,t;t1<=t/3;t1=t1+0.1) // вывод координат
		{
			x=V*cos(b)*t1;
			printf("x: %f\t",x);
			y=V*sin(b)*t1 - g*t1*t1/2;
			printf("y: %f\n",y);
			r=x; // запомнить последнюю координату
		}
			printf("x: %f\t",r);
			printf("y: 0.000000");
	}
	return 0;
}








