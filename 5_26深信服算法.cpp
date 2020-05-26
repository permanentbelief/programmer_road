#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> partition(vector<int>& arr, int left, int right)
{
	int L = left - 1;
	int R = right;
	while (left < R)
	{
		if (arr[left] < arr[right])
		{
			swap(arr[++L], arr[left++]);
		}
		else if (arr[left] == arr[right])
		{
			left++;
		}
		else // arr[left] > arr[R]
		{
			swap(arr[--R], arr[left]);
		}
	}
	swap(arr[right], arr[left]);
	return vector<int> { L + 1, R };
}
void QuickSort(vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		vector<int> tmp = partition(arr, left, right);
		QuickSort(arr, left, tmp[0] - 1);
		QuickSort(arr, tmp[1] + 1, right);
	}
}
#include <ctime>

//int main()
//{
//	srand(time(nullptr));
//	vector<int> arr(10);
//	for (int i = 0; i < arr.size(); i++)
//	{
//		arr[i] = rand() % 20 + 1;
//	}
//	QuickSort(arr, 0, 9);
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	system("pause");
//}

//
//void dfs(int sum, vector<int>& v, vector<int>& count, int _count, int& min_)
//{
//	if (sum <= 0)
//	{
//		min_ = min(min_, _count);
//		return;
//	}
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (sum - v[i] >= 0)
//		{
//			_count += count[i];
//			dfs(sum - v[i], v, count, _count, min_);
//		}
//	}
//}
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		int a = 0;
//		int b = 0;
//		int c = 0;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> a;
//			cin >> b;
//			cin >> c;
//
//			int sum = a;
//			int min_ = INT_MAX;
//			vector<int> v = { 500, 1500 };
//			vector<int> count = { b, c };
//			dfs(a, v, count, 0, min_);
//			cout << min_ << endl;
//		}
//		
//
//
//	}
//	system("pause");
//}


//#include<cstdio>
//#include<cstring>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int len2;
//int next1[20004];
//char s2[20004];
//void get_next(char *s2, int len2){
//	memset(next1, 0, sizeof(next1));
//	int t1 = 0, t2;
//	next1[0] = t2 = -1;
//	while (t1<len2){
//		if (t2 == -1 || s2[t1] == s2[t2]) next1[++t1] = ++t2;
//		else t2 = next1[t2];
//	}
//}
//int ret = 0;
//int mk = 100005;
//int main(){
//	scanf("%s", s2);
//	len2 = strlen(s2);
//	for (int i = 0; i<len2; i++){
//		get_next(s2 + i, len2 - i);
//		for (int j = 1; j <= len2 - i; j++){
//			if (j % (j - next1[j]) == 0 && next1[j]){
//				int c33 = j / (j - next1[j]);
//				if (c33 % 2 == 0) ret = max(ret, j);
//			}
//		}
//	}
//	cout << ret << endl;
//	return 0;
//}


#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010;
char s[N], stk[N];

int get(char c1, char c2) {
	int res;
	if (c1 >= '0' && c1 <= '9') res = c1 - '0';
	if (c1 >= 'a' && c2 <= 'f') res = c1 - 'a' + 10;
	if (c1 >= 'A' && c2 <= 'F') res = c1 - 'A' + 10;

	if (c2 >= '0' && c2 <= '9') res = res * 16 + c2 - '0';
	if (c2 >= 'a' && c2 <= 'f') res = res * 16 + c2 - 'a' + 10;
	if (c2 >= 'A' && c2 <= 'F') res = res * 16 + c2 - 'A' + 10;

	return res;
}

bool isnum(char x) {
	return (x >= '0' && x <= '9') || (x >= 'A' && x <= 'F') || (x >= 'a' && x <= 'f');
}


class A
{
public:
	A()
	{
		func();
	}
	virtual void func()
	{
		cout << "delete []A()" << endl;
	}
};
class B : public A
{
public:
	B()
	{
		func();
	}
	virtual void func()
	{
		cout << "yes" << endl;
	}
	~B()
	{

	}

};

int main()
{
	B b;
	system("pause");
}


//ʵ��һ��shared_ptr.

