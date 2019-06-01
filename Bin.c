#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>
#include<locale.h>

struct NOTE
{
    char First_Name[30], Second_Name[30];
    int Number;
    int date[3];
};

void VivodStroki(struct NOTE * arr, int row);
FILE* Binar(char* filename, int * count);
void ReadFiles(FILE* bin, struct NOTE* arr, char* answer);
int ReadStrok(FILE* bin, struct NOTE * arr, int row);

int main()
{
    setlocale(LC_ALL, "Rus");
	int count = 0, i = 0; // ��������
	FILE* bin = Binar("NOTE.txt", &count);
	struct NOTE * arr = (struct NOTE *)calloc(count, sizeof(struct NOTE)); // �������� ������ ��� ��������� � �����, count ����� ����� ������ ������� � �����, � ����������� �� � ������� �������
    int row = 0; // ����� ���������
    char answer[12];
	ReadFiles(bin, arr, answer); // ����������� �� �����
	printf("������� � ���������: ");  //���������� ������ �� ������
	scanf("%u", &row);
	if (ReadStrok(bin, arr, row) == 0) // ������� ������ ������, ���� ���������� 0, ������ row > ������ ���������� ��������
		printf("\n������: � ��������� ������ ������������� ��������.");
	else
	{
		VivodStroki(arr, row); // ������� ��������� ������ ��� ������� row
	}

	char First_Name[30]; // ������ ��� �����
	int output = 0; // ���������� ��� �����������, ��� �� ����� ���� �� ����� ��������� NOTE
	printf("������� ���: ");
	scanf("%20s", &First_Name); // ��������� ��� � ���������� ��� (First_Name)
	printf("���������:\n");
	fseek(bin, sizeof(int), SEEK_SET); // ������ � �������� ����� � ����� ������, ����������� ��� �� sizeof(int), ����� ��������� ����� �� ������ ������ ���������
	fread(arr, sizeof(struct NOTE), count, bin); // ������ count (��� ���������) � �����, ��������� ����� ��� � ����� �����
	for (i = 0; i < count; i++)
		if (strcmp(arr[i].First_Name, First_Name) == 0)
		{
			printf("%s %s %d.%d.%d\n", arr[i].First_Name,arr[i].Second_Name, arr[i].date[0], arr[i].date[1], arr[i].date[2]); // ����� ��������� � ������� ������� ��� � ������, ������� �� �����
            if(arr[i].Number!=0)
            	printf("%d\n", arr[i].Number);
            else
                printf("����� �������� �����������\n");
            if (output == 0)
                output = 1; // ������ 1, ����������, ��� ���� ������� ��� ������� ���� ���������� ��������� � �������� �� �����
		}
	if (output == 0) // ���� ������� ���������� �������� �� ����, ������� ��� ���������� ����� ���
		printf("����� ����������� ���\n");

	fclose(bin); // ��������� ����
	return 0; //
}



void VivodStroki(struct NOTE * arr, int row)
{
    setlocale(LC_ALL, "Rus");
	printf("%s ", arr[row - 1].First_Name);
	printf("%s ", arr[row - 1].Second_Name);
	printf("%d.%d.%d\n", arr[row - 1].date[0], arr[row - 1].date[1], arr[row - 1].date[2]);
	if(arr[row - 1].Number!=0)
	printf("%d\n", arr[row - 1].Number);
	else
    printf("����� �������� �����������\n");
}



FILE* Binar(char* filename, int * count)
{
    setlocale(LC_ALL, "Rus");
    int ch, i;
    FILE * file = fopen(filename, "r");
    if (file == NULL) // �� ���������, ������, ��������� ���������
	{
		printf("%s", strerror(errno));
		exit(0);
	}
	fscanf(file, "%u", count); // ��������� ��������������� ������ � ����� ���������� ��������
    struct NOTE * arr = (struct NOTE *)calloc(*count, sizeof(struct NOTE)); // �������� ������
    for (i = 0; i < *count; i++)
	{
		fscanf(file, "%s", arr[i].First_Name);
		fscanf(file, "%s", arr[i].Second_Name);
		fscanf(file, "%d", &arr[i].date[0]);
		fscanf(file, "%d", &arr[i].date[1]);
		fscanf(file, "%d", &arr[i].date[2]);
		fscanf(file, "%d", &arr[i].Number);
	}
    fclose(file);
    FILE* bin = fopen("Bin.txt", "w+b"); // ��������� �������� ����
    fwrite(count, sizeof(int), 1, bin); // ���������� count
    for (i = 0; i < *count; i++)
		fwrite(&arr[i], sizeof(struct NOTE), 1, bin);// ������� ������ ����� � ����� count. ���������� ��� ���������
    fseek(bin, 0, SEEK_SET); // ������������ �� ������.
    free(arr); // ������������ ���������� ������ ��� ������
	return bin;
}

void ReadFiles(FILE* bin, struct NOTE* arr, char* answer)
{
    setlocale(LC_ALL, "Rus");
	// ��������� � ����� � ������
	int i, count = 0;
	fread(&count, sizeof(int), 1, bin); // ������ ���������� �������� � ��������� �����
	for(i = 0; answer[i]; i++)
		answer[i] = tolower(answer[i]); // string.h ����� ��� tolower. ������ ������ � ������ ��������, ������, ����� TyPE ��������� type
	for (i = 0; i < count; i++)
	{ // � ����������� �� ���� ��� �� ��������� ����������� � ��������� ����� � ������������ � ������ �� main
		if (strcmp(answer, "SecondName") == 0)
		{
			fread(arr[i].Second_Name, sizeof(char), 30, bin); // ��������� 1 �������
			fseek(bin, 2 + sizeof(int) + 20*sizeof(char), SEEK_CUR); // ������������� ������ � ������ �������
		}
		else if (strcmp(answer, "FirstName") == 0)
		{
			fseek(bin, 30*sizeof(char), SEEK_CUR); // ������������� ������ �������
			fread(arr[i].First_Name, sizeof(char), 20, bin); // ������ ������
			fseek(bin, 2 + sizeof(int), SEEK_CUR); // ������������� 3 �������
		}
		else if (strcmp(answer, "Year") == 0)
		{
			fseek(bin, 52*sizeof(char), SEEK_CUR); // ������������� ������ � ������ �������
			fread(&arr[i].date[2], sizeof(int), 1, bin); // ������ 3, ��������� ��� ����� � ������ ��������� ���������
		}
	}
	fseek(bin, 0, SEEK_SET); // ����� ������ ������� ���������� � �������� ������, � ������ � ������ ��������� �����
}

int ReadStrok(FILE* bin, struct NOTE * arr, int row)
{
    setlocale(LC_ALL, "Rus");
	// ��������� � ����� � ������
	int count = 0;
	fread(&count, sizeof(int), 1, bin); // ������ ���������� �������� � ��������� �����
	if (row > count)
		return 0; // ���� row ������ ���������� ��������, ���������� 0 - ����
	// �������� ������� ������� ������� 1 �������, �� � ������� ��� ��� �������� 0, ������ row-1
	// �������� ������� ����� 3 �������, ������ 2, � �������� ����� ��� �� ����� ������
	// ������ �� ������������� fseek'�� ��� ��������� (row-1) � ��������� ������
	fseek(bin, (row-1)*sizeof(struct NOTE), SEEK_CUR); // ����������� row-1
	fread(arr + row-1, sizeof(struct NOTE), 1, bin); // ������� �� ���� ��� row � �������� � ������ ��� �������� [row-1]
	fseek(bin, 0, SEEK_SET); // ��������� � ������ ��������� �����
	return 1; // ���������� true ������
}


