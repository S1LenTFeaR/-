#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>
#include<locale.h>
#include "Base.h"
#define YEAR 1900



int Sort(int s, int i, struct NOTE *arr, struct NOTE tmp) //��������� ���������� �� �����
{
    int k, j=0, n=0;
    for(k = 0 ; k < i ; k++)
    {
        arr[k].Date = (arr[k].date[0]) + (arr[k].date[1]*30) + ((arr[k].date[2]-YEAR)*360);
    }
    //������� �������� (���������� �� ���������� n ���� ����� ���� YEAR)
    for(n = 0; n < 200000 ; n++)
    {
        //�������� ������� �������� (������� �� �������� n-��� ����)
        for(k = 0 ; k < i ; k++)
        {
            if(arr[k].Date == n)
            {
                //������ ����� ����������� �������� ������� ���������
                strcpy(tmp.First_Name,arr[j].First_Name);
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
    return arr;
}
