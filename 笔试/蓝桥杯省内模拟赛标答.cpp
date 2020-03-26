#define _CRT_SECURE_NO_WARNINGS 1 





/*
题目
【问题描述】
在1至2019中，有多少个数的数位中包含数字9？
注意，有的数中的数位中包含多个9，这个数只算一次。例如，1999这个数包含数字9，在计算时只是算一个数。
【答案提交】
这是一道结果填空的题，你只需要算出结果后提交即可。本题的结果为一个整数，在提交答案时只填写这个整数，填写多余的内容将无法得分。
————————————————


#include <iostream>

using namespace std;
const int N = 2019;


————————————————

544
*/



/*
第五题 数位递增的数
题目
【问题描述】
一个正整数如果任何一个数位不大于右边相邻的数位，则称为一个数位递增的数，例如1135是一个数位递增的数，而1024不是一个数位递增的数。
给定正整数 n，请问在整数 1 至 n 中有多少个数位递增的数？
【输入格式】
输入的第一行包含一个整数 n。
【输出格式】
输出一行包含一个整数，表示答案。
【样例输入】
30
【样例输出】
26
【评测用例规模与约定】
对于 40% 的评测用例，1 <= n <= 1000。
对于 80% 的评测用例，1 <= n <= 100000。
对于所有评测用例，1 <= n <= 1000000。
————————————————
*/



/*
第六题 递增三元组
题目
【问题描述】
在数列 a[1], a[2], …, a[n] 中，如果对于下标 i, j, k 满足 0<i<j<k<n+1 且 a[i]<a[j]<a[k]，则称 a[i], a[j], a[k] 为一组递增三元组，a[j]为递增三元组的中心。
给定一个数列，请问数列中有多少个元素可能是递增三元组的中心。
【输入格式】
输入的第一行包含一个整数 n。
第二行包含 n 个整数 a[1], a[2], …, a[n]，相邻的整数间用空格分隔，表示给定的数列。
【输出格式】
输出一行包含一个整数，表示答案。
【样例输入】
5
1 2 5 3 5
【样例输出】
2
【样例说明】
a[2] 和 a[4] 可能是三元组的中心。
【评测用例规模与约定】
对于 50% 的评测用例，2 <= n <= 100，0 <= 数列中的数 <= 1000。
对于所有评测用例，2 <= n <= 1000，0 <= 数列中的数 <= 10000。
————————————————
*/



/*


第七题 音节判断
题目
【问题描述】
小明对类似于 hello 这种单词非常感兴趣，这种单词可以正好分为四段，第一段由一个或多个辅音字母组成，第二段由一个或多个元音字母组成，第三段由一个或多个辅音字母组成，第四段由一个或多个元音字母组成。
给定一个单词，请判断这个单词是否也是这种单词，如果是请输出yes，否则请输出no。
元音字母包括 a, e, i, o, u，共五个，其他均为辅音字母。
【输入格式】
输入一行，包含一个单词，单词中只包含小写英文字母。
【输出格式】
输出答案，或者为yes，或者为no。
【样例输入】
lanqiao
【样例输出】
yes
【样例输入】
world
【样例输出】
no
【评测用例规模与约定】
对于所有评测用例，单词中的字母个数不超过100。
————————————————


/*
1. 第一段至少有一个辅音字母
2. 第二段至少元音字母
3. 第三段至少有一个辅音字母
4. 第四段至少有一个元音字母(第四段不能存在辅音)
*/


/*
第八题 长草
题目
【问题描述】
小明有一块空地，他将这块空地划分为 n 行 m 列的小块，每行和每列的长度都为 1。
小明选了其中的一些小块空地，种上了草，其他小块仍然保持是空地。
这些草长得很快，每个月，草都会向外长出一些，如果一个小块种了草，则它将向自己的上、下、左、右四小块空地扩展，这四小块空地都将变为有草的小块。
请告诉小明，k 个月后空地上哪些地方有草。
【输入格式】
输入的第一行包含两个整数 n, m。
接下来 n 行，每行包含 m 个字母，表示初始的空地状态，字母之间没有空格。如果为小数点，表示为空地，如果字母为 g，表示种了草。
接下来包含一个整数 k。
【输出格式】
输出 n 行，每行包含 m 个字母，表示 k 个月后空地的状态。如果为小数点，表示为空地，如果字母为 g，表示长了草。
【样例输入】
4 5
.g...
.....
..g..
.....
2
【样例输出】
gggg.
gggg.
ggggg
.ggg.
【评测用例规模与约定】
对于 30% 的评测用例，2 <= n, m <= 20。
对于 70% 的评测用例，2 <= n, m <= 100。
对于所有评测用例，2 <= n, m <= 1000，1 <= k <= 1000。

————————————————
*/

