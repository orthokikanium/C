#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;

int main() {
	int n;
	int t[255];
	int value[128];
	cin >> n;
	int t1 = pow(2,n) - 1;
	int t2 = 2 * t1;
	int t3 = pow(2, n);
	for (int i = 0; i < 255; i++) {
		t[i] = 0;
	}
	for (int i = 0; i < 128; i++) {
		value[i] = 0;
	}
	for (int i = t1; i <= t2; i++) {
		t[i]=i-t1+1;
	}

	for (int i = 0; i < t3; i++) {
		cin>>value[i];
	}
	for (int i = t1 - 1; i >= 0; i--) {
		if (value[t[2*i+1]-1] > value[t[2*i+2]-1]) {
			t[i] = t[2*i+1];
		}
		else {
			t[i]= t[2 * i + 2];
		}
	}

	if (t[0] == t[1]) {
		cout << t[2];
	}
	else {
		cout << t[1];
	}
	return 0;
}
