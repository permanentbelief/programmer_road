#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str1;
	string str2;
	cin >> str1 >> str2;
	int  m = str1.size();
	int n = str2.size();
	vector<vector<int>> v(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++)
	{
		if (str1[i] == str2[0])
		{
			v[i][0] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (str2[i] == str1[0])
		{
			v[0][i] = 1;
		}
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (str1[i] == str2[j])
			{
				v[i][j] = v[i - 1][j - 1] + 1;
			}
		}
	}
	int max = v[0][0];
	int flag = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (max  < v[i][j])
			{
				max = v[i][j];
				flag = i;

			} // abcde  5 4
		}
	}
	cout << str1.substr(flag- max + 1  ,max) << endl;
	system("pause");
}


//yrtqyfxyrmbasfmkbuudetaahxxgvcpkfhlkfxtjvguizsmwbnwamftshffyzumqfzqvirxgjjuocobvhvgstvrynduavkvntvxgnravjyfjkycguqyrnbnwnoqvhh

//xxzjrwyqtgzfgxyitvszmltcsdjweeycqgzsazahpqrvlgvwexcfwkusmuyltvtbjftkvwebmjctwbfcxfimoevbquznojlzkxygruhebhostshenguhymzjxhkjstiwzgyudtfeddgqlegxesngnlbubkhzfmspalfajiqsvohghxhswjiimnyazfmgqazdewfptldiilrwkhuntvseohykutjecuhg

