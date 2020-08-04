#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;



//
///*
//const int N = 1e5 + 1000;
//
//
//int a[N],d1[N],d2[N];
//
//int n;
//int f[N];
//
//int lowbit(int x)
//{
//return x & -x;
//}
//
//void add(int x, int c)
//{
//for(int i = x; i <= maxn; i+= lowbit(x))
//{
//f[i] = max(f[i],c); //维护最大值
//}
//}
//
//int query(int x)
//{
//int res = 0;
//for(int i = x; i >= 1; i -= lowbit(i)) res = max(res,f[i]);
//return res;
//}
//
//int main()
//{
//int k = 0;
//
//int ans1 = 0;
//int ans2 = 0;
//while(scanf("%d",&k) != EOF)
//{
//a[++n] = k;
//}
//for(int i = n; i >= 1; i--)
//{
////求最长不下降的
//int q = query(a[i]) + 1;
//add(a[i],q);
//ans1 = max(ans1,q);
//}
//
//memset(f,0,sizeof f);
//for(int i = 1; i <= n; i++)
//{
////求最长上升的
//int q = query(a[i] - 1) + 1;
//add(a[i],q);
//ans2 = max(ans2,q);
//
//}
//cout << ans1 << endl;
//cout << ans2 << endl;
//
//
//}
//*/
///*
//const int NN = 35;
//const int MM = 35;
//
//int f[NN][MM];
//int n,m;
//int main()
//{
//cin >> n >> m;
//f[0][1] = 1;
////dp[i][j][m] 传了i次球，且已经传球m次了的时候，球在j手上
//// dp[]
//for(int i = 1; i <= m; i++)
//{
//for(int j = 1; j <= n; j++)
//{
//if(j == 1)
//f[i][j] = f[i - 1][n] + f[i - 1][2];
//else if(j == n)
//f[i][j] = f[i - 1][1] + f[i  - 1][n - 1];
//else
//f[i][j] = f[i - 1][j - 1] + f[i- 1][j + 1];
//}
//
//}
//cout << f[m][1] << endl;
//}
//*/
//
///*
//
//#include <iostream>
//#include <cstring>//memset库
//using namespace std;
//int f[31][31],n,m;
//void dfs(int s/*位置*/, int c/*步数*/){
//	f[s][c] = 0;//记忆数组清零
//	if (c == m&&s == 1) f[s][c] = 1;//搜到步数上限并且在小蛮的位置就让这个状况下的记忆数组置一，有一个解
//	if (c != m)//没搜到上限，可能会继续进行递归
//	{
//		if (f[s%n + 1][c + 1] == -1) dfs(s%n + 1, c + 1);//如果右边没有记忆，搜右边
//		if (f[s != 1 ? s - 1 : n][c + 1] == -1) dfs(s != 1 ? s - 1 : n, c + 1);//如果左边没有记忆，搜左边
//		f[s][c] = f[s%n + 1][c + 1] + f[s != 1 ? s - 1 : n][c + 1];//将左右两边的解加起来就可以得到这里的解
//	}
//}
//int main(){
//	memset(f, -1, sizeof(f));//将f数组标记为-1，-1的意思是没有被记录
//	cin >> n >> m;
//	dfs(1, 0);//起始在小蛮的位置，步数为0
//	cout << f[1][0] << endl;//输出起始在小蛮的位置，步数为0的解数
//	return 0;
//}
//*/
///*
//int dp[N][N];
//int dfs(int s, int c)
//{
//if(dp[s][c]) return dp[s][c];
//int sum = 0;
//if(c == m)
//{
//return s == 1 ? 1 : 0;
//}
//dp[s][c] = sum = dfs(s % n + 1,c + 1) + dfs(s == 1 ? n: s - 1, c + 1);
//}
//int main()
//{
//dfs(1,0);
//}
//*/



