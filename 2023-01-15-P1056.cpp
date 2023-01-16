//#include<iostream>
//#include<cstdio>
//#include<vector>
//#include <algorithm>
//
//using namespace std;
//
//struct Line {
//	int id;
//	int cnt;
//	Line(int nid, int ncnt) {
//		id = nid;
//		cnt = ncnt;
//	}
//};
//
//bool cmp(Line a, Line b) {
//	if (a.cnt > b.cnt) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//int main() {
//	vector<int> row_cout(1001, 0);
//	vector<int> column_cout(1001, 0);
//
//	int M, N, K, L, D;
//	cin >> M >> N >> K >> L >> D;
//	int x1, x2, y1, y2;
//
//	for (int i = 0; i < D; i++) {
//		cin >> x1 >> y1 >> x2 >> y2;
//		if (x1 == x2) {
//			if (y1 > y2) {
//				column_cout[y2] = column_cout[y2] + 1;
//			}
//			else {
//				column_cout[y1] = column_cout[y1] + 1;
//			}
//		}
//		else {
//			if (x1 > x2) {
//				row_cout[x2] = row_cout[x2] + 1;
//			}
//			else {
//				row_cout[x1] = row_cout[x1] + 1;
//			}
//		}
//
//	}
//	vector<Line> rows;
//	vector<Line> columns;
//	for (int i = 1; i <= 1000; i++) {
//		Line tmp1 = Line(i,row_cout[i]);
//		rows.push_back(tmp1);
//		Line tmp2 = Line(i, column_cout[i]);
//		columns.push_back(tmp2);
//	}
//
//
//	sort(rows.begin(), rows.end(),cmp);
//	sort(columns.begin(), columns.end(),cmp);
//	////
//	//for (int i = 0; i < 10; i++) {
//	//	cout << columns[i].id << " ";
//	//}
//	////
//	vector<int> final_row;
//	vector<int> final_column;
//	for (int i = 0; i < K; i++) {
//		final_row.push_back(rows[i].id);
//	}
//	for (int i = 0; i < L; i++) {
//		final_column.push_back(columns[i].id);
//	}
//
//	sort(final_row.begin(), final_row.end());
//	sort(final_column.begin(), final_column.end());
//
//	if (K > 0) {
//		for (int i = 0; i <K; i++) {
//			cout << final_row[i] << " ";
//		}
//	}
//	cout << endl;
//
//	if (L > 0) {
//		for (int i = 0; i <L; i++) {
//			cout << final_column[i]<< " ";
//
//		}
//	}
//	cout << endl;
//
//	return 0;
//
//}
//
