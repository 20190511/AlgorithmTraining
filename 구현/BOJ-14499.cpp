//1500 ~ 1520
/**
 * 주사위돌리기 2 를 통과해서 새로 다시 짠 프로그램
 * 주사위를 상하, 좌우 부분을 따로 구현해서 보는게 방법이다.
*/
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
//#define DEBUG

// 상하운동을할 때 upDown은 [2]인덱스를 rightLeft[2] 로 변경해줘야함 (아래도 마찬가지)
int rightLeft[4] = {0,0,0,0};  //정방향 : 오른쪽
int downUp[4] = {0,0,0,0}; //정방향 : 아럐쪽
int n,m,a,b,k;
int map[20][20] = {0,};

pair<int,int> mv[4] = {
    {0,1}, {0,-1}, {-1,0}, {1,0}
};
queue<int> mvDir;

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
    case 2:
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
    case 1:
        tmp = rightLeft[3];
        rightLeft[3] = rightLeft[2];
        rightLeft[2] = rightLeft[1];
        rightLeft[1] = rightLeft[0];
        rightLeft[0] = tmp;
        downUp[0] = rightLeft[0];
        downUp[2] = rightLeft[2];
        break;
    }

}

void printDice() {
    cout<<"DownUp -> ";
    for (int i = 0 ; i < 4 ; i++)
        cout<<downUp[i]<<" ";
    cout<<endl;
    cout<<"rightLeft -> ";
    for (int i = 0 ; i < 4 ; i++)
        cout<<rightLeft[i]<<" ";
    cout<<endl;
}

void printMap(int map[20][20]) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++)
            cout<<map[i][j]<<" ";
        cout<<endl;
    }
}
int run() {
    int result = 0;
    int nDir = 0;
    pair<int,int> curPos(a,b);

    while(!mvDir.empty()) {
        int x = curPos.first, y = curPos.second, nDir = mvDir.front();
#ifdef DEBUG
        cout<<"dir : "<<nDir+1<<endl;
#endif
        mvDir.pop();
        int dx = x + mv[nDir].first, dy = y + mv[nDir].second;
        if (dx < 0 || dx >= n || dy < 0 || dy >= m) 
            continue;

        curPos.first = dx, curPos.second = dy;
        diceMove(nDir);
#ifdef DEBUG
        cout<<dx<<", "<<dy<<endl;
        cout<<"bottom : "<<rightLeft[0]<<", mapValue = "<<map[dx][dy]<<endl;
#endif
        cout<<rightLeft[2]<<"\n";
        if (!map[dx][dy])
            map[dx][dy] = rightLeft[0];
        else {
            rightLeft[0] = downUp[0] = map[dx][dy];
            map[dx][dy] = 0;
        }
#ifdef DEBUG
        printMap(map);
        printDice();
        cout<<"-=-=-=-=-=-=-=-=\n";
#endif
    }
    
    return result;
}

int main(void) {
    cin>>n>>m>>a>>b>>k;
    int tmpV;
    for (int i = 0 ; i < n ; i++) 
        for (int j = 0 ; j < m ; j++)
            cin>>map[i][j];
    for (int i = 0 ; i < k ; i++) {
        cin>>tmpV;
        mvDir.push(--tmpV);
    }
    run();
    return 0;
}
