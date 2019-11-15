#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	int m = 0;
	int n = 0;
	do
	{
		m = num1^num2;
		n = (num1&num2)<<1;
		num1 = m;
		num2 = n;
	} while (num2 != 0);
	printf("%d",num1);
	system("pause");
}