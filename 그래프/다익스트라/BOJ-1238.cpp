#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#define INF	0x7FFFFFFF
using namespace std;

vector<pair<int, int>> house[1001];
int defaultDist[1001];
int n, x;

int dijk(int start, int end) {
	int dist[1001] = { INF, INF, INF,};

	dist[start] = 0;
	for (int i = 0; i <= n; i++) dist[i] = INF;

	priority_queue<pair<int, int>> q;
	q.push({ 0, start });
	while (!q.empty()) {
		int curDis = -q.top().first, curPos = q.top().second;
		q.pop();

		for (int i = 0; i < (int)house[curPos].size(); i++) {
			pair<int, int> tmp = house[curPos].at(i);
			int nextDis = tmp.first, nextPos = tmp.second;
			int newCals = curDis + nextDis;
			if (dist[nextPos] > newCals) {
				dist[nextPos] = newCals;
				q.push({ -newCals, nextPos });
			}
		}
	}
	if (start == x)
		for (int i = 0; i <= n; i++) defaultDist[i] = dist[i];
	return dist[end];
}

int main(void) {
	cin.tie(0)->sync_with_stdio(false);
	int m;
	cin >> n >> m >> x;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		house[a].push_back({c, b});
	}

	int answer = 0;
	dijk(x, x);
	for (int i = 1 ; i <= n; i++) {
		if (x == i) continue;
		int a = dijk(i, x);
		int b = defaultDist[i];
		answer = max(answer, a + b);
	}
	cout << answer;
	
	return 0;
}
