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


//实现一个shared_ptr.

/*
京东:
一面

1.问了一些项目问题。

2.简单实现一个shared_ptr,


3.vector底层怎么实现的

三个指针，第1个指针指向数组的起始位置start，第2个指针指向存储最多数据的位置end，第3个指针指向容量的最大值end_of_storage

4.uordered_map底层怎么实现的

unordered_map是哈希表实现的，一个带有映射关系的数组。

5.讲一下多态

6.模板是什么时候实例化的

7.你有什么问题问我

给我介绍了一下他们部门

二面

1.问我为啥做这个项目

2.项目有啥应用

3.项目的缺点

4.项目性能怎么样？

5.什么时候能去实习，实习多久

然后就结束了。。二面总共20分钟


虚函数的实现机制.

虚函数是依靠子类重写父类的虚函数，完成在子类虚函数表上的覆盖。依靠类中的虚函数表指针指向虚函数，进行调用。

讲讲inline.

1.用inline关键字修饰的函数，编译器会在调用内联函数的地方展开。inline函数适合
很短的代码，省去调用函数的开销，是一种空间换时间的做法。
2. 对于编译器而言只是一个建议，编译器看情况进行优化（编译器对于循环，递归，冗余不做处理）
3. 注意的问题： inline函数没有地址，所以不支持分离编译


C++如何在main()函数执行之前执行一个函数?

linux下 _attribute main()。  
vs下， 依靠对象的构造函数 和 静态函数实现  


如果在构造函数调用一个类的虚函数会发生什么?

1. 在基类的构造函数中，虚函数还没有被定义，因为虚表是在构造函数中构造的
2. 当我们构造一个子类的对象是，先调用基类的构造函数，构造子类中基类的部分,子类还没有构造，还没有初始化，调用没有初始化的变量


继承条件下基类派生类的构造函数各自调用自己的虚函数(派生类重写过), 创建基类和派生类对象分别会发生什么?

vector list区别?

vector list 中如何删除元素? 用remove 和erase的区别?


网络字节序是什么?

网络字节序是大端字节序，因为每一个网卡的厂商不一样，所以就规定了网络中的通信按照大端字节序来通信，避免
通信中数据的二义性。

视频聊天适合哪种传输层协议? 为什么?(面试官想让你说: UDP, 速度快)

udp，因为udp传输数据快，不用进行三次握手建立连接，udp的特性是无连接，不可靠，面向数据报。
因为视频要求实时性，丢失一两帧没什么问题。


socket默认是阻塞还是非阻塞?

socket默认是非阻塞的，当调用accept方法的时候，这个是阻塞的，等待监听由客户端来的连接

什么是哈希表? 如何解决哈希冲突?






常用进程间通信方法.


举例说明什么是死锁.

一般什么情况程序会崩溃?(面试官: 需要说很多种)



HTTPS为什么安全?

在数组中找到重复次数出现最多的数? 至少两种方法. 其中一种空间复杂度要求O(1)

反问? (建议大家提前准备好, 我说我没问题)
一面太紧张了, 电话都在手里抖, 说话一开始也有点结巴. 还是太嫩了. 二面用耳机了.

2. 二面 4.07
自我介绍.
项目介绍.
岗位介绍, 你想来哪个? (要能去我站着都行)
.c与.cpp如何混合编程, 为什么需要extern “C”?
C++11新特性有什么?
传输文件用什么传输层协议? 用UDP怎么传文件?
滑动窗口如何适应带宽?
HTTPS为什么安全? 为什么非对称加密算法能保证安全?(需要讲非对称加密算法的原理)
文件MD5是什么? MD5原理?
TCP为什么挥手比握手多一次?
100KB数据直接用TCP/UDP发送分别有什么问题? 不分包会怎么样?
链表和数组的区别以及应用场景?
STL map底层是什么? 什么是红黑树? 为什么效率高?
进程间通信方式及使用场景.
什么是XSS漏洞?
什么是缓冲区溢出? 使用strcpy()溢出怎么办?(面试官想让你说: 用strncpy())
实习时间多长?
反问(二面感觉二面回答的可以, 嚣张了起来. 我还有几面? )
*/