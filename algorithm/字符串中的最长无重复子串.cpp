#define _CRT_SECURE_NO_WARNINGS 1 


//
//int main()
//{
//	int n = 0;
//	int left = 0;
//	int right = 0;
//	int result = 0;
//	cin >> n;
//	vector<int> re(n);
//	unordered_set<int> jilu;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> re[i];
//	}
//	while (left < n && right < n)
//	{
//		if (!jilu.count(re[right]))
//		{
//			jilu.insert(re[right++]);
//			result = max(result, right - left);
//		}
//		else
//		{
//			jilu.erase(re[left++]);
//		}
//	}
//	cout << result << endl;
//
//
//	system("pause");
//}

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;

//int main(){
//	int n;
//	cin >> n;
//	vector<int> arr(n);
//	for (int i = 0; i < n; i++){
//		cin >> arr[i];
//	}
//	int pre = 0, len = 0;
//	int hash_table[1000] = { 0 };
//	for (int i = 0; i < n; i++){
//		if (hash_table[arr[i]] == 0 || hash_table[arr[i]] < pre){
//			len = max(len, i - pre + 1);
//		}
//		else{
//			pre = hash_table[arr[i]];
//		}
//		hash_table[arr[i]] = i + 1;
//	}
//	cout << len << endl;
//	system("pause");
//	return 0;
//}


#include <unordered_map>

using namespace std;
int main(){
	string A;
	while (cin >> A){
		int size = A.length();
		int res = 0;
		unordered_map<int, int> map;
		for (int start = 0, end = 0; end < size; end++){
			if (map.count(A[end])){
				start = max(start, map[A[end]]);
			}
			map[A[end]] = end + 1;
			res = max(res, end - start + 1);
		}
		cout << res << endl;
	}
	return 0;
}