#include<stdio.h>
#include<math.h>
#include<locale.h>
int main()
{
    setlocale(LC_ALL, "Rus");
	double x,y,t,t1,b,r,T,U,G;
	double g=9.80665, pi=3.14159;
	int a,V,A,B,C,F,D,E;

	printf("Ввод целых чисел");
	printf("\nВведите X координату барьера: ");
	scanf("%d", &A);
	printf("Введите высоту нижнего барьера: ");
	scanf("%d", &B);
	printf("Введите высоту, с которой начинается верхний барьер: ");
	scanf("%d", &C);
	printf("Введите, до какой скорости считает диапазон: ");
	scanf("%d", &D);
	printf("Введите скорость при которой считает диапазон углов: ");
	scanf("%d", &E);
	printf("Введите угол при котором считает диапазон скоростей: ");
	scanf("%d", &F);
    printf("\nВвод дробных чисел (разделитель - запятая)\n");
    printf("Введите толщину барьера: ");
	scanf("%lf", &U);
	printf("Введите шаг времени (чем меньше, тем точнее результат): ");
	scanf("%lf", &T);


    G=U/2;
    V = E;


	FILE *file1;
	FILE *file2;
	FILE *result;
    file1 = fopen("Polet1.txt", "w");
    file2 = fopen("Polet2.txt", "w");
    result = fopen("Result.txt", "w");

    printf("\nРасстояние от начала координат по X - %d\nНижний барьер по Y - %d\nВерхний барьер барьер по Y - %d\n", A, B, C);


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
                    fprintf(file1, "x = %lf\t", x);
                    y=V*sin(b)*t1 - g*t1*t1/2;
                    fprintf(file1, "y = %lf\n", y);
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
                fprintf(file1, "\nСнаряд ударился об барьер\n");
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
                fprintf(file2, "x = %lf\t", x);
                y=V*sin(b)*t1 - g*t1*t1/2;
                fprintf(file2, "y = %lf\n", y);
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
            fprintf(file2, "\nСнаряд ударился об барьер\n");
    }
    printf("\n\n");
    fclose(result);
    fclose(file1);
    fclose(file2);
    system("pause");
	return 0;
}
