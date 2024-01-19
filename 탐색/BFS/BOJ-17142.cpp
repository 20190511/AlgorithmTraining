#include <iostream>
#include <queue>
using namespace std;
#define INF 25000

int n,m;
int virusCount = 0, zeroCount = 0;
int originMap[50][50];
int minCount = INF;
pair<int,int> virus[10];
pair<int,int> mv[4] = {
    {0,1}, {0,-1}, {1,0}, {-1,0}
};

int selectVirus[10] = {false};


void printMap(int map[50][50]) {
    printf("-------\n");
    for (int i = 0 ; i < virusCount ; i++)
        printf("%d ", selectVirus[i]);
    printf("\n");
    printf("======\n");
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            printf("%2d ", map[i][j]);
        }
        printf("\n");
    }
}

void run(int s, int activeCount) {
    //originMap의 2를 3으로 변경
    if (activeCount != m) {
        for (int x = s ; x < virusCount ; x++)  {
            selectVirus[x] = true;
            run(x+1, activeCount+1);
            selectVirus[x] = false;
        }
    }

    if (activeCount != m)
        return;

    queue<pair<int,int>> v;
    int map[50][50] = {0,};
    for (int i = 0 ; i < virusCount ; i++) {
        if (selectVirus[i]) {
            v.push(virus[i]);
            map[virus[i].first][virus[i].second] = 1;
        }
    }

    int zc = 0, curTime = 0;
    while(!v.empty()) {
        pair<int,int> xy = v.front();

        v.pop();
        for (int i = 0 ; i < 4 ; i++) {
            int dx = mv[i].first + xy.first, dy = mv[i].second + xy.second; 
            if (dx < 0 || dx >= n || dy < 0 || dy >= n || originMap[dx][dy] == 1 || map[dx][dy] != 0) {
                continue;
            }
            if (originMap[dx][dy] == 0)
                zc++;
            map[dx][dy] = map[xy.first][xy.second] + 1;
            if (originMap[dx][dy] == 0)
                curTime = max(curTime, map[dx][dy]);
            v.push(pair<int,int>(dx,dy));
        }
    }

    if (zc == zeroCount)
        if (curTime == 0)
            minCount = 0;
        else
            minCount = min(minCount, curTime-1);
} 

int main(void)
{
    cin>>n>>m;
    int v;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin>>v;
            originMap[i][j] = v;
            if (v == 2) 
               virus[virusCount++] = pair<int, int>(i,j);
            else if (v == 0)
                zeroCount++;
        }
    }

    run(0, 0);     
    minCount = minCount == INF ? -1 : minCount;
    cout<<minCount;
    return 0;
}
