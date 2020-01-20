//#define _CRT_SECURE_NO_WARNINGS 1 
//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//
//
//// ºÃ·½·¨£¡
//class Gift
//{
//public:
//	int getValue(vector<int> gifts, int n)
//	{
//		map<int, int> count;
//		int middle = gifts.size() / 2;
//		for (auto& e : gifts)
//		{
//			++count[e];
//		}
//		for (auto &e : count)
//		{
//			if (e.second >= middle)
//				return e.first;
//		}
//		return 0;
//	}
//};
//int main()
//{
//	Gift g;
//	cout << g.getValue({ 2, 1, 3, 2, 2 }, 5) << endl;
//	system("pause");
//}
//
////int GCD(int a, int b)
////{
////	int c = 0;
////	while (c = a%b)
////	{
////		a = b;
////		b = c;
////	}
////	return b;
////}
////
////int main()
////{
////	int a = 0;
////	int b = 0;
////	while (cin >> a >> b)
////	{
////		cout << GCD(a, b) << endl;
////	}
////	system("pause");
////}