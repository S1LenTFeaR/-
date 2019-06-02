#include<stdio.h>
#include<math.h>
int main()
{
	float a,x,y,V,t,t1=0,b;
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

	for(t1,t;t1<=t;t1=t1+0.1) // вывод координат
	{
		x=V*cos(b)*t1;
		printf("x: %f\t",x);
		y=V*sin(b)*t1 - g*t1*t1/2;
		printf("y: %f\n",y);
	} 
	
	x=V*V*sin(2*b)/g; // последняя координата x
	printf("x: %f\t",x);
	printf("y: 0.000000"); // последняя координата y 
	return 0;
}
	