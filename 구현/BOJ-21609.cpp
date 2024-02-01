//1058 ~ 1228
// 20 이라서 BF
// 문제 구현과정 중에선 실수가 없었으나 하이퍼파라미터 
// 행의 번호가 큰 값이 큰 것을 작은걸로 설정해버리는 실수로 인한 30분 디버깅이 있었음
		//그래도 디버깅 시간이 30분으로 합리적이긴 하였음.
//  이런 복잡한 구현 류는 구현단계마다 printf 를 찍어보았는데 괜찮은 것 같음
#include <iostream>
#include <queue>
#include <cstring>
#define dltVal 6
using namespace std;
struct blk {
	int sz;
	int rainbow;
	int x;
	int y;	
	
	const bool operator>(const blk& b) const {
		if (sz != b.sz)
			return sz > b.sz;
		else if (rainbow != b.rainbow)
			return rainbow > b.rainbow;
		else if (x != b.x)	
			return x > b.x;
		else
			return y > b.y;
	}

	const void operator=(const blk& b) {
		sz = b.sz, rainbow = b.rainbow, x = b.x, y = b.y;
	}
};
pair<int,int> mv[4] = {
	{0,-1}, {0,1}, {1,0}, {-1,0}
};
int map[20][20], n, m, score = 0;

void printMap(int map[20][20]) {
	cout<<"====="<<endl;
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			if (map[i][j] == dltVal)
				printf("   ");
			else
				printf("%2d ", map[i][j]);

		}
		cout<<endl;
	}
}

void mapDown() {
	for (int i = 0 ; i < n ; i++) {
		for (int j = n-2 ; j >= 0 ; j--) {
			for (int k = j; k < n-1 ; k++) {
				if (map[k][i] != -1 && map[k+1][i] == dltVal) {
					map[k+1][i] = map[k][i];
					map[k][i] = dltVal;
				}
			}
		}
	}
}
void rotate90() {
	int tmpMap[20][20];
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			tmpMap[n-j-1][i] = map[i][j];
		}
	}
	memcpy(map, tmpMap, sizeof(map));
}

void run() {
	int groupCnt = 0;
	while(true) {
		groupCnt = 0;
		// 블록그룹 찾기
		blk stdBlk = {0,0,20,20}, ptr;
		int visited[20][20] = {0,};
		for (int i = 0 ; i < n ; i++) {
			for (int j = 0 ; j < n ; j++) {
				if (map[i][j] == -1 || map[i][j] == 0 || map[i][j] == dltVal || visited[i][j]) 
					continue;		

				visited[i][j] = groupCnt+1;	
				queue<pair<int,int>> q;
				q.push(pair<int,int>(i,j));
				int tmpSize = 1, rbCnt = 0, curVal = map[i][j];
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int s = 0 ; s < 4 ; s++) {
						int dx = x + mv[s].first, dy = y + mv[s].second;
						if (dx < 0 || dx >= n || dy < 0 || dy >= n || visited[dx][dy] == groupCnt+1)
							continue;

						if (map[dx][dy] != 0 && map[dx][dy] != curVal)	
							continue;

						visited[dx][dy] = groupCnt+1;
						rbCnt = map[dx][dy] == 0 ? rbCnt+1 : rbCnt;
						tmpSize++;
						q.push(pair<int,int>(dx,dy));
					}
				}	
				if (tmpSize < 2)
					continue;
				ptr = (blk){tmpSize,rbCnt,i,j};
				stdBlk = ptr > stdBlk ? ptr : stdBlk;
				groupCnt++;
			}
		} 
		//printMap(visited);
		//cout<<stdBlk.x<<","<<stdBlk.y<<"-->"<<stdBlk.sz<<endl; //확인
		
		if (!groupCnt)
			break;

		//기준블록으로 다시 BFS로 delVal로 설정 후 삭제
		queue<pair<int,int>> q;
		q.push(pair<int,int>(stdBlk.x, stdBlk.y));
		score += stdBlk.sz*stdBlk.sz;
		int curVal = map[stdBlk.x][stdBlk.y];
		while (!q.empty())
		{
			int x = q.front().first, y = q.front().second;
			q.pop();
			map[x][y] = dltVal;
			for (int s = 0; s < 4; s++)
			{
				int dx = x + mv[s].first, dy = y + mv[s].second;
				if (dx < 0 || dx >= n || dy < 0 || dy >= n ||(map[dx][dy] != 0 && map[dx][dy] != curVal))
						continue;
				map[dx][dy] = dltVal;
				q.push(pair<int, int>(dx, dy));
			}
		}
		//cout<<stdBlk.x<<","<<stdBlk.y<<"-->"<<stdBlk.sz<<endl;
		mapDown();
		//printMap(map);
		rotate90();	
		//printMap(map);
		mapDown();
		//printMap(map);	
		//cout<<"end-----\n";
	}
}

//격자회전
int main(void)
{
	cin>>n>>m;
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			cin>>map[i][j];
		}
	}

	//printMap(map);
	run();
	cout<<score;
	return 0;
}

