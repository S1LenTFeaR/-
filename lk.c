#include<stdio.h>
#include<math.h>
int main()
{
	float a,x,y,V,t,t1=0,b,r;
	float g=9.80665, pi=3.14159;

	/* a - ���� � ��������� � ������ ��������
	    x,y - ����������
	    V - ��������� ��������
	    t,t1 - ����� ����� ��������, ������� �����
	    b - ���� � ��������� � ��������
	    g - ��������� ���������� �������
	    pi - ����� ��
	*/

	printf("\nthe angle of the shot: ");
	scanf("%f",&a);
	printf("initial speed: ");
	scanf("%f",&V);

	b=pi*a/180;  // ���� � ��������
	t=(2*V*sin(b))/g; // ����� ����� ��������

	if(V==50) // ���� �������� 50, �� ������ �� ��������
	{
		for(t1,t;t1<=t;t1=t1+0.1) // ����� ���������
		{
			x=V*cos(b)*t1;
			printf("x: %f\t",x);
			y=V*sin(b)*t1 - g*t1*t1/2;
			printf("y: %f\n",y);
		}
	}
	else // ���� �������� �� 50, ������������ ������
	{
		for(t1,t;t1<=t/3;t1=t1+0.1) // ����� ���������
		{
			x=V*cos(b)*t1;
			printf("x: %f\t",x);
			y=V*sin(b)*t1 - g*t1*t1/2;
			printf("y: %f\n",y);
			r=x; // ��������� ��������� ����������
		}
			printf("x: %f\t",r);
			printf("y: 0.000000");
	}

	a=0;x=0;y=0;V=0;t=0;t1=0;b=0;r=0; // ������� ���������

	printf("\nthe angle of the shot: ");
	scanf("%f",&a);
	printf("initial speed: ");
	scanf("%f",&V);

	b=pi*a/180;  // ���� � ��������
	t=(2*V*sin(b))/g; // ����� ����� ��������

	if(a==50) // ���� ���� 50, �� ������ �� ��������
	{
		for(t1,t;t1<=t;t1=t1+0.1) // ����� ���������
		{
			x=V*cos(b)*t1;
			printf("x: %f\t",x);
			y=V*sin(b)*t1 - g*t1*t1/2;
			printf("y: %f\n",y);
		}
	}
	else  // ���� ���� �� 50, ������������ ������
	{
		for(t1,t;t1<=t/3;t1=t1+0.1) // ����� ���������
		{
			x=V*cos(b)*t1;
			printf("x: %f\t",x);
			y=V*sin(b)*t1 - g*t1*t1/2;
			printf("y: %f\n",y);
			r=x; // ��������� ��������� ����������
		}
			printf("x: %f\t",r);
			printf("y: 0.000000");
	}
	return 0;
}








