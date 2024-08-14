#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
//0942 ~ 1037
/**
* 시간초과 2번 일어남 => bfs를 교대로할 때 이미 지나왔던 길에데해서 추가할 필요없음. 새로운 경계에 추가되는 녀석들만 추가하면됨
*	왜냐면 이전 기록의 녀석들은 이미 지나왔기 때문에..
*/
using namespace std;
#define WALL	11

#define DEBUG false

int n, m, p;
int map[1000][1000];
int player_map[11][1000][1000];

struct item
{
	int x;
	int y;
	int p;
	item(int x=0, int y=0, int p=0) : x(x), y(y), p(p) {}
};

int player[11], player_sum[11];

queue<item> player_pos[11];
pair<int, int> mv[4] = {
	{0,1}, {0,-1}, {1,0}, {-1,0}
};

void printMap(int map[1000][1000]) {
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << "=======================" << endl;
}


int bfs(int num, int cur_cnt) {
	queue<item> q, &ex = player_pos[num];
	
	int counter = 0;
	while (!ex.empty()) {
		int x = ex.front().x, y = ex.front().y, pow = ex.front().p;
		
		/*
		if (cur_cnt - player_map[num][x][y] > 0) {
			q.push({ex.front()});
		}
		*/
		ex.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + mv[i].first, dy = y + mv[i].second;
			if (dx < 0 || dx >= n || dy < 0 || dy >= m || map[dx][dy] != 0)
				continue;
			
			map[dx][dy] = num;
			player_map[num][dx][dy] = cur_cnt;
			player_sum[num]++;
			counter++;
			q.push({ dx,dy, player[num]});
			if (pow - 1 > 0) {
				ex.push({ dx,dy,pow - 1 });
			}

		}
	}

	ex = q;
#if DEBUG
	cout << "player : " << num << endl;
	printMap(map);
#endif
	return counter;
}

int main(void)
{
#if DEBUG
	freopen("test.txt", "r", stdin);
#endif
	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++) {
		cin >> player[i];
	}
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		for (int j = 0; j < m; j++) {
			if (s[j] == '.')
				map[i][j] = 0;
			else if (s[j] == '#')
				map[i][j] = WALL;
			else {
				int idx = s[j] - '0';
				map[i][j] = idx;
				player_pos[idx].push({ i,j,player[idx]});
				player_sum[idx]++;
			}

		}
	}

#if DEBUG
	printMap(map);
#endif
	
	for (int cur_cnt = 0; ; cur_cnt++) {
		int add_cnt = 0;
		for (int i = 1; i <= p; i++) {
			add_cnt += bfs(i, cur_cnt);
		}
		if (!add_cnt)
			break;
	}

	for (int i = 1; i <= p; i++)
		cout << player_sum[i] << " ";
	cout << endl;


	return 0;
}
