#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
/* ������ ö���еĿ��ܣ� ÿһ�е���������
int n;
const int N = 130;
int a[N][N];
int dp[N][N];

int main()
{
cin >> n;
for(int i = 1; i <= n; i++)
{
for(int j = 1; j <= n; j++)
{
cin >> a[i][j];
}
}
int max_ = a[1][1];
for(int i = 1; i <= n; i++)
{
for(int j = 1; j <= n; j++)
{
a[i][j] = a[i - 1][j] + a[i][j];
//max_ = max(max_,dp[i][j]);
}
}

int dp[1000];
int f[1000];
for(int i = 1; i <= n; i++)
{
for(int k = 1; k <= i; k++)
{
for(int j = 1; j <= n; j++)
{
f[i] = a[i][j] - a[i - k][j];
dp[j] = max(dp[j -1] + f[i], f[i]);
max_ = max(max_, dp[j]);
}
}
}

cout << max_ << endl;
}
*/
// �� �����, ÿһ��ĺͲ��� <0 �ұ�������
/*
const int N = 1e3 + 3000;
int a[N];
int n;
int dp[N];
int main()
{
cin >> n;
for(int i = 1; i <= n; i++)
{
cin >> a[i];
a[i] += a[i - 1]; //����
if(a[i] >= 0) dp[i] = 1;
}
for(int i = 1; i <= n; i++)
{
for(int j = 1; j < i; j++)
{
if(dp[j] > 0 && a[i] - a[j] >= 0)
{
dp[i] = max(dp[i],dp[j] + 1);
}
}
}
if(dp[n] == 0)
{
cout << "Impossible" <<endl;
return 0;
}
cout << dp[n] <<endl;
return 0;

}
*/
//���� ��������
/*
int n,m;

const int N = 1010;
const int M = 1010;

int f[M],a[N],b[N], c[101][20], cc[101], cn;

int main()
{
cin >> m >> n;
for(int i = 1; i <= n; i++)
{
int C;
cin >> a[i] >> b[i] >> C;
cn = max(cn, C);
cc[C]++; //��¼C��һ�����ټ���Ʒ
c[C][cc[C]] = i; // ��¼��C���i����Ʒ����� Ϊi

}
for(int i = 1; i <= cn; i++) //ö�ٷ���
{
for(int j = m; j >= 0; j--)
{
for(int k = 1; k <= cc[i]; k++) //�����е�ö��
{
if(j >= a[c[i][k]])
{
f[j] = max(f[j],f[j - a[c[i][k]]] + b[c[i][k]]);
}
}
}
}
cout << f[m] << endl;
}
*/
/* 01���� ��ͨ������
const int N = 1e4 + 1000;

int v,n,c;
int k,m;
int V[N],L[N];
int f[N];

int main()
{
cin >> v >> n >> c;
for(int i = 1; i <= n; i++)
{
cin >> V[i] >> L[i];
}
for(int i = 1; i <= n; i++)
{
for(int j = c; j >= L[i] ; j--)
{
f[j] = max(f[j], f[j -L[i]] + V[i]);
}
}
for(int i = 1; i <= c; i++)
{
if(w[i] >= v)
{
cout << c - i << endl;
return 0;
}
else
{
cout << "Impossible" <<endl;
}
}
}
*/
// ����ά�ȵ� 01��������
/*
int sumV, sumM;
int n;
int v[100],m[100],ka[100];
int f[400][400];
int main()
{
cin >> sumV >> sumM;
cin >> n;
for(int i = 1; i <= n; i++)
{
cin >> v[i] >> m[i] >> ka[i];
}
for(int i =1; i <= n; i++)
{
for(int j = sumV; j >= v[i]; j--)
{
for(int k = sumM; k >= m[i]; k--)
{
f[j][k] = max(f[j][k],f[j - v[i]][k - m[i]] + ka[i]);
}
}
}
cout << f[sumV][sumM] <<endl;
}
*/
/*

const int N = 230;
int n;

int a[N][N];

int main()
{
cin >> n;
//�����ǵĻ� i��n �� 1�� j�� i�� n�� ������ dp[1];
}
*/
/*
int f[100000][5];
int a = 0;
int check(int k)
{
memset(f,0,sizeof f);
f[0][0] = 1;
for(int i = 1; i <= k; i++)
{
for(int j = 0; j <= 4; j++)
{
if(j == 0) f[i][j] = 1;
else
f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
}
}
for(int i = 0; i <= k; i++)
{
for(int j = 0; j <= 4; j++)
{
cout << f[i][j] <<  " ";
}
cout << endl;
}
return f[k][4];
}

int main()
{

cout << check(5) << endl;
}
*/
/* ��ȫ����
const int N = 1e5 + 100;
int f[N];
int dp[N];
int n = 0;
long long qmid(int a, int k)
{
long long ans = 1;
while(k)
{
if(k & 1)  ans = ans * a;
a = a * a;
k >>= 1;
}
return ans;
}

int main()
{
for(int i = 0; i <= 20; i++)
{
f[i] = qmid(i,4);
}
cin >> n;
memset(dp,0x3f,sizeof dp);
dp[0] = 0;
for(int i = 1; i <= 20; i++)
{
for(int j = f[i]; j <= n; j++)
{
dp[j] = min(dp[j], dp[j - f[i]] + 1);
}
}
cout << dp[n] <<endl;
}
*/


