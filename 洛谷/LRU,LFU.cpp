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
//f[i] = max(f[i],c); //ά�����ֵ
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
////������½���
//int q = query(a[i]) + 1;
//add(a[i],q);
//ans1 = max(ans1,q);
//}
//
//memset(f,0,sizeof f);
//for(int i = 1; i <= n; i++)
//{
////���������
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
////dp[i][j][m] ����i�������Ѿ�����m���˵�ʱ������j����
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
//#include <cstring>//memset��
//using namespace std;
//int f[31][31],n,m;
//void dfs(int s/*λ��*/, int c/*����*/){
//	f[s][c] = 0;//������������
//	if (c == m&&s == 1) f[s][c] = 1;//�ѵ��������޲�����С����λ�þ������״���µļ���������һ����һ����
//	if (c != m)//û�ѵ����ޣ����ܻ�������еݹ�
//	{
//		if (f[s%n + 1][c + 1] == -1) dfs(s%n + 1, c + 1);//����ұ�û�м��䣬���ұ�
//		if (f[s != 1 ? s - 1 : n][c + 1] == -1) dfs(s != 1 ? s - 1 : n, c + 1);//������û�м��䣬�����
//		f[s][c] = f[s%n + 1][c + 1] + f[s != 1 ? s - 1 : n][c + 1];//���������ߵĽ�������Ϳ��Եõ�����Ľ�
//	}
//}
//int main(){
//	memset(f, -1, sizeof(f));//��f������Ϊ-1��-1����˼��û�б���¼
//	cin >> n >> m;
//	dfs(1, 0);//��ʼ��С����λ�ã�����Ϊ0
//	cout << f[1][0] << endl;//�����ʼ��С����λ�ã�����Ϊ0�Ľ���
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
//f[i][j] ǰi������Ϊj�ĸ���
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
//	else if (sum == m) // i == n��ʱ�� ���һ��Ҫ��������㣬��
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
//void dfs(int m/*ħ��ֵ*/, int dis/*ʣ�µľ���*/, int t/*ʱ��*/)
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
//	//ʹ�õĻ�
//	if (m >= 10)
//		dfs(m - 10, dis - 60, t + 1);
//
//	//ʹ�õĻ�
//	//1 ֱ������ǰ��
//	dfs(m, dis - 17, t + 1);
//
//	//2. �ȷ���ֵ�ָ�
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
//	vector<int> v2 = v1;             // ��ʱ���ø��ƹ��캯����v2��v1�ĸ���
//	vector<int> v3 = std::move(v1);  // ��ʱ�����ƶ����캯����v3��v1������v1Ϊ�գ�v3Ϊ{1, 2, 3, 4}
//
//	cout << v2.size() << endl;
//	system("pause");
//	//C++11 �������͵��б��ʼ��
//	//��̬����
//	int *arr = new int[5]{ 1, 2, 3, 4, 5 };
//	
//	//����ܻ��룬std::move�����ڲ���������ôʵ�ֵġ�4
//	//��ʵstd::move�����������ƶ���������������������ת�����������һ���򻯰汾��std::move
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
//	��ʹ�õ���ͨ���������ͣ�&&������ζ������Խ�����ֵ��Ҳ���Խ�����ֵ��
//	���Ƶ��������£����ʵ������ֵ���Ƶ�����β�����ֵ���ã��������ֵ��
//	�Ƶ�����������ֵ���ã�����Ȥ�Ļ����Կ���reference collapsing��������
//	������ô�Ƶ���ReturnType������һ������ֵ���ã����std::move����ֻ�Ǽ�
//	���ص���static_cast������ת��Ϊ��ֵ���á����ԣ�std::moveʲôҲû������
//	ֻ�Ǹ��߱�����������Ĳ�����������ת��Ϊһ����ֵ�����ԣ�����ʹ��std::
//	move������һ������ʱ����ֻ�Ǹ��߱������������Ҫת��Ϊ��ֵ��Ȼ������ʸ�����ƶ������ˣ�
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
////	�Զ�����ĳ�����
////		����������ݳ�ʼ���б������Զ���������͵Ķ���
////		1. ��ʼ���б��������ô������������Ķ��ŷָ�Ԫ�ص��б�
////
////		2.
////
////		�������������͵�һ�������Ĺ��캯����һ������Ĺ��캯����
////		��Ϊinitializer - list���캯����
////		ʹ�ó�ʼ�����б������﷨ʱ����ʼ�����б���������������������
////
////		��Ȼ���������std::map�����ṩ����Ϊinitializer_list�Ĺ��캯���磺
////
////		map(std::initializer_list<value_type> init,
////		const Compare& comp = Compare(),
////		const Allocator& alloc = Allocator());
////	��ʵfor��initializer�� list�������list�Ǹ����磺{ a, b, c... }����ô��ʵlist�Զ����������initializer_list����
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


void foo(const string& str)  // ������ֵ
{
	cout << "��ֵ" << endl;
}
void foo(string&& str)    // ������ֵ
{
	cout << "��ֵ" << endl;
}

template <typename T>
void wrapper(T&& param)
{
	cout << typeid(param).name() << endl;
	foo(std::forward<T>(param));  // ����ת��
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
//	//cout << text << endl;           // output: hello ���ǿգ��ƶ�����û��ʵ��
//	system("pause");
//	return 0;
//}



/*

LRU��ʵ��
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
//	void addLast(ListNode* x) // �� tailǰ���ӽڵ� 
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
//	void makeRecently(int key) //����Ϊ���ʹ��
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
	map<int, int> KeyToF; //Ƶ��
	
	map<int, unordered_set<int>> FK; // һ����Ƶ�� �����ж��ٸ�
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
		//����key��Ƶ��
		increase(key);
		return KeyToVal[key];
	}
	void put(int key, int value)
	{
		if (!KeyToVal.count(key))
		{
			KeyToVal[key] = value;
			increase(key); //��key��Ƶ�� + 1
			return;
		}

		if (capacity <= KeyToVal.size())
		{
			removeMinFreqKey();
		}

		KeyToVal[key] = value;
		KeyToF[key] = 1;
		//����KF��
		FK[1].insert(key);

		minFeq = 1;

	}

	void removeMinFreqKey() //ɾ��ʹ�� Ƶ�� ��С�ı�
	{
		
	}

	void increase(int key)
	{
		if (!KeyToVal.count(key)) //��ʵǰ��Ĵ����߼��Ѿ��жϹ���
		{
			return;
		}

		int freq = KeyToF[key];
		
		//����FK ��
		FK[freq].erase(key);
		FK[freq + 1].insert(key);

		KeyToF[key] = freq + 1;

		if (minFeq == freq)  // minFeq�п����и��ģ� ע�⣡
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
//		cout << "���� ~~~" << endl;
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

	// ������Ҫ����ʼ��֮�����ֵ���ý����һ����ֵ��
	// �����non-const�����Ա���ֵ��
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