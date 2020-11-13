#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;


// À¨ºÅÐòÁÐ Ë«Õ»
//int w[110];
//char s[110], c[110];
//string a;
//int top;
//
//
//int main()
//{
//	cin >> a;
//	int n = a.size();
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] == '(' || a[i] == '[')
//		{
//			s[++top] = a[i];
//			w[top] = i;
//			if (a[i] == '(') c[i] = ')';
//			else c[i] = ']';
//		}
//		if (a[i] == ')')
//		{
//			if (top && s[top] == '(')
//			{
//				c[w[top]] = ' ';
//				top--;
//			}
//			else
//			{
//				c[i] = '(';
//
//			}
//		}
//		if (a[i] == ']')
//		{
//			if (top && s[top] == '[')
//			{
//				c[w[top]] = ' ';
//				top--;
//			}
//			else
//				c[i] = '[';
//		}
//	}
//	for (int i = 0; i<n; i++)
//	{
//		if (c[i] == '(' || c[i] == '[') printf("%c%c", c[i], a[i]);
//		else if (c[i] == ')' || c[i] == ']') printf("%c%c", a[i], c[i]);
//		else printf("%c", a[i]);
//	}
//	cout << endl;
//	system("pause");
//}
