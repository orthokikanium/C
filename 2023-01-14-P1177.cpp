//#include<iostream>
//#include<cstdio>
//#include<vector>
//
//using namespace std;
//
//
//vector<int> merge(vector<int> a, vector<int> b) {
//	
//	int i = 0; 
//	int j = 0; 
//
//	int x = a.size() - 1;
//	int y = b.size() - 1;
//	vector<int> A;
//	while (i <= x && j <= y) {
//		if (a[i] <= b[j]) {
//			A.push_back(a[i]);
//			i++;
//		}
//		else {
//			A.push_back(b[j]);
//			j++;
//		}
//	}
//	if (i > x) {
//		for (int t = j; t <=y; t++) {
//			A.push_back(b[t]);
//		}
//	}
//	else {
//		for (int t = i; t <= x; t++) {
//			A.push_back(a[t]);
//		}
//	}
//	return A;
//
//}
//vector<int> merge_sort(vector<int> a) {
//	//for (int i = 0; i < a.size(); i++) {
//	//	cout << a[i] << " ";
//	//}
//	//cout<<endl;
//	if (a.size() == 1) {
//		return a;
//	}
//	else {
//		int tmp = (a.size() -1) / 2;
//		vector<int> a1;
//		vector<int> a2;
//		if (a.size() % 2 == 0) {
//			for (int i = 0; i <= tmp; i++) {
//				a1.push_back(a[i]);
//				a2.push_back(a[tmp + 1 + i]);
//			}
//		}
//		else {
//			for (int i = 0; i < tmp; i++) {
//				a1.push_back(a[i]);
//				a2.push_back(a[tmp + 1 + i]);
//			}
//			a1.push_back(a[tmp]);
//		}
//		a1 = merge_sort(a1);
//		a2 = merge_sort(a2);
//		return merge(a1, a2);
//	}
//
//}
//
//int main() {
//	int N;
//	cin >> N;
//	vector<int> a;
//	int tmp;
//	for (int i = 0; i < N; i++) {
//		cin >> tmp;
//		a.push_back(tmp);
//	}
//	merge_sort(a);
//	a= merge_sort(a);
//	for (int i = 0; i < a.size(); i++) {
//		cout << a[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}