//1040 ~ 1232 : 시간초과가 헬 문제
/**
 *  시간초과 안났으면 1시간 정도 걸려서 푼 문제였다.
 * 시간초과 해결 테크닉:
 *  얘가 거의 1시간 잡아먹었다. 100 * 100 * 1000 = 1억ns 이기 때문에 거의 1초로 친다.
 *  그래서 선형적으로 해결하기 위해서 이동속도를 해결하는 테크닉이 필요하다.
 *      ! 해결방법은 원점으로 돌아오는 시점을 잘 파악해서 푸는 것인데 이때 상어는 좌우, 상하 한 방향으로 움직이므로
 *      (규칙성있게 원점으로 돌아오므로) 규칙을 찾아보면 (r-1)*2 혹은 (c-1)*2 임을 알 수 있다.
 *      --> 시간 최적화 테크닉이 필수인 문제..
 *      
 * 구현실수 : 
 *  1. 벡터복사는 = 로 해주면 알아서 operator가 복사된다는 점 기억 (빨리 수정함)
 *  2. 지역변수 m을 선언을 (int) 2번해서 반영이 안되었던 실수. (빨리 수정함)
 * 
*/

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
