//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//
//void DFS(vector<vector<int>>& ret, vector<int>& arr, vector<int> tmp, int curId, int prevPos)
//{
//	if (curId == tmp.size())
//	{
//		ret.push_back(tmp);
//
//	}
//	for (int i = prevPos; i < arr.size(); i++)
//	{
//		tmp.push_back(arr[i]);
//		DFS(ret, arr, tmp,curId+1,i);
//		tmp.pop_back();
//	}
//}
//vector<vector<int>> getFirstUnFormedNum(vector<int> arr)
//{
//	vector<vector<int>> ret;
//	vector<int> tmp;
//	DFS(ret, arr, tmp, 0, 0);
//	return ret;
//}
//
//
//int main()
//{
//
//
//
//	vector<vector<int>> ret = getFirstUnFormedNum({ 1, 2, 3 });
//	for (auto e : ret)
//	{
//		for (auto i : e)
//		{
//			cout << i << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//}
//
