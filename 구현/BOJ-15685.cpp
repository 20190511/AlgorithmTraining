//0943 ~ 1117 -> 좀 어려움 : 시간 내에 풀기 실패 (1시간30분 걸림)
/**
 * 회전 문제에 대한 이해도.. 떨어졌음.
 * 구현은 한 번에 통과함 (문제 이해 오류의 과정)
 * 
 *  일단, 이런 회전 문제는 좌표 비교를 통해 구할 수 있음.
 *      좌표 비교
 *      끝점 좌표 기준으로 원래 -> 새롭게 이동하는 좌표의 차이를 분석
 *      ex) 예제의 3세대 드래곤을 기준으로 함 (근데 좌표가x,y가 뒤집혀 있으므로 반대로 분석)
 *      
 *      (-1,0) 점 || (-1, 0) --> (-2,0) + (0,-1)
 *      (-1,1) 점 || (-1,-1) --> (-2,0) + (1,-1)
 *      ( 0,1) 점 || (-2,-1) --> (-2,0) + (1,-2)
 *      ( 0,0) 점 || (-2, 0) --> (-2,0) + (0,-2)
 *      
 *      로 바뀌는 점을 알 수 있다. (여기서 실수요인이, 새롭게 이동하는점 -> 원래 점 으로 표시하여 섞여버리면 규칙이 다 뭉게진다...)
 *      그럼 즉 원래의 좌표 (x,y) 는 끝점(lx,ly) + (-y,x) 좌표로 90도 이동함을 알 수 있다.
 *      
 *      그래서 vector 2개를 두고 새로운 좌표를 추가해 나가는 방식으로 구현..
 *      구현 Idea는 좋았지만 회전규칙을 찾는데 1시간을 사용한 문제.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int info[20][4];
bool map[101][101] = {false,};
pair<int,int> mv[4] = {
    {0,1}, {-1,0}, {0,-1}, {1,0}
};
int n;
int counter = 0;

void checkMap() {
    for (int i = 0 ; i < 101 ; i++) {
        for (int j = 0 ; j < 101 ; j++) {
            if (map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1])  
                counter++;
        }
    }
}

void s() {
    for (int k = 0 ; k < n ; k++) {
        vector<pair<int,int>> q;
        int x = info[k][0], y = info[k][1];
        int d = info[k][2], g = info[k][3];

        q.push_back(pair<int,int>(x,y));
        q.push_back(pair<int,int>(x+mv[d].first,y+mv[d].second));

        map[x][y] = map[x+mv[d].first][y+mv[d].second] = true;
        for (int i = 0 ; i < g ; i++) {
            vector<pair<int,int>> newQ = q;
            int lx = newQ.back().first, ly = newQ.back().second;
            newQ.pop_back();
            while(!newQ.empty()) {
                int ox = newQ.back().first, oy = newQ.back().second;                
                int dx = lx-ox, dy = ly-oy;
                map[lx-dy][ly+dx] = true;
                q.push_back(pair<int,int>(lx-dy,ly+dx));
                newQ.pop_back();
            }
        }
    }
}

int main(void)
{
    cin>>n;
    for(int i = 0 ; i < n ; i++) {
        int x,y,d,g;
        cin>>x>>y>>d>>g;
        info[i][0] = y;
        info[i][1] = x;
        info[i][2] = d;
        info[i][3] = g;
    }

    s();
    checkMap();
    cout<<counter;
    return 0;

}
