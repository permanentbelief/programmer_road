#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

string shortestPalindrome(string s) {
	string s_reverse(s), s_new;
	reverse(s_reverse.begin(), s_reverse.end());
	s_new = s + "#" + s_reverse;
	int i = -1, j = 0;  //i指向前缀下标初始-1，j指向后缀下标初始0
	//next[j]表示j之前的字符串的最长前缀和后缀相等的字符个数，即最长前缀的下一个字符下标
	vector<int> next(s_new.size() + 1, 0);
	next[0] = -1;
	//循环扫描字符串s_new
	while (j < s_new.size())
	{
		if (i == -1 || s_new[i] == s_new[j])
		{
			i++;
			j++;
			next[j] = i;
		}
		else
			i = next[i];
	}
	//将s_new的s_reverse的与s非重复重复部分截取拼接上s就是最短回文串结果
	return s_new.substr(s.size() + 1, s.size() - next[s_new.size()]) + s;
}

class A
{
public:
	int a = 10;
};
//int main()
//{
//	//string str = "aabbabb";
//	//vector<int> next(str.size()+1,0);
//	//next[0] = -1;
//	//int i = -1;
//	//int j = 0;
//	////循环扫描字符串s_new
//	//while (j < str.size())
//	//{
//	//	if (i == -1 || str[i] == str[j])
//	//	{
//	//		i++;
//	//		j++;
//	//		next[j] = i;
//	//	}
//	//	else
//	//		i = next[i];
//	//}
//
//	system("pause");
//}
class  C
{
public:
	int a = 10;
};
class B : public C
{
public:
	int c = 10;
};

void foo(const string& str)
{


}

class Animal
{
public:
	char name[20];
	virtual void Speak() = 0;
	void introduce();
};
class Cat :public Animal
{
public:
	char color[20];
	virtual void Speak()
	{
		cout << "cat" << endl;
	}
	void ShowColor();
};
class Dog : public Animal
{
public:
	virtual void Speak()
	{
		cout << "dog" << endl;
	}

};




int partition(vector<int>& v, int left, int right)
{
	
	int end = v[right];
	int small = left - 1;
	for (int i = left; i < right; i++)
	{
		if (v[i] < end)
		{
			++small;
			if (small != i)
			{
				swap(v[small], v[i]);
			}
		}
	}
	++small;
	swap(v[small], v[right]);
	return small;
}

vector<int> func(vector<int>& arr, int k)
{
	int index = partition(arr, 0, arr.size() - 1);
	int left = 0;
	int right = arr.size() - 1;
	while (index != k - 1)
	{
		if (index > k - 1)
		{
			right = index - 1;
			index = partition(arr, left, right);
		}
		else if (index <= k - 1)
		{
			left = index + 1;
			index = partition(arr, left, right);
		}
	}
	vector<int> v;
	for (int i = 0; i < k; i++)
	{
		v.push_back(arr[i]);
	}
	return v;
}

class Person
{
public:
	Person(char* s = "", int age = 10)
		:_name(new char[sizeof(s) + 1])
		, _age(age)
	{
		strcpy(_name, s);
	}
	//Person()
	//{

	//}
	~Person()
	{
		
	}
	Person(const Person& p)
	{
		if (_name)
		{
			delete []_name;
		}
		_name = new char[sizeof(p._name) + 1];
		strcpy(_name, p._name);
		_age = p._age;
	}
	Person& operator=(const Person& p)
	{
		if (this != &p)
		{
			_name = new char[sizeof(p._name) + 1];
			strcpy(_name, p._name);
			_age = p._age;
		}
		return *this;
	}
	Person* operator&()
	{
		return this;
	}
	const Person* operator&() const
	{
		return  this;
	}
public:
	char* _name;
	int _age;
};


template <class T>
//模板单例
int main()
{

	Person k;
	cout << k._age << endl;
	cout << k._name << endl;
	Person Tom("Tom", 20);
	Person Cat(Tom);
	cout << Cat._name << endl;
	cout << Cat._age << endl;
	system("pause");

}