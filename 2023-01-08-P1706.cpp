#include<iostream>
#include<cstdio>
using namespace std;

int ans[9], n;
bool used[9];

void generate(int index) {
	if (index == n) {
		for (int i = 0; i < n; i++) {
			cout << "    " << ans[i];
		}
		cout << endl;
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (used[i - 1] == false) {
			ans[index] = i;
			used[i - 1] = true;
			int t = index + 1;
			generate(t);
			used[i - 1] = false;
		}
	}
	return;
}

int main() {
	cin >> n;
	for (int i = 0; i < 9; i++) {
		used[i] = false;
		ans[i] = 0;
	}
	generate(0);
	return 0;
}