/*
����:
һ��

1.����һЩ��Ŀ���⡣

2.��ʵ��һ��shared_ptr,


3.vector�ײ���ôʵ�ֵ�

����ָ�룬��1��ָ��ָ���������ʼλ��start����2��ָ��ָ��洢������ݵ�λ��end����3��ָ��ָ�����������ֵend_of_storage

4.uordered_map�ײ���ôʵ�ֵ�

unordered_map�ǹ�ϣ��ʵ�ֵģ�һ������ӳ���ϵ�����顣

5.��һ�¶�̬

6.ģ����ʲôʱ��ʵ������

7.����ʲô��������

���ҽ�����һ�����ǲ���

����

1.����Ϊɶ�������Ŀ

2.��Ŀ��ɶӦ��

3.��Ŀ��ȱ��

4.��Ŀ������ô����

5.ʲôʱ����ȥʵϰ��ʵϰ���

Ȼ��ͽ����ˡ��������ܹ�20����


�麯����ʵ�ֻ���.

�麯��������������д������麯��������������麯�����ϵĸ��ǡ��������е��麯����ָ��ָ���麯�������е��á�

����inline.

1.��inline�ؼ������εĺ��������������ڵ������������ĵط�չ����inline�����ʺ�
�̵ܶĴ��룬ʡȥ���ú����Ŀ�������һ�ֿռ任ʱ���������
2. ���ڱ���������ֻ��һ�����飬����������������Ż�������������ѭ�����ݹ飬���಻������
3. ע������⣺ inline����û�е�ַ�����Բ�֧�ַ������


C++�����main()����ִ��֮ǰִ��һ������?

linux�� _attribute main()��  
vs�£� ��������Ĺ��캯�� �� ��̬����ʵ��  


����ڹ��캯������һ������麯���ᷢ��ʲô?

1. �ڻ���Ĺ��캯���У��麯����û�б����壬��Ϊ������ڹ��캯���й����
2. �����ǹ���һ������Ķ����ǣ��ȵ��û���Ĺ��캯�������������л���Ĳ���,���໹û�й��죬��û�г�ʼ��������û�г�ʼ���ı���


�̳������»���������Ĺ��캯�����Ե����Լ����麯��(��������д��), ������������������ֱ�ᷢ��ʲô?

vector list����?

vector list �����ɾ��Ԫ��? ��remove ��erase������?


�����ֽ�����ʲô?

�����ֽ����Ǵ���ֽ�����Ϊÿһ�������ĳ��̲�һ�������Ծ͹涨�������е�ͨ�Ű��մ���ֽ�����ͨ�ţ�����
ͨ�������ݵĶ����ԡ�

��Ƶ�����ʺ����ִ����Э��? Ϊʲô?(���Թ�������˵: UDP, �ٶȿ�)

udp����Ϊudp�������ݿ죬���ý����������ֽ������ӣ�udp�������������ӣ����ɿ����������ݱ���
��Ϊ��ƵҪ��ʵʱ�ԣ���ʧһ��֡ûʲô���⡣


socketĬ�����������Ƿ�����?

socketĬ���Ƿ������ģ�������accept������ʱ������������ģ��ȴ������ɿͻ�����������

ʲô�ǹ�ϣ��? ��ν����ϣ��ͻ?






���ý��̼�ͨ�ŷ���.


����˵��ʲô������.

һ��ʲô�����������?(���Թ�: ��Ҫ˵�ܶ���)



HTTPSΪʲô��ȫ?

���������ҵ��ظ���������������? �������ַ���. ����һ�ֿռ临�Ӷ�Ҫ��O(1)

����? (��������ǰ׼����, ��˵��û����)
һ��̫������, �绰�������ﶶ, ˵��һ��ʼҲ�е���. ����̫����. �����ö�����.

2. ���� 4.07
���ҽ���.
��Ŀ����.
��λ����, �������ĸ�? (Ҫ��ȥ��վ�Ŷ���)
.c��.cpp��λ�ϱ��, Ϊʲô��Ҫextern ��C��?
C++11��������ʲô?
�����ļ���ʲô�����Э��? ��UDP��ô���ļ�?
�������������Ӧ����?
HTTPSΪʲô��ȫ? Ϊʲô�ǶԳƼ����㷨�ܱ�֤��ȫ?(��Ҫ���ǶԳƼ����㷨��ԭ��)
�ļ�MD5��ʲô? MD5ԭ��?
TCPΪʲô���ֱ����ֶ�һ��?
100KB����ֱ����TCP/UDP���ͷֱ���ʲô����? ���ְ�����ô��?
���������������Լ�Ӧ�ó���?
STL map�ײ���ʲô? ʲô�Ǻ����? ΪʲôЧ�ʸ�?
���̼�ͨ�ŷ�ʽ��ʹ�ó���.
ʲô��XSS©��?
ʲô�ǻ��������? ʹ��strcpy()�����ô��?(���Թ�������˵: ��strncpy())
ʵϰʱ��೤?
����(����о�����ش�Ŀ���, ����������. �һ��м���? )
*/