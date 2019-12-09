#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
using namespace std;

int stepSearch(int N, int M) {
	if (N > M) {
		return -1;
	}
	if (N == M) {
		return 0;
	}
	int res = 0;
	for (int i = 2; i<N; i++) {
		if (i*(N / i) == N) {
			res++;
			if (stepSearch(N + N / i, M) != -1) {
				res += stepSearch(N + N / i, M);
				return res;
			}
			else {
				res--;
			}
		}
	}
	return -1;
}

int main() {
	int N, M;
	while (cin >> N >> M) {
		cout << stepSearch(N, M) << endl;
	}
	system("pause");
	return 0;
}