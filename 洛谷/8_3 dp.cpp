#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;



//
///*
//const int N = 1e5 + 1000;
//
//
//int a[N],d1[N],d2[N];
//
//int n;
//int f[N];
//
//int lowbit(int x)
//{
//return x & -x;
//}
//
//void add(int x, int c)
//{
//for(int i = x; i <= maxn; i+= lowbit(x))
//{
//f[i] = max(f[i],c); //ά�����ֵ
//}
//}
//
//int query(int x)
//{
//int res = 0;
//for(int i = x; i >= 1; i -= lowbit(i)) res = max(res,f[i]);
//return res;
//}
//
//int main()
//{
//int k = 0;
//
//int ans1 = 0;
//int ans2 = 0;
//while(scanf("%d",&k) != EOF)
//{
//a[++n] = k;
//}
//for(int i = n; i >= 1; i--)
//{
////������½���
//int q = query(a[i]) + 1;
//add(a[i],q);
//ans1 = max(ans1,q);
//}
//
//memset(f,0,sizeof f);
//for(int i = 1; i <= n; i++)
//{
////���������
//int q = query(a[i] - 1) + 1;
//add(a[i],q);
//ans2 = max(ans2,q);
//
//}
//cout << ans1 << endl;
//cout << ans2 << endl;
//
//
//}
//*/
///*
//const int NN = 35;
//const int MM = 35;
//
//int f[NN][MM];
//int n,m;
//int main()
//{
//cin >> n >> m;
//f[0][1] = 1;
////dp[i][j][m] ����i�������Ѿ�����m���˵�ʱ������j����
//// dp[]
//for(int i = 1; i <= m; i++)
//{
//for(int j = 1; j <= n; j++)
//{
//if(j == 1)
//f[i][j] = f[i - 1][n] + f[i - 1][2];
//else if(j == n)
//f[i][j] = f[i - 1][1] + f[i  - 1][n - 1];
//else
//f[i][j] = f[i - 1][j - 1] + f[i- 1][j + 1];
//}
//
//}
//cout << f[m][1] << endl;
//}
//*/
//
///*
//
//#include <iostream>
//#include <cstring>//memset��
//using namespace std;
//int f[31][31],n,m;
//void dfs(int s/*λ��*/, int c/*����*/){
//	f[s][c] = 0;//������������
//	if (c == m&&s == 1) f[s][c] = 1;//�ѵ��������޲�����С����λ�þ������״���µļ���������һ����һ����
//	if (c != m)//û�ѵ����ޣ����ܻ�������еݹ�
//	{
//		if (f[s%n + 1][c + 1] == -1) dfs(s%n + 1, c + 1);//����ұ�û�м��䣬���ұ�
//		if (f[s != 1 ? s - 1 : n][c + 1] == -1) dfs(s != 1 ? s - 1 : n, c + 1);//������û�м��䣬�����
//		f[s][c] = f[s%n + 1][c + 1] + f[s != 1 ? s - 1 : n][c + 1];//���������ߵĽ�������Ϳ��Եõ�����Ľ�
//	}
//}
//int main(){
//	memset(f, -1, sizeof(f));//��f������Ϊ-1��-1����˼��û�б���¼
//	cin >> n >> m;
//	dfs(1, 0);//��ʼ��С����λ�ã�����Ϊ0
//	cout << f[1][0] << endl;//�����ʼ��С����λ�ã�����Ϊ0�Ľ���
//	return 0;
//}
//*/
///*
//int dp[N][N];
//int dfs(int s, int c)
//{
//if(dp[s][c]) return dp[s][c];
//int sum = 0;
//if(c == m)
//{
//return s == 1 ? 1 : 0;
//}
//dp[s][c] = sum = dfs(s % n + 1,c + 1) + dfs(s == 1 ? n: s - 1, c + 1);
//}
//int main()
//{
//dfs(1,0);
//}
//*/



