//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//#include <iostream>
//#include <cstring>
//#include <functional>
//using namespace std;
//const int N = 1e5 + 20;
//#include <set>
//
//int n;
//int a[N];
//
//priority_queue<int, vector<int>> q1; //大根堆
//priority_queue<int, vector<int>, greater<int>> q2; //小根堆
//
//
//int main()
//{
//	cin >> n;
//	cin >> a[1];
//	q1.push(a[1]);
//	cout << q1.top() << endl;
//	for (int i = 2; i <= n; i++)
//	{
//		cin >> a[i];
//		int input = a[i];
//		if (input > q1.top()) q2.push(input);
//		else
//			q1.push(input);
//		while (abs((int)q1.size() - (int)q2.size()) > 1)
//		{
//			if (q1.size() < q2.size())
//			{
//				q2.push(q1.top());
//				q1.pop();
//			}
//			else
//			{
//				q1.push(q2.top());
//				q2.pop();
//			}
//		}
//		if (i % 2) cout << (q1.size() > q2.size() ? q1.top() : q2.top()) << endl;
//	}
//	return 0;
//
//}