#define _CRT_SECURE_NO_WARNINGS 1 


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
#include <map>
using namespace std;

///*
//消除
//时间限制： 1000MS
//内存限制： 262144KB
//题目描述：
//给一个长度为n的只包含0和1的序列，每次可以使用魔法消除相邻的3个数。在可以用任意次魔法的前提下，0的个数和1的个数的最大差值为多少？输出这个最大差值。
//
//
//
//输入描述
//第一行是一个正整数n，表示序列的长度。
//
//第二行是只包含0和1的序列，其长度为n。
//
//输出描述
//输出一个整数，表示这个最大差值。
//
//
//样例输入
//5
//00001
//样例输出
//3

// dp0[x]  前x个字符0-1的最大差值
// dp1[x]  前x个字符1-0的最大差值

//
//
//int a[6] = {1,1,1,1,0,0};
//int N = 6;
//int f[2][6 + 1];
//int main(){
//
//	int cnt1 = 0;
//	int cnt2 = 0;
//	for (int i = 1; i <= N; i++){
//		if (i < 3){
//			//特判一下前2个字符 
//			if (a[i - 1] == 1){
//				cnt1++;
//			}
//			f[0][i] = cnt1;			// f[0][i]  是1-0的多少 
//			f[1][i] = -cnt1;		// f[i][0]  是0-1的最大值
//		}
//		else{
//			if (a[i - 1] == 1){
//				f[0][i] = max(f[0][i - 1] + 1, f[0][i - 3]);
//				f[1][i] = max(f[1][i - 1] - 1, f[1][i - 3]);
//			}
//			else{
//				f[0][i] = max(f[0][i - 1] - 1, f[0][i - 3]);
//				f[1][i] = max(f[1][i - 1] + 1, f[1][i - 3]);
//			}
//		}
//	}
//	cout << max(f[0][N], f[1][N]) << endl;
//	system("pause");
//}


//
//
//
//关键串
//时间限制： 1000MS
//内存限制： 65536KB
//题目描述：
//定义一个字符串为关键串当且仅当该串中出现次数最多的字符严格超过了字符总数（即串长）的一半。
//
//例如字符串"a","aab","aaab","abccc"是关键串，而"ab","abc","aabb","abcc"不是。
//
//给一个长度为n的字符串s，有多少个子串是关键串？
//
//子串：对于一个给定的字符串，串中任意个连续的字符组成的子序列称为该串的子串。
//
//
//
//输入描述
//第一行是一个正整数n，表示字符串的长度。
//
//第二行是一个长度为n的仅包含小写字母的字符串s。
//
//输出描述
//输出一行，表示字符串s中是关键串的子串个数。
//
//
//样例输入
//5
//ccccb
//样例输出
//14
//
//
//*/


// 第二题 题解
//using namespace std;
//
//int cal(int d, vector<int>&v){
//	int lw = upper_bound(v.begin(), v.end(), d) - v.begin();
//	return lw + (v.size() - lw) * 2;
//}
//
//int main(){
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(n), b(m);
//	for (int i = 0; i<n; i++){
//		cin >> a[i];
//	}
//	for (int i = 0; i<m; i++){
//		cin >> b[i];
//	}
//	sort(a.begin(), a.end());
//	sort(b.begin(), b.end());
//	int ans = -1e9;
//	for (int i = 1; i <= 1000; i++){
//		ans = max(ans, cal(i, b) - cal(i, a));
//	}
//	cout << ans << endl;
//}


/*
	时间限制： 1000MS
	内存限制： 65536KB
	题目描述：
	小团作为一位宝石收藏家和制造家，对宝石了如指掌。每个宝石拥有不同的等级（1级到6级）。

	制造：小团可以制造1级宝石，每制造一个1级宝石，需要花费1222个金币来购买原料。

	合成：小团可以用同等级的宝石来合成更高等级的宝石。具体地，(x+1)个x级的宝石可以合成为一个(x+1)级的宝石，该合成过程需要花费7890*x个金币。

	为了合成6级宝石，小团购买了n堆低级宝石，同一堆宝石的等级都一样。（不同堆的宝石等级也可能相同）

	现在告诉你这n堆宝石每堆的数量和等级和激活状态，问如果小团需要m个6级宝石，至少需要花费的金币数量是多少？



	输入描述
	第一行是一个整数n，表示有n堆宝石。

	接下来n行，每行两个整数ai,bi，表示第i堆宝石有ai个，等级为bi(1≤bi≤5)。

	最后一行是一个整数m，表示小团想要的6级宝石数量。

	输出描述
	一行一个整数，表示最少需要花费的金币数。


	样例输入
	1
	6 2
	1
	样例输出
	6490746

	提示
	n≤20,ai≤100000,m≤1000


	1
	6 2
	1

*/