/*
const int N = 110;
const int M = 110;

const int mod =  1000007;
int a[N];
int b[N];
int dp[N][M];
int n,m;
//int ans;

int dfs(int sum, int i)
{



if(sum > m )
return 0;
else if(sum == m)
{
return 1;
}
if(i == n + 1) return 0;
if(dp[sum][i] ) return dp[sum][i];

int ans = 0;
for(int j = 0; j <= a[i]; j ++)
{
ans = (ans + dfs(sum + j, i + 1))%mod;
}
return dp[sum][i] = ans;
}
int main()
{
cin >> n >> m;
for(int i = 1; i <= n; i++)
{
cin >> a[i];
}


memset(dp,0, sizeof(dp));
dp[0][0] = 1;
for(int i = 1; i <= n; i++)
{
for(int j = 0; j <= m ; j++)
{
for(int k = 0; k <= min(a[i],j); k++)

{
dp[i][j] = ( dp[i][j] + dp[i - 1][j - k]) % mod;
}

}
}
cout << dp[n][m] << endl;
//f[i][j] 前i个数和为j的个数
// cout << dfs(0,1) << endl;
}


*/
//
//const int N = 110;
//const int M = 110;
//
//int a[N];
//int b[N];
//int n, m;
//int ans;
//
//void dfs(int sum, int i)
//{
//	if (sum > m )
//		return;
//	else if (sum == m) // i == n的时候 最后一次要在这里结算，草
//	{
//		ans++;
//		return;
//	}
//	if (i == n + 1)
//		return;
//	for (int j = 0; j <= a[i]; j++)
//	{
//		dfs(sum + j, i + 1);
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	dfs(0, 1);
//	cout << ans << endl;
//	system("pause");
//}




const int N = 1e2 + 100;

//int sum = INT_MAX;
//int index1 = INT_MAX;
//bool flag = false;
//int M, S, T;
//
//void dfs(int m/*魔法值*/, int dis/*剩下的距离*/, int t/*时间*/)
//{
//
//	if (dis <= 0)
//	{
//		flag = true;
//		index1 = min(index1, t);
//		return;
//	}
//	if (t == T)
//	{
//		sum = min(sum, dis);
//		return;
//	}
//	//使用的话
//	if (m >= 10)
//		dfs(m - 10, dis - 60, t + 1);
//
//	//使用的话
//	//1 直接匀速前进
//	dfs(m, dis - 17, t + 1);
//
//	//2. 等法力值恢复
//	dfs(m + 4, dis, t + 1);
//
//}
//int main()
//{
//	cin >> M >> S >> T;
//	dfs(M, S, 0);
//	if (flag == false)
//	{
//		cout << "No" << endl;
//		cout << S - sum << endl;
//	}
//	else
//	{
//		cout << "Yes" << endl;
//		cout << index1 << endl;
//	}
//	system("pause");
//}

//template <class T>
//class initializer_list;

#include <map>

struct myclass
{
	myclass(int, int)
	{
		cout << "~~" << endl;
	}
	myclass(initializer_list<int>)
	{
		cout << "___" << endl;
	}
};



template <class T>
struct S
{
	vector<int> v;
	S(initializer_list<T> l) : v(l)
	{
		cout << "cons" << l.size() << "dada" << endl;
	}
	void append(initializer_list<T> l)
	{
		v.insert(v.end(), l.begin(), l.end());
	}
	pair<const T*, size_t> c_arr() const
	{
		return{ &v[0], v.size() };
	}
};

