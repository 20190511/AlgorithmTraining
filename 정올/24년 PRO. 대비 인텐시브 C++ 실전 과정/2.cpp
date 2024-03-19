//1110 ~ 1128
#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		map<int, int> a, b;
		cin >> n >> m;

		while (n--) {
			int v;
			cin >> v;
			map<int, int>::iterator s = a.find(v);
			if (s == a.end())
				a[v] = 1;
			else
				s->second++;
		}

		while (m--) {
			int v;
			cin >> v;
			map<int, int>::iterator s = b.find(v);
			if (s == b.end())
				b[v] = 1;
			else
				s->second++;
		}

		int ans = 0, prevCnt = 0;
		//two_Pointer
		map<int, int>::iterator it = a.begin(), it2 = b.begin();
		for (; it != a.end(); it++) {
			// Iterator 순서 조심
			while (it2 != b.end() && it2->first < it->first) {
				prevCnt += it2->second;
				it2++;
			}
			ans += prevCnt * it->second;
		}
		cout << ans << "\n";

	}
	return 0;
}		
