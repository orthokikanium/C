#include<iostream>
#include<cstdio>
using namespace std;

bool used[6][6];
int FX, FY;
int N, M;//这个N×M是指其中方格个数!

/*这个题不能用动态规划：划分状态(得到当前状态需要使用未来的状态)和无后效性(每个点只经过一次有重叠)都不好满足*/
int dfs(int x, int y) {
	used[x][y] = true;//确保不再经过起点!
	int cout = 0;
	if (x == FX && y == FY) {
		cout++;//在确保main()中输入x，y是合格起点时可以这样写
		return cout;
	}
	/*将cout拆分成4部分加和组成：即第一步向上下左右走*/
	if ((x - 1) >= 1 && used[x - 1][y] == false) {
		used[x - 1][y] = true;
		cout += dfs(x - 1, y);
		used[x - 1][y] = false;
	}
	if ((y - 1) >= 1 && used[x][y-1] == false) {
		used[x][y - 1] = true;
		cout += dfs(x, y-1);
		used[x][y - 1] = false;
	}
	if ((x + 1) <= N && used[x + 1][y] == false) {
		used[x + 1][y] = true;
		cout += dfs(x + 1, y);
		used[x + 1][y] = false;
	}
	if ((y + 1) <= M && used[x][y+1] == false) {
		used[x][y + 1] = true;
		cout += dfs(x, y+1);
		used[x][y + 1] = false;
	}
	return cout;
}

int main() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			used[i][j] = false;
		}
	}

	int T;
	cin >> N >> M >> T;
	int* TX = new int[T]();
	int* TY = new int[T]();
	
	int SX, SY;
	cin >> SX >> SY;
	cin >> FX >> FY;
	for (int i = 0; i < T; i++) {
		cin >> TX[i] >> TY[i];
		used[TX[i]][TY[i]] = true;
	}

	cout<< dfs(SX,SY) <<endl;

	return 0;
}
