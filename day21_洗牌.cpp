//#define _CRT_SECURE_NO_WARNINGS 1 
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	/*int T = 0;
//	cin >> T;
//	while (T--)
//	{
//	int n = 0;
//	int k = 0;
//	cin >> n >> k;
//	vector<int> left(n, 0);
//	vector<int> right(n, 0);
//	for (int i = 0; i < n; i++)
//	{
//	cin >> left[i];
//	}
//	for (int i = 0; i < n; i++)
//	{
//	cin >> right[i];
//	}*/
//	int k = 2;
//	vector<int> left = { 1, 2, 3 };
//	vector<int>right = { 4, 5, 6 };
//	int n = 3;
//	vector<int>v;
//	while (k--)
//	{
//		v.clear();
//		for (int i = n - 1; i >= 0; i--)
//		{
//			v.push_back(right[i]);
//			v.push_back(left[i]);
//		}
//		/*for (int i = 0; i < n; i++)
//			left[i] = v[i];
//			for (int i = 0; i < n; i++)
//			right[i] = v[i+n];*/
//		for (int i = n - 1; i >= 0; i--)
//			right[n - 1 - i] = v[i];
//		for (int i = 2 * n - 1; i >= n; i--)
//			left[2 * n - 1 - i] = v[i];
//	}
//	for (int i = v.size() - 1; i >= 0; i--)
//	{
//		cout << v[i] << " ";
//	}
////}
//	system("pause");
//}
//
//// 6 3 5 2 4 1
