#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <sstream>
using namespace std;

//unordered_map<char, int> map;
//int main()
//{
//	string str;
//	getline(cin, str);
//	int k = 0;
//	int max_boy = 0;
//	int max_girl = 0;
//	while ( (k = str.find("boy")) != -1)
//	{
//		for (int i = k; i <= k + 2; i++)
//		{
//			str[i] = '.';
//		}
//		max_boy++;
//	}
//	while ( (k = str.find("girl")) != -1)
//	{
//		for (int i = k; i <= k + 3; i++)
//		{
//			str[i] = '.';
//		}
//		max_girl++;
//	}
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] == 'g' || str[i] == 'i' || str[i] == 'r' || str[i] == 'l')
//		{
//			max_girl++;
//		}
//		else if (str[i] != '.')
//		{
//			max_boy++;
//		}
//	}
//	//string str = "......boy...girl";
//	//cout << str.find("boy") << endl;
//
//
//	cout << max_boy << endl;
//	cout << max_girl << endl;
//	system("pause");
//	return 0;
//}

string get_str(int i)
{
	stringstream ss;
	ss << i;
	string str;
	ss >> str;
	return str;
}

const int N = 210;
char a[210];
char c[40000];
int n;
int main()
{
	scanf("%s",a);
     n = strlen(a);
	 strcat(c, a);
	
	for (int i = 2; i <= n; i++)
	{
		scanf("%s", a);
		strcat(c, a);
	}
//	fflush(stdout);
	//getchar();
	cout << n << " ";
	
	for (int i = 0, sum = 0, ch = '0'; i <= strlen(c); i++)
	{
		if (ch == c[i])
		{
			sum++;
		}
		else
		{
			ch = c[i];
			printf("%d ", sum);
			sum = 1;
		}
	}
	system("pause");
}
/*
0001000
0001000
0001111
0001000
0001000
0001000
1111111

*/