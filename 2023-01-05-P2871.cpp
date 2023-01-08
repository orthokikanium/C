#include<iostream>
#include<cstdio>

using namespace std;

int main() {
	int N, M;

	cin >> N >> M;
	int W[3402], D[3402], F[2][12881];
	for (int i = 0; i < N; i++) {
		cin >> W[i] >> D[i];
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < M + 1; j++) {
			F[i][j] = 0;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (j - W[i - 1] < 0) {
				F[i%2][j] = F[(i%2) ^ 1][j];
			}
			else {
				if (F[(i % 2) ^ 1][j] >= F[(i % 2) ^ 1][j - W[i - 1]] + D[i - 1]) {
					F[i % 2][j] = F[(i % 2) ^ 1][j];
				}
				else {
					F[i % 2][j] = F[(i % 2) ^ 1][j - W[i - 1]] + D[i - 1];
				}
			}
		}
	}
	cout << F[N%2][M] << endl;
	return 0;
}
