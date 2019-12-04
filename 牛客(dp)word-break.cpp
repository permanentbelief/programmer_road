#define _CRT_SECURE_NO_WARNINGS 1 
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		//初始状态 辅助状态F(0) = true
		// 用于把整个卡成一个整体
		// 也可以不存在 多几行 先判断整体是否在词典中是否能找到

		if (s.empty())
			return false;
		if (dict.empty())
			return false;
		vector<bool> wbreak(s.size() + 1, false);
		wbreak[0] = true;

		for (int i = 1; i <= s.size(); ++i)
		{
			//F(j) && j+1 ~i
			for (int j = 0; j < i; ++j)
			{
				//1 ~ j 可以被分割 且j+1到i可以在词典中找到
				//1 ~ i 可以被分割
				if (wbreak[j] && dict.find(s.substr(i, i - j)) != dict.end())
				{
					wbreak[i] = true;
					break;
				}
			}
		}
		return wbreak[s.size()];
	}
};