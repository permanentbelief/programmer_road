#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str("123abcd");
	int max = -1;
	int flag = -1;
	int flag1 = -1;
	for (int i = 0; i < str.size() - 1; i++)
	{
		int count = 0;
		while (i <str.size() - 1 && str[i + 1] - str[i] == 1) //1234
		{
			count++;
			i++;
		}
		if (count > max)
		{
			max = count;
			flag = i - count;
		}

	}
	for (int i = flag; i <= flag+max; i++)
	{
		cout << str[i];
	}
	system("pause");
}