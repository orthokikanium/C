#include<iostream>
#include<cstdio>
#include<vector>
#include <algorithm>

using namespace std;

bool cmp(int a,int b) {
	if (a > b) {
		return true;
	}
	else {
		return false;
	}
}




int main() {
	int m, s, c;
	cin >> m >> s >> c;
	vector<int> used;

	int tmp;
	for (int i = 0; i < c; i++) {
		cin >> tmp;
		used.push_back(tmp);
		
	}
	int length;
	if (m >= c) {
		length = c;
	}

	if (m < c) {
		sort(used.begin(), used.end());
		vector<int> dot;
		for (int i = 1; i < used.size(); i++) {
			if (used[i] - used[i - 1] - 1 > 0) {
				dot.push_back(used[i] - used[i - 1] - 1);
			}
		}
		//for (int i = 0; i < used.size(); i++) {
		//	cout << used[i] << " ";
		//}
		//cout << endl;

		//for (int i = 0; i < dot.size(); i++) {
		//	cout<<dot[i]<<" ";
		//}
		//cout << endl;

		sort(dot.begin(), dot.end(), cmp);
		int sum = 0;
		for (int i = 0; i < m - 1; i++) {
			sum += dot[i];
		}

		length = used[used.size() - 1] - used[0] + 1 - sum;
	}
	
	cout << length;


	return 0;







}