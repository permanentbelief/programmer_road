#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
using namespace std;


// 窗口值
int main()
{
	int n = 0;
	int w = 0;
	deque<int> dq;
	cin >> n >> w;
	vector<int> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		while (!dq.empty() && a[dq.back()] <= a[i]) //更新最大值，不满足最大的pop出来
		{
			dq.pop_back();
		}
		dq.push_back(i); // 将i值push进双端队列
		// 如果是队列中的元素超过窗口w的大小,且窗口中第一个元素的下标为i-w，要弹出，因为要维护的是w大小
		if (dq.front() == i - w) 
		{
			dq.pop_front();
		}
		// 如果i的值已经达到窗口大小，每一次都要输出窗口中的最大值，也就是最先进入窗口的
		if (i >= w - 1)
		{
			cout << a[dq.front()] << ' ';
		}
	}
	system("pause");
}


//找子数组的差值 小于num的的子数组数量
int GetNum(vector<int> arr, int num)
{
	deque<int> qmax;
	deque<int> qmin;

	int i = 0;
	int j = 0;
	int res = 0;
	while (i < arr.size())
	{
		while (j < arr.size())
		{

			while (!qmin.empty() && arr[qmin.back()] >= arr[j])
			{
				qmin.pop_back();
			}
			qmin.push_back(j);
			while (!qmax.empty() && arr[qmax.back()] <= arr[j])
			{
				qmax.pop_back();
			}
			qmax.push_back(j);

			if (arr[qmax.front()] - arr[qmin.front()] > num)
			{
				break;
			}
			j++;
		}
		if (qmin.front() == i)
			qmin.pop_front();
		if (qmax.front() == i)
			qmax.pop_front();

		res += j - i;
		i++;
	}
	return res;
}
int main()
{
	vector<int> arr = { 1, 3, 6, 9, 5 };
	int num = 7;
	cout << GetNum(arr, num) << endl;
	system("pause");

}