#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

#include <set>

using namespace std;

class Solution {
public:
	int cnt;
	int max_ = 0;

	void dfs(string& tiles, vector<bool>& used, set<string> s, string str)
	{
		s.insert(str);

		for (int i = 0; i < tiles.size(); i++)
		{
			if (used[i] == false)
			{
				used[i] = true;
				dfs(tiles, used, s, str + tiles[i]);
				used[i] = false;
			}
		}
	}
	int numTilePossibilities(string tiles) {

		set<string> s;
		vector<bool> used(tiles.size(), false);
		dfs(tiles, used, s, "");
		return s.size() - 1;

	}
};
int main()
{
	Solution s;
	cout << s.numTilePossibilities("AAB") << endl;
	vector<char> c = { 'C', 'a' };
	cout << c.back() << endl;

	system("pause");
}