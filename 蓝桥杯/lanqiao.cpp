#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
char a[N];
int top;
int ans;

int main()
{
	string str = "acb"; // 从后往前 小的单调栈 维护 abzcd 的单调栈  abdc 
	
	//reverse(str.begin(),str.end());
	int n = str.size();
	for(int i = str.size(); i >= 0; i--)
	{
		while(top && a[top] < str[i])
		{
			top--;
			ans += pow(2,top) - 1; 	
			cout << "top : " << top << " " << "ans : " << ans << endl;
		}
		a[++top] = str[i];
	}
	ans += pow(2,top - 1) - 1; // 算出栈顶的 
	//while(top)
	//{
	//	ans += pow(2,(int)str.size() - 1) - 1;
	//} 
	
	cout << ans << endl; 
}
