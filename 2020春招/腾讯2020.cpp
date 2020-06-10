#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


//int main()
//{
//	int n = 0;
//	int L = 0;
//	cin >> n >> L;
//	vector<vector<int>> vv(n);
//	for (int j = 0; j < n; j++)
//	{
//		int a = 0;
//		int b = 0;
//		cin >> a;
//		cin >> b;
//		vv[j] = { a, b };
//	}
//	sort(vv.begin(), vv.end(), [](vector<int>&a, vector<int>&b)
//	{
//		return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
//	});
//	int prev = 0;
//	int right = 0;
//	int ans = 0;
//	int i = 0;
//	int last = 0;
//	while (i < vv.size())
//	{
//		if (i < vv.size() && vv[i][0] <= prev)
//		{
//			last = max(last, vv[i][1]);
//			++i;
//		}
//		ans++;
//		prev = last;
//		if (i < vv.size() && vv[i][0] > prev)
//		{
//			ans = -1;
//			break;
//		}
//		if (last >= L)
//			break;
//	}
//	if (ans == -1 || last < L)
//		cout << -1 << endl;
//	else
//	cout << ans << endl;
//	system("pause");
//}

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> a, b;
stack<int> st1, st2;

//int main() {
//	int n, x[100001];
//	cin >> n;
//	int ans = 0;
//	for (int i = 0; i < n; i++) cin >> x[i];
//
//	for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
//		a.push_back(st1.size());
//		b.push_back(st2.size());
//
//		while (!st1.empty() && st1.top() <= x[i]) st1.pop();
//		while (!st2.empty() && st2.top() <= x[j]) st2.pop();
//		st1.push(x[i]);
//		st2.push(x[j]);
//	}
//	reverse(b.begin(), b.end());
//	for (int i = 0; i < n; i++) cout << b[i] + a[i] + 1 << " ";
//	system("pause");
//	return 0;
//}

# include <iostream>
# include <cstdlib>
# include <cstring>
# include <stack>
# define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

int main(void){
	int n = 0;
	while (cin >> n){
		int gym[4], i, work[4];
		for (i = 0; i<n; ++i)
			cin >> work[i];
		for (i = 0; i<n; ++i)
			cin >> gym[i];
		int dp[4 + 1][3]; // 0是休息，1是锻炼，2是工作
		memset(dp, 0x3f, sizeof(dp));
		dp[0][0] = dp[0][1] = dp[0][2] = 0;
		for (int i = 1; i <= n; ++i){
			if (gym[i - 1] == 1){
				// 可以锻炼
				dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
			}
			if (work[i - 1] == 1){
				// 可以工作
				dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
			}
			dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
		}
		int res = min(dp[n][0], min(dp[n][1], dp[n][2]));
		cout << res << endl;
	}
	return 0;
}

//
//O(nlogn)可全过
//大概思路就是记录所有2^i上的逆序对，只要记录2i - 1和另一半2i - 1之间的逆序对，例如2341里面
//21上有1个
//22上一共3个，但是有一个在21中算过了，所以就是2个
//计算这个值的过程用O(n2)能过80%，改成merge可以全过
//同时，要计算2i下所有可能的组合, 即2i - 1 * 2i - 1, 再乘上2i的个数，即2n - i，得到2n + i - 2, 在merge的过程中同时还要记录等于的情况，因为这些等于的不管是否翻转都不是逆序对，所以对每一个2i还要减去等于的对数。
//然后翻转的时候，假如翻转数字的是x，对于每个2i(x >= i), 值都改为上面求出的数 - 原值
//逆序对总数就是从1 - n求和。
//
#include<stdio.h>
#include<vector>
using namespace std;

