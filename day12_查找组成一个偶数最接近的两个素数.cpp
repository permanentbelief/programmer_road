//#define _CRT_SECURE_NO_WARNINGS 1 
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int num = 20;
//	while (cin >> num)
//	{
//		vector<int> v;
//		
//		for (int i = 3; i < num; i++)
//		{
//			int flag = 0;
//			for (int j = i-1;j > 1; j--)
//			{
//				if (i % j == 0)
//				{
//					flag = 1;
//					break;
//				}
//					
//			}
//			if (flag == 0)
//			{
//				v.push_back(i);
//			}
//			
//		}
//		int start = 0;
//		int end = v.size() - 1;
//		int flag1 = start;
//		int flag2 = end;
//		//v中存在的是最大数小于num的素数
//		int min = v.size() * 2 - 1;
//		for (int i = 0; i < v.size(); i++)
//		{
//			for (int j = i + 1; j < v.size(); j++)
//			{
//				if ((v[i] + v[j] ) == num)
//				{
//					if (i + j < min)
//					{
//						flag1 = v[i];
//						flag2 = v[j];
//					}
//
//				}
//			}
//		}
//		cout << flag1 << endl;
//		cout << flag2 << endl;
//
//	}
//	system("pause");
//
//}