auto  aa = 100;
//int main()
//{
//	
//
//	//S<int> s = { 1, 2, 3, 4, 5 };
//	//s.append({ 3, 4, 5 });
//	//cout << s.c_arr().second << endl;
//	//cout << s.c_arr().first << endl;
//
//	//for (auto e : s.v)
//	//{
//	//	cout << ' ' << e;
//	//}
//	//S<int> s1 = s;
//	//initializer_list<int>l1 = { 1, 2, 3 };
//	//initializer_list<int> l2 = l1;
//	//cout << l2.size();
//	//for (auto x : { -1, -2, 03 })
//	//{
//	//	cout << x << ' ';
//	//}
//	//cout << endl;
//
//	//int a = 100;
//	//cout << &a << endl; 
//	//cout << *(&a) << endl;
//	//int b = move(a);
//	//cout << &a << endl;
//	//cout << *(&a) << endl;
//	vector<int> v1{ 1, 2, 3, 4 };
//	vector<int> v2 = v1;             // 此时调用复制构造函数，v2是v1的副本
//	vector<int> v3 = std::move(v1);  // 此时调用移动构造函数，v3与v1交换：v1为空，v3为{1, 2, 3, 4}
//
//	cout << v2.size() << endl;
//	system("pause");
//	//C++11 内置类型的列表初始化
//	//动态数组
//	int *arr = new int[5]{ 1, 2, 3, 4, 5 };
//	
//	//你可能会想，std::move函数内部到底是怎么实现的。4
//	//其实std::move函数并不“移动”，它仅仅进行了类型转换。下面给出一个简化版本的std::move
//
//	/*
//	template <typename T>
//	typename remove_reference<T>::type&& move(T&& param)
//	{
//	using ReturnType = typename remove_reference<T>::type&&;
//
//	return static_cast<ReturnType>(param);
//	}
//	
//	，使用的是通用引用类型（&&），意味者其可以接收左值，也可以接收右值。
//	其推导规则如下：如果实参是左值，推导后的形参是左值引用，如果是右值，
//	推导出来的是右值引用（感兴趣的话可以看看reference collapsing）。但是
//	不管怎么推导，ReturnType的类型一定是右值引用，最后std::move函数只是简
//	单地调用static_cast将参数转化为右值引用。所以，std::move什么也没有做，
//	只是告诉编译器将传入的参数无条件地转化为一个右值。所以，当你使用std::
//	move作用于一个对象时，你只是告诉编译器这个对象要转化为右值，然后就有资格进行移动语义了！
//
//=
//
//	*/
//	map<int, int> m = { { 1, 2 }, { 2, 3 }, { 4, 5 } };
//
//
////initializer:
////
////
////	自动构造的场景：
////		编译器会根据初始化列表声明自动构造此类型的对象，
////		1. 初始化列表声明是用大括号括起来的逗号分隔元素的列表
////
////		2.
////
////		仅采用这种类型的一个参数的构造函数是一种特殊的构造函数，
////		称为initializer - list构造函数。
////		使用初始化器列表构造器语法时，初始化器列表构造器优先于其他构造器
////
////		当然啦，里面的std::map必须提供参数为initializer_list的构造函数如：
////
////		map(std::initializer_list<value_type> init,
////		const Compare& comp = Compare(),
////		const Allocator& alloc = Allocator());
////	其实for（initializer： list）中如果list是个形如：{ a, b, c... }，那么其实list自动被构造成了initializer_list对象。
////
////	
//}


class Annotation
{
public:
	explicit Annotation( string& text) :
		m_text{ std::move(text) }
	{ 
		
	}

	const string& getText() const
	{
		cout << &m_text << endl;
		return m_text;
	}

	~Annotation()
	{
		
	}
private:
	string m_text;
};


void foo(const string& str)  // 接收左值
{
	cout << "左值" << endl;
}
void foo(string&& str)    // 接收右值
{
	cout << "右值" << endl;
}

