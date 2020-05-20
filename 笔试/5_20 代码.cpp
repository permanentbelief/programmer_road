#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <mutex>

using namespace std;

//typedef mutex Lock;
//template <class T>
//class shared_ptr
//{
//	shared_ptr(T* ptr= nullptr)
//	:_ptr(ptr)
//	, _lock(new mutex)
//	, _count(new int(1))
//	{}
//	~shared_ptr()
//	{
//
//	}
//	shared_ptr<T>(const shared_ptr<T>& ap)
//	{
//		if (_ptr != nullptr)
//		{
//			delete[]_ptr;
//		}
//
//		_ptr = ap->_ptr;
//		_count = ap->_count;
//		_lock = ap->_lock;
//		
//	}
//	shared_ptr<T>& operator=(const shared_ptr<T>& ap)
//	{
//		if (this != &ap && _ptr != ap._ptr)
//		{
//			//先释放原地资源
//			ReleaseRef();
//			_ptr = ap._ptr;
//			_count = ap._count;
//			_lock = ap._lock;
//			AddRef();
//
//		}
//		return  *this;
//	}
//	void AddRef()
//	{
//		_lock->lock();
//		++(*_count);
//		_lock->unlock();
//	}
//	void ReleaseRef()
//	{
//		bool deleteflag = false;
//		_lock->lock();
//		if (--(*count) == 0)
//		{
//			delete count;
//			delete _ptr;
//			deleteflag = true;
//		}
//		_lock->unlock();
//
//		if (deleteflag == true)
//		{
//			delete _lock;
//		}
//	}
//	T& operator()
//	{
//		return *_ptr;
//	}
//
//	T* oparator->()
//	{
//		return _ptr;
//	}
//public:
//	T* _ptr;
//	Lock* _lock;
//	int* _count;
//};


template <class T>
class shared_ptr
{
public:
	shared_ptr(T* ptr = nullptr)
		:_ptr(ptr)
		, _pCount(new int(1))
		, Mutex(new mutex)
	{
	}
	~shared_ptr()
	{
		ReleaseRef();
	}
	shared_ptr<T>(shared_ptr<T>& sp)
		:_ptr(sp._ptr)
		, _pCount(sp._pCount)
		, Mutex(sp.Mutex)
	{
		AddRef();

	}
	shared_ptr<T>& operator=(const shared_ptr<T>& sp)
	{
		if (this != &sp  && _ptr != sp._ptr)
		{

			// 先释放原对象的资源
			ReleaseRef();
			_ptr = sp._ptr;
			_pCount = sp._pCount; // 引用计数赋值过去
			Mutex = sp.Mutex;  // 互斥锁变量也要赋值过去
			AddRef();
		}
		return *this;
	}


	// 引用计数的线程安全问题
	// 加引用计数
	void AddRef()
	{
		Mutex->lock();
		++(*_pCount);
		Mutex->unlock();
	}

	// 减引用计数
	void ReleaseRef()
	{

		bool deleteflag = false;
		Mutex->lock();
		if (--(*_pCount) == 0)
		{
			delete _pCount;
			delete _ptr;
			deleteflag = true; //如果资源减到0的话， true
		}
		Mutex->unlock();

		if (deleteflag == true) //释放堆上的锁资源
		{
			delete Mutex;
		}
	}
	T& operator*()
	{
		return *_ptr;
	}

	T*operator->()
	{
		return _ptr;
	}
	int GetRefCount()
	{
		return *_pCount;
	}
	T* GetPtr() const
	{
		return _ptr;
	}
private:
	T* _ptr;
	int* _pCount;
	mutex* Mutex;

public:
	void test_threads()
	{
		shared_ptr<int> sp(new int);
		vector<thread> vthreads;
		for (size_t i = 0; i < 2; i++)
		{
			vhreads.push_back()
			{

			}
		}
	}
};


