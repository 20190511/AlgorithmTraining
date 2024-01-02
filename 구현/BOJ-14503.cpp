//2102 ~ 2139
/*
    => 시작할 때 한 번 방향 회전하는거 고려할 것.
*/
#include <iostream>
#include <vector>
using namespace std;

int n,m;
int x,y;
int dir;

int map[50][50];
int cleanArea = 0;

//dir 0:북,동,남,서
pair<int,int> mv[4] = {
    {-1,0}, {0,1}, {1,0}, {0,-1}
};

void printMap() {
    cout<<"=============="<<endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}

void simulaotr() {
    while(true) {
        int nx, ny;
        //청소 되지 않은 칸이면 청소
        if (map[x][y] == 0) {
            map[x][y] = 2;
            cleanArea++; 
        }

        int next = false, ndir, count;
        for (count = 0, ndir=dir+3 ; count < 4 ; ndir--, count++) {
            nx = x + mv[ndir%4].first, ny = y + mv[ndir%4].second;
            

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (map[nx][ny] == 0) {
                dir = ndir%4, x = nx, y = ny;
                next = true;
                break; 
            }
        }
        if (next)
            continue;

        //모두 청소된 공간이라면 방향유지한 채 후진
        nx = x-mv[dir].first, ny = y-mv[dir].second;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            break;
        else if (map[nx][ny] == 1)
            break;
        else  {
            x = nx, y = ny;
        }
    }   
}

int main(void) {
    cin>>n>>m; 
    cin>>x>>y>>dir;

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin>>map[i][j];
        }
    }    

    simulaotr();
    cout<<cleanArea;
    return 0;
}