/*
const int N = 110;
const int M = 110;

const int mod =  1000007;
int a[N];
int b[N];
int dp[N][M];
int n,m;
//int ans;

int dfs(int sum, int i)
{



if(sum > m )
return 0;
else if(sum == m)
{
return 1;
}
if(i == n + 1) return 0;
if(dp[sum][i] ) return dp[sum][i];

int ans = 0;
for(int j = 0; j <= a[i]; j ++)
{
ans = (ans + dfs(sum + j, i + 1))%mod;
}
return dp[sum][i] = ans;
}
int main()
{
cin >> n >> m;
for(int i = 1; i <= n; i++)
{
cin >> a[i];
}


memset(dp,0, sizeof(dp));
dp[0][0] = 1;
for(int i = 1; i <= n; i++)
{
for(int j = 0; j <= m ; j++)
{
for(int k = 0; k <= min(a[i],j); k++)

{
dp[i][j] = ( dp[i][j] + dp[i - 1][j - k]) % mod;
}

}
}
cout << dp[n][m] << endl;
//f[i][j] ǰi������Ϊj�ĸ���
// cout << dfs(0,1) << endl;
}


*/
//
//const int N = 110;
//const int M = 110;
//
//int a[N];
//int b[N];
//int n, m;
//int ans;
//
//void dfs(int sum, int i)
//{
//	if (sum > m )
//		return;
//	else if (sum == m) // i == n��ʱ�� ���һ��Ҫ��������㣬��
//	{
//		ans++;
//		return;
//	}
//	if (i == n + 1)
//		return;
//	for (int j = 0; j <= a[i]; j++)
//	{
//		dfs(sum + j, i + 1);
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	dfs(0, 1);
//	cout << ans << endl;
//	system("pause");
//}




const int N = 1e2 + 100;

//int sum = INT_MAX;
//int index1 = INT_MAX;
//bool flag = false;
//int M, S, T;
//
//void dfs(int m/*ħ��ֵ*/, int dis/*ʣ�µľ���*/, int t/*ʱ��*/)
//{
//
//	if (dis <= 0)
//	{
//		flag = true;
//		index1 = min(index1, t);
//		return;
//	}
//	if (t == T)
//	{
//		sum = min(sum, dis);
//		return;
//	}
//	//ʹ�õĻ�
//	if (m >= 10)
//		dfs(m - 10, dis - 60, t + 1);
//
//	//ʹ�õĻ�
//	//1 ֱ������ǰ��
//	dfs(m, dis - 17, t + 1);
//
//	//2. �ȷ���ֵ�ָ�
//	dfs(m + 4, dis, t + 1);
//
//}
//int main()
//{
//	cin >> M >> S >> T;
//	dfs(M, S, 0);
//	if (flag == false)
//	{
//		cout << "No" << endl;
//		cout << S - sum << endl;
//	}
//	else
//	{
//		cout << "Yes" << endl;
//		cout << index1 << endl;
//	}
//	system("pause");
//}

//template <class T>
//class initializer_list;

#include <map>

struct myclass
{
	myclass(int, int)
	{
		cout << "~~" << endl;
	}
	myclass(initializer_list<int>)
	{
		cout << "___" << endl;
	}
};



template <class T>
struct S
{
	vector<int> v;
	S(initializer_list<T> l) : v(l)
	{
		cout << "cons" << l.size() << "dada" << endl;
	}
	void append(initializer_list<T> l)
	{
		v.insert(v.end(), l.begin(), l.end());
	}
	pair<const T*, size_t> c_arr() const
	{
		return{ &v[0], v.size() };
	}
};
int main()
{
	

	S<int> s = { 1, 2, 3, 4, 5 };
	s.append({ 3, 4, 5 });
	cout << s.c_arr().second << endl;
	cout << s.c_arr().first << endl;

	for (auto e : s.v)
	{

	}
	system("pause");
	//C++11 �������͵��б��ʼ��
	//��̬����
	int *arr = new int[5]{ 1, 2, 3, 4, 5 };
	auto a = { 1, 2, 3 };

	map<int, int> m = { { 1, 2 }, { 2, 3 }, { 4, 5 } };

	//initializer: 

	
	//�Զ�����ĳ�����
	// ����������ݳ�ʼ���б������Զ���������͵Ķ���
	//1. ��ʼ���б��������ô������������Ķ��ŷָ�Ԫ�ص��б�

	//2. 

	//�������������͵�һ�������Ĺ��캯����һ������Ĺ��캯����
	//��Ϊinitializer-list���캯����
	//ʹ�ó�ʼ�����б������﷨ʱ����ʼ�����б���������������������

	
	
}