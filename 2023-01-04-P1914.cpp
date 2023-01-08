#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main() {
	int n;
	string plain;
	cin >> n;
	cin >> plain;
	n = n % 26;
	string cipher = "";
	for (int i = 0; i < plain.size(); i++) {
		
		if (int(plain[i]) + n > 122) {
			cipher = cipher + char(int(plain[i]) + n-26);
		}
		else {
			cipher = cipher + char(int(plain[i]) + n);
		}
	}
	cout << cipher << endl;
	return 0;

}
