//#define _CRT_SECURE_NO_WARNINGS 1 
//
// ţ�͹�����
//#include <iostream>
//#include <vector>
//#include  <string>
//using namespace std;
//
//int main()
//{
//	string str;
//	int key = 0;
//	int N = 0;
//	vector<int> v;
//	cin >> N >> key;
//	for (int i = 0; i < N; i++)
//	{
//		int k = 0;
//		cin >> k;
//		v.push_back(k);
//	}
//	int max = 0;
//	for (int i = 0; i < v.size(); i++)
//	{
//		int sum = 0;
//		for (int j = i; j < v.size(); j++)
//		{
//			sum += v[j];
//			if (sum == key)
//			{
//				max = max >(j - i + 1) ? max : j - i;
//				break;
//			}
//		}
//
//	}
//	cout << max << endl;
//	system("pause");
//}
// ͨ�����в������� 100%
//#include<iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//#define N 100005
//int  main()
//{
//	long n, k;
//	cin >> n >> k;
//	vector<long>v(n + 1);
//	for (int i = 1; i <= n; ++i)
//		cin >> v[i];
//	long long temp;
//	int ans = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		temp = 0;
//		for (int j = i; j <= n; ++j)
//		{
//
//
//			temp += v[j];
//			if (temp == k)
//				ans = max(ans, j - i + 1);
//
//		}
//
//		// �ⲽ�ܹؼ�  �ο����е�˼·  ����֦ ʱ���Ż�  ��Ȼֻ��70%
//		if (ans> n - i)
//			break;
//	}
//	cout << ans << endl;
//	system("pause");
//	return 0;
//}