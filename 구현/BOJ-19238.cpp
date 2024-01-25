//0950 ~ 11:30
/**
 * 
 * 반례가 굉장히 많아 고생한 문제
 * 1. BFS에서 start과 end 지점이 같아 경로를 찾지 못하는 반례 ==> 가장 초기에 검사를 해주어야함.
 * 2. 문제에서 사람 번호는 입력 순이 아닌, 행,열 번호순인데 이를 인지하지 못한 문제. (문제를 잘 읽어야함.. 의심해보라 왜 1번인지..)
*/
//다익스트라  + 스캔 BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int,int> mv[4] = {
    {0,1}, {0,-1}, {1,0}, {-1,0}
};
pair<int,int> nexts;
pair<int,int> curPos;
pair<int,int> manEnd[400];

int n,m,feul, manCount;
int map[20][20];

void printMap(int maps[20][20]) {
    cout<<"======="<<endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (curPos.first == i && curPos.second == j) 
                cout<<"S ";
            else
                cout<<maps[i][j]<<" ";
        }
        cout<<endl;
    }
}

//연료 소모량 -> mode ==0 -> 최단경로, mode ==1 승객 찾기
int bfs(pair<int,int> start, pair<int,int> end, int mode) {
    queue<pair<int,int>> q;
    queue<pair<int,int>> man;
    q.push(start);
    int visited[20][20] = {0,}, minVal = 405;
    if (mode == 1 && map[start.first][start.second]) {
        nexts = start;
        return 0;
    }

    visited[start.first][start.second] = 1;

    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;

        for (int i = 0 ; i < 4 ; i++) {
            int dx = x + mv[i].first, dy = y + mv[i].second; 
            //승객을 지나쳐서 갈 수 있는지 애매함 예제에는 안된다고 하고 짬
            if (dx < 0 || dx >= n || dy < 0 || dy >= n || visited[dx][dy] || map[dx][dy] == 1)
                continue;
            
            if (mode == 0 && dx == end.first && dy == end.second) {
                return visited[x][y];
            }
            else if (mode == 1 && map[dx][dy]) {
                if (man.empty() || visited[man.front().first][man.front().second] >= visited[x][y]+1) {
                    man.push(pair<int,int>(dx,dy));
                    visited[dx][dy] = visited[x][y] + 1;
                    continue;
                }
            }

            visited[dx][dy] = visited[x][y] + 1;
            q.push(pair<int,int>(dx,dy));

        }
        q.pop(); 
    }

    int feuls = 0;

    if (man.empty()) {
        cout<<-1;
        exit(0);
    }

    int minX = n , minY = n;
    while (!man.empty()) {
        if (mode == 1 && (minX > man.front().first || (minX == man.front().first && minY > man.front().second))) {
            minX = man.front().first, minY = man.front().second;
            feuls = visited[man.front().first][man.front().second] - 1;
            nexts = man.front();
        }
        man.pop();
    } 

    return feuls;
}

void run() {
    while(manCount) {
        //손님 찾기
        int f = bfs(curPos, curPos, 1);
        curPos = nexts;
        int e = bfs(curPos, manEnd[map[curPos.first][curPos.second]-2], 0);
        curPos = manEnd[map[curPos.first][curPos.second]-2];
        if (feul >= f+e) {
            map[nexts.first][nexts.second] = 0;
            feul += e-f;
            manCount--;
        }
        else {
            cout<<-1;
            exit(0);
        }
    }
}


int main(void)
{
    cin>>n>>m>>feul;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin>>map[i][j];
        }
    }
    
    cin>>curPos.first>>curPos.second;
    curPos.first--, curPos.second--;
    for (int i = 0 ; i < m ; i++) {
        int x,y, fx,fy;
        cin>>x>>y>>fx>>fy;
        x--,y--,fx--,fy--;
        map[x][y] = i+2;
        manEnd[i] = pair<int,int> (fx,fy);
    }

    //디버그
    manCount = m;
    run();
    cout<<feul;
    return 0;
}
