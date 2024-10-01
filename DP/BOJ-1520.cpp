#define _CRT_SECURE_NO_WARNINGS
#define DEBUG false
#include <iostream>
#include <vector>
using namespace std;

int N, M;

int map[501][501], v[501][501];
pair<int, int> mv[4] = {
	{0,1}, {0, -1}, {1,0}, {-1,0}
};

void printMap(int map[501][501]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	cout << "=================" << endl;
}


int dfs(int x, int y) {
	if (x == N - 1 && y == M - 1) {
		v[x][y] = 1;
		return 1;
	}
	
	v[x][y] = 0;
	
	for (int i = 0; i < 4; i++) {
		int dx = x + mv[i].first, dy = y + mv[i].second;

		if (dx < 0 || dx >= N || dy < 0 || dy >= M || map[dx][dy] >= map[x][y]) continue;
		
		if (v[dx][dy] == -1) {
			v[x][y] += dfs(dx, dy);
		}
		else {
			v[x][y] += v[dx][dy];
		}
	}
	return v[x][y];
}

int main(void)
{
#if DEBUG
	freopen("q.txt", "r", stdin);
#endif
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			v[i][j] = -1;
		}
	}

	v[0][0] = 0;
	cout<<dfs(0, 0);
#if DEBUG
	cout << endl;
	cout << " <<< total >>>" << endl;
	printMap(v);
#endif
	return 0;
}
