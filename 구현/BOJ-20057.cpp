//1030 ~ 1200
/**
 * outOfBounds  -> dx,dy 조건 적기 실수
 * 컴퓨터비전 필터적용과 비슷한 문제이지만 x,y 땡겨주는 부분을 놓친 실수 등을 함.
*/
#include <iostream>
#include <vector>
using namespace std;

int filter[4][5][5] = {
    {{0,0,2,0,0},
    {0,10,7,1,0},
    {5,0,0,0,0},
    {0,10,7,1,0},
    {0,0,2,0,0}}
};
int n, trash = 0, totalSum = 0, map[500][500];
pair<int,int> mv[4] = {
    {0,-1},{1,0},{0,1},{-1,0}
};

int mapSum() {
    int sums = 0;
    for (int i = 0 ; i < n ; i++) 
        for (int j = 0 ; j < n ; j++) 
            sums += map[i][j];
    return sums;
}

void printMap() {
    int sums = 0;
    cout<<"======="<<endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cout<<map[i][j]<<" ";
            sums += map[i][j];
        }
        cout<<endl;
    }
    cout<<"sums == "<<totalSum - sums<<endl;
    /*
    cout<<"====="<<endl;
    for (int x = 0; x < 4; x++) {
        cout<<"-------"<<endl;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout<<filter[x][i][j]<<" ";
            }
            cout<<endl;
        }
    }
    */
}
void rotate() {
    for (int x = 1; x < 4; x++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                filter[x][5-j-1][i] = filter[x-1][i][j];
            }
        }
    }
}


void tnd(pair<int,int> cp, int s) { 
    int x = cp.first, y = cp.second;
    int curVal = map[x][y];
    int leave = curVal;
    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 5 ; j++) {
            int dx = x-2 + i, dy = y-2 + j;
            int portial = (curVal * filter[s][i][j]) / 100;
            leave -= portial;
            if (dx < 0 || dx >= n || dy < 0 || dy >= n) {
                continue;
            }
            else {
                map[dx][dy] += portial;
            }
        }
    }
    map[x][y] = 0;
    int dx = x + mv[s].first, dy = y + mv[s].second;
    if (dx < 0 || dx >= n || dy < 0 || dy >= n) {
        return;
    }
    map[dx][dy] += leave;
}

void run() {
    pair<int,int> curPos = {n/2, n/2};
    for (int offset = 0, mvCount = 0 ; curPos.first != 0 || curPos.second != 0 ; offset++, mvCount++) {
        for (int i = 0 ; i <= offset ; i++) {
            int cx = curPos.first, cy = curPos.second;
            int x = cx+mv[mvCount%4].first , y = cy+mv[mvCount%4].second;
            tnd(pair<int,int>(x,y), mvCount%4);
            curPos.first = x, curPos.second = y;
            if (curPos.first == 0 && curPos.second == 0)
                return;
        }
        mvCount++; 
        rotate();

        for (int i = 0 ; i <= offset ; i++) {
            int cx = curPos.first, cy = curPos.second;
            int x = cx+mv[mvCount%4].first , y = cy+mv[mvCount%4].second;
            tnd(pair<int,int>(x,y), mvCount%4); 
            curPos.first = x, curPos.second = y;
            if (curPos.first == 0 && curPos.second == 0)
                return;
        }
        rotate();
    }
}

int main(void) {
    cin>>n;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin>>map[i][j];
            totalSum += map[i][j];
        }
    }
    rotate();
    run();
    
    cout<<totalSum - mapSum();
    return 0;
}
