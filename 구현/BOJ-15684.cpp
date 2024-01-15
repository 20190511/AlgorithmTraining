//1707 ~ 1813
/**
 * cpp 배열 복사
 *  copy(begin)
 * memcpy
 * 
 * 실수 요인:
 *  1. n,h 가 가로 세로인지 먼저 체크하고 풀어볼 것!! (실수 많이해서 시간 10분은 잡아먹은듯)
 *  2. 좌표에서 왼/오른쪽 이동하는 부분을 단지 1로 두다가 오류가났음
 *      --> 좌표 점으로 그래프를 판단할 때는 인접한 부분이 더 많은 정보가 줄 수 있도록 배열을 변경해야함.
*/
#include <iostream>
using namespace std;

int n,m,h;
int answer = 4;

int map[31][11] = {0,};
bool checker() {
    for (int y = 1 ; y <= n ; y++) {
        int cur = y;
        for (int start = 1 ; start <= h ; start++)  {
            if (map[start][cur]) {
                if (map[start][cur] == 1) 
                    cur--;
                else
                    cur++;
            }
        }
        if (cur != y) {
            return false;
        }
    }
    return true;
}

void simulator(int depth)
{

    if (checker()) {
        answer = min(answer, depth);
        if (answer == 0) {
            cout<<0;
            exit(0);
        }
    }

    if(depth >= 3) {
        return;
    }

    for (int x = 1 ; x <= h ; x++) {
        for (int y = 1 ; y < n ; y++) {
            if (map[x][y] || map[x][y+1])
                continue;   
            map[x][y] = -1;
            map[x][y+1] = 1;
            simulator(depth+1);
            map[x][y] = map[x][y+1] = 0;
        }
    }
    return;
}

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>h;
    int x,y;
    for (int i = 0 ; i < m ; i++) {
        cin>>x>>y;
        map[x][y] = -1;
        map[x][y+1] = 1;
    }

    simulator(0);
    answer = answer == 4 ? -1 : answer;
    cout<<answer;
    return 0;
}
