#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

using namespace std;
// nums����  ���鳤�� ���Լ���maxlen�����ǾͿ����ˣ� ������ֱ�� nums.size()�˰�
int main()
{
	vector<int> nums = { -1, 4, 5, 2, 7, 3 };
	vector<pair<double, double>> vp(nums.size() / 2);
	int idx = 0;
	for (int i = 0; i < nums.size(); i += 2)
	{
		vp[idx++] = { nums[i] - 1.0* nums[i + 1] / 2, nums[i] + 1.0*nums[i + 1] / 2 };
	}
	//cout << vp.size() << endl;
	sort(vp.begin(), vp.end()); // ���ǰ�����߽�ȣ� �������� <


	for (int i = 0; i < vp.size(); i++)
	{
		cout << vp[i].first << " " << vp[i].second << endl;
	}
	if (vp.size() == 1)
	{
		// cout << 2 << endl;
		return 2;
	}
	int max_ = vp[0].second;
	int t = 2; // �ӿڲ����е�t
	int sums = 0;

	for (int i = 1; i < vp.size(); i++)
	{
		if (vp[i].first - vp[i - 1].second > t)
		{
			sums += 2;
		}
		else if (vp[i].first - vp[i - 1].second == t)
		{
			sums += 1;
		}
	}
	cout << sums + 2 << endl;

	system("pause");
}