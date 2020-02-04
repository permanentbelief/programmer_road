#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
#include <iostream>
#include <string>
using namespace std;
bool Is_(string &s) //判断是否为回文
{
	int i = 0;
	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - i - 1])
			return false;
	}
	return true;
}
int main()
{
	string a;
	string b;
	getline(cin, a);
	getline(cin, b);
	int count = 0;
	for (int i = 0; i < a.size(); i++)
	{
		string ret(a);
		if (Is_(ret.insert(i, b)))
			count++;
	}
	if (Is_(a += b))
		count++;
	cout << count << endl;
	system("pause");
}


int StrToInt(string str) {
	if (str.empty())
		return 0;
	int flag = 0;
	int i = 0;
	double sum = 0;
	if (str[i] == '-')
	{
		flag = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (i < str.size())
	{
		while (i < str.size() && str[i] == ' ')
			i++;
		if (str[i] > '9' || str[i] < '0')
			return 0;
		while (i < str.size() && str[i] >= '0'&&str[i] <= '9')
		{
			sum = sum * 10 + (str[i] - '0');
			i++;
		}

	}
	if ((flag == -1 && (0 - sum) < INT_MIN) || (flag == 0 && sum  > INT_MAX))
		return 0;
	if (flag == -1)
		sum = 0 - sum;
	return sum;
}


int addAB(int A, int B) {
	int sum = 0, carry = 0;
	while (B != 0){
		对应位的和
		sum = A^B;
		对应位和的进位，既然是进位，就要整体左移一位
		carry = (A&B) << 1;
		A = sum;
		B = carry;
	}
	return sum;
}
int main()
{
	string str("-2147483649");
	cout << addAB(3,5)<< endl;
	system("pause");
}