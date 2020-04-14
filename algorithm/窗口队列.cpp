#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
using namespace std;


// ����ֵ
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
		while (!dq.empty() && a[dq.back()] <= a[i]) //�������ֵ������������pop����
		{
			dq.pop_back();
		}
		dq.push_back(i); // ��iֵpush��˫�˶���
		// ����Ƕ����е�Ԫ�س�������w�Ĵ�С,�Ҵ����е�һ��Ԫ�ص��±�Ϊi-w��Ҫ��������ΪҪά������w��С
		if (dq.front() == i - w) 
		{
			dq.pop_front();
		}
		// ���i��ֵ�Ѿ��ﵽ���ڴ�С��ÿһ�ζ�Ҫ��������е����ֵ��Ҳ�������Ƚ��봰�ڵ�
		if (i >= w - 1)
		{
			cout << a[dq.front()] << ' ';
		}
	}
	system("pause");
}


//��������Ĳ�ֵ С��num�ĵ�����������
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