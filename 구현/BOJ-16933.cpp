#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define DEBUG false

struct element{
	int break_cnt;
	bool day;
	pair<int, int> dir;
	int save_cnt;
	
	element(int a, bool b, pair<int, int> c, int d) : break_cnt(a), day(b), dir(c), save_cnt(d) {}
};

// 0607 
// 0709 디버깅 시작 - 0731
/**
*	-> 틀린 이유 : visited[10][1000][1000] 조건을 잘못 썼다. 한 칸 정도 더 많이 두는 걸 습관으로 두자...
*  그리고 이전에 지나왔던 길을 다시 BFS에서는 굳이 길이 탐색을 하지 않아도 된다.
* 왜냐하면 어차피 직선거리로 최단거리를 찾는건데 for문에서 도는 시점에서 이미 queue의 특성상 짧은 시간이 앞에오기 때문이다.
*/

int map[1000][1000], visited[11][1000][1000];
int n, m, k;
pair<int, int> mv[5] = {
	{0,1}, {0,-1}, {1,0}, {-1,0}, {0,0}
};
queue<element> q;

void printMap(int map[1000][1000], int cnt) {
	cout << "map count = " << cnt << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << "==========" << endl;
}


int bfs() {
	element start(0, true, { 0,0 }, 1);
	visited[0][0][0] = 1;
	q.push(start);

	while (!q.empty()) {
		int break_cnt = q.front().break_cnt;
		bool day = q.front().day;
		pair<int, int> pos = q.front().dir;
		int save_cnt = q.front().save_cnt;
		q.pop();
		int cx = pos.first, cy = pos.second;

#if DEBUG
		cout << endl << "day 여부 " << day << endl;
		cout << "cur: x=" << cx << ", " << cy << endl;

		printMap(visited[break_cnt], break_cnt);

#endif
		for (int i = 0; i < 5; i++) {

			int dx = cx + mv[i].first, dy = cy + mv[i].second;
#if DEBUG
			cout << "dx=" << dx << ", dy=" << dy << endl;
#endif
			if (dx < 0 || dx >= n || dy < 0 || dy >= m)
				continue;
			else if (dx == cx && dy == cy && !day) {
				if (dx == n - 1 && dy == m - 1)
					break;
				visited[break_cnt][dx][dy] = save_cnt + 1;
				q.push({ break_cnt, true, {dx,dy}, save_cnt + 1 });
				continue;
			}
			else if (map[dx][dy] == 1 && day) {
				if (break_cnt < k && !visited[break_cnt + 1][dx][dy] ) {
					visited[break_cnt + 1][dx][dy] = save_cnt + 1;
					q.push({ break_cnt + 1, day ? false : true, {dx, dy}, save_cnt + 1 });
					if (dx == n - 1 && dy == m - 1)
						break;
					continue;
				}
			}
			else if (map[dx][dy] == 0 && !visited[break_cnt][dx][dy]) {
				visited[break_cnt][dx][dy] = save_cnt + 1;
				q.push({ break_cnt,  day ? false : true, {dx, dy} , save_cnt + 1});
				if (dx == n - 1 && dy == m - 1)
					break;
				continue;
			}
		}
	}
	int min_val = 0x7FFFFFFF;
	for (int i = 0; i <= k; i++) {
		if (!visited[i][n - 1][m - 1]) continue;

		min_val = min(visited[i][n - 1][m - 1], min_val);
	}
	if (min_val == 0x7FFFFFFF)
		return -1;
	else
		return min_val;
}


int main(void) {

	cin >> n >> m >> k;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
		}
	}

#if DEBUG
	printMap(map, 0);
#endif

	cout << bfs();

	return 0;
}
