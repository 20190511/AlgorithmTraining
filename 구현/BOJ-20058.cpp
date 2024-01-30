#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
queue<int> qq;

int n=1,q,map[64][64], map2[64][64], totalCount = 0;
int sizes[6] = {2,4,8,16,32,64};

void printMap(int map2[64][64]) {
    cout<<"========="<<endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cout<<map2[i][j]<<" ";
        }
        cout<<endl;
    }
}

void test() {
    for (int i = 0 ; i < 64 ; i++) {
        map[i/8][i%8] = i+1;
    }
}

void rotate90(int sx, int sy, int size) {
    for (int i = 0 ; i < size ; i++) {
        for (int j = 0 ; j < size ; j++) {
            map[i+sx][j+sy] = map2[size-j-1+sx][i+sy];
        }
    }
}

void rotate(int l) {
    int k = sizes[l];
    for (int i = 0 ; i < n ; i += k) {
        for (int j = 0 ; j < n ; j += k) {
            rotate90(i, j, k);
        }
    }
}

int run() {
    pair<int,int> mv[4] = {
        {0,1}, {0,-1}, {1,0}, {-1,0}
    };
    while(!qq.empty()) {
        int l = qq.front();
        qq.pop();
        if (l >= 0)
            rotate(l); 
        else
            memcpy(map, map2, sizeof(map2));

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                map2[i][j] = map[i][j];
                if (!map[i][j]) continue;
                int count = 0;
                for (int x = 0 ; x < 4 ; x++) {
                    int dx = i + mv[x].first, dy = j + mv[x].second;
                    if (dx < 0 || dx >= n || dy < 0 || dy >= n || !map[dx][dy]) {
                        count++;
                    }
                }

                if (count >= 2) {
                    map2[i][j]--;
                    totalCount--;
                }
            }
        }
    }

    //덩어리 구하기 --> map2
    bool map3[64][64] = {0,};
    queue<pair<int,int>> sq;
    int maxSpace = 0, curSpace = 0;

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (map3[i][j] || !map2[i][j]) {
                continue;
            }
            sq.push(pair<int,int>(i,j));
            curSpace = 1;
            while(!sq.empty()) {
                int x = sq.front().first, y = sq.front().second;
                sq.pop();
                map3[x][y] = true;
                for (int m = 0 ; m < 4 ; m++) {
                    int dx = x + mv[m].first, dy = y + mv[m].second;
                    if (dx < 0 || dx >= n || dy < 0 || dy >= n || map3[dx][dy] || !map2[dx][dy]) {
                        continue;
                    }
                    map3[dx][dy] = true; 
                    curSpace++;
                    sq.push(pair<int,int> (dx,dy));
                }
            }
            maxSpace = max(maxSpace, curSpace);
        }
    }

    return maxSpace;
}

int main(void) {
    //freopen("tmp1", "r", stdin);
    int s;
    cin>>s>>q;
    n = n << s;
    for (int i = 0 ; i < n ; i++) 
        for (int j = 0 ; j < n ; j++) {
            cin>>map[i][j];
            map2[i][j] = map[i][j];
            totalCount += map[i][j];
        }

    
    for (int i = 0 ; i < q ; i++) {
        int qqq;
        cin>>qqq;
        qq.push(--qqq);
    }

    int result2 = run();
    cout<<totalCount<<"\n"<<result2;
    return 0;
}
