//1046 ~ 1153
/**
 * visited 되는 변수를 memoization 해뒀다가 갱신하는 방법도 있다.
 *  (괜찮음 나중에 써볼 것.)
*/
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

// 상하운동을할 때 upDown은 [2]인덱스를 rightLeft[2] 로 변경해줘야함 (아래도 마찬가지)
int rightLeft[4] = {6,3,1,4};  //정방향 : 오른쪽
int downUp[4] = {6,2,1,5}; //정방향 : 아럐쪽
int n,m,k;
int map[20][20] = {0,};

pair<int,int> mv[4] = {
    {0,1}, {1,0}, {0,-1}, {-1, 0}
};

void  diceMove(int mode) {
    int tmp;
    switch (mode)
    {
    case 3:
        tmp = downUp[0];
        downUp[0] = downUp[1];
        downUp[1] = downUp[2];
        downUp[2] = downUp[3];
        downUp[3] = tmp;
        rightLeft[0] = downUp[0];
        rightLeft[2] = downUp[2];
        break;
    case 1:
        tmp = downUp[3];
        downUp[3] = downUp[2];
        downUp[2] = downUp[1];
        downUp[1] = downUp[0];
        downUp[0] = tmp;
        rightLeft[0] = downUp[0];
        rightLeft[2] = downUp[2];
        break; 
    case 0:
        tmp = rightLeft[0];
        rightLeft[0] = rightLeft[1];
        rightLeft[1] = rightLeft[2];
        rightLeft[2] = rightLeft[3];
        rightLeft[3] = tmp;
        downUp[0] = rightLeft[0];
        downUp[2] = rightLeft[2];
        break;
    case 2:
        tmp = rightLeft[3];
        rightLeft[3] = rightLeft[2];
        rightLeft[2] = rightLeft[1];
        rightLeft[1] = rightLeft[0];
        rightLeft[0] = tmp;
        downUp[0] = rightLeft[0];
        downUp[2] = rightLeft[2];
        break;
    }

    //debug
#ifdef DEBUG
    cout<<"====="<<endl;
    for (int i = 0 ; i < 4 ; i++)
        cout<<downUp[i]<<" ";
    cout<<endl;
    for (int i = 0 ; i < 4 ; i++)
        cout<<rightLeft[i]<<" ";
    cout<<endl;
#endif
}

void printMap(int map[20][20]) {
    cout<<"------"<<endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++)
            cout<<map[i][j]<<" ";
        cout<<endl;
    }
}
int run() {
    int result = 0;
    int nDir = 0;
    pair<int,int> curPos(0,0);

    while(k--) {
        int x = curPos.first, y = curPos.second;
        int dx = x + mv[nDir].first, dy = y + mv[nDir].second;
        if (dx < 0 || dx >= n || dy < 0 || dy >= m) {
            nDir = (nDir+2)%4;
            dx = x + mv[nDir].first, dy = y + mv[nDir].second; 
        }
        curPos.first = dx, curPos.second = dy;

        diceMove(nDir);
#ifdef DEBUG
        cout<<dx<<", "<<dy<<endl;
        cout<<rightLeft[0]<<", "<<map[dx][dy]<<endl;
#endif
 
        if (rightLeft[0] > map[dx][dy])
            nDir = (nDir+1)%4;
        else if (rightLeft[0] < map[dx][dy])
            nDir = (nDir+3)%4; 


        int visited[20][20] = {0,};
        int curColor = map[dx][dy];
        result += curColor;
        queue<pair<int,int>> q;
        q.push(curPos);
        while (!q.empty()) {
            int cx = q.front().first, cy = q.front().second;
            visited[cx][cy] = true;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ddx = cx + mv[i].first, ddy = cy + mv[i].second;
                if (ddx < 0 || ddx >= n || ddy < 0 || ddy >= m || visited[ddx][ddy] || map[ddx][ddy] != curColor)
                    continue;
                result += curColor;
                visited[ddx][ddy] = true;
                q.push(pair<int, int>(ddx, ddy));
            }
        }
#ifdef DEBUG
        printMap(visited);
#endif
    }
    

    return result;
}

int main(void) {
    cin>>n>>m>>k;
    for (int i = 0 ; i < n ; i++) 
        for (int j = 0 ; j < m ; j++)
            cin>>map[i][j];

    cout<<run();
    return 0;
}
