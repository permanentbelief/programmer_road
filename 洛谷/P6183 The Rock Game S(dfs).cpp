#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;



int a[20];//��OΪ0��XΪ1
int vis[1 << 10];
int ans[1 << 10][20], tot = 0;
void output(){//������� 
	for (int i = 1; i <= 1 << n; i++){
		for (int j = 1; j <= n; j++){
			cout << (ans[i][j] ? 'X' : 'O');
		}
		cout << endl;
	}
}
int calc(){//��һ����������ת��Ϊʮ������ 
	int ans = 0;
	for (int i = 1; i <= n; i++){
		ans = ans * 2 + a[i];//������� 
	}
	return ans;
}
void dfs(int pos){
	if (pos == (1 << n)){//��Ϊans��ʼ��ʱOOOOO...OO�����������һ��������� 
		output();//��� 
		//exit(0);//SPJ���ҵ�һ�鼴�� 
		system("pause");
	}
	for (int i = 1; i <= n; i++){
		a[i] = !a[i];//һλ��� 
		if (vis[calc()]){//�߹��� 
			a[i] = !a[i];//��ԭ 
			continue;//�ټ� 
		}
		vis[calc()] = true;//��¼���߹��� 
		for (int j = 1; j <= n; j++){
			ans[pos][j] = a[j];//�洢�� 
		}
		dfs(pos + 1);//����������һ�� 
		vis[calc()] = false;//���� 
		a[i] = !a[i];//ע�⣺���ܵߵ���������һ�� 
	}
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cout << 'O';//��� 
	cout << endl;
	vis[0] = true;//OOO.OOO�������� 
	dfs(1); //��1��ʼ���� 
	//system("pause");
	return 0;
}

