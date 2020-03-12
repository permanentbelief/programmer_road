#define _CRT_SECURE_NO_WARNINGS 1 
#define _CRT_SECURE_NO_WARNINGS 1 

#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<stack>
#include <string>


using namespace std;
int main()
{
	int n = 0;
	while (cin >> n)
	{
		getchar();
		string str;
		getline(cin, str);
		stack<int> si;
		for (int i = 0; i < str.size(); i++)
		{

			if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			{
				int a = si.top();
				si.pop();
				int b = si.top();
				si.pop();
				if (str[i] == '+')
				{
					si.push(a + b);
				}
				else if (str[i] == '-')
				{
					si.push(b - a);
				}
				else if (str[i] == '*')
				{
					si.push(b*a);
				}
				else
				{
					if (a)
						si.push(b / a);
				}
			}
			else if (str[i] >= '0' && str[i] <= '9') //这不一定是个位数 ， 太坑人了
			{
				int sum = 0;
				while (i < str.size() && str[i] >= '0'&& str[i] <= '9')
				{
					
					sum = sum * 10 + (str[i] - '0');
					i++;
				}
				si.push(sum);
			}

		}
		cout << (int)si.top() << endl;
	}
}

