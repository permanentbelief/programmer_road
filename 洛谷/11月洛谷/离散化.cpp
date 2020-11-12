//#define _CRT_SECURE_NO_WARNINGS 1 
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>



using namespace std;

int a[100];
int b[100];
int m, n;

inline void dis()
{
	sort(a + 1, a + 1 + n);

	for (int i = 1; i <= n; i++)
	{
		if (i == 1 || a[i] != a[i - 1])
			b[++m] = a[i];
	}
}
int find(int x)
{
	return lower_bound(b + 1, b + m + 1, x) - b;
}

// C++中的 unique函数，是STL中比较常用的函数， 删除： 必须排序后在unique
// 序列中所有相邻的重复元素(只保留一个)，此处的删除并不是真正的删除，
// 而是位置 被不重复的元素给占领了， 它的删除 指的是相邻的重复元素


// iterator unique(interator it_1, iterator it_2)
// unique返回的是 去重容器中不重复序列的最后一个元素的下一个元素

// 去重的过程就是 把后面不重复的元素移到 前面来，也可以说用不重复的元素占领前面
// 重复元素的位置
vector<int>::iterator my_unique(vector<int>::iterator first, vector<int>::iterator last)
{
	if (first == last)
		return last;

	auto result = first;
	while (++first != last)
	{
		if (!(*result == *first))
		{
			*(++result) = *first;
		}
	}
	return ++result;
}


int main()
{


	vector<int> h = { 1, 2, 2, 3 };
	auto e = my_unique(h.begin(), h.end());
	h.erase(e, h.end());
	for (auto e : h) cout << e << " ";

	cout << endl;

	/*
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
	cin >> a[i];
	}
	dis();
	for(int i = 1; i <= m; i++)
	{
	cout << b[i] << " ";
	}
	cout <<endl;
	*/


}