//1216 ~ 1334
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
#define RUNS    1000

struct horse {
    int rank;
    int dir;

    horse(int a, int b) {
        rank = a, dir = b; 
    }
};

struct saveH{
    int first;
    int second;
    int dir; 
    saveH(int a, int b, int c) {
        first = a, second = b, dir = c;
    }
};

#define blue    2
#define red     1
#define white   0
int map[12][12];
int n,k;

vector<horse> obj[12][12];
saveH horsePos[10] = { {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}}; //말 위치 기록

pair<int,int> mv[5] = {
    {0,0}, {0,1}, {0,-1}, {-1,0}, {1,0}
};

void printMap() {
    cout<<"======="<<endl;
    for (int i = 0 ; i < n ; i++)  {
        for (int j = 0 ; j < n ; j++) {
            cout<<map[i][j];

            if (obj[i][j].size() == 0)  {
                cout<<" ";
                continue;
            }
            cout<<"[";
            for (int x = obj[i][j].size()-1 ; x >= 0 ; x--) {
                cout<<obj[i][j][x].rank+1<<"(";
                int dir = obj[i][j][x].dir;
                switch(dir) {
                case 1:
                    cout<<"→)";
                    break;
                case 2:
                    cout<<"←)";
                    break;
                case 3:
                    cout<<"↑)";
                    break;
                case 4:
                    cout<<"↓)";
                    break;
                }
                if (x != 0)
                    cout<<" ";
            }
            cout<<"] ";
        }
        cout<<endl;
    }
}
// 색 판단 함수 0:white, 1:red, Blue:2
int mapColor(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) 
        return blue;
    return map[x][y];
}


int horseMove(int rank) {     
    saveH xy = horsePos[rank];
    int x = xy.first, y = xy.second;
    int dx = x + mv[xy.dir].first, dy = y + mv[xy.dir].second;

    //이동방향 체크 및 방향전환
    int color = mapColor(dx,dy);
    if (color == blue) {
        switch(xy.dir) {
        case 1:
            xy.dir = 2;
            break;
        case 2:
            xy.dir = 1;
            break;
        case 3:
            xy.dir = 4;
            break;
        case 4:
            xy.dir = 3;
            break;
        }
        horsePos[rank].dir = xy.dir;
        for (int i = 0 ; i < obj[x][y].size() ; i++) {
            if (obj[x][y][i].rank == rank) {
                obj[x][y][i].dir = xy.dir;
            }
        }
        dx = x + mv[xy.dir].first, dy = y + mv[xy.dir].second;
        if ((color = mapColor(dx, dy)) == blue)
            return false; 
    }

    //뭉티기 이동
    deque<horse> tmp;
    while(!obj[x][y].empty()) {
        tmp.push_back(obj[x][y].back());
        obj[x][y].pop_back();
        if (tmp.back().rank == rank) {
            break;
        }
    }

    //이동방향으로 이동
    while(!tmp.empty()) {
        horse h = color == red ? tmp.front() : tmp.back();
        color == red ? tmp.pop_front() : tmp.pop_back();
        obj[dx][dy].push_back(h);
        horsePos[h.rank] = saveH(dx,dy,h.dir);
        if (obj[dx][dy].size() == 4)
            return true;
    }
    return false;
}

int main(void) {
    cin>>n>>k;
    for (int i = 0 ; i < n ; i++) 
        for (int j = 0 ; j < n ; j++)
            cin>>map[i][j];

    for (int i = 0 ; i < k ; i++) { 
        int a,b,c;
        cin>>a>>b>>c;
        a--, b--;
        obj[a][b].push_back(horse(i,c));
        horsePos[i] = saveH(a,b,c);
    }

    for (int i = 1 ; i <= RUNS ; i++) {
        for (int x = 0 ; x < k ; x++) {
            if (horseMove(x)) {
                cout<<i;
                exit(0);
            }
        }
    }
    cout<<-1;
    return 0;
}

