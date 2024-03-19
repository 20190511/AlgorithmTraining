//12:25 ~ 12:35 (10분)
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#define INF	0x7FFFFFFF
using namespace std;
int map[125][125];

pair<int, int > mv[4] = {
	{0,1}, {0,-1}, {1,0}, {-1,0}
};
int run(int n)
{
	int visited[125][125];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = INF;

	priority_queue<pair<int, pair<int,int> > > q;
	visited[0][0] = false;
	q.push({ 0, {0,0} });
	while (!q.empty()) {
		int c_dis = -q.top().first, cx = q.top().second.first, cy=q.top().second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = cx + mv[i].first, dy = cy + mv[i].second;
			if (dx < 0 || dx >= n || dy < 0 || dy >= n)
				continue;
			int cals = map[cx][cy] + c_dis;
			if (visited[dx][dy] > cals) {
				visited[dx][dy] = cals;
				q.push({ -cals, {dx,dy} });
			}
		}
	}
	return visited[n - 1][n - 1] + map[n-1][n-1];
}
int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	for (int c = 1;; c++) {
		int n;
		cin >> n;
		if (!n) break;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];
		
		int ans = run(n);
		cout << "Problem " << c << ": " << ans << "\n";
	}
	return 0;
}
