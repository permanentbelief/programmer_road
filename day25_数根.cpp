//#define _CRT_SECURE_NO_WARNINGS 1 
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//
//// 通过率 47% 主要是输入的数太大，得用字符串装
////int main()
////{
////	long long  i = 0; 
////	while (cin >> i)
////	{
////		
////			long long sum = 0;
////			while (i > 0)
////			{
////				sum += (i % 10);
////				i /= 10;	
////			}
////			while (sum > 9)
////			{
////				i = sum;
////				sum = 0;
////				while (i > 0)
////				{
////					sum += (i % 10);
////					i /= 10;
////				}
////			}
////		cout << sum << endl;
////	}
////	system("pause");
////}
//
//// 超出运行时间
////int main()
////{
////	string str;
////	while (cin >> str)
////	{
////
////		long long sum = 0;
////		int i = str.size();
////		while (i--)
////		{
////			
////			sum += str[i] - '0';
////		}
////		while (sum > 9)
////		{
////			string tmp = to_string(sum);
////			sum = 0;
////			int sz = tmp.size();
////			while (sz--)
////			{
////				sum += str[sz] - '0';
////			}
////		}
////		cout << sum << endl;
////	}
////	system("pause");
////}
//  // 正确
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//
//		long long sum = 0;
//		int i = str.size();
//		while (i--)
//		{
//
//			sum += str[i] - '0';
//		}
//		while (sum > 9)
//		{
//			int t = sum;
//			sum = 0;
//			while (t > 0)
//			{
//				sum += t % 10;
//				t = t / 10;
//			}
//
//		}
//		cout << sum << endl;
//	}
//	system("pause");
//}