#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>

using namespace std;

bool is_prime(int n) {
	if (n == 2) {
		return true;
	}
	int c = int(sqrt(n));
	for (int i = 2; i <=c+1; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

string check(int n) {
	string content;
	
	for (int i = 2; i <n; i++) {
		if (is_prime(i) == 1 && is_prime(n - i)==1) {
			content = to_string(n) + '=' + to_string(i) + '+' + to_string(n - i);
			return content;
		}
	}
	return "wrong answer!";
}


int main() {
	int N;
	cin >> N;
	for (int i = 4; i <= N; i += 2) {
		cout << check(i) << endl;
	}
	return 0;
}
