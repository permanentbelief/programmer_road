//#define _CRT_SECURE_NO_WARNINGS 1 
//#include<iostream>
//#include <vector>
//using namespace std;
//
//int max(int &x1, int &x2)
//{
//	if (x1 > x2)
//	{
//		return x1;
//	}
//	return x2;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int v_n = 0;
//	vector<int> v;
//	for (int i = 0; i <3 * n; i++)
//	{
//		cin >>v_n;
//		v.push_back(v_n);
//	}
//	int sum1 = 0;
//	long long  sum2 = 0;
//	int k = v.size();
//	for (int i = 0; i < k - 1 ; i++)						 // 5 2 8 5 1 5  k = 6
//													 // j = i = 0  j < k - 1 < 5  j < 5
//													 // 
//													 //
//	{
//		for (int j = i  ; j < k -i - 1 ; j++)
//		{
//			if (v[j] >= v[j + 1]) //排成升序
//			{
//				int temp = v[j];
//				v[j] = v[j + 1];
//				v[j + 1] = temp;
//			}
//		}
//	}
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//
//	for (int i = n; i < 2 * n ; i++) // 2  3 
//	{
//		sum1 += v[i];
//	}
//	int count = 0;
//	for (int i = v.size() - 2; i >= 0&&count < n; i -= 2)
//	{
//		sum2 += v[i];  //       max-2  max-1  max  将所有的max-1相加为sum2
//		++count;
//	}
//	cout << sum2 << endl;
//	system("pause");
//}
//
//// 9 3 1 2 3 4 9 8 2
//// 1 2 2 3 3 4 8 9 9
//// 5 2 8 5 1 5
//// 1 2 5 5 5 8
//
