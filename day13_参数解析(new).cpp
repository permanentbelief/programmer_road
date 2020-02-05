#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#include  <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string str;
	while (getline(cin,str))
	{
		vector<string> vs;
		int flag = 0;
		for (int i = 0; i < str.size(); i++)
		{
			string _str;
			if (str[i] == '"')
			{
				flag = -1;
				continue;
			}
			if (flag == -1)  //在" " 之内的字符
			{
				while (i < str.size() && str[i] != '"')
				{
					_str += str[i];
					i++;
				}
				vs.push_back(_str);
				flag = 0;
			}
			else  //flag != -1;
			{
				while (i < str.size() && flag == 0 && str[i] != ' ' && str[i] != '"')
				{
					_str += str[i];
					i++;
				}
				vs.push_back(_str);
			}
			
		}
		for (int i = 0; i < vs.size(); i++)
		{
			cout << vs[i] << endl;
		}
	}
	system("pause");
}
