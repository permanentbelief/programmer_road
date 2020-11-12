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

// C++�е� unique��������STL�бȽϳ��õĺ����� ɾ���� �����������unique
// �������������ڵ��ظ�Ԫ��(ֻ����һ��)���˴���ɾ��������������ɾ����
// ����λ�� �����ظ���Ԫ�ظ�ռ���ˣ� ����ɾ�� ָ�������ڵ��ظ�Ԫ��


// iterator unique(interator it_1, iterator it_2)
// unique���ص��� ȥ�������в��ظ����е����һ��Ԫ�ص���һ��Ԫ��

// ȥ�صĹ��̾��� �Ѻ��治�ظ���Ԫ���Ƶ� ǰ������Ҳ����˵�ò��ظ���Ԫ��ռ��ǰ��
// �ظ�Ԫ�ص�λ��
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