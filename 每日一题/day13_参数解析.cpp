#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	/*string str;
	while (getline(cin,str))
	{
	int count = 0;
	vector<string>  v;

	for (int i = 0; i < str.size(); i++)
	{
	while(str[i] == ' ' || str[i] == '\"')
	i++;
	string s(0);
	while (str[i] != ' ')
	{
	s.push_back(str[i]);
	i++;
	}
	v.push_back(s);

	}


	/*int flag = 0;
	if(str[i] == ' ')
	i++;
	if(flag == 0 &&str[i] == '"')
	{
	flag = 1;
	count+=1;
	}
	if(flag == 1 && str[i] =='"')
	{
	flag = 0;
	}

	if(str[i] != ' ')
	{
	count++;
	}
	}
	cout << count << endl;

	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
	{
	cout << v[i] << endl;
	}
	}*/




	string str;
	while (getline(cin, str)) {
		bool flag = false;
		vector<string> vec;
		string row;
		for (int i = 0; i < str.size(); i++) {
			if (flag) {//ÔÚÀ¨ºÅÄÚ
				if (str[i] != '\"') row += str[i];
				else flag = false;
			}
			else {
				if (str[i] == ' ') {
					vec.push_back(row);
					row = "";
				}
				else if (str[i] == '\"') flag = true;
				else row += str[i];
			}
		}
		vec.push_back(row);
		cout << vec.size() << endl;
		for (auto i : vec) cout << i << endl;
	}



	system("pause");
}
