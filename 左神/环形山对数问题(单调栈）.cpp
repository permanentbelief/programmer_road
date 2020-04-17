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

static int nextIndex(int size, int i) //��Ϊ��һ�������ߵ��������,Ҫ�ص�0λ�ü���
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
	st.push(Pair(value));//�����ֵѹ��ջ��
	while (index != maxIndex) // ������һȦ��maxIndexλ�ã��ͽ���
	{
		value = arr[index];  // ȡ�����е�ǰ��ֵ
		while (!st.empty() && st.top().value < value) //û������ջ�дӴ�С��˳������������Ҫ���������н���
		{
			int times = st.top().times;
			st.pop();
			//           C(k,2)�����ظ���  ����
			res += getInternalSum(times) + times * 2;
		}
		if (!st.empty() && st.top().value == value) //��ǰ��ֵ��ջ����ֵ��ȣ�times++
		{
			st.top().times++;
		}
		else // �����������棬С��ջ�����½�һ������
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