//long long n, m, total, sum, offset, num;
//
////vector<long long> count1;
////vector<long long> l;
////vector<long long> l_copy;
////vector<long long> max_c;
////void mergesort(long long index, long long size)
////{
////	if (size == 0)
////	{
////		l_copy[index] = l[index];
////		return;
////	}
////	vector<long long> l_copy2(1 << size);
////	long long st1 = index, st2 = index + (1 << (size - 1)), ed1 = st2, ed2 = index + (1 << size);
////	long long pos = 0, p1 = st1, p2 = st2;
////	mergesort(st1, size - 1);
////	mergesort(st2, size - 1);
////	while (p1 < ed1 && p2 < ed2)
////	{
////		if (l_copy[p1] == l_copy[p2]){
////			long long c1 = 1, c2 = 1;
////			l_copy2[pos++] = l_copy[p1++];
////			l_copy2[pos++] = l_copy[p2++];
////			while (p1 < ed1 && l_copy[p1] == l_copy[p1 - 1]) l_copy2[pos++] = l_copy[p1++], ++c1;
////			while (p2 < ed2 && l_copy[p2] == l_copy[p2 - 1]) l_copy2[pos++] = l_copy[p2++], ++c2;
////			max_c[size] -= c1 * c2;
////			count1[size] += (ed1 - p1) * c2;
////		}
////		else if (l_copy[p1] < l_copy[p2]){
////			l_copy2[pos++] = l_copy[p1++];
////		}
////		else {
////			count1[size] += ed1 - p1;
////			l_copy2[pos++] = l_copy[p2++];
////		}
////	}
////	if (p1 == ed1)while (p2 != ed2) l_copy2[pos++] = l_copy[p2++];
////	else if (p2 == ed2) while (p1 != ed1) l_copy2[pos++] = l_copy[p1++];
////	for (long long i = st1; i < ed2; ++i) l_copy[i] = l_copy2[i - st1];
////}
//
//int main()
//{
//	scanf("%lld", &n);
//	total = (long long)1 << n;
//	count1.resize(n + 1);
//	max_c.resize(n + 1);
//	l.resize(total);
//	l_copy.resize(total);
//	for (long long i = 0; i < total; ++i) scanf("%lld", &l[i]);
//	max_c[0] = 1;
//	for (long long i = 1; i <= n; ++i) max_c[i] = (long long)1 << (n + i - 2);//(1 << 2 * (i - 1) ) * ( 1 << (n - i))
//
//	mergesort(0, n);
//
//	scanf("%lld", &m);
//	for (long long i = 0; i < m; ++i)
//	{
//		scanf("%lld", &num);
//		sum = 0;
//		for (long long j = 1; j <= n; ++j)
//		{
//			if (j <= num) count1[j] = max_c[j] - count1[j];
//			sum += count1[j];
//		}
//		printf("%lld\n", sum);
//	}
//	system("pause");
//}



//void MergeSort(vector<int>& arr, int left, int right ,int& count2)
//{
//	if (left >= right)
//		return;
//	int mid = left + (right - left) / 2;
//	MergeSort(arr, left, mid,count2);
//	MergeSort(arr, mid + 1, right,count2);
//
//	int i = left;
//	int m = (left + right) / 2;
//	int j = m + 1;
//	int index = 0;
//	vector<int> temp(right - left + 1);
//	while (i <= m && j <= right)
//	{
//		if (arr[i] < arr[j])
//		{
//			temp[index++] = arr[i];
//			i++;
//		}
//		else
//		{
//			count2 += mid - i + 1;
//			temp[index++] = arr[j];
//			j++;
//		}
//	}
//	while (i <= m)
//	{
//		temp[index++] = arr[i++];
//	}
//	while (j <= right)
//	{
//		temp[index++] = arr[j++];
//	}
//	for (int i = left; i <= right; i++)
//	{
//		arr[i] = temp[i - left];
//	}
//
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v(pow(2,n));
//	for (int i = 0; i < v.size(); i++)
//	{
//		cin >> v[i];
//	}
//	int m = 0;
//	cin >> m;
//	vector<int> counts(m);
//	for (int i = 0; i < m; i++)
//	{
//		cin >> counts[i];
//	}
//	int j = 0;
//	while (j < m)
//	{
//		int flag = 0;
//		if (pow(2, counts[j]) == 1)
//		{
//			MergeSort(v, 0, v.size() - 1, flag);
//			cout << flag << endl;
//		}
//		else
//		{
//			int n = pow(2, counts[j]);
//			for (int i = 0;  i  < v.size();)
//			{
//				int left = i;
//				int right = i + n - 1;
//				while (left <= right)
//				{
//					swap(v[left], v[right]);
//					left++;
//					right--;
//				}
//				i += n;
//			}
//			MergeSort(v, 0, v.size() - 1, flag);
//			cout << flag << endl;
//		}
//		j++;
//	}
//
//	system("pause");
//}


