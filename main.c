#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define N 3 //������������ ���������� ����������
#define YEAR 1990 //���, � �������� ���������� ����������
struct NOTE
{
    char First_Name[9], Second_Name[9];
    int Number;
    int date[3];
    int Date
} arr[N], tmp;

int main()
{
    setlocale(LC_ALL, "Rus");

    int k, n, j = 0;


    for(k = 0 ; k < N ; k++)
    {
        printf("�������� %d:\n",k+1);
        printf("������� ���: ");
        scanf("%8s",arr[k].First_Name);
        printf("������� �������: ");
        scanf("%8s",arr[k].Second_Name);
        printf("������� ����� ��������: ");
        scanf("%8d",&arr[k].Number);
        printf("������� ���� ��������: ");
        scanf("%8d",&arr[k].date[0]);
        printf("������� ������ ��������: ");
        scanf("%8d",&arr[k].date[1]);
        printf("������� ��� ��������: ");
        scanf("%8d",&arr[k].date[2]);
    }

    //������� ���������� ���� ����� ���� YEAR ��� ������� ��������� ������
    for(k = 0 ; k < N ; k++)
    {
        arr[k].Date = (arr[k].date[0]) + (arr[k].date[1]*30) + ((arr[k].date[2]-YEAR)*360);
    }
    //������� �������� (���������� �� ���������� n ���� ����� ���� YEAR)
    for(n = 0; n < 50000 ; n++)
    {
        //�������� ������� �������� (������� �� �������� n-��� ����)
        for(k = 0 ; k < N ; k++)
        {
            if(arr[k].Date == n)
            {
                //������ ����� ����������� �������� ������� ���������
                strcpy(tmp.First_Name,arr[j].First_Name );
                strcpy(tmp.Second_Name,arr[j].Second_Name);
                tmp.Number = arr[j].Number;
                tmp.date[0] = arr[j].date[0];
                tmp.date[1] = arr[j].date[1];
                tmp.date[2] = arr[j].date[2];
                tmp.Date = arr[j].Date;
                //�������� ������� ������� ���������
                strcpy(arr[j].First_Name , arr[k].First_Name);
                strcpy(arr[j].Second_Name , arr[k].Second_Name);
                arr[j].Number = arr[k].Number;
                arr[j].date[0] = arr[k].date[0];
                arr[j].date[1] = arr[k].date[1];
                arr[j].date[2] = arr[k].date[2];
                arr[j].Date = arr[k].Date;
                j++;
                //���������� �������� ����������� �������� ������� ��������� �� ����� k
                strcpy(arr[k].First_Name , tmp.First_Name);
                strcpy(arr[k].Second_Name , tmp.Second_Name);
                arr[k].Number=tmp.Number;
                arr[k].date[0]=tmp.date[0];
                arr[k].date[1]=tmp.date[1];
                arr[k].date[2]=tmp.date[2];

                arr[k].Date=tmp.Date;
            }
            else
            {
            }

        }

    }

    printf("\n---------------------------------------------\n");
    //����� ��������������� �� ����� ������
    for(k = 0 ; k < N ; k++)
    {
        printf("��� - %s, ������� - %s\n", arr[k].First_Name, arr[k].Second_Name);
        //��������, ��� �� ������ ����� �������� (���� 0 -���, ���� ���� ����� - ������� ������)
        if(arr[k].Number!=0)
        {
            printf("����� ��������: %d\n", arr[k].Number);
        }
        else
        {
            printf("����� �������� �� ������\n");
        }
        printf("���� ��������: %d.%d.%d\n", arr[k].date[0], arr[k].date[1], arr[k].date[2]);
        printf("---------------------------------------------\n");
    }

    return 0;
}


