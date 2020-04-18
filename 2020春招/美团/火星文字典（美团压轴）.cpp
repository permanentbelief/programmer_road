//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include<iostream>
//#include<algorithm>
//#include<string>
//#include <map>
//#include <vector>
//#include <set>
//using namespace std;
//
////����ͼ,����ַ�i���ַ�jǰ����ô����i��j��·������map[i][j]=  1
//vector<vector<int>> mymap(26, vector<int>(26));
//// ����ÿ���ڵ�����
//vector<int> indegree(26);
//
////��¼���ֹ����ַ�
//vector<bool> flag(26);
//set<char> myset;
//
////������
//vector<char> ans;
//
//
//void build(vector<string>& vs)
//{
//	//�ҵ��������ڵ��ַ�������һ������ͬ���ַ��Ϳ���ȷ���ַ���˳��
//	// ���ҵ�wrt��wrf�Ϳ����ҵ� t->f
//	string pre = vs[0];
//	for (auto c : pre)
//	{
//		myset.insert(c);
//	}
//	for (int i = 1; i < vs.size(); i++)
//	{
//		string cur = vs[i];
//		for (char c : cur)
//		{
//			myset.insert(c);
//		}
//		for (int j = 0; j < min(pre.size(), cur.size()); j++)
//		{
//			if (pre[j] == cur[j]) //��ͬ�����
//				continue;
//			if (mymap[pre[j] - 'a'][cur[j] - 'a'] == 1) //���������·��,�������ֱ��break
//				break;
//			mymap[pre[j] - 'a'][cur[j] - 'a'] = 1; // ��i�е�j��·��
//			indegree[cur[j] - 'a'] += 1; //�ڵ����� +1
//			flag[pre[j] - 'a'] = true; // ��־����ַ����ֹ�
//			flag[cur[j] - 'a'] = true; // ��־����ַ����ֹ�
//			break; //��Ϊ�ֵ���Ƚϵ��ǵ�һ��������ģ�����������һ����ͬ���ַ���Ҫbreak
//		}
//		pre = cur;
//	}
//}
//
//void topology()
//{
//	while (ans.size() < myset.size())
//	{
//		//�Ƿ���һ���������ҵ����Ϊ0�Ľڵ㣬���û���ҵ�����Ҫbreak.
//		//���һ�α����ҵ��������Ϊ0�ĵ㣬���޷�ȷ��˳���
//		int cnt = 0;
//		for (int i = 0; i < indegree.size(); i++)
//		{
//			if (indegree[i] == 0 && flag[i])  //�ڵ����Ϊ0 �ҽڵ���ڣ�������ͼ��ɾ������ڵ�ʹ�����ڵ�����ı�
//				cnt++;
//		}
//		if (cnt != 1)
//			break;
//
//		//��û����ȵĽڵ�������У�������ͼ��ɾ������ڵ�ʹ�����ڵ�����ı�
//
//		for (int i = 0; i < indegree.size(); i++)
//		{
//			if (indegree[i] == 0 && flag[i])
//			{
//				ans.push_back((char)(i + 'a'));
//				flag[i] = false; //ɾ���ڵ㣬��Ǵ�δ���ֹ�
//				for (int j = 0; j < 26; j++) // ɾ��������ڵ�����ı�
//				{
//					if (mymap[i][j] == 0)
//						continue;
//					indegree[j]--;
//					mymap[i][j] = 0;
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		vector<string>vs;
//
//		for (int i = 0; i < str.size(); i++)
//		{
//			string tmp;
//			while (i < str.size() && str[i] != ' ')
//			{
//				tmp += str[i];
//				i++;
//			}
//			vs.push_back(tmp);
//		}
//
//		int maxLen = 0; //�п����ò���
//
//
//		// ��������ͼ
//		build(vs);
//
//		// �����˽ṹ
//		topology();
//
//		if (ans.size() == myset.size())
//		{
//			for (auto e : ans)
//			{
//				cout << e << " ";
//			}
//			cout << endl;
//		}
//		else
//		{
//			cout << "Invalid" << endl;
//		}
//		//mymap.clear();
//		mymap.swap(vector<vector<int>>(26, vector<int>(26)));
//		//indegree.clear();
//		indegree.swap(vector<int>(26));
//		//flag.clear();
//		flag.swap(vector<bool>(26));
//		//myset.clear();
//		myset.swap(set<char>());
//		//ans.clear();
//		ans.swap(vector<char>());
//	}
//}