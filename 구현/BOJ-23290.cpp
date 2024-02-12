//1100 ~ 실패 *문제 이해를 잘못해석함
/**
 * 1. 밑에 노트가 있다는데 노트를 못 찾아서 Shark를 구현하다가 왜틀렸지 하면서 시간을 다 보내버림
 * 2. 문제에서 
 *  "모든 물고기가 한 칸 이동한다. 
 *  상어가 있는 칸, 물고기의 냄새가 있는 칸, 격자의 범위를 벗어나는 칸으로는 이동할 수 없다. 
 *  각 물고기는 자신이 가지고 있는 이동 방향이 이동할 수 있는 칸을 향할 '때까지' 방향을 45도 반시계 회전시킨다. 
 *  만약, 이동할 수 있는 칸이 없으면 이동을 하지 않는다. 그 외의 경우에는 그 칸으로 이동을 한다. 물고기의 냄새는 아래 3에서 설명한다"
 * 
 *  >> 때까지를 못봐서 한칸 움직이고 못 움직이면 이동을 하지 않게했다가 고치느라 시간을 꽤 썼다.
 * 3. 상어는 8방향이 아닌 4방향만 움직이는데 캐치하지 못함. (밑에 노트를 봤더라면..)

*/

#include <iostream>
#include <deque>
#include <vector>
#include <cstring>
using namespace std;
#define DEBUG  true 

deque<int> map[4][4], map2[4][4];
int smell[4][4];
pair<int,int> mv[8] = {
    {0,-1}, {-1,-1}, {-1,0}, {-1,1},
    {0, 1}, { 1, 1}, { 1,0}, {1,-1}
};
pair<int,int> smv[4] = {
    {-1,0}, {0,-1}, {1,0}, {0,1}
};
pair<int,int> shark;

void printDir(int x) {
    
    if (x == 0)
        cout<<"← ";
    else if (x == 1)
        cout<<"↖ ";
    else if (x == 2)
        cout<<"↑ ";
    else if (x == 3)
        cout<<"↗ ";
    else if (x == 4)
        cout<<"→ ";
    else if (x == 5)
        cout<<"↘ ";
    else if (x == 6)
        cout<<"↓ ";
    else if (x == 7)
        cout<<"↙ ";
}
void printMap(deque<int> map[4][4], int debug, int cur) {
    if (cur < debug) 
        return;
    cout<<"====="<<endl;
    for (int i = 0 ; i < 4 ; i++) {
        for (int j = 0 ; j < 4 ; j++) {
            cout<<"[";
            int size = map[i][j].size();
            while(size--) {
                printDir(map[i][j][size]);
            }
            cout<<"] ";
        }
        cout<<endl;
    }

    cout<<"+++ smell +++"<<endl;
    for (int i = 0 ; i < 4 ; i++) {
        for (int j = 0 ; j < 4 ; j++) {
            cout<<smell[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"cur Shark pos :: "<<shark.first+1<<", "<<shark.second+1<<endl;
}

bool canMove(int i, int j) {
    if (i < 0 || i >= 4 || j < 0 || j >= 4)
        return false;
    if (smell[i][j] || (shark.first == i && shark.second == j))
        return false;
    return true;
}

void fishMove() {
    for (int i = 0 ; i < 4 ; i++) {
        for (int j = 0 ; j < 4 ; j++) {
            if (!map[i][j].size())
                continue;
            int sz = map[i][j].size();
            while(sz--) {
                int dir = map[i][j][sz];
                int dx = mv[dir].first + i, dy = mv[dir].second + j;
                if (!canMove(dx,dy)) {
                    dir = (dir+7)%8;
                    for (int count = 1 ; count < 8 ; count++, dir = (dir+7)%8) {
                        dx = i + mv[dir].first, dy = j + mv[dir].second;
                        if (canMove(dx,dy)) {
                            break;
                        }
                    }
                }
                if (canMove(dx,dy)) {
                    map2[dx][dy].push_back(dir);
                } else {
                    map2[i][j].push_back(map[i][j][sz]);
                }
            }
        }
    }
}

int sharkMaxEat;
int sd[3] = {-1,-1,-1};
int visited[4][4] = {0,};
void printV() {
    for (int i = 0 ; i < 4 ; i++) {
        for (int j = 0 ; j < 4 ; j++) {
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }
}
void sharkMove(pair<int,int> curVal, int val, int depth, int abc[2]) {
    if (depth == 0) {
        sharkMaxEat = -1;
        memset(visited, 0, sizeof(visited));
    }

    int dx,dy, cv;
    for (int i = 0 ; i < 4; i++) {
        dx = curVal.first + smv[i].first, dy = curVal.second + smv[i].second;
        if (dx < 0 || dx >= 4 || dy < 0 || dy >= 4)
            continue;

        if (!visited[dx][dy]) 
            cv = val + (int)map2[dx][dy].size();
        else
            cv = val;

        if (depth == 2) {
            if (sharkMaxEat < cv) {
                sd[0] = abc[0];
                sd[1] = abc[1];
                sd[2] = i;
                sharkMaxEat = cv;
            }
        }
        else {
            abc[depth] = i;
            visited[dx][dy]++;
            sharkMove(pair<int,int>(dx,dy), cv, depth+1, abc);
            visited[dx][dy]--;
        }
    }

    dx = curVal.first, dy = curVal.second;
    if (depth == 0) {
#if DEBUG
        cout<<"상어 이동 >> ";
#endif
        for (int i = 0 ; i < 3 ; i++) {
#if DEBUG
        switch(sd[i]) {
        case 0:
            cout<<"상 ";
            break;
        case 1:
            cout<<"좌 ";
            break;
        case 2:
            cout<<"하 ";
            break;
        case 3:
            cout<<"우 ";
            break;
        }
#endif
            dx += smv[sd[i]].first;
            dy += smv[sd[i]].second;
            if (map2[dx][dy].size()) {
                smell[dx][dy] = 3;
                map2[dx][dy].clear();
            }
        }
#if DEBUG
        cout<<endl;
#endif
    }
    shark = pair<int,int> (dx,dy);
}

int smellAndCopy() {
    int totalCount = 0;
    for (int i = 0 ; i < 4 ; i++) {
        for (int j = 0 ; j < 4 ; j++) {
            if (smell[i][j])
                smell[i][j]--;
            while(!map2[i][j].empty()) {
                map[i][j].push_back(map2[i][j].back());
                map2[i][j].pop_back();
            }
            totalCount += (int)map[i][j].size();
        }
    }
    return totalCount;
}

int main(void)
{
    int m,s;
    cin>>m>>s;
    while(m--) {
        int a,b,c;
        cin>>a>>b>>c;
        map[--a][--b].push_back(--c);
    }
    cin>>shark.first>>shark.second;
    shark.first--;
    shark.second--;
    int result = 0;
    for (int i = 1 ; i <= s ; i++) {
#if DEBUG
        cout<<endl<<endl<<"--start ["<<i<<"] ---"<<endl;
        cout<<endl<<"물고기 이동"<<endl;
#endif
        // 물고기 이동
        fishMove();
#if DEBUG
        printMap(map2,3, i);   
        cout<<endl<<"상어 이동"<<endl;
#endif
        // 상어이동
        int abc[2];
        sharkMove(shark, 0, 0, abc);
#if DEBUG
        printMap(map2, 1, i);
        cout<<endl<<"냄새 소멸 및 물고기 복사"<<endl;
#endif
        //냄새 소멸 및 물고기 복사
        result = smellAndCopy();
#if DEBUG
        printMap(map, 1, i);
#endif
    }
    cout<<result;
    return 0;
}
