#include<stdio.h>
#include<math.h>
#include<locale.h>
#define A 50 // X координата барьера
#define B 40 // Высота нижнего барьера
#define C 50 // Высота, с которой начинается верхний барьер
#define D 100 // До какой скорости считает
#define E 50 //Скорость, при кторой считает в а)
#define F 50 //Угол, при котором считает в б)
#define G 0.1 //Погрешность X барьера
int main()
{
    setlocale(LC_ALL, "Rus");
	double x,y,t,t1,b,r;
	double g=9.80665, pi=3.14159;
	int a, V;
    printf("\nРасстояние от начала координат по X - %d\nНижний барьер по Y - %d\nВерхний барьер барьер по Y - %d\n", A, B, C);

	//барьер расположен на x=60 b y<=50 и y>=90 (свободное окно при у > 50 && y<90)

    V = E;
    printf("\nТестирование диапозона углов при скорости = %d\n", V);
    for(a = 0 , x = 0 , y = 0 ; a <= 90 ; a += 1)
    {
        b=pi*a/180;
        t=(2*V*sin(b))/g;
        for( t1 = 0 ; t1 <= t ; t1 += 0.00001)
            {
                if((x > A - G && x < A + G) && (y < B || y > C))
                {
                    x=0;
                    t1=t;
                }
                else
                {
                    x=V*cos(b)*t1;
                    y=V*sin(b)*t1 - g*t1*t1/2;
                }
            }
            if(x!=0 && x > A)
            {
                printf("a=%d ", a);
            }
        }
    a = F;
    printf("\n\nТестирование диапозона скоростей при угле = %d\n", a);
    for(V = 0 , x = 0 , y = 0 ; V <= D ; V += 1)
    {
        b=pi*a/180;
        t=(2*V*sin(b))/g;
        for(t1 = 0 ; t1 <= t ; t1 += 0.00001)
        {
            if((x > A - G && x < A + G) && (y < B || y > C))
            {
                x=0;
                t1=t;
            }
            else
            {
                x=V*cos(b)*t1;
                y=V*sin(b)*t1 - g*t1*t1/2;
            }
        }
        if(x!=0 && x > A)
        {
            printf("V=%d ", V);
        }
    }
    printf("\n");
	return 0;
}