template <typename T>
void wrapper(T&& param)
{
	cout << typeid(param).name() << endl;
	foo(std::forward<T>(param));  // 完美转发
}
//
//int main()
//{
//	//string str1 = "asda";
//	//string str2 = str1;
//	//wrapper(str1);
//	//wrapper(str2);
//
//
//	int a = 10;
//	int b = 0;
//	
//	auto func1 = [&](int c) { a = 100; b = a + c; };
//	func1(10);
//	//cout << a << " " << b << endl;
//
//	//cout << typeid(c).name() << endl;
//	cout << "a :  " << a << endl;
//	cout << "b :  " << b << endl;
//	//string text{ "hello" };
//	//Annotation ant{ text };
//	//string str = ant.getText();
//	//string str1 = ant.getText();
//	//cout << &str1 << endl;
//	//cout << &str << endl;
//	//str = "11100";
//
//	////cout << ant.getText() << endl;  // output: hello
//	//cout << text << endl;           // output: hello 不是空，移动语义没有实现
//	system("pause");
//	return 0;
//}



/*

LRU的实现
*/

//
//class ListNode
//{
//public:
//	ListNode* _prev;
//	ListNode* _next;
//	int _key;
//	int _val;
//	ListNode(int key, int val)
//		: _key(key)
//		,_val(val)
//		, _prev(nullptr)
//		, _next(nullptr)
//	{
//
//	}
//};
//class DoubleList
//{
//private:
//	ListNode* head;
//	ListNode* tail;
//	int size;
//public:
//	DoubleList()
//	{
//		tail = new ListNode(0, 0);
//		head = new ListNode(0, 0);
//		tail->_prev = head;
//		head->_next = tail;
//		size = 0;
//	}
//	void addLast(ListNode* x) // 在 tail前增加节点 
//	{
//		x->_prev = tail->_prev;
//		x->_next = tail;
//		tail->_prev->_next = x;
//		tail->_prev = x;
//		size++;
//	}
//
//	void remove(ListNode* x)
//	{
//		x->_prev->_next = x->_next;
//		x->_next->_prev = x->_prev;
//	}
//	ListNode* removeFirst()
//	{
//		if (head->_next == tail)
//			return nullptr;
//
//		ListNode* node = head->_next;
//
//		node->_prev = head;
//		head->_next= node->_next;
//		return node;
//	}
//public:
//	size_t Getsize() 
//	{
//		return size;
//	}
//};
//class LRUCache
//{
//public:
//	DoubleList l;
//	map<int, ListNode*> m;
//	int _capacity;
//	LRUCache(int capacity)
//	{
//		_capacity = capacity;
//	}
//	void makeRecently(int key) //提升为最近使用
//	{
//		ListNode* node = m[key];
//
//		l.remove(node);
//		l.addLast(node);
//
//	}
//	void addRecently(int  key, int val)
//	{
//		ListNode* newnode = new ListNode(key, val);
//		l.addLast(newnode);
//		m[key] = newnode;
//	}
//	void deletekey(int key)
//	{
//		ListNode* node = m[key];
//		l.remove(node);
//
//		m.erase(key);
//	}
//	void deleteLeastRecently()
//	{
//		ListNode* node = l.removeFirst();
//		if (node != nullptr)
//		{
//			int key = node->_key;
//			m.erase(key);
//		}
//	}
//
//	int get(int key)
//	{
//		if (m.count(key) == 0)
//			return -1;
//		makeRecently(key);
//		return m[key]->_val;
//	}
//
//	void put(int key, int val)
//	{
//		if (m.count(key))
//		{
//			deletekey(key);
//			addRecently(key, val);
//			return;
//		}
//		if (_capacity == (int)l.Getsize())
//		{
//			deleteLeastRecently();
//			
//		}
//		addRecently(key, val);
//	}
//};
//
//
//int main()
//{
//	LRUCache lru(3);
//	lru.put(1, 4);
//	lru.put(2, 4);
//
//	lru.put(3, 4);
//	cout << lru.get(4) <<endl;
//	lru.put(5, 5);
//	cout << lru.get(1) << endl;
//	system("pause");
//}



#include <unordered_map>
#include <unordered_set>

class LFUCache
{
private:
	map<int, int> KeyToVal;
	map<int, int> KeyToF; //频率
	
