#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
	int n = 0;
	//fTable[n]��¼n���˶��ô�ȫ���񽱣������������allTable[n]��¼���п��ܵ�������n�Ľ׳�
	long long fTable[21] = { 0, 0, 1 }, allTable[21] = { 0, 1, 2 };
	for (int i = 3; i < 21; ++i) {
		//���Ƽ���i����ȫ���ô�
		fTable[i] = (i - 1) * (fTable[i - 1] + fTable[i - 2]);
		//���Ƽ���i�Ľ׳�
		allTable[i] = i * allTable[i - 1];
	}
	//scanf����ֵΪ��ȷ�������ݵı�����������һ��������û�гɹ���ȡ����ʱ����ʱ����-1
	while (scanf("%d", &n) != -1) {
		//ע��%���ڿ����ַ�������������%%�ű�ʾ������%�ַ�
		printf("%4.2lf%%\n", 100* double(fTable[n]) / allTable[n]);
	}
	return 0;
}