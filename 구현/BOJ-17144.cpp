#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//1043 ~ 1209

int r,c,t;

int map[50][50];
pair<int,int> mv[4] = {
    {-1,0}, {0,1}, {1,0}, {0,-1}
};

pair<int,int> air[2];
void dust() {
    int map2[50][50] = {0,};
    //해당 좌표는 마지막에 채우는 것으로 통일
    map2[air[0].first][air[0].second] = -1;
    map2[air[1].first][air[1].second] = -1;
    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < c ; j++) {
            if (map[i][j] <= 0) 
                continue;
            int curVal = map[i][j], minusVal = 0;
            for (int x = 0 ; x < 4 ; x++) {
                int dx = i + mv[x].first , dy = j + mv[x].second; 
                if (dx < 0 || dx >= r || dy < 0 || dy >= c || map[dx][dy] == -1) 
                    continue;
                
                map2[dx][dy] += curVal / 5;
                minusVal += curVal / 5;

            }
            map2[i][j] += curVal - minusVal;
        }
    }
    memcpy(map, map2, sizeof(int)*50*50);
}

void airs(pair<int,int> mv[4], int cx, int cy, int mode) {
    int sx = cx;
    for (int x = 0 ; x < 4 ; x++) {
        while(true) {
            int dx = cx + mv[x].first, dy = cy + mv[x].second;
            if (dx < 0 || dx >= r || dy < 0 || dy >= c || (x == 2 && mode*dx > mode*sx))
                break;

            if (map[cx][cy] != -1 && map[dx][dy] != -1) {
                map[cx][cy] = map[dx][dy];
                map[dx][dy] = 0;
            }
            cx = dx, cy = dy;
        }
    }
    

}
void run() {
    pair<int,int> mv1[4] = { {-1,0}, {0,1}, {1,0}, {0,-1}}, mv2[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    for (int i = 0 ; i < t ; i++) {
        dust();
        airs(mv1, air[0].first, air[0].second, 1);
        airs(mv2, air[1].first, air[1].second, -1);
    }
}

int main(void)
{
    cin>>r>>c>>t;
    int ac = 0;
    for (int i = 0 ; i < r ; i++)  {
        for (int j = 0 ; j < c ; j++) {
            int a;
            cin>>a;
            map[i][j] = a;
            if (a == -1) {
                air[ac].first = i, air[ac].second = j;
                ac++;
            }
        }
    }
    run();
    int cnt = 0;
    for (int i = 0 ; i < r ; i++) 
        for (int j = 0 ; j < c ; j++)
            if (map[i][j] > 0)
                cnt += map[i][j];
    cout<<cnt;
    return 0; 
}
