#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <vector>

using namespace std;


//循环太大 75%  复习deque 用deque做
int main()
{
	int array_size;
	int window_size;
	cin >> array_size >> window_size;
	vector<int> v(array_size);
	for (int i = 0; i < array_size; i++)
	{
		cin >> v[i];
	}
	vector<int> v_;

	for (int i = 0; i < v.size() - window_size + 1; i++)
	{
		int max = v[i];
		for (int j = i + 1; j < i + window_size; j++)
		{
			if (max < v[j])
				max = v[j];
		}
		v_.push_back(max);
	}
	for (int i = 0; i < v_.size(); i++)
	{
		cout << v_[i] << " ";
	}
	system("pause");
}



//#include<bits/stdc++.h>
//using namespace std;
//
//deque<int> dq;
//int main() {
//	int n, w;
//	cin >> n >> w;
//	vector<int> a(n);
//
//	for (int i = 0; i<n; ++i) {
//		cin >> a[i];
//	}
//
//	for (int i = 0; i<n; ++i) {
//		while (!dq.empty() && a[dq.back()] <= a[i]) {
//			dq.pop_back();
//		}
//		dq.push_back(i);
//		if (dq.front() == i - w) {
//			dq.pop_front();
//		}
//		if (i >= w - 1) {
//			cout << a[dq.front()] << ' ';
//		}
//
//
//	}
//
//	return 0;
//}