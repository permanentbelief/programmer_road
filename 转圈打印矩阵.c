#define _CRT_SECURE_NO_WARNINGS 1 

// (tR,tC)左上角坐标
// (dR,dC)右下角坐标 都减减到分开
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
{						   //   横     纵       横     纵
	//当二维数组只有一行时
	if (dr == 0)
	{
		for (int i = 0; i <= dc; i++)
		{
			printf("%d ", matrix[tr][i]);
		}
	}
	//当二维数组只有一列时
	else if (dc == 0)
	{
		for (int i = 0; i <= dr; i++)
		{
			printf("%d ", matrix[i][tc]);
		}
	}
	//当二维数组有多行多列时
	else
	{
		int tmptc = tc;
		int tmptr = tr;
		while (tmptc != dc)               // 先横着打印 第一排
		{
			printf("%d ", matrix[tr][tmptc]);
			tmptc++;
		}
		while (tmptr != dr)               // 在竖着打印 最后一列Z
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
void spiralOrderPrint(int *matrix[]) //行标 列标
{
	int tR = 0;
	int tC = 0;
	int dR = 3;          //右下角位置横坐标
	int dC = 3;          //右下角位置纵坐标
	while (tR <= dR && tC <= dC)
	{
		PrintEdg(matrix, tR++, tC++, dR--, dC--);
	}

}


int main()
{
	int matrix[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	//for (int i = 0)
	//printf("初始的二维数组");
	//Print(matrix, sizeof(matrix) / sizeof(int));
	spiralOrderPrint(matrix);

	system("pause");
}