// DFS也行
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int nums = 0;
//void DFS(vector<vector<char>>&vvc,vector<vector<bool>>&books, int x, int y)
//{
//	static int pos[4][2] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };
//	vvc[x][y] = 'g';
//	books[x][y] = true;
//	if (nums == 1)
//	{
//		nums = 0;
//		return;
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = x + pos[i][0];
//		int ny = y + pos[i][1];
//		if (nx < 0 || nx >= vvc.size() || ny < 0 || ny >= vvc[0].size() || vvc[nx][ny] == 'g' || books[nx][ny] == true)
//			continue;
//		nums++;
//		DFS(vvc, books,nx, ny);
//	}
//}
//int main()
//{
//	int n = 0;
//	int m = 0;
//	
//	cin >> n >> m;
//	vector<vector<char>>vvc(n, vector<char>(m));
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> vvc[i][j];
//		}
//	}
//	int k = 0;
//	cin >> k;
//	while (k--)
//	{
//		vector<vector<bool>> books(vvc.size(), vector<bool>(vvc[0].size(), false));
//		for (int i = 0; i < vvc.size(); i++)
//		{
//			for (int j = 0; j < vvc[0].size(); j++)
//			{
//				if (vvc[i][j] == 'g' && books[i][j] == false)
//				{
//					DFS(vvc,books, i, j);
//				}
//			}
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cout << vvc[i][j];
//		}
//		cout << endl;
//	}
//	system("pause");
//}

/*
第九题 序列计数
题目
【问题描述】
小明想知道，满足以下条件的正整数序列的数量：
1. 第一项为 n；
2. 第二项不超过 n；
3. 从第三项开始，每一项小于前两项的差的绝对值。
请计算，对于给定的 n，有多少种满足条件的序列。
【输入格式】
输入一行包含一个整数 n。
【输出格式】
输出一个整数，表示答案。答案可能很大，请输出答案除以10000的余数。
【样例输入】
4
【样例输出】
7
【样例说明】
以下是满足条件的序列：
4 1
4 1 1
4 1 2
4 2
4 2 1
4 3
4 4
【评测用例规模与约定】
对于 20% 的评测用例，1 <= n <= 5；
对于 50% 的评测用例，1 <= n <= 10；
对于 80% 的评测用例，1 <= n <= 100；
对于所有评测用例，1 <= n <= 1000。

————————————————
*/

//
//void back(vector<vector<int>>& vv, vector<int> tmp)
//{
//	vv.push_back(tmp);
//	for (int i = 1; i < abs(tmp[tmp.size() - 1] - tmp[tmp.size() -2]); i++)
//	{
//		tmp.push_back(i);
//		back(vv, tmp);
//		tmp.pop_back();
//	}
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<vector<int>> vv;
//	n = n % 10000;
//	vector<int> tmp(1, n);
//	for (int i = 1; i <= n; i++)
//	{
//		vector<int> tep(tmp);
// 		tep.push_back(i);
//		back(vv, tep);
//	}
//	for (auto e : vv)
//	{
//		for (auto ee : e)
//		{
//			cout << ee << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//}

//void DFS(vector<vector<int>>&vv, vector<int> tmp, int n)
//{
//	vv.push_back(tmp);
//	for (int i = 1; i <= n ; i++)
//	{
//		if (i < abs(tmp[tmp.size() - 1] - tmp[tmp.size() - 2]))
//		{
//			tmp.push_back(i);
//			DFS(vv, tmp, n);
//			tmp.pop_back();
//		}
//	}
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<vector<int>> vv;
//	vector<int> tmp(1,n);
//	for (int i = 1; i <= 4; i++)
//	{
//		vector<int> ttmp(tmp);
//		ttmp.push_back(i);
//		DFS(vv, ttmp, n);
//	}
//	for (auto& e : vv)
//	{
//		for (auto& ee : e)
//		{
//			cout << ee << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//
//
//}


/*
第十题 晚会节目单
题目
【问题描述】
小明要组织一台晚会，总共准备了 n 个节目。然后晚会的时间有限，他只能最终选择其中的 m 个节目。
这 n 个节目是按照小明设想的顺序给定的，顺序不能改变。
小明发现，观众对于晚会的喜欢程度与前几个节目的好看程度有非常大的关系，他希望选出的第一个节目尽可能好看，在此前提下希望第二个节目尽可能好看，依次类推。
小明给每个节目定义了一个好看值，请你帮助小明选择出 m 个节目，满足他的要求。
【输入格式】
输入的第一行包含两个整数 n, m ，表示节目的数量和要选择的数量。
第二行包含 n 个整数，依次为每个节目的好看值。
【输出格式】
输出一行包含 m 个整数，为选出的节目的好看值。
【样例输入】
5 3
3 1 2 5 4
【样例输出】
3 5 4
【样例说明】
选择了第1, 4, 5个节目。
【评测用例规模与约定】
对于 30% 的评测用例，1 <= n <= 20；
对于 60% 的评测用例，1 <= n <= 100；
对于所有评测用例，1 <= n <= 100000，0 <= 节目的好看值 <= 100000。

————————————————

*/

/*
6 3
2 6 3 3 1 3
*/
//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int n, m;
//
//struct node{
//	int deep; // 好看值
//	int id;   // 下标
//};
//
//bool cmp1(node a, node b)
//{
//	return a.deep > b.deep; //降序
//}
//
//bool cmp2(node a, node b)
//{
//	return a.id < b.id;   //升序
//}
//
//vector<node> ans;
//int main()
//{
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++) //  2 6 3 3 1 3
//	{							//  0 1 2 3 4 5
//		node t;
//		cin >> t.deep; // 就是分值。
//		t.id = i;
//		ans.push_back(t);
//	}
//	sort(ans.begin(), ans.end(), cmp1);  // 函数指针
//	sort(ans.begin(), ans.begin() + m, cmp2); //函数指针
//
//	for (int i = 0; i < m; i++) 
//	{
//		cout << ans[i].deep << " ";
//	}
//	system("pause");
//	return 0;
//}

