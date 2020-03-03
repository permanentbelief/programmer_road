#define _CRT_SECURE_NO_WARNINGS 1 


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char str[1000];
//	char sub[1000];
//	while (scanf("%s", str) && scanf("%s", sub))
//	{
//		int count = 0;
//		int i = 0;
//		char* c_str = str;
//		while (*c_str)
//		{
//			char* c_ptr = c_str;//±£´æ×¡c_str
//			char* c_sub = sub;
//			while (*c_str && *c_sub && *c_str == *c_sub)
//			{
//				c_str++;
//				c_sub++;
//			}
//		
//			if (*c_sub == '\0')
//			{
//				count++;
//			}
//			else
//			{
//				c_str = c_ptr + 1;
//			}
//		}
//		printf("%d\n", count);
//	}
//}
		

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		int count = 0;
		int i = 0;

		while (i < str1.size())
		{
			int j = 0;
			int k = i;
			while (i < str1.size() && j < str2.size() && str1[i++] == str2[j++]);

			if (i >= 1 && j >= 1 && j == str2.size() && str1[i-1] == str2[j-1])
			{
				count++;
				continue;
			}
			else
			{
				i = k + 1;

			}
		}
		cout << count << endl;
	}
}
