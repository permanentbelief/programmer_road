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
//����
//ʱ�����ƣ� 1000MS
//�ڴ����ƣ� 262144KB
//��Ŀ������
//��һ������Ϊn��ֻ����0��1�����У�ÿ�ο���ʹ��ħ���������ڵ�3�������ڿ����������ħ����ǰ���£�0�ĸ�����1�ĸ���������ֵΪ���٣�����������ֵ��
//
//
//
//��������
//��һ����һ��������n����ʾ���еĳ��ȡ�
//
//�ڶ�����ֻ����0��1�����У��䳤��Ϊn��
//
//�������
//���һ����������ʾ�������ֵ��
//
//
//��������
//5
//00001
//�������
//3

// dp0[x]  ǰx���ַ�0-1������ֵ
// dp1[x]  ǰx���ַ�1-0������ֵ

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
//			//����һ��ǰ2���ַ� 
//			if (a[i - 1] == 1){
//				cnt1++;
//			}
//			f[0][i] = cnt1;			// f[0][i]  ��1-0�Ķ��� 
//			f[1][i] = -cnt1;		// f[i][0]  ��0-1�����ֵ
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
//�ؼ���
//ʱ�����ƣ� 1000MS
//�ڴ����ƣ� 65536KB
//��Ŀ������
//����һ���ַ���Ϊ�ؼ������ҽ����ô��г��ִ��������ַ��ϸ񳬹����ַ�����������������һ�롣
//
//�����ַ���"a","aab","aaab","abccc"�ǹؼ�������"ab","abc","aabb","abcc"���ǡ�
//
//��һ������Ϊn���ַ���s���ж��ٸ��Ӵ��ǹؼ�����
//
//�Ӵ�������һ���������ַ���������������������ַ���ɵ������г�Ϊ�ô����Ӵ���
//
//
//
//��������
//��һ����һ��������n����ʾ�ַ����ĳ��ȡ�
//
//�ڶ�����һ������Ϊn�Ľ�����Сд��ĸ���ַ���s��
//
//�������
//���һ�У���ʾ�ַ���s���ǹؼ������Ӵ�������
//
//
//��������
//5
//ccccb
//�������
//14
//
//
//*/


// �ڶ��� ���
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
	ʱ�����ƣ� 1000MS
	�ڴ����ƣ� 65536KB
	��Ŀ������
	С����Ϊһλ��ʯ�ղؼҺ�����ң��Ա�ʯ����ָ�ơ�ÿ����ʯӵ�в�ͬ�ĵȼ���1����6������

	���죺С�ſ�������1����ʯ��ÿ����һ��1����ʯ����Ҫ����1222�����������ԭ�ϡ�

	�ϳɣ�С�ſ�����ͬ�ȼ��ı�ʯ���ϳɸ��ߵȼ��ı�ʯ������أ�(x+1)��x���ı�ʯ���Ժϳ�Ϊһ��(x+1)���ı�ʯ���úϳɹ�����Ҫ����7890*x����ҡ�

	Ϊ�˺ϳ�6����ʯ��С�Ź�����n�ѵͼ���ʯ��ͬһ�ѱ�ʯ�ĵȼ���һ��������ͬ�ѵı�ʯ�ȼ�Ҳ������ͬ��

	���ڸ�������n�ѱ�ʯÿ�ѵ������͵ȼ��ͼ���״̬�������С����Ҫm��6����ʯ��������Ҫ���ѵĽ�������Ƕ��٣�



	��������
	��һ����һ������n����ʾ��n�ѱ�ʯ��

	������n�У�ÿ����������ai,bi����ʾ��i�ѱ�ʯ��ai�����ȼ�Ϊbi(1��bi��5)��

	���һ����һ������m����ʾС����Ҫ��6����ʯ������

	�������
	һ��һ����������ʾ������Ҫ���ѵĽ������


	��������
	1
	6 2
	1
	�������
	6490746

	��ʾ
	n��20,ai��100000,m��1000


	1
	6 2
	1

*/


// �ϳ�һ��6����Ҫ 10786998
//
//int n, m;
//int v[6];  // ԭ����
//int values[7];     //�ϳɻ���  �ϳ�i�����
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
//	//1222 2444 7332 29328 146640       //�ϳ�һ�� i���� ��ʯ��Ҫ������Ǯ
//
//	for (int i = 1; i <= 5; i++) cout << v[i] << " ";
//	cout << endl;
//
//	for (int i = 2; i <= 6; i++){
//		values[i] = 7890 * (i - 1);
//	}
//
//	// 0 7890 15780 23670 31560 39450   //����һ�� i���� ��ʯ��Ҫ������Ǯ
//	for (int i = 1; i <= 6; i++) cout << values[i] << " ";
//	cout << endl;
//
//
//	for (int i = 1; i <= 6; i++) cout << has[i] << " "; // �ж��ٸ�i����ı�ʯ
//	cout << endl;
//	// �Ѿ��е���
//	m -= has[6];
//	int sums = 0;
//	int left = m; // �����i�� ��Ҫ�ϳɶ��ٸ� 
//	sums += m * (values[6]);
//	sums += m * (v[6]);
//	for (int i = 5; i >= 2; i--){
//		left = left * (i + 1);       //��Ҫi + 1����� left������ ��i����
//		left -= has[i];				// 5������Ҫleft - �����е�left
//		if (left <= 0){
//			break;
//		}
//		sums += (left - has[i]) * values[i];   // 5��left�ĺϳ� 
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
//		//���ѭ��
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
//		//��ǰѭ��
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
��Ŀ������
��һ������Ϊn��ֻ����0��1�����У�ÿ�ο���ʹ��ħ���������ڵ�3�������ڿ����������ħ����ǰ���£�0�ĸ�����1�ĸ���������ֵΪ���٣�����������ֵ��



��������
��һ����һ��������n����ʾ���еĳ��ȡ�

�ڶ�����ֻ����0��1�����У��䳤��Ϊn��

�������
���һ����������ʾ�������ֵ��


��������
5
00001
�������
3

��ʾ
n��100000


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