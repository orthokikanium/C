////#include<iostream>
////#include<cstdio>
////using namespace std;
////int ans[13],n;
////bool column[13], diagonal_1[25], diagonal_2[25];//对角线个数（n-1）×2+1
////int num = 0;
////
////void dfs(int row) {
////	if (row == n) {
////		num++;
////		if (num == 1 || num == 2 || num == 3) {
////			for (int i = 0; i < n; i++) {
////				cout << ans[i] << " ";
////			}
////			cout << endl;
////		}
////		return;
////	}
////	int i = row;//这里：之前写成for(int i=row;i<n;i++)了，是因为没有标记行是否冲突又没有按照顺序依次填入行!
////	for (int j = 0; j < n; j++) {
////		if (i - j < 0) {
////			if (column[j] == false && diagonal_1[i + j] == false && diagonal_2[i - j + (n - 1) * 2 + 1] == false) {
////				ans[i] = j + 1;
////				column[j] = true;
////				diagonal_1[i + j] = true;
////				diagonal_2[i - j + (n - 1) * 2 + 1] = true;
////				dfs(i + 1);
////				column[j] = false;
////				diagonal_1[i + j] = false;
////				diagonal_2[i - j + (n - 1) * 2 + 1] = false;
////			}
////		}
////		else {
////			if (column[j] == false && diagonal_1[i + j] == false && diagonal_2[i - j] == false) {
////				ans[i] = j + 1;
////				column[j] = true;
////				diagonal_1[i + j] = true;
////				diagonal_2[i - j] = true;
////				dfs(i + 1);
////				column[j] = false;
////				diagonal_1[i + j] = false;
////				diagonal_2[i - j] = false;
////			}
////		}
////	}
////	return;
////}
////
////int main() {
////	for (int i = 0; i < 13; i++) {
////		ans[i] = 0;
////		column[i] = false;
////	}
////
////	for (int i = 0; i < 25; i++) {
////		diagonal_1[i] = false;
////		diagonal_2[i] = false;
////	}
////
////	cin >> n;
////	dfs(0);
////	cout << num;
////
////	return 0;
////}
//
////常数级优化：位运算
///*
//1.获取第i位的数字：（a >> i）& 1 或者 a & (1<<i) 其中的i应该是多少位的意思。
//2.设置第i位为1：a=a | (1<<i) 记住的是1<<i也就是说为1左移i位后的数字。
//3.设置第i位为0：a=a & (~(1<<i))
//*/
//#include<iostream>
//#include<cstdio>
//using namespace std;
//int ans[13], n;
//int column=0,diagonal_1=0, diagonal_2=0;//对角线个数（n-1）×2+1
//int num = 0;
//
//void dfs(int row) {
//	if (row == n) {
//		num++;
//		if (num == 1 || num == 2 || num == 3) {
//			for (int i = 0; i < n; i++) {
//				cout << ans[i] << " ";
//			}
//			cout << endl;
//		}
//		return;
//	}
//	int i = row;//这里：之前写成for(int i=row;i<n;i++)了，是因为没有标记行是否冲突又没有按照顺序依次填入行!
//	for (int j = 0; j < n; j++) {
//		if (i - j < 0) {
//			int column_ = (column >> j) & 1;
//			int diagonal_1_ = (diagonal_1 >> i + j) & 1;
//			int diagonal_2_ = (diagonal_2 >> (i - j + (n - 1) * 2 + 1)) & 1;
//			if (column_ == 0 && diagonal_1_ == 0 && diagonal_2_ == 0) {
//				ans[i] = j + 1;
//				column = column | (1 << j);
//				diagonal_1 = diagonal_1 | (1 << (i+j));
//				diagonal_2 = diagonal_2 | (1 << (i - j + (n - 1) * 2 + 1));
//				dfs(i + 1);
//				column = column & (~(1 << j));
//				diagonal_1 = diagonal_1 & (~(1 << (i+j)));
//				diagonal_2 = diagonal_2 & (~(1 << (i - j + (n - 1) * 2 + 1)));
//			}
//		}
//		else {
//			int column_ = (column >> j) & 1;
//			int diagonal_1_ = (diagonal_1 >> i + j) & 1;
//			int diagonal_2_ = (diagonal_2 >> (i - j)) & 1;
//			if (column_ == 0 && diagonal_1_ == 0 && diagonal_2_ == 0) {
//				ans[i] = j + 1;
//				column = column | (1 << j);
//				diagonal_1 = diagonal_1 | (1 << (i + j));
//				diagonal_2 = diagonal_2 | (1 << (i - j));
//				dfs(i + 1);
//				column = column & (~(1 << j));
//				diagonal_1 = diagonal_1 & (~(1 << (i + j)));
//				diagonal_2 = diagonal_2 & (~(1 << (i - j)));
//			}
//		}
//	}
//	return;
//}
//
//int main() {
//
//	cin >> n;
//	dfs(0);
//	cout << num;
//
//	return 0;
//}
