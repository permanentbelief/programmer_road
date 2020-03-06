#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


int main()
{
	string str1;
	string str2;

	while (getline(cin, str1) && getline(cin, str2))
	{
		vector<string> vs;
	    int flag = 0;
		for (int i = 0; i < str1.size(); i++)
		{
			string tmp;
			if (str1[i] == '"')
			{
				flag^= 1;
				continue;
			}
			if (str1[i] == ',' || str1[i] == ' ')
			{
				continue;
			}
			while (i < str1.size() && flag == 1 && str1[i] != ',' && str1[i] != ' ' && str1[i] != '"')
			{
				tmp += str1[i];
				i++;
			}
			while (i < str1.size() && flag == 0 && str1[i] != ',')
			{
				tmp += str1[i];
				i++;
			}
			if (str1[i] == '"')
			{
				flag ^= 1;
			}
			vs.push_back(tmp);

	
			//vs.push_back(tmp);
		}
		for (int i = 0; i < vs.size(); i++)
		{
			cout << vs[i] << endl;

		}
	}
	
}
/*

Joe,Kewell,Leon
Joe
"Letendre, Bruce",Joe,"Quan, William"
William
*/
int main()
{
	string str1;
	string str2;
	while (getline(cin, str1) && getline(cin, str2))
	{
		vector<string> vs;
		int flag = 0;
		for (int i = 0; i < str1.size(); i++)
		{
			string tmp;
			if (flag == 0 && (str1[i] == ',' || str1[i] == ' '))
			{
				continue;
			}
			if (str1[i] == '"')
			{
				flag ^= 1;
			
				i++;
			}
			while (flag == 0 && i < str1.size() && str1[i] != ',')
			{
				tmp += str1[i];
				i++;
			}
			while (flag == 1 && i < str1.size() && str1[i] != '"')
			{
				tmp += str1[i];
				i++;
			}
			if (str1[i] == '"')
			{
				flag ^= 1;
		
			}
			vs.push_back(tmp);
		}

		for (int i = 0; i < vs.size(); i++)
		{
			cout << vs[i] << endl;
		}
	}
}




#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s, res;
	while (getline(cin, s))
	{
		getline(cin, res);
		bool sta = false;
		for (int i = 0; i < s.length(); i++)
		{
			string t;
			if (s[i] == '"')
			{
				i++;
				while (i < s.length() && s[i] != '"')
				{
					t += s[i];
					i++;
				}
				if (t == res)
				{
					sta = true;
					break;
				}
			}
			else if (s[i] != ',')
			{
				while (i < s.length() && s[i] != ',')
				{
					t += s[i];
					i++;
				}
				if (t == res)
				{
					sta = true;
					break;
				}
			}
		}
		if (sta == true)
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}
	return 0;
}

