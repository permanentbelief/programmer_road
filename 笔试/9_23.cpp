#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

#include <set>

using namespace std;

// һ����ֻ�ܴ���һ������Ҳ����˵һ����ֻ����һ��ʵ�������ṩʵ����ȫ�ַ��ʵ�

// ����ģʽ

// ����ģʽ


// ����ģʽ �����ڶ��ϵ� 
class Singleton {
public:
	static Singleton* Get()
	{
		return _sInst;
	}
	int a = 3;
	int b = 4;
private:

	Singleton()
	{

	}
	Singleton(const Singleton&) = delete;

	 static Singleton *_sInst;
	
};

Singleton* Singleton::_sInst = new Singleton();




class A
{
public:
	int _aa = 10;
	int _ab = 9;
	A()
	{
		cout << "A()" << endl;
	}
	virtual void func()
	{
		cout << "virtual ::func()" << endl;
	}
};
class B : public A
{
public:
	B()
	{
		cout << "B() " << endl;
	}

	void func()
	{
		A::func();
		cout << " ~B() " << endl;
	}

	int bb = 1000;


};

int main()
{
	

	vector<int> v;
	v.reserve(20);

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.push_back(1);
	v.push_back(2);
	v.push_back(30);

	v.push_back(400);

	v.resize(21);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	int * ptr = nullptr;
    ptr = new int[100000000];
	cout << ptr << endl;


	system("pause");
}