//int main()
//{
//	string s;
//	cin >> s;
//	stack<char> st;
//	stack<int> stNum;
//	string res;
//	string temp;
//	int k;
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] >= 'A' && s[i] <= 'Z') {
//			st.push(s[i]);
//		}
//		if (s[i] == '[') {
//			st.push(s[i]);
//			k = 0;
//		}
//		if (s[i] >= '0' && s[i] <= '9') {
//			k = k * 10 + (s[i] - '0');
//		}
//		if (s[i] == '|') {
//			stNum.push(k);
//		}
//		if (s[i] == ']') {
//			while (st.top() != '[') {
//				temp = st.top() + temp;
//				st.pop();
//			}
//			st.pop();
//			for (int j = 0; j < stNum.top(); j++) {
//				for (char c : temp) {
//					st.push(c);
//				}
//			}
//			stNum.pop();
//			temp = "";
//		}
//	}
//	while (!st.empty()) {
//		res = st.top() + res;
//		st.pop();
//	}
//	cout << res << endl;
//	system("pause");
//	return 0;
//}
//
//

//
//int main()
//{
//	string s;
//	cin >> s;
//	stack<int> num;
//	stack<string> str;
//	string res;
//	int base = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] >= '0' && s[i] <= '9')
//		{
//			base = base * 10 + s[i] - '0';
//		}
//		else if (s[i] == '|')
//		{
//			num.push(base);
//			base = 0;
//		}
//		else if (s[i] == '[')
//		{
//			str.push(res);
//			res.clear();
//		}
//		else if (s[i] == ']')
//		{
//			int k = num.top();
//			num.pop();
//			while (k--)
//			{
//
//				str.top() += res;
//			}
//			res = str.top();
//			str.pop();
//		}
//		else
//			res += s[i];
//	}
//	cout << res << endl;
//	system("pause");
//}


//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//	
//		string cur;
//		string result;
//		stack<char> s;
//		bool flag = false;
//		int count = 0;
//		for (int i = 0; i < str.size(); i++)
//		{
//			int nums = 0;
//			while (i < str.size() && str[i] >= 'A' && str[i] <= 'Z')
//			{
//				result += str[i];
//				i++;
//			}
//			if (str[i] == '[')
//			{
//				count++;
//				flag = true;
//			}
//			while (flag  && i < str.size() && str[i] >= '0' && str[i] <= '9')
//			{
//				nums = nums * 10 + str[i] - '0';
//				i++;
//			}
//			if (i < str.size() && str[i] == '[')
//			{
//
//			}
//		}
//	}
//	system("pause");
//}


//stack<char> s;
//for (int i = 0; i < str.size(); i++)
//{
//	s.push(str[i]);
//}
//int count = 0;
//string str;
//while (!s.empty())
//{
//	while (!s.empty() && s.top() != ']' && s.top() != '['
//		&& s.top() != '|')
//	{
//		str += s.top();
//		s.pop();
//	}
//	reverse(str.begin(), str.end());
//	str = "" + str;
//	while (!s.empty() && s.top() == ']')
//	{
//		count++;
//		s.pop();
//	}
//	while (!s.empty() && s.top() >= 'A' && s.top() <= 'Z')
//	{
//		cur += s.top();
//		s.pop();
//	}
//	if (!cur.empty())
//		reverse(cur.begin(), cur.end());
//	if (!s.empty() && s.top() == '|')
//	{
//		s.pop();
//		while (!s.empty() && s.top() >= '0' && s.top() <= '9')
//		{
//			c += s.top();
//			s.pop();
//		}
//		reverse(c.begin(), c.end());
//	}
//	for (int i = 0; i < stoi(c); i++)
//	{
//		result +=
//	}