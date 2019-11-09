#define _CRT_SECURE_NO_WARNINGS 1 
//#include <stdio.h>
//#include <string.h>
//
//int Max(int a, int b)
//{
//	if (a > b)
//		return a;
//	else
//		return b;
//}
//int main()
//{
//	char str[256] = { 0 };
//	scanf("%s", &str);
//	int len = strlen(str);
//	int max = 0;
//	int count = 0;
//	for (int i = 0; i < len; i++)
//	{
//		int begin = i;
//		count = 0;
//		while ((begin + 1)<len && (str[begin + 1] - str[begin]) == 1)
//		{
//			begin++;
//			count++;
//		}
//		max = Max(count, max);
//	}
//	return max;
//}
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char str[256];
//	scanf("%s", str);
//	int max = 0;
//	char* temp = str;
//	char* tmp = str;
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		char * begin = &str[i];
//		int count = 0;
//		while (*(begin + 1) != '\0' && (*begin + 1) - *(begin) == 1)
//		{
//			begin++;
//			count++;
//		}
//		if (count > max)
//		{
//			max = count;
//			temp = begin;
//		}
//	}
//	printf("%s",temp);
//	system("pause");
//}
#include <stdio.h>
#include <string.h>
int main()
{
	char str[256] = { 0 };
	char Index[256] = { 0 };
	scanf("%s", str);
	int len = strlen(str);
	int k = 0;
	for (int i = 0; i < len - 1; i++)
	{
		Index[k] = i; //直到最后一个k 的时候走到 数值的下一位 ， 并置上'\0’
		k++;
		int count = 0;
		while (str[i + 1] != '\0' && str[i + 1] - str[i] == 1)
		{
			i++;
		}

	}
	Index[k] = '\0';
	printf("k: %d Index[k]:%d\n", k, Index[k-1]);
	int count_len = strlen(Index);
	printf("%d\n", count_len); //!!!这里有问题 第一个Index[0] = 0以后 Index的长度都是0 进行不下去运算
	if (/*count_len == 1&&Index[k-1] == 0*/count_len == 0 ) //Index[0] = 0;
	{
		printf("%s", str);
	}
	int max = Index[1] - Index[0];
	int j = 0;
	for (int i = 1; i < count_len - 1; i++)
	{
		if (Index[i + 1] - Index[i] > max)
		{
			max = Index[i + 1] - Index[i];
			j = i;
		}
	}
	for (int i = j; i < j + max; i++)
	{
		printf("%c", str[i]);
	}
	system("pause");
}