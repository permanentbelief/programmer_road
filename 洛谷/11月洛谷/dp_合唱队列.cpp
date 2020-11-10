#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>



using namespace std;
const int N = 150;

int n;
int a[N];
int backup[N];
int l[N];
int r[N];
int ans = 0x7fffffff;


void kk(int *l)
{
	stack<int> s;
	for (int i = 1; i <= n; i++)
	{
		while (s.size() && a[s.top()] < a[i])
		{
			l[s.top()] = s.size() - 1;
			s.pop();
		}
		s.push(i);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	kk(l);

	// for(int i = 1; i <= n; i++) cout << l[i] << " ";
	// cout <<endl;

	reverse(a + 1, a + 1 + n);

	//cout <<endl;
	kk(r);
	//for(int i = 1; i <= n; i++) cout << r[i] << " ";
	int sums = 0;
	for (int i = 1; i <= n; i++)
	{
		sums = max(sums, l[i] + r[i]);
	}
	cout << n - sums << endl;
}

// dp 合唱队形

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		l[i] = 1;
		for (int j = i - 1; j >= 1; j--)
		{
			if (a[i] > a[j])
			{
				l[i] = max(l[i], l[j] + 1);
			}
		}
	}

	for (int i = n; i >= 1; i--)
	{
		r[i] = 1;
		for (int j = i + 1; j <= n; j++)
		{
			if (a[i] > a[j])
			{
				r[i] = max(r[i], r[j] + 1);
			}
		}
	}
	int max_ = 1;
	for (int i = 1; i <= n; i++)
	{
		max_ = max(max_, l[i] + r[i] - 1);
	}

	cout << n - max_ << endl;
}



// 正序 逆序 求最长上升子串
/*
using namespace std;
int b[1001],le[1001],ri[1001];
void lis1()
{
int f[1005];
int len = 1;
f[1] = b[1];
le[1] = 1;
for(int i = 2; i <= n; i++)
{
if(f[len] < b[i])
f[++len] = b[i];
else
{
int l = 1;
int r = len;
while(l < r){
int mid = (l + r) / 2;
if(f[mid] >= b[i])
r = mid;
else
l = mid + 1;
}

f[l] = b[i];
}
le[i] =len;

}
}
void lis2()
{
int f[1005],len = 1;
f[1] = b[n];
for(int i = n - 1; i >= 1; i--)
{
if(f[len] < b[i]) f[++len] = b[i];
else
{
auto t = lower_bound(f + 1, f +len + 1, b[i]) -f;
f[t]  =  b[i];
}
ri[i] = len;
}
}
int main(){
cin>>n;
for(int i=1;i<=n;i++) cin>>b[i];
lis1();
lis2();
for(int i=1;i<=n;i++)
ans=min(ans,n-le[i]-ri[i+1]);
cout<<ans;
}
*/