// 合成一个6级需要 10786998
//
//int n, m;
//int v[6];  // 原材料
//int values[7];     //合成花费  合成i级别的
//int has[7];
//int main(){
//	int n, m;
//	cin >> n;
//	for (int i = 1; i <= n; i++){
//		int a, b;
//		cin >> a >> b;
//		has[b] = a;
//	}
//	cin >> m;
//
//	v[1] = 1222;
//	for (int i = 2; i <= 6; i++){
//		v[i] = i * v[i - 1];
//	}
//	//1222 2444 7332 29328 146640       //合成一个 i级别 宝石需要花多少钱
//
//	for (int i = 1; i <= 5; i++) cout << v[i] << " ";
//	cout << endl;
//
//	for (int i = 2; i <= 6; i++){
//		values[i] = 7890 * (i - 1);
//	}
//
//	// 0 7890 15780 23670 31560 39450   //制造一个 i级别 宝石需要花多少钱
//	for (int i = 1; i <= 6; i++) cout << values[i] << " ";
//	cout << endl;
//
//
//	for (int i = 1; i <= 6; i++) cout << has[i] << " "; // 有多少个i级别的宝石
//	cout << endl;
//	// 已经有的是
//	m -= has[6];
//	int sums = 0;
//	int left = m; // 计算第i层 需要合成多少个 
//	sums += m * (values[6]);
//	sums += m * (v[6]);
//	for (int i = 5; i >= 2; i--){
//		left = left * (i + 1);       //需要i + 1级别的 left个数的 第i级别
//		left -= has[i];				// 5级的需要left - 本来有的left
//		if (left <= 0){
//			break;
//		}
//		sums += (left - has[i]) * values[i];   // 5级left的合成 
//		
//	//	sums += left * v[i];
//	//  left = left + 1;			//
//
//	}
//	//sums += left * v[1];
//
//	// 6552750
//	// 
//	cout << sums << endl;
//	system("pause");
//}

//
//typedef long long ll;
//int n;
//const int N = 1e5 + 1000;
//map<int, int> m;
//int a[N];
//string str;
//
//int main(){
//	cin >> n;
//	cin >> str;
//	for (int i = 0; i < str.size(); i++){
//	
//		m[str[i] - '0']++;
//	}
//	//int max_ = abs(m[0] - m[1]);
//	int max_ = 0;
//	for (int i = 0; i < str.size() - 2; i++){
//		for (int j = 0; j < 3; j++){
//			m[str[i + j] - '0']--;
//		}
//		max_ = max(max_, abs(m[0] - m[1]));
//		for (int j = 0; j < 3; j++){
//			m[str[i + j] -  '0']++;
//		}
//	}
//	cout << max_ << endl;
//
//
//	system("pause");
//}



