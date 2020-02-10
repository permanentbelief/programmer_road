#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


void DFS(vector<string>& vs, string& str, string tmp, vector<int> books)
{
	if (tmp.size() == str.size())
	{
		vs.push_back(tmp);
		return;
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (books[i] == 0)
		{
			books[i] = 1;
			tmp.push_back(str[i]);
			DFS(vs, str, tmp, books);
			tmp.pop_back();
			books[i] = 0;
		}
	}

}

void Permutation(string str)
{
	vector<string> vs;
	vector<int> books(str.size());
	string tmp;
	DFS(vs, str, tmp, books);
	for (auto e : vs)
	{
		cout << e << endl;
	}
	//cout << endl;
	
}

int main()
{
	Permutation("bbb");
	system("pause");
}