#include<stdio.h>
#include<math.h>
#include<locale.h>
int main()
{
    setlocale(LC_ALL, "Rus");
	float a,x,y,V,t,t1=0,b;
	float g=9.80665, pi=3.14159;
	FILE *koord;
    koord = fopen("koord.txt", "w");

	/* a - ���� � ��������� � ������ ��������
	    x,y - ����������
	    V - ��������� ��������
	    t,t1 - ����� ����� ��������, ������� �����
	    b - ���� � ��������� � ��������
	    g - ��������� ���������� �������
	    pi - ����� ��
	*/

	printf("\n���� ������ (� ��������): ");
	scanf("%f",&a);
	printf("��������� �������� (� �/�): ");
	scanf("%f",&V);
	printf("\n");

	b=pi*a/180;  // ���� � ��������
	t=(2*V*sin(b))/g; // ����� ����� ��������

	for(t1,t;t1<=t;t1=t1+0.01) // ����� ���������
	{
		x=V*cos(b)*t1;
        printf("x: %f\t",x);
        fprintf(koord, "%lf;", x);
        y=V*sin(b)*t1 - g*t1*t1/2;
        printf("y: %f\n",y);
        fprintf(koord, "%lf\n", y);
	}

	x=V*V*sin(2*b)/g; // ��������� ���������� x
	printf("x: %f\t",x);
	printf("y: 0.000000"); // ��������� ���������� y
	printf("\n");
	fclose(koord);
	return 0;
}
