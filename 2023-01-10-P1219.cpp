////#include<iostream>
////#include<cstdio>
////using namespace std;
////int ans[13],n;
////bool column[13], diagonal_1[25], diagonal_2[25];//�Խ��߸�����n-1����2+1
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
////	int i = row;//���֮ǰд��for(int i=row;i<n;i++)�ˣ�����Ϊû�б�����Ƿ��ͻ��û�а���˳������������!
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
////�������Ż���λ����
///*
//1.��ȡ��iλ�����֣���a >> i��& 1 ���� a & (1<<i) ���е�iӦ���Ƕ���λ����˼��
//2.���õ�iλΪ1��a=a | (1<<i) ��ס����1<<iҲ����˵Ϊ1����iλ������֡�
//3.���õ�iλΪ0��a=a & (~(1<<i))
//*/
//#include<iostream>
//#include<cstdio>
//using namespace std;
//int ans[13], n;
//int column=0,diagonal_1=0, diagonal_2=0;//�Խ��߸�����n-1����2+1
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
//	int i = row;//���֮ǰд��for(int i=row;i<n;i++)�ˣ�����Ϊû�б�����Ƿ��ͻ��û�а���˳������������!
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
