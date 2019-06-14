#include<stdio.h>
#include<math.h>
#include<locale.h>
#define A 50 // X ���������� �������
#define B 40 // ������ ������� �������
#define C 50 // ������, � ������� ���������� ������� ������
#define D 100 // �� ����� �������� �������
#define E 50 //��������, ��� ������ ������� � �)
#define F 50 //����, ��� ������� ������� � �)
#define G 1 //������� �� X ������� � ������ ������� �� ������
#define T 0.001 // ��� ������� (��� ������, ��� ������ ��������� ���������)
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
    printf("\n���������� �� ������ ��������� �� X - %d\n������ ������ �� Y - %d\n������� ������ ������ �� Y - %d\n", A, B, C);

    L=A-G;
    V = E;

    fprintf(result, "���������� �� ������ ��������� �� X - %d\n������ ������ �� Y - %d\n������� ������ ������ �� Y - %d\n", A, B, C);
    fprintf(result, "\n������������ ��������� ����� ��� �������� = %d\n", V);
    printf("\n������������ ��������� ����� ��� �������� = %d\n", V);
    for(a = 0 , x = 0 , y = 0 ; a <= 90 ; a += 1)
    {
        b=pi*a/180;
        t=(2*V*sin(b))/g;
        fprintf(file1, "\n������� ��� ���� = %d ��������\n\n", a);
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
                fprintf(file1, "\n������ �������� ����� ������\n");
            }
            else if(y < 1 && x < A + G)
                fprintf(file1, "\n������ ���� �� �������\n");
            else
            {
                fprintf(file1, "%lf;", L);
                fprintf(file1, "0.0000000\n");
                fprintf(file1, "\n������ �������� �� ������\n");
            }
        }
    a = F;
    printf("\n\n������������ ��������� ��������� ��� ���� = %d\n", a);
    fprintf(result, "\n\n������������ ��������� ��������� ��� ���� = %d\n", a);
    for(V = 0 , x = 0 , y = 0 ; V <= D ; V += 1)
    {
        b=pi*a/180;
        t=(2*V*sin(b))/g;
        fprintf(file2, "\n������� ��� �������� = %d �/�\n\n", V);
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
            fprintf(file2, "\n������ �������� ����� ������\n");
        }
        else if(y < 1 && x < A + G)
            fprintf(file2, "\n������ ���� �� �������\n");
        else
        {
            fprintf(file2, "%lf;", L);
            fprintf(file2, "0.0000000\n");
            fprintf(file2, "\n������ �������� �� ������\n");
        }
    }
    printf("\n");
    fclose(result);
    fclose(file1);
    fclose(file2);
	return 0;
}
