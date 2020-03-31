#define _CRT_SECURE_NO_WARNINGS 1 
//201301 JAVA 题目2-3级
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int m = 2;
	int n = 2;
	cin >> m;
	cin >> n;
	vector <vector<int>> v((m + 1 ), vector<int>(n + 1 , 0));
	//初始化数组F(i,0)
	for (int i = 1; i < n + 1; i++) //m是行号
	{
		v[0][i] = 1;
		//cout << v[0][i] << " ";

	}
	//初始化数组F(i,0)
	for (int j = 1; j < m + 1 ; j++)
	{
		v[j][0] = 1;
	}
	for (int i = 1; i < m+1 ; i++)
	{
		for (int j = 1; j < n+1 ; j++)
		{
			v[i][j] = v[i - 1][j] + v[i][j - 1];
		}
	}
	cout << v[m ][n ] << endl;
	system("pause");
}