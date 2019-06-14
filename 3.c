#include<stdio.h>
#include<math.h>
#include<locale.h>
#define A 50 // X координата барьера
#define B 40 // Высота нижнего барьера
#define C 50 // Высота, с которой начинается верхний барьер
#define D 100 // До какой скорости считает
#define E 50 //Скорость, при кторой считает в а)
#define F 50 //Угол, при котором считает в б)
#define G 1 //Толщина по X барьера в каждую сторону от центра
#define T 0.001 // Шаг времени (чем меньше, тем точнее вычисляет программа)
int main()
{
    setlocale(LC_ALL, "Rus");
	double x,y,t,t1,b,r,L;
	double g=9.80665, pi=3.14159;
	int a, V;
	FILE *file1;
	FILE *file2;
	FILE *result;
    file1 = fopen("Polet1.txt", "w");
    file2 = fopen("Polet2.txt", "w");
    result = fopen("Result.txt", "w");
    printf("\nРасстояние от начала координат по X - %d\nНижний барьер по Y - %d\nВерхний барьер барьер по Y - %d\n", A, B, C);

    L=A-G;
    V = E;

    fprintf(result, "Расстояние от начала координат по X - %d\nНижний барьер по Y - %d\nВерхний барьер барьер по Y - %d\n", A, B, C);
    fprintf(result, "\nТестирование диапозона углов при скорости = %d\n", V);
    printf("\nТестирование диапозона углов при скорости = %d\n", V);
    for(a = 0 , x = 0 , y = 0 ; a <= 90 ; a += 1)
    {
        b=pi*a/180;
        t=(2*V*sin(b))/g;
        fprintf(file1, "\nРассчет при угле = %d градусов\n\n", a);
        for( t1 = 0 ; t1 <= t ; t1 += T)
            {
                if((x > A - G && x < A + G) && (y < B || y > C))
                {
                    x=0;
                    t1=t;
                }
                else
                {
                    x=V*cos(b)*t1;
                    fprintf(file1, "%lf;", x);
                    y=V*sin(b)*t1 - g*t1*t1/2;
                    fprintf(file1, "%lf\n", y);
                }
            }
            if(x!=0 && x > A + G)
            {
                printf("a=%d ", a);
                fprintf(result, "a = %d ", a);
                fprintf(file1, "\nСнаряд пролетел через барьер\n");
            }
            else if(y < 1 && x < A + G)
                fprintf(file1, "\nСнаряд упал до барьера\n");
            else
            {
                fprintf(file1, "%lf;", L);
                fprintf(file1, "0.0000000\n");
                fprintf(file1, "\nСнаряд ударился об барьер\n");
            }
        }
    a = F;
    printf("\n\nТестирование диапозона скоростей при угле = %d\n", a);
    fprintf(result, "\n\nТестирование диапозона скоростей при угле = %d\n", a);
    for(V = 0 , x = 0 , y = 0 ; V <= D ; V += 1)
    {
        b=pi*a/180;
        t=(2*V*sin(b))/g;
        fprintf(file2, "\nРассчет при скорости = %d м/с\n\n", V);
        for(t1 = 0 ; t1 <= t ; t1 += T)
        {
            if((x > A - G && x < A + G) && (y < B || y > C))
            {
                x=0;
                t1=t;
            }
            else
            {
                x=V*cos(b)*t1;
                fprintf(file2, "%lf;", x);
                y=V*sin(b)*t1 - g*t1*t1/2;
                fprintf(file2, "%lf\n", y);
            }
        }
        if(x!=0 && x > A + G)
        {
            printf("V=%d ", V);
            fprintf(result, "V = %d ", V);
            fprintf(file2, "\nСнаряд пролетел через барьер\n");
        }
        else if(y < 1 && x < A + G)
            fprintf(file2, "\nСнаряд упал до барьера\n");
        else
        {
            fprintf(file2, "%lf;", L);
            fprintf(file2, "0.0000000\n");
            fprintf(file2, "\nСнаряд ударился об барьер\n");
        }
    }
    printf("\n");
    fclose(result);
    fclose(file1);
    fclose(file2);
	return 0;
}
