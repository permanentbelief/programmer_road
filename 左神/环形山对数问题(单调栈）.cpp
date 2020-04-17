#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Pair
{
public:
	int value;
	int times;
public:
	Pair(int _value)
	{
		value = _value;
		times = 1;
	}
};

static int nextIndex(int size, int i) //因为是一个环，走到数组最后,要回到0位置继续
{
	return i < (size - 1) ? (i + 1) : 0; 
}
static long getInternalSum(int n)
{
	return n == 1L ? 0L : (long)n*(long)(n - 1) / 2L;
}
long communication(vector<int> arr)
{
	if (arr.size() < 2)
		return 0;
	int size = arr.size();
	int maxIndex = 0;
	for (int i = 0; i < size; i++)
	{
		maxIndex = arr[maxIndex] < arr[i] ? i : maxIndex;
	}
	int value = arr[maxIndex];
	int index = nextIndex(size, maxIndex);
	long res = 0L;
	stack<Pair> st;
	st.push(Pair(value));//将最大值压入栈底
	while (index != maxIndex) // 当遍历一圈到maxIndex位置，就结束
	{
		value = arr[index];  // 取数组中当前的值
		while (!st.empty() && st.top().value < value) //没法满足栈中从大到小的顺序，所以有数据要弹出，进行结算
		{
			int times = st.top().times;
			st.pop();
			//           C(k,2)就是重复的  左右
			res += getInternalSum(times) + times * 2;
		}
		if (!st.empty() && st.top().value == value) //当前的值与栈顶的值相等，times++
		{
			st.top().times++;
		}
		else // 可以落在上面，小于栈顶，新建一条数据
		{
			st.push(Pair(value)); 
		}
		index = nextIndex(size, index);
	}
	while (!st.empty())
	{
		int times = st.top().times;
		st.pop();
		res += getInternalSum(times);
		if (!st.empty())
		{
			res += times;
			if (st.size() > 1)
			{
				res += times;
			}
			else
			{
				res += st.top().times > 1 ? times : 0;
			}
		}
	}
	return res;
}
//int main()
//{
//	
//	system("pause");
//}