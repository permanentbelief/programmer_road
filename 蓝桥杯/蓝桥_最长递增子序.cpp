#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
ll ans;
ll sums;
unordered_set<string> us;
//  abcd 
// 
void dfs(string& str, string tmp, int cur)
{
	
	if(!us.count(tmp) && tmp.size() >= 2)
	{
		us.insert(tmp);
		ans++;
	}
	//cout << "yea" << endl; 
	for(int i = cur; i < str.size(); i++)
	{
		if(tmp.size() == 0 || tmp.size() && tmp.back() < str[i])
		{
			tmp += str[i];
			dfs(str, tmp, i + 1);
			tmp.pop_back();
		} 
	}
}
int main()
{
	string str = "fiadgdcdjstemphmnjihecoapdjjrprrqnhgccevdarufmliqijgihhfgdcmxvicfauachlifhafpdccfseflcdgjncadfclvfmadvrnaaahahndsikzssoywakgnfjjaihtniptwoulxbaeqkqhfwl";
	//string str = "woailanqia";
	
	dfs(str,"",0);
	cout << ans << endl;
	/*
	string str = "wocaolanqiaobei";
	
	for(int i = 0; i < str.size(); i++)
	{
		int j = i;
		dfs(str.substr(i),i,)
		
	}
	*/
}

/*
const int N = 1e4;
int a[N];
int b[N];
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
 
	//cout << ans << endl; 

}
*/ 
	
	

//最长上升子序 

/*
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
int a[N];
int main()
{

	int b[11] = {0,1,6,3,2,7,9,3,2,4,5};
	int n = 10;
	int idx = 1;
	a[idx] = b[1];
	
	for(int i = 2; i <= n; i++)
	{
		if(b[i] > a[idx])
		{
			cout << b[i] << "  " << a[idx] <<endl; 
			cout << "yea" << endl;
		    a[++idx] =  b[i];
		}
		else
		{
			auto e = lower_bound(a + 1, a + 1 + idx, b[i]) - a;
			a[e] =  b[i]; 
		}
	}
	//cout << idx << endl;
	for(int i = 1; i <= idx; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl; 
}
*/


