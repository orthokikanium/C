#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<int> to[1001];
int num = 0;
int K;
int* grazing;
int *used;
void dfs(int a) {
	used[a - 1] = 1;
	for (int i = 0; i < to[a].size(); i++) {
		int v = to[a][i];
		if (used[v - 1] ==0) {
			dfs(v);
		}
	}
}

int main() {
	int N, M;
	cin >> K >> N >> M;
	grazing = new int[K];
	used = new int[N];
	for (int i = 0; i < K; i++) {
		cin >> grazing[i];
	}

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		to[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N; j++) {
			used[j] = 0;
		}
		dfs(i);
		int sum = 0;
		for (int k = 0; k < K; k++) {
			sum += used[grazing[k] - 1];
		}
		if (sum == K) {
			num++;
		}
	}
	cout << num;
	return 0;
}
