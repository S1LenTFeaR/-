#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>
#include<locale.h>
#include "Base.h"
#define YEAR 1900



int note(int s, struct NOTE *arr) //���� � ���������� � ������� ��� �������� ����������� �����������
{
    setlocale(LC_ALL, "Rus");
    FILE *file;
    file = fopen("NOTE.txt", "a+");
    if (file==NULL)
        printf("���� �� ������� �������\n");
    else
        printf("���� ������� ������\n");
    int k=0;

     for(k = 0 ; k < s ; k++)
    {
        printf("�������� %d:\n",k+1);
        printf("������� ���: ");
        scanf("%8s",arr[k].First_Name);
        printf("������� �������: ");
        scanf("%8s",arr[k].Second_Name);
        printf("������� ���� ��������: ");
        scanf("%8d",&arr[k].date[0]);
        printf("������� ����� ��������: ");
        scanf("%8d",&arr[k].date[1]);
        printf("������� ��� ��������: ");
        scanf("%8d",&arr[k].date[2]);
        printf("������� ����� ��������: ");
        scanf("%8d",&arr[k].Number);
    }

    for(k = 0 ; k < s ; k++)
    fprintf(file, "%s %s %d %d %d %d\n", arr[k].First_Name, arr[k].Second_Name, arr[k].date[0], arr[k].date[1], arr[k].date[2], arr[k].Number);

    fclose(file);
    return arr;
}
