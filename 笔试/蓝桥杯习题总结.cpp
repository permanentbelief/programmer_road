#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
#define MOD 1e5


int n = 0;
const int MaxN = 1e5;
long long w[MaxN + 1]; //ÿһ�����Ȩ��
long long ww[MaxN + 1]; //ÿһ������Ϊ���ڵ�ʱ�ܵõ������Ȩ��

vector<int> g[MaxN + 1]; // �ڽӱ�

/*��rootΪ�����������Ȩ��*/

//void dfs(int root, int fa)
//{
//	ww[root] = w[root];
//	for (int i = 0; i < g[root].size(); i++)
//	{
//		int son = g[root][i];//���е�һ������
//		if (son != fa)
//		{
//			dfs(son, root);
//			if (ww[son] > 0)
//				ww[root] += ww[son];
//		}
//	}
//	if (ww[root] > ans)
//		ans = ww[root];
//}
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%lld", &w[i]);
//	}
//	for (int j = 0; j < n - 1; j++)
//	{
//		int u = 0;
//		int v = 0;
//		scanf("%d %d", &u, &v);
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//
//	dfs(5, 0);
//	printf("%lld\n", ans);
//}



#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string pai[7];

int ans = 0;

//void f(int k, int cnt)
//{
//	if (cnt > 13 || k > 13)
//		return;
//	if (k == 13 && cnt == 13)
//	{
//		ans++;
//		return;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		f(k + 1, cnt + i);
//	}
//}
//int main()
//{
//	f(0, 0);
//	cout << ans << endl;
//	system("pause");
//}




//#include <iostream>
//#include <algorithm>
//#include <string>
//using namespace std;
//
//
//int cmp(string a, string b) //�п���a Ϊ"00"  bΪ"4"������Ҫȥ0
//{
//	if (a.find_first_not_of('0') == string::npos)
//		a = "0";
//	else
//		 a.substr(a.find_first_not_of('0'));
//	if (b.find_first_not_of('0') == string::npos)
//		b = "0";
//	else
//		b.substr(b.find_first_not_of('0'));
//
//
//	if (a.size() > b.size())
//		return 1;
//	else if (a.size() < b.size())
//		return -1;
//	else  //�������
//	{
//		if (a < b)
//			return -1;
//		else if (a > b)
//			return 1;
//		else
//			return 0; //���
//
//	}
//}
//
//string substract(string a, string b)
//{
//	// a����b
//	// 1.��ת
//	reverse(a.begin(), a.end());
//	reverse(b.begin(), b.end());
//
//	// 2.��λ������
//	 
//	for (int i = 0; i < b.size(); i++)
//	{
//		if (a[i] >= b[i])
//		{
//			a[i] = ( a[i] - b[i] + '0');
//		}
//		else //Ҫ��λ��
//		{
//			int k = 1;
//			while (a[i + k] == '0')
//			{
//				a[i + k] = '9';
//				k++;
//			}
//			//������Ա�֤ i+k��һλ�ϲ���0
//			a[i + k] = a[i + k] - '1' + '0'; // a[i+k] - '1'��������������Ҫ����ַ�
//
//			//    a[i] - '0'������    b[i] - '0'������
//			a[i] = a[i] - '0' + 10 - (b[i] - '0') + '0';
//		}
//	}
//	reverse(a.begin(), a.end()); //��ת����
//
//	if (a.find_first_not_of('0') == string::npos) //��ͷ��βȫ��0����ֱ�ӷ���0,
//		return "0";
//	return a.substr(a.find_first_not_of('0'));
//}
//
//string divide(string a, string b)  //ֻ����aС��b�����
//{
//	string ans = "0.";
//	//ת��Ϊ����
//
//	//��ΪaС��b��������a��0
//
//	for (int i = 0; i < 101; i++) // 101��
//	{
//		a.append("0");
//		int t = 0;
//		while (cmp(a, b) >= 0) // a >= b
//		{
//			a = substract(a, b); //��ͣ������������
//			t++; // ��¼�˼��������ٴ�
//		}
//		ans.append(to_string(t));
//	}
//	return ans;
//}
//int main()
//{
//	string a = "100";
//	string b = "7";
//	cout << divide(a, b) << endl;
//	system("pause");
//}
//
//#define MOD  1000000007
//int data[50][50];
//int m, n, k = 0;
//long long ans1 = 0;
//long long cache[50][50][14][13];
//
//
//long long dfs2(int x, int y, int max, int cnt)
//{
//	//�Ȳ黺��
//	if (cache[x][y][max+1][cnt] != -1)
//		return cache[x][y][max+1][cnt];
//	long long ans = 0;
//	if (x == n || y == m || cnt > k)
//	{
//		return  0;
//	}
//	int cur = data[x][y];
//	if (x == n - 1 && y == m - 1) //�Ѿ��������һ������
//	{
//		if (cnt == k || (cnt == k - 1 && cur > max))
//		{
//			ans++;
//			if (ans > MOD)
//				ans %= MOD;
//		}
//		return ans;
//	}
//	if (cur > max)// ����ȡ�����Ʒ
//	{
//		ans += dfs2(x, y + 1, cur, cnt + 1);
//		ans += dfs2(x + 1, y, cur, cnt + 1);
//	}
//
//	//���ڼ�ֵС�ģ����߼�ֵ���ǲ�ȡ�����Ʒ�������
//	ans += dfs2(x, y + 1, max, cnt);
//	ans += dfs2(x + 1, y, max, cnt);
//
//	//��¼����
//	cache[x][y][max+1][cnt] = ans % MOD;
//	return ans%MOD;
//}
//void dfs(int x, int y, int max, int cnt)
//{
//	if (x == n || y == m || cnt > k)
//	{
//		return;
//	}
//	int cur = data[x][y];
//	if (x == n - 1 && y == m - 1) //�Ѿ��������һ������
//	{
//		if (cnt == k || (cnt == k - 1 && cur > max))
//		{
//			ans1++;
//			if(ans1 > MOD)
//				ans1 %= MOD;
//		}
//	}
//	if (cur > max)// ����ȡ�����Ʒ
//	{
//		dfs(x, y + 1, cur, cnt + 1);
//		dfs(x + 1, y, cur, cnt + 1);
//	}
//
//	//���ڼ�ֵС�ģ����߼�ֵ���ǲ�ȡ�����Ʒ�������
//	dfs(x, y + 1, max, cnt);
//	dfs(x + 1, y, max, cnt);
//}
//int main()
//{
//	long long v[10][10][10][10];
//	memset(v, -1, sizeof(v));
//	system("pause");
//}