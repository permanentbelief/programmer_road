#define _CRT_SECURE_NO_WARNINGS 1 

//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//
//const int N = 20;
//
//char g[N][N]; //�洢����
//int ans = 0; // �洢��
//
//int k = 0; 
//int m = 0; // �洢��ǰ�ѷ��������ϵ�������
//
//
//bool line[N];
//
//void dfs(int x)
//{
//	if (m == k)
//	{
//		// �����ӷŹ��ʱ��
//		ans++;
//		return;
//	}
//	if (x == n)
//		return;
//	for (int i = 0; i < n; i++)
//	{
//		if (!line[i] && g[x][i] == '#')
//		{
//			line[i] = true;
//			m++; // ����һö����
//			dfs(x + 1); //��һ�б���
//			line[i] = false;
//			m--;
//		}
//	}
//	dfs(x + 1); //ֱ�ӽ�������һ��
//
//}
//
//int main()
//{
//	int n = 0;
//	while (scanf("%d %d",&n ,&k) && n != -1 && k != -1)
//	{
//		ans = m = 0;
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				cin >> g[i][j];
//			}
//		}
//		dfs(0);
//		cout << ans << endl;
//	}
//	system("pause");
//}