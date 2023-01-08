#include<iostream>
#include<cstdio>
#include <string>

using namespace std;

//不用string
int main() {
	int n, x;
	int num=0;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		int i_ = i;
		while (i_ > 0) {
			tmp = i_ % 10;
			i_ = i_ / 10;
			if (tmp == x) {
				num++;
			}
		}
	}
	cout << num << endl;
	return 0;
}

//用string
int main() {
	int n, x;
	cin >> n >> x;
	int num = 0;
	string x_ = to_string(x);
	for (int i = 1; i <= n; i++) {
		string i_ = to_string(i);
		for(int j=0;j<i_.size();j++)
		if (x_[0]==i_[j]) {
			num++;
		}

	}
	cout << num << endl;
	return 0;
}
