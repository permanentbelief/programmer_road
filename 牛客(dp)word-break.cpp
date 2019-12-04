#define _CRT_SECURE_NO_WARNINGS 1 
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		//��ʼ״̬ ����״̬F(0) = true
		// ���ڰ���������һ������
		// Ҳ���Բ����� �༸�� ���ж������Ƿ��ڴʵ����Ƿ����ҵ�

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
				//1 ~ j ���Ա��ָ� ��j+1��i�����ڴʵ����ҵ�
				//1 ~ i ���Ա��ָ�
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