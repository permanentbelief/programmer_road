//#define _CRT_SECURE_NO_WARNINGS 1 
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
////// 通过
////int main()
////{
////	int n = 0;
////	while (cin >> n)
////	{
////		vector<int> v(n, 0);
////		string str;
////		for (int i = 0; i < n; i++)
////		{
////			cin >> v[i];
////		}
////		vector<int> vj(100000, 1);
////		vj[1] = 1;
////		for (int i = 0; i < v.size(); i++)
////		{
////			for (int j = 2; j <= v[i]; j++)
////			{
////				vj[j] = (vj[j - 1]%10000 + vj[j - 2]%10000)%10000;
////
////			}
////			string s = to_string(vj[v[i]]);
////			int sz = 4 - s.size();
////			for (int i = 0; i < sz; i++)
////			{
////				str += '0';
////			}
////			str += s;
////
////		}
////		cout << str << endl;
////	}
////	system("pause");
////}
//
//// 方法二
//#include <cstdio>
//int main()
//{
//	int n = 0;
//	int fib[10001] = { 0 };
//	fib[0] = 1;
//	fib[1] = 1;
//	int x = 0;
//	for (int i = 2; i < 10001; i++)
//	{
//		fib[i] = (fib[i - 1] % 10000 + fib[i - 2] % 10000) % 10000;
//	}
//	while (scanf("%d", &n) != EOF)
//	{
//		while (n--)
//		{
//			scanf("%d", &x);
//			printf("%05d", fib[x]);
//		}
//		printf("\n");
//	}
//	system("pause");
//}