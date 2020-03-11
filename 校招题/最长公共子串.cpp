#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


vector<vector<int>> findLongest(string A, int n, string B, int m) {
	vector<vector<int>> vv(n, vector<int>(m, 0));
	vv[0][0] = A[0] == B[0] ? 1 : 0;
	for (int i = 1; i < m; i++)
	{
		//vv[0][i] = max(vv[0][i - 1], A[0] == B[i] ? 1 : 0);
		if (A[0] == B[i])
			vv[0][i] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		//vv[i][0] = max(vv[i - 1][0], A[i] == B[0] ? 1 : 0);
		if (A[i] == B[0])
			vv[i][0] = 1;

	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (A[i] == B[j])
				vv[i][j] = vv[i - 1][j - 1] + 1;
		}
	}
	//int mmax = vv[0][0];
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		mmax = max(vv[i][j], mmax);
	//	}
	//}
	//return mmax;

	return vv;
}
string FindLongest(vector<vector<int>>& ret,string& str1, string& str2)
{
	int mmax = ret[0][0];
	string str;
	int end = 0;
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[0].size(); j++)
		{
			if (ret[i][j] > mmax)
			{
				mmax = ret[i][j];
				end = i;
			}
		}
	}
	// a b c d
	// b c d a
	return str1.substr(end-mmax + 1, mmax);
}
int main()
{
	string str1 = "ABCDFdadsadsa";
		string str2 = "DFdasdahd";
	 vector<vector<int>> out = findLongest(str1, 9, str2, 7) ; 
	 cout << FindLongest(out, str1, str2) << endl;
	system("pause");
}