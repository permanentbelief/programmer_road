//#define _CRT_SECURE_NO_WARNINGS 1 
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//
//// ͨ���� 47% ��Ҫ���������̫�󣬵����ַ���װ
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
//// ��������ʱ��
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
//  // ��ȷ
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