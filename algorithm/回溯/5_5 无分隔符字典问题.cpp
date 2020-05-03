#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


void permutation(vector<int>&v, int k ,vector<int> tmp,vector<bool>& books, int& count)
{
	if (k == tmp.size())
	{
		//for (auto e : tmp)
		//{
		//	cout << e << " ";
		//}
		count++;
		//cout << endl;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (i > 0 && v[i] == v[i - 1] && books[i - 1] == false)
			continue;
		if (books[i] == false)
		{
			books[i] = true;
			tmp.push_back(v[i]);
			permutation(v,k, tmp,books, count);
			books[i] = false;
			tmp.pop_back();
		}
	}
}
int main()
{
	int n = 0;
	int k = 0;
	while (cin >> n >> k)
	{
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			v[i] = i;
		}
		int count = 0;
		vector<int> tmp;
		vector<bool> books(v.size());
		permutation(v, n, tmp, books, count);
		cout << count << endl;
		
	}

}