	map<int, unordered_set<int>> FK; // 一样的频率 后面有多少个
	int capacity;
	int minFeq;
public:
	LFUCache(int capacity)
	{
		capacity = capacity;
		minFeq = 0;
	}
	int get(int key)
	{
		if (!KeyToVal.count(key))
		{
			return -1;
		}
		//增加key的频次
		increase(key);
		return KeyToVal[key];
	}
	void put(int key, int value)
	{
		if (!KeyToVal.count(key))
		{
			KeyToVal[key] = value;
			increase(key); //给key的频次 + 1
			return;
		}

		if (capacity <= KeyToVal.size())
		{
			removeMinFreqKey();
		}

		KeyToVal[key] = value;
		KeyToF[key] = 1;
		//插入KF表
		FK[1].insert(key);

		minFeq = 1;

	}

	void removeMinFreqKey() //删除使用 频数 最小的表
	{
		
	}

	void increase(int key)
	{
		if (!KeyToVal.count(key)) //其实前面的代码逻辑已经判断过了
		{
			return;
		}

		int freq = KeyToF[key];
		
		//更改FK 表
		FK[freq].erase(key);
		FK[freq + 1].insert(key);

		KeyToF[key] = freq + 1;

		if (minFeq == freq)  // minFeq有可能有更改！ 注意！
		{
			if (FK[freq].empty())
			{
				minFeq += 1;
			}
		}
	}
};
//
//template <class T>
//class Vector
//{
//public:
//	Vector(int size = 4)
//		:_size(0)
//		, _cap(size)
//	{
//		tmp = new T[_cap];
//	}
//	Vector<T> (Vector<T>& s)
//	{
//		delete[] tmp;
//		this->_cap = s._cap;
//		this->_size = s._size;
//		tmp = new T[s._size];
//		for (int i = 0; i < s._size; i++)
//		{
//			tmp[i] = s.tmp[i];
//		}
//	}
//	Vector<T>(Vector<T>&& s)
//	{
//		swap(tmp, s.tmp);
//		swap(_size, s._size);
//		swap(_cap, s._cap);
//	}
//	void push(T key)
//	{
//		tmp[_size] = key;
//		_size++;
//	}
//	~Vector()
//	{
//		cout << "析构 ~~~" << endl;
//		delete[] tmp;
//	}
//	void print()
//	{
//		for (int i = 0; i < _size; i++)
//		{
//			cout << tmp[i] << " ";
//		}
//		cout << endl;
//	}
//public:
//	T* tmp;
//	int _size;
//	int _cap;
//};

//void test()
//{
//	Vector<string> v;
//	v.push("dada");
//	v.push("dadada");
//	v.print();
//	Vector<string> vs(move(v));
//	vs.print();
//	v.print();
//}

//void func(const int & lref)
//{
//	cout << "l -value " << endl;
//
//}

template <typename T>
typename remove_reference<T>::type&& move1(T&& param)
{
	using ReturnType = typename remove_reference<T>::type&&;

	return static_cast<ReturnType>(param);
}

void func(int&& rref)
{
	cout << "r -value" << endl;
}
int main()
{
	int x = 10;
	int& cx = x;
	auto e3 = move(cx);
	auto e4 = move(10);

	auto e = move1<int&>(cx);
	auto e1 = move1<int>(10);

	/*int x = 10;
	func(move<int>(x));
	func(10);*/
	//const int& x = 10;
	// int && rrx = 200;
	//rrx = 100;

	// 这点很重要，初始化之后的右值引用将变成一个左值，
	// 如果是non-const还可以被赋值！
	system("pause");

}

class P
{
public:
	string _name;
	P( string& name)
		:_name(move(name))
	{
		cout << &name << endl;
		cout << "----" << endl;
	}
};
//int main()
//{
//	//P a("dad");
//
//	string bn = "dadda";
//	cout << &bn << endl;
//	P b(bn);
//	
//	cout << bn << endl;
//	system("pause");
//
//}