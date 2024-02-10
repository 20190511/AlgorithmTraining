/**
 * 
 * 뻘짓 시리즈
 *  1. 온풍기바람 체크 <-- 근데 얜 문제가 아니었음 (문제조건을 잘 못 케이스인데 온풍기 앞에 장애물은 두지 않는다고 명시)
 *      --> 하지만, 문제에서 온풍기가 있는 칸과 바람이 나오는 방향에 있는 칸 사이에는 벽이 없다 라고 명시를 해주긴함.
 *  2. <중요 체크미스> :: 온풍기 바람이 0이하가 되는 지점에서는 queue에 삽입되지 않도록 하기 위해 val >= 1이라고 체크를 해두었지만.
 *      -> 실제로는 val 이 1일때면 현재값이 0인 상태가 삽입이 되기 때문에 -1이 들어가는 중대한 실수를 해버림
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

struct info {
    int x;
    int y;
    int dir;
};

int r,c,k;
int map[20][20]; 
bool rWall[20][20], cWall[20][20]; //r : 가로, c : 세로
deque<info> machine;
deque<pair<int,int>>checker;
pair<int,int> mv[4] = {
    {0,1}, {0,-1}, {-1,0}, {1,0}
};

void printMap() {
    cout<<"====="<<endl;
    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < c ; j++) {
            cout<<map[i][j]; 

            if (cWall[i][j])
                cout<<"|";
            else
                cout<<" ";
        }
        cout<<endl;

        for (int j = 0 ; j < c ; j++) {
            if (map[i][j] > 10)
                cout<<" ";
            if (rWall[i][j])
                cout<<"──";
            else
                cout<<"  ";
        }
        cout<<endl;
    }
}

bool windChecker(int x, int y, int dir) {
    if (x < 0 || x >= r || y < 0 || y >= c)
        return false;
    switch (dir) {
    case 0:
        if (cWall[x][y-1]) return false;
        break;
    case 1:
        if (cWall[x][y]) return false;
        break;
    case 2:
        if (rWall[x][y]) return false;
        break;
    case 3:
        if (rWall[x-1][y]) return false;
        break;
    }
    return true;
}

void wind(info cond) {
    int otherOp = 2 - (cond.dir/2)*2;
    int x = cond.x, y = cond.y, dir = cond.dir;
    bool visited[20][20] = {0,}; 
    x += mv[dir].first, y+= mv[dir].second;
    /*
    // 온풍기에서 바람이 한 번 나왔을 때, 온풍기의 바람이 나오는 방향에 있는 칸은 항상 온도가 5도 올라간다.
    if (!windChecker(x,y,dir) || visited[x][y])
        return;
    */
    map[x][y] += 5;

    queue<info> q;
    q.push((info){x,y,5});
    while(!q.empty()) {
        int cx = q.front().x , cy = q.front().y, val =q.front().dir;
        q.pop();
        int dx,dy;
        //중앙
        dx = cx + mv[dir].first, dy = cy + mv[dir].second;
        if (windChecker(dx,dy,dir) && !visited[dx][dy]) {
            map[dx][dy] += val-1;
            if (val >= 2) {
                q.push((info){dx,dy,val-1});
            }
            visited[dx][dy] = true;
        }
        //수직
        for (int i = 0; i < 2; i++) {
            dx = cx + mv[otherOp+i].first, dy = cy + mv[otherOp+i].second;
            if (!windChecker(dx, dy, otherOp+i) || visited[dx][dy]) {
                continue;
            }
            dx = dx + mv[dir].first, dy = dy + mv[dir].second;
            if (windChecker(dx, dy, dir) && !visited[dx][dy]) {
                map[dx][dy] += val-1;
                if (val >= 2) {
                    q.push((info){dx,dy,val-1});
                }
                visited[dx][dy] = true;
            }
        }
    }
}

int main(void)
{
    int val;
    cin>>r>>c>>k;
    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < c ; j++) {
            cin>>val;
            if (!val) 
                continue;
            else if (val == 5)
                checker.push_back(pair<int,int> (i,j));
            else
                machine.push_back((info){i,j,--val});
        }
    }

    int wCount;
    cin>>wCount;
    while(wCount--) {
        int x,y,t;
        cin>>x>>y>>t;
        --x, --y;
        if (!t)
            rWall[x - 1][y] = true;
        else
            cWall[x][y] = true;
    }

    for (int i = 1 ; i <= 100 ; i++) {
        for (int s = 0 ; s < machine.size() ; s++) {
            wind(machine[s]);
        }
        //printMap(); //check 완료

        int cpyMap[20][20] = {0,};
        bool visited[20][20] = {0,};
        memcpy(cpyMap, map, sizeof(map));
        for (int a = 0 ; a < r ; a++) {
            for (int b = 0 ; b < c ; b++) {
                visited[a][b] = true;
                for (int dir = 0 ; dir < 4 ; dir++) {
                    int dx = a + mv[dir].first, dy = b + mv[dir].second;
                    if (visited[dx][dy] || !windChecker(dx,dy,dir))
                        continue;
                    int diff = cpyMap[a][b] - cpyMap[dx][dy];
                    if (diff < 0) {
                        diff = -diff;
                        map[dx][dy] -= diff/4;
                        map[a][b] += diff/4;
                    }
                    else {
                        map[dx][dy] += diff/4;
                        map[a][b] -= diff/4;
                    }
                } 
            }
        }

        //printMap();
        for (int a = 0 ; a < r ; a++) {
            if (map[a][0]) map[a][0]--;
            if (map[a][c-1]) map[a][c-1]--;
        }
        for (int b = 1 ; b < c-1 ; b++) {
            if (map[0][b]) map[0][b]--;
            if (map[r-1][b]) map[r-1][b]--;
        }
        //printMap();

        bool passFlag = true;
        for (int s = 0 ; s < checker.size() ; s++) {
            if (map[checker[s].first][checker[s].second] < k)  { 
                passFlag = false;
                break;
            }
        }
        if (passFlag) {
            //printMap();
            cout<<i;
            return 0;
        }
    }
    cout<<101;
    return 0;
}