//const int N = 105;
//int a[N];
//int n, k;
//int max_ = INT_MAX;
//int host = 0;
//int main()
//{
//	vector<int> v;
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++){
//		cin >> a[i];
//		if (a[i] == 0){
//			v.push_back(i);
//		}
//	}
//	
//	for (int i = 0; i < v.size(); i++){
//		//向后循环
//		for (int j = v[i] + 1; j <= n && a[j] != 0; j++){
//			if (k >= a[j]){
//				int sums1 = 0;
//				for (int i = 0; i < v.size(); i++){
//					sums1 += abs(v[i] - j);
//				}
//				if (max_ > sums1){
//					max_ = sums1;
//					host = j;
//				}
//			}
//		}
//		//向前循环
//		for (int j = v[i] - 1; j >= 1 && a[j] != 0; j--){
//			if (k >= a[j]){
//				int sums2 = 0;
//				for (int i = 0; i < v.size(); i++){
//					sums2 += abs(v[i] - j);
//				}
//				if (max_ >sums2){
//					max_ = sums2;
//					host = j;
//				}
//			}
//		}
//	}
//	cout << host << endl;
//	system("pause");
//}

//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//#include <map>
//using namespace std;
//
//int n = 0;
//int main(){
//	string str;
//	cin >> n;
//	cin >> str;
//	map<int, int> m;
//	//	m[1] = 10;
//	//	m[2] = 100;
//
//	int l = 0;
//	int r = 0;
//	int cnt = 0;
//	for (int i = 0; i < str.size(); i++){
//		m[str[i]]++;
//		cnt++;
//		int last = str[i];
//		bool f = false;
//		for (int j = i + 1; j < str.size(); j++){
//			m[str[j]]++;
//			for (auto e : m){
//				if (e.second >(j - i + 1) / 2){
//					cnt++;
//					break;
//				}
//			}
//		}
//		m.clear();
//	}
//	cout << cnt << endl;
//	system("pause");
//}



//}
//
//vector<string> vs;
//bool valid(string & tmp){
//	char target = tmp[0];
//	int count = 1;
//	for (int i = 1; i < tmp.size(); i++){
//		if (tmp[i] == target){
//			count++;
//		}
//		else{
//			count--;
//			if (count == 0){
//				target = tmp[i];
//				count = 1;
//			}
//		}
//	}
//	count = 0;
//	for (int i = 0; i < tmp.size(); i++){
//		if (tmp[i] == target)
//		{
//			count++;
//		}
//	}
//	return count > tmp.size() / 2;
//}
//void dfs(string &str, int cur, string tmp){
//	
//	if (tmp.size() && valid(tmp))
//	{
//		vs.push_back(tmp);
//	}
//
//	for (int i = cur; i < str.size(); i++){
//		tmp += str[i];
//		dfs(str, i + 1, tmp);
//		tmp.pop_back();
//	}
//}
//int n = 0;
//string str;
//int main(){
//	string str;
//	cin >> n;
//	cin >> str;
//	dfs(str, 0, "");
//	cout << vs.size() << endl;
//	system("pause");
//
//
//}


/*
题目描述：
给一个长度为n的只包含0和1的序列，每次可以使用魔法消除相邻的3个数。在可以用任意次魔法的前提下，0的个数和1的个数的最大差值为多少？输出这个最大差值。



输入描述
第一行是一个正整数n，表示序列的长度。

第二行是只包含0和1的序列，其长度为n。

输出描述
输出一个整数，表示这个最大差值。


样例输入
5
00001
样例输出
3

提示
n≤100000


*/
//#include <map>
//using namespace std;
//
//typedef long long ll;
//int n;
//const int N = 1e5 + 1000;
//map<int, int> m;
//int a[N];
//
//int main(){
//	cin >> n;
//	for (int i = 1; i <= n; i++){
//		cin >> a[i];
//		m[a[i]]++;
//	}
//	int max_ = abs(m[0] - m[1]);
//	cout << max_ << endl;
//	for (int i = 1; i <= n; i++){
//
//	}
//	
//
//
//	system("pause");
//}
//


//int main(){
//	cin >> n >> m;
//	int max_gap = 0;
//	for (int i = 1; i <= n; i++){
//		cin >> a[i];
//	}
//	//sort(a + 1, a + n + 1);
//	for (int i = 1; i <= m; i++){
//		cin >> b[i];
//	}
//	
//
//	for (int i = 1; i <= n; i++){
//		if (a[i] <= 1000)
//			max_gap = max(max_gap, a[i]);
//	}
//	if (max_gap == 0){
//		max_gap = 1000;
//	}
//	int sums1 = 0;
//	int sums2 = 0;
//	for (int i = 1; i <= n; i++){
//		if (a[i]  > max_gap){
//			sums1 += 2;
//		}
//		else{
//			sums1 += 1;
//		}
//	}
//	for (int i = 1; i <= m; i++){
//		if (b[i] > max_gap)
//			sums2 += 2;
//		else
//			sums2 += 1;
//	}
//	cout << sums2 - sums1 << endl;
//	system("pause");
//}


//const int N = 105;
//int a[N];
//int n,k;
//int max_ = INT_MAX;
//int host = 0;
//int main()
//{
//	vector<int> v;
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++){
//		cin >> a[i];
//		if (a[i] == 0){
//			v.push_back(i);
//		}
//	}
//	bool f = false;
//	for (int i = 0; i < v.size(); i++){
//		int j = v[i] - 1;
//		int r = v[i] + 1;
//		while (j >= 1 || r <= n){
//			if (j >= 1 && a[j] <= k){
//				max_ = min(max_,v[i] - j);
//				host = j;
//				f = true;
//			}
//			if (f)
//				break;
//			if (r <= n && a[r] <= k){
//				max_ = min(max_, r - v[i]);
//				host = r;
//				f = true;
//			}
//		}
//		if (f)
//			break;
//		j--;
//		k++;
//	}
//	cout << host << endl;
//	system("pause");
//}