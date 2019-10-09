#define _CRT_SECURE_NO_WARNINGS 1 

// (tR,tC)���Ͻ�����
// (dR,dC)���½����� ���������ֿ�
#include <stdio.h>
void Print(int * matrix[], size_t size)
{

	for (int i = 0; i < size; i++)
	{

		if (i % 4 == 0)
		{
			printf(" \n");
		}
		printf("%2d ", matrix[i]);
	}
	printf("\n");
}
void PrintEdg(int *matrix[], int tr, int tc, int dr, int dc)
{						   //   ��     ��       ��     ��
	//����ά����ֻ��һ��ʱ
	if (dr == 0)
	{
		for (int i = 0; i <= dc; i++)
		{
			printf("%d ", matrix[tr][i]);
		}
	}
	//����ά����ֻ��һ��ʱ
	else if (dc == 0)
	{
		for (int i = 0; i <= dr; i++)
		{
			printf("%d ", matrix[i][tc]);
		}
	}
	//����ά�����ж��ж���ʱ
	else
	{
		int tmptc = tc;
		int tmptr = tr;
		while (tmptc != dc)               // �Ⱥ��Ŵ�ӡ ��һ��
		{
			printf("%d ", matrix[tr][tmptc]);
			tmptc++;
		}
		while (tmptr != dr)               // �����Ŵ�ӡ ���һ��Z
		{
			printf("%d ", matrix[tmptr][dc]);
			tmptr++;
		}

		while (tmptc != tc)
		{
			printf("%d ", matrix[dr][tmptc]);
			tmptc--;
		}
		while (tmptr != tr)
		{
			printf("%d ", matrix[tmptr][tc]);
			tmptr--;
		}
	}

}
void spiralOrderPrint(int *matrix[]) //�б� �б�
{
	int tR = 0;
	int tC = 0;
	int dR = 3;          //���½�λ�ú�����
	int dC = 3;          //���½�λ��������
	while (tR <= dR && tC <= dC)
	{
		PrintEdg(matrix, tR++, tC++, dR--, dC--);
	}

}


int main()
{
	int matrix[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	//for (int i = 0)
	//printf("��ʼ�Ķ�ά����");
	//Print(matrix, sizeof(matrix) / sizeof(int));
	spiralOrderPrint(matrix);

	system("pause");
}