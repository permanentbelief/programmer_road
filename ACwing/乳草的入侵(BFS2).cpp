#include<iostream>
#include <cstring>
#include<queue>
using namespace std;


const int N = 105;
char s[N][N];
int R = 0;
int C = 0;
int dis[N][N];
int vis[N][N];
int m = 0;
int n = 0;
pair<int, int> st;
pair<int, int> now;
const int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
const int dy[8] = { 0, 0, 1, -1, 1, -1, -1, 1 };
int cnt = 0;
queue<pair<int, int>> q;
int x;
int y;

int ans = 0;

int check(int x, int y)//�ж�:�ڷ�Χ;û�б����ʹ�;����ʯͷ
{
	return x >= 1 && x <= m && y >= 1 && y <= n && vis[x][y] == 0 && s[x][y] != '*';
}
void bfs()
{
	q.push(st);
	dis[st.first][st.second] = 0;
	vis[st.first][st.second] = 1;
	while (q.size())
	{
		now = q.front();
		q.pop();
		s[now.first][now.second] = '*';
		for (int i = 0; i < 8; i++)
		{
			int x = now.first + dx[i];
			int y = now.second + dy[i];
			if (check(x, y))
			{
				vis[x][y] = 1;
				dis[x][y] = dis[now.first][now.second] + 1;
				ans = max(ans, dis[x][y]);
				q.push({ x, y });
			}
		}
	}
}
int main()
{
	cin >> n >> m; // ����������У� �����������
	cin >> x >> y;  //��ʼ������� �� ��
	st.first = y;
	st.second = x;
	for (int i = m; i >= 1; i--)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> s[i][j];
			if (s[i][j] == '.')
				cnt++;
		}
	}
	/*
	if(s[st.first][st.second] == '.') //�տ�ʼ����һ����
	cnt--;
	*/
	bfs();
	cout << ans << endl;

}



