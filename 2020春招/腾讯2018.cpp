#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


void AdjustDown(vector<int>& arr, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] > arr[child])
		{
			child++;
		}
		if (arr[child] > arr[parent])
		{
			swap(arr[child], arr[parent]);
			parent = child;
			child = 2 * child + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(vector<int>& arr)
{
	int n = arr.size();
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(arr,n,i);
	}

	int end = n - 1;
	while (end > 0)
	{
		swap(arr[0], arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
}

struct TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
		:val(x)
		, left(nullptr)
		, right(nullptr)
	{}
	
};

TreeNode* sorted(vector<int>& nums, int left, int right)
{
	if (left >= right)
		return nullptr;
	else
	{
		int mid = left + (right - left) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = sorted(nums, left, mid - 1);
		root->right = sorted(nums, mid + 1, right);
		return root;
	}
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
	if (nums.empty())
		return nullptr;
	return sorted(nums, 0, nums.size() - 1);

}

vector<string> splits(string str)
{
	vector<string> result;
	int begin = 0;
	int end = 0;
	while (1)
	{
		end = str.find(',', begin);
		if (end == string::npos)
			break;
		result.push_back(str.substr(begin, end - begin));
		begin = end + 1;
	}

	return result;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

//
//vector<int> getnum(vector<int>& nums)
//{
//	int n = nums.size();
//	vector<int> ans{ 0, 0 };
//	sort(nums.begin(), nums.end());
//	int a = INT_MAX;
//	int count = 0;
//	int total = 0;
//	for (int i = 0; i + 1 < nums.size(); i++)
//	{
//		if (nums[i + 1] == nums[i])
//		{
//			count++;
//		}
//		else
//		{
//			ans[0] = count;
//			count = 0;
//		}
//	}
//	ans[0] = count*(count + 1) / 2;
//	//һ������ans[0]��
//	count = 0;
//	if (ans[0] == 0)
//	{
//		for (int i = 1; i < nums.size(); i++)
//		{
//			if (nums[i] - nums[i - 1] < a)
//			{
//				a = nums[i] - nums[i - 1];
//				count = 0;
//			}
//			else if (nums[i] - nums[i - 1] == a)
//			{
//				count++;
//			}
//		}
//		ans[0] = count;
//	}
//	int count2 = 1;
//
//	for (int i = n - 2; i >= 0; i--)
//	{
//		if (nums[i] == nums[i + 1])
//			count2++;
//		else
//			break;
//	}
//
//	int count3 = 1;
//	for (int i = 0; i + 1 < nums.size(); i++)
//	{
//		if (nums[i] == nums[i + 1])
//		{
//			count3++;
//		}
//		else
//		{
//			break;
//		}
//	}
//	ans[1] = count3 * count2;
//
//	return ans;
//}
//vector<int> getnum(vector<int>& nums)
//{
//	vector<int> ans{ 0, 0 };
//	sort(nums.begin(), nums.end());
//	int len = nums.size();
//	if (len <= 1)
//		return ans;
//	int mindis = INT_MAX;
//
//	int count = 0;
//	for (int i = 1; i < len; ++i)
//	{
//		int dis = nums[i] - nums[i - 1];
//		if (dis == 0)
//		{
//			count++;
//		}
//		else
//		{
//			ans[0] += count * (count + 1) / 2;
//			count = 0;
//		}
//	}
//	ans[0] += count * (count + 1) / 2;
//	if (ans[0] == 0)
//	{
//		for (int i = 1; i < len; ++i)
//		{
//			int dis = nums[i] - nums[i - 1];
//			if (dis < mindis)
//			{
//				mindis = dis;
//				ans[0] = 1;
//			}
//			else if (dis == mindis)
//				++ans[0];
//		}
//	}
//	count = 1;
//	for (int i = 1; i < len; ++i)
//	{
//		if (nums[i] == nums[i - 1])
//			++count;
//		else
//			break;
//	}
//	int count2 = 1;
//	for (int i = len - 2; i >= 0; --i)
//	{
//		if (nums[i] == nums[i + 1])
//			++count2;
//		else
//			break;
//	}
//	ans[1] = count * count2;
//	return ans;
//}
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<int> ans(n);
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> ans[i];
//		}
//		ans = getnum(ans);
//		cout << ans[0] << " " << ans[1] << endl;
//	}
//	system("pause");
//}

//ð������˼��




//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int main()
//{
//	int num, i, j;
//	while (cin >> num)//����Ԫ�ص��ܸ���
//	{
//		if (num<2)
//		{
//			cout << 0 << " " << 0 << endl;
//			continue;
//		}
//		vector<int> arr;//arr��Ҫ����Ϊȫ�ֱ���,��Ȼȫ���������ݶ���������arr
//		int length = num;
//		int temp;
//		while (num--)//����д��while(cin>>temp)����Ȼ��ȫ���������ݶ���һ���Դ�����arr
//		{
//			cin >> temp;
//			arr.push_back(temp);
//		}
//		sort(arr.begin(), arr.end());//C++����������[begin,end)������Ԫ������
//
//		//����СֵminVal
//		int minVal = arr[1] - arr[0];
//		for (i = 1; i< length - 1; ++i)
//		{
//			int cur = arr[i + 1] - arr[i];
//			if (cur<minVal)
//				minVal = cur;
//		}
//		//����Сֵ�ĸ���minCount
//		int minCount = 0;
//		if (minVal == 0)//arr�������Ԫ��ʱ
//		{
//			for (i = 0; i<length - 1; ++i)
//			{
//				for (j = i + 1; j<length; ++j)
//				{
//					if (arr[i] == arr[j])
//						++minCount;
//				}
//			}
//		}
//		else//arr����Ԫ�����ʱ
//		{
//			for (i = 0; i<length - 1; ++i)
//			{
//				int cur = arr[i + 1] - arr[i];
//				if (cur == minVal)
//				{
//					++minCount;
//				}
//			}
//		}
//
//		//�����ֵmaxVal
//		int maxVal = arr[length - 1] - arr[0];
//		//�����ֵ�ĸ���maxCount
//		int maxCount = 0;
//		if (maxVal == 0)//ȫ��Ԫ�ض����,�������ԭ��
//		{
//			maxCount = length*(length - 1) / 2;
//		}
//		else//�в�ͬ��Ԫ��,���ֵ�ĸ���=��С�ĸ���*���ĸ���
//		{
//			int smallCount = 0, bigCount = 0;
//			for (i = 0; i<length; ++i)
//			{
//				if (arr[i] == arr[0])
//					++smallCount;
//				else if (arr[i] == arr[length - 1])
//					++bigCount;
//			}
//			maxCount = smallCount*bigCount;
//		}
//		cout << minCount << " " << maxCount << endl;
//	}
//	system("pause");
//	return 0;
//}


bool isP(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i < sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
#include <set>
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int count = 0;
//	//set<vector<int, int>> s;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (isP(i) && isP(j) && i + j == n)
//			{
//				cout << "{" << i << "," << j << "}" << endl;
//			}
//		}
//	}
//	cout << count << endl;
//	system("pause");
//
//}

#include<iostream>
#include<vector>
#include<cmath>
//�ж��Ƿ�Ϊ����
bool isPrime(int n) {
	//ע����<=.....
	for (int i = 2; i <= sqrt(n); i++)
	if (n % i == 0)
		return false;
	return true;
}

//����1000���ڵ�����
void PrimeIn1000(vector<int> &vec) {
	vec.push_back(2);
	for (int i = 3; i < 1000; i++)
	if (isPrime(i))
		vec.push_back(i);
}

/*
{3,47}
{7,43}
{9,41}
{13,37}
{19,31}
*/
//�������������ֱ�ָ��vector��ͷβ��������β�ˣ���С��ͷ��
int SumofPrimePair(int n) {
	vector<int> PrimeVec;
	PrimeIn1000(PrimeVec);
	int result = 0;
	vector<int>::iterator iterLeft = PrimeVec.begin();
	vector<int>::iterator iterRight = PrimeVec.end() - 1;
	while (iterLeft <= iterRight) {
		int tempSum = *iterLeft + *iterRight;
		if (tempSum == n) {
			result++;
			cout << *iterLeft << " " << *iterRight << endl;
			iterLeft++;
			iterRight--;
		}
		else if (tempSum < n)
			iterLeft++;
		else
			iterRight--;
	}

	return result;
}

int main() {
	int n;
	cin >> n;
	cout << SumofPrimePair(n) << endl;
	system("pause");
	return 0;
}