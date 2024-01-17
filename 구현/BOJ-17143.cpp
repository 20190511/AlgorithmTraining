#include <iostream>
#include <vector>
using namespace std;

int r,c,m;
int map[100][100] = {0,};
pair<int,int> mv[5] = {
    {0,0}, {-1,0}, {1,0}, {0,1}, {0,-1}
};

// 상어 시뮬레이션 방향전환 1<->2 , 3<->4
typedef struct {
    int x;
    int y;
    int s;
    int d;
    int z;
}Obj;

void printMap() {
    cout<<"======"<<endl;
    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < c ; j++) {
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<Obj> v;
int tc = 0;
void run() {
    for (int j = 0; j < c ; j++) {
        //i가 이미 이동했다고 치고 물고기 잡기
        vector<Obj> saveL, saveV;        
        for (int i = 0 ; i < r ; i++) {
            if (map[i][j]) {
                tc += map[i][j];
                map[i][j] = 0;
                break;
            }
        }
        while(!v.empty()) {
            Obj o = v.back();
            v.pop_back();
            if (map[o.x][o.y] != o.z) 
                continue;
            map[o.x][o.y] = 0; 
            for (int k = 0; k < o.s ; k++) {
                int dx = o.x + mv[o.d].first, dy = o.y + mv[o.d].second;
                if (dx < 0 || dx >= r || dy < 0 || dy >= c) {
                    switch (o.d)
                    {
                    case 1:
                        o.d = 2;
                        break;
                    case 2:
                        o.d = 1;
                        break;
                    case 3:
                        o.d = 4;
                        break;
                    case 4:
                        o.d = 3;
                        break;
                    }
                    dx = o.x + mv[o.d].first, dy = o.y + mv[o.d].second;
                }
                else {
                }

                o.x = dx, o.y = dy;
            }
            saveV.push_back(o);
        }    

        //맵 적용
        while(!saveV.empty()) {
            Obj o = saveV.back();
            saveV.pop_back();
            if (map[o.x][o.y] < o.z) {
                map[o.x][o.y] = o.z;
                v.push_back(o);
            }
        }
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>r>>c>>m;
    for (int i = 0 ; i < m ; i++) {
        Obj o;
        cin>>o.x>>o.y>>o.s>>o.d>>o.z;
        o.x--, o.y--;
        int m;
        if (o.d <= 2) {
            for (; o.s >= 0 ; o.s -= (r-1)*2);
            o.s += (r-1)*2;
        }
        else {
            for (; o.s >= 0 ; o.s -= (c-1)*2);
            o.s += (c-1)*2;
        }

        if (map[o.x][o.y] < o.z) {
            map[o.x][o.y] = o.z;
            v.push_back(o);
        }
    }
    run();
    cout<<tc;
}
