#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

bool isValid(string s,  string exp)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '*' || s[i] == '.')
			return  false;
	}
	for (int i = 0; i < exp.size(); i++)
	{
		if (exp[i] == '*' && (i == 0 || exp[i - 1] == '*'))
			return false;
	}
	return true;
}
bool process(string str, string exp, int sIdex, int eIdex)
{
 	if (eIdex == exp.size()) //ע�����������ж�exp����ƥ������ַ����Ƿ񵽽�β
							 //�п��ܳ��� a      ..*  ���Ƶ����
		return str.size() == sIdex;
	if (eIdex + 1 == exp.size() || exp[eIdex + 1] != '*')
	{
		return sIdex != str.size() && (exp[eIdex] == str[sIdex] || exp[eIdex] == '.')
			&& process(str, exp, sIdex + 1, eIdex + 1);
	}
	while (sIdex != str.size() && (exp[eIdex] == str[sIdex] || exp[eIdex] == '.'))
	{
		if (process(str, exp, sIdex, eIdex + 2))
			return true;
		sIdex++;
	}
	return process(str, exp, sIdex, eIdex + 2);
}


bool isMatch(string str, string exp)
{
	if (str.empty() || exp.empty())
		return false;
	return isValid(str, exp) && process(str, exp, 0, 0);
}

int main()
{
	string str1 = "aaaaa";
	string str2 = "a*b";

	
	cout << isMatch(str1, str2) << endl;
	
	system("pause");

}