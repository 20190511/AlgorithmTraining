//1158 ~ 1338 : 100분..
/**
 * 원판 rotate 과정에서 포인터를 이용해서 돌리는 부분이 있다. (앞전 문제와 유사함)
 *  
 *  실수1. 하지만 중요한 실수요소 : 다음 원판의 경우에서는 ptr[x] + J + mv[i].first 이런식으로 해줘야하는데 ptr를 고려하지 못하는 경우ㅑ
 *  실수2. 총 개수를 세는 부분에서 평균을 빼주는 아이디어까지 좋았지만 평균 뺄 때 원판의 값의 총 개수가 빠지는 부분 고려못함
*/
#include <iostream>
#include <vector>
using namespace std;

int n,m,t;
int map[51][50];
int ptr[51] = {0,};
int xdk[50][3] = {0,};
int totalCount = 0, elementCount = 0;
pair<int,int> mv[4] = {
    {1,0}, {-1,0}, {0,1}, {0,-1}
};

void printMap(int map[51][50]) {
    cout<<"======"<<endl;
    for (int i = 1 ; i <= n ; i++)
        cout<<ptr[i]<<" ";
    cout<<endl;
    cout<<"------"<<endl;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cout<<map[i][(ptr[i]+j)%m]<<" ";
        }
        cout<<endl;
    }
}

void run() {
    for (int r = 0 ; r < t ; r++) {
        //회전
        for (int s = xdk[r][0] ; s <= n ; s += xdk[r][0]) {
            ptr[s] = !xdk[r][1] ? (ptr[s]-xdk[r][2]+m)%m : (ptr[s]+xdk[r][2])%m;       
        }

        //인접 찾기
        vector<pair<int,int>> v;
        for (int s = 1 ; s <= n ; s++) {
            for (int j = 0 ; j < m ; j++) {
                int curJ = (ptr[s]+j)%m, curVal = map[s][curJ];
                for (int i = 0 ; i < 4 ; i++) {
                    int dx = mv[i].first + s; 
                    if (dx <= 0 || dx > n)
                        continue;
                        
                    int dy = (mv[i].second + ptr[dx] + j)%m;
                    dy = dy < 0 ? dy + m : dy;
                    if (map[dx][dy] && map[dx][dy] == curVal) {
                        v.push_back(pair<int,int>(s,curJ));
                        break;
                    }
                }
            }
        }

        if (v.size() == 0) {
            if (!elementCount)
                continue;
            int ev_a = totalCount / elementCount, ev_b = totalCount % elementCount;
            for (int s = 1 ; s <= n ; s++) {
                for (int j = 0 ; j < m ; j++) {
                    if (!map[s][j]) 
                        continue;

                    if (map[s][j] > ev_a) {
                        totalCount--;
                        map[s][j]--;
                    }
                    else if (map[s][j] < ev_a || (map[s][j] == ev_a && ev_b > 0)) {
                        totalCount++;
                        map[s][j]++;
                    }
                }
            }
            continue;
        }

        while(!v.empty()) {
            pair<int,int> xy = v.back();
            totalCount -= map[xy.first][xy.second];
            map[xy.first][xy.second] = 0;
            elementCount--;
            v.pop_back();
        }
    }
}

int main(void) {
    cin>>n>>m>>t;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin>>map[i][j];
            totalCount += map[i][j];
            elementCount++;
        }
    }
    for (int i = 0 ; i < t ; i++) {
        cin>>xdk[i][0]>>xdk[i][1]>>xdk[i][2];
    }

    run();
    cout<<totalCount;

    return 0;
}
