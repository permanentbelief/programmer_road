#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int manhattan_dist(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x1) + abs(y2 - y1);
}


//���������ӵ��㣨x0,y0)�������پݵ�
int get_dist_sum(int x0, int y0, const vector<int> &X, const vector<int>&Y, int k)
{
	int n = X.size();
	vector<int> dists(n);
	for (int i = 0; i < n; i++)
	{
		dists[i] = manhattan_dist(x0, y0, X[i], Y[i]);
	}
	sort(dists.begin(), dists.end());

	//��vector�еĵ�0��Ԫ�ص�k-1��Ԫ�����
	int dist_sum = 0;
	for (int i = 0; i < k; i++)
	{
		dist_sum += dists[i];
	}
	return dist_sum;

}

// �ҵ���ѡ�ĸ��� ��X[i],Y[i])�� ���ֱ����dist_sum
// ������ǵ���Сֵ
int min_move(int k, const vector<int>& X, const vector<int>& Y)
{
	int min_dist_sum = INT_MAX, n = X.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int dist_sum = get_dist_sum(X[i], Y[i], X, Y, k);
			min_dist_sum = min(min_dist_sum, dist_sum);
		}
	}
	return min_dist_sum;
}

vector<int> min_moves(int n, const vector<int>& X, const vector<int>& Y)
{
	vector<int> res(n, 0);
	for (int k = 2; k <= n; k++)
	{
		res[k - 1] = min_move(k, X, Y);
	}
	return res;
}

int main()
{	
	int n = 0;
	cin >> n;
	vector<int> X(n);
	vector<int> Y(n);
	vector<int> res = min_moves(n, X, Y);
	for (int i = 0; i < n - 1; i++)
	{
		cout << res[i] << " ";
	}
	cout << res.back() << endl;
	return 0;
}