// ��ȷ��p1130 ����
/*
#include<bits/stdc++.h>
using namespace std;
int a[2010][2010],n,m;
int main(){
scanf("%d%d",&n,&m); // ����, С����
for(int j=1;j<=m;j++)
{
for(int i=1;i<=n;i++)
{
scanf("%d",&a[i][j]);//����

}
}
for(int i = 1; i <= n; i++)
{
for(int j =1; j <= m; j++)
{
cout << a[i][j] << " ";
}
cout << endl;
}
for(int i=2;i<=n;i++)
for(int j=1;j<=m;j++)
{
if(j==1) a[i][j]+=min(a[i-1][j],a[i-1][m]);//j==1��ʱ��Ҫ����һ�£�������Ҫϸ΢�ı仯���Լ���Ŷ
else a[i][j]+=min(a[i-1][j],a[i-1][j-1]);//DP����ʽ�����潲���ˡ�
}
int ans=100000010;//������a[n]��Ѱ����Сֵ��ֵ��ans
for(int i=1;i<=m;i++)
if(a[n][i]<ans) ans=a[n][i];


for(int i =1; i <= n; i++)
{
for(int j = 1; j <= m; j++)
{
cout << a[i][j] << " ";
}
cout << endl;
}
printf("%d",ans);//���ans����
return 0;
}
*/



//
//auto e = 100;
//
//const int N = 2200;
//int a[N][N];
//int dp[N][N];
//int n, m;
//int V;
//int f[N];
//
//int main()
//{
//	cin >> m >> n;
//	//m���� n����
//	// memset(dp,0x3f,sizeof dp);
//	for (int i = 1; i <= n; i++)
//	{
//		//  memset(dp[i],0,sizeof dp[i]);
//		for (int j = 1; j <= m; j++)
//		{
//			cin >> a[i][j];
//			//dp[i][j] += dp[i][j - 1];
//		}
//	}
//	// dp[i][j] �ڵ�i�е�ʱ�� ,ѡ��j�е� ��Сֵ
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//
//			dp[i][j] = min(dp[n][j - 1], dp[n][j - 1]) + a[i][j];
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << n << endl;
//	cout << dp[n][m] << endl;
//
//}

//
//class Test1
//{
//public:
//	Test1() // �޲ι��캯��
//	{
//		cout << "Construct Test1" << endl;
//	}
//	Test1(const Test1& t1) // �������캯��
//	{
//		cout << "Copy constructor for Test1" << endl; this->a = t1.a;
//	}
//	Test1& operator = (const Test1& t1) // ��ֵ�����
//	{
//		cout << "assignment for Test1" << endl; this->a = t1.a; return *this;
//	}
//	int a;
//};
//
//class Test2
//{
//public:
//	Test1 test1;
//	Test2(Test1 &t1)
//	{
//		test1 = t1;
//	}
//
//};
//
//int main()
//{
//	Test1 t1;
//	Test2 t(t1);
//	system("pause");
//}


////template <class T>
//class String
//{
//public:
//	String(char* str = "")
//		:_str(new char[strlen(str) + 1])
//	{
//		strcpy(_str, str);
//	}
//	String(const String& s)
//	{
//		if (_str != nullptr)
//		{
//			delete[] _str;
//		}
//		_str = new char[strlen(s._str) + 1];
//		strcpy(_str, s._str);
//	}
//	~String()
//	{
//		delete[]_str;
//		_str = nullptr;
//	}
//	String& operator=(const String& s)
//	{
//		if (_str != s._str)
//		{
//			if (_str != nullptr)
//			{
//				delete[] _str;
//
//			}
//			_str = new char[strlen(s._str)];
//			strcpy(_str, s._str);
//		}
//		return *this;
//	}
//		
//private:
//	char* _str;
//};
//
//
//class String1
//{
//public:
//	String1(char* str = "")
//		:_str(new char[strlen(str) + 1])
//	{
//		strcpy(_str, str);
//	}
//	String1(const String1& s)
//		:_str(nullptr)
//	{
//		String1 tmp(s._str);
//		swap(_str, tmp._str);
//	}
//	String1& operator=(String1 s)
//	{
//		swap(s._str, _str);
//		return *this;
//	}
//private:
//	char* _str;
//};

int main()
{
	
	string str = "test";
	string&& r = move(str);
	string t(r);
	cout << str << endl;
	cout << r << endl;
	cout << t < endl;

	system("pause");
}