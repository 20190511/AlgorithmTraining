#include <iostream>
using namespace std;

//순회 BFS

int n,m, maxVal = 0;
int map[500][500];
bool visitmap[500][500];

//1600

//DFS 재귀호출 
/**
 * x,y 좌표를 넘기고 1칸씩 이동하면서 최댓값 추이 분석
*/

//count start = 0
void simulator(int x, int y, int count, int value) {
    count++;
    if (count > 4) {
        maxVal = max(value, maxVal);
        return;
    }

    pair<int,int> move[4] = {
        {0,1}, {0,-1}, {1,0}, {-1,0}
    };

    int tmpValue = value;
    for (int k = 0 ; k < 4 ; k++)     {
        int dx = x + move[k].first, dy = y + move[k].second;
        if (dx < 0 || dx >= n || dy < 0 || dy >= m || visitmap[dx][dy])
            continue;
        tmpValue = value;
        tmpValue += map[dx][dy];
        visitmap[dx][dy] = true;
        simulator(dx, dy, count, tmpValue);

        //reset
        visitmap[dx][dy] = false;
        tmpValue = value;
    }
}

//수동으로 체크
void check2() {
    for(int i = 1 ; i < n-1 ; i++) {
        for (int j = 1 ; j < m-1 ; j++) { 
            int c = map[i][j], u = map[i-1][j], d = map[i+1][j], l = map[i][j-1], r = map[i][j+1];
            int minV = min(u,d);
            minV = min(minV, l);
            minV = min(minV, r);
            maxVal = max(maxVal, c+u+d+l+r-minV);
        }
    }

    //벽면순회
    for (int i = 1 ; i < n-1 ; i++) {
        //상단
        int c = map[0][i], l = map[0][i-1], r = map[0][i+1], e = map[1][i];
        maxVal = max(maxVal, c+l+r+e);
        c = map[n-1][i], l = map[n-1][i-1], r = map[n-1][i+1], e = map[n-2][i];
        maxVal = max(maxVal, c+l+r+e);

        c = map[i][0], l = map[i-1][0], r = map[i+1][0], e = map[i][1];
        maxVal = max(maxVal, c+l+r+e);
        c = map[i][m-1], l = map[i-1][m-1], r = map[i+1][m-1], e = map[i][m-2];
        maxVal = max(maxVal, c+l+r+e);
    }
}

int main(void)
{
    cin>>n>>m;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin>>map[i][j];
        }
    }

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            visitmap[i][j] = true;
            simulator(i,j,1, map[i][j]);
            visitmap[i][j] = false;
        }
    } 
    check2();
    cout<<maxVal;
    return 0;
    
}
