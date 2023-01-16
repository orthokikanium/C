#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct node {
	int left, right;
};
node tree[1000001];

int dfs(int node) {
	int deep = 1;
	if (node == 0) {
		return deep;
	}
	if (tree[node].left == 0 && tree[node].right == 0) {
		return deep;
	}
	int left_deep = dfs(tree[node].left);
	int right_deep = dfs(tree[node].right);
	if (left_deep >= right_deep) {
		deep = left_deep+1;
	}
	else {
		deep = right_deep+1;
	}
	return deep;
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> tree[i].left >> tree[i].right;
	}
	cout << dfs(1);
	return 0;
}
