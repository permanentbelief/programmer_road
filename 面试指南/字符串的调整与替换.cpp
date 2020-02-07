#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


void replace( char *chas)
{
	int size = strlen(chas);
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (chas[i] == ' ')
			count++;
	}
	int j = size + 2 * count ;
	for (int i = size ; i >= 0; i--)
	{
		if (chas[i] != ' ')
		{
			chas[j] = chas[i];
			j--;
		}
		else
		{
			chas[j] = '0';
			chas[j - 1] = '2';
			chas[j- 2] = '%';
			j -= 3;
		}
	}
}
void modify(string chars)
{
	int start = 0;
	int j = chars.size() - 1;
	for (int i = chars.size() - 1; i >= 0; i--)
	{
		if (chars[i] != '*')
			chars[j--] = chars[i];
	}
	for (int i = j; i >= 0; i--)
	{
		chars[i] = '*';
	}
	
	cout << chars << endl;
}
int main()
{
	/*string str;
	cin >> str;*/
	
	char chas[100] = "acd  da";
	char chas[100];
	gets(chas);
	replace(chas);
	printf("%s\n", chas);
	system("pause");
}