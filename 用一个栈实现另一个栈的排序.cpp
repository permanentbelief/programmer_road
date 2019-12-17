//#define _CRT_SECURE_NO_WARNINGS 1 
//#include <iostream>
//#include <stack>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//
//	stack<int> s;
//	for (int i = 0; i < n; i++)
//	{
//		int k = 0;
//		cin >> k;
//		s.push(k);
//	}
//	stack<int> s_helper;
//
//	while (!s.empty())
//	{
//		int top = s.top();
//		s.pop();
//		if (s_helper.empty())
//		{
//			s_helper.push(top);
//		}
//		else if (top < s_helper.top())
//		{
//			while (!s_helper.empty() && top < s_helper.top())
//			{
//				s.push(s_helper.top());
//				s_helper.pop();
//		
//			}
//			s_helper.push(top);
//
//		}
//		else if (top >= s_helper.top())
//		{
//			s_helper.push(top);
//		}
//
//	}
//	while (!s_helper.empty())
//	{
//		cout << s_helper.top()<< " ";
//		s_helper.pop();
//	}
//	system("pause");
//}