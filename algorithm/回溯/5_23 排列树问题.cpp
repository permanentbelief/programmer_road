//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//
//double min_ = INT_MAX;
//void dfs(vector<int> & v, vector<int> temp, vector<bool>& vb)
//{
//	if (temp.size() == v.size())
//	{
//		double sums = 0.0;
//		for (int i = 0; i < temp.size() - 1; i++)
//		{
//			sums += sqrt((temp[i]+temp[i+1])*(temp[i]+temp[i+1])- (temp[i]- temp[i+1])*(temp[i] - temp[i+1]));
//		}
//		sums += temp[0];
//		sums += temp[temp.size() - 1];
//		min_ = min(min_, sums);
//	}
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (i > 0 && v[i] == v[i - 1] && vb[i - 1] == false)
//		{
//			continue;
//		}
//		if (vb[i] == false)
//		{
//			vb[i] = true;
//			temp.push_back(v[i]);
//			dfs(v, temp,vb);
//			vb[i] = false;
//			temp.pop_back();
//		}
//	}
//}
//int main()
//{
//	vector<int> v = {1,1,2};
//	vector<bool> books(v.size());
//	vector<int> temp;
//	dfs(v,vector<int>(), books);
//	printf("%.5lf", min_);
//	system("pause");
//}