#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;



int a[20];//记O为0，X为1
int vis[1 << 10];
int ans[1 << 10][20], tot = 0;
void output(){//输出函数 
	for (int i = 1; i <= 1 << n; i++){
		for (int j = 1; j <= n; j++){
			cout << (ans[i][j] ? 'X' : 'O');
		}
		cout << endl;
	}
}
int calc(){//将一个二进制数转化为十进制数 
	int ans = 0;
	for (int i = 1; i <= n; i++){
		ans = ans * 2 + a[i];//常规操作 
	}
	return ans;
}
void dfs(int pos){
	if (pos == (1 << n)){//因为ans初始化时OOOOO...OO，所以最后留一组输出即可 
		output();//输出 
		//exit(0);//SPJ，找到一组即可 
		system("pause");
	}
	for (int i = 1; i <= n; i++){
		a[i] = !a[i];//一位差别 
		if (vis[calc()]){//走过了 
			a[i] = !a[i];//还原 
			continue;//再见 
		}
		vis[calc()] = true;//记录，走过了 
		for (int j = 1; j <= n; j++){
			ans[pos][j] = a[j];//存储答案 
		}
		dfs(pos + 1);//继续搜索下一个 
		vis[calc()] = false;//回溯 
		a[i] = !a[i];//注意：不能颠倒，被坑了一次 
	}
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cout << 'O';//输出 
	cout << endl;
	vis[0] = true;//OOO.OOO不可再走 
	dfs(1); //从1开始搜索 
	//system("pause");
	return 0;
}

