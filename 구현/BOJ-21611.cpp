//1125 ~ 1312 : 
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

// ↑, ↓, ←, →
/**
 * 실수 1 : 다른 공이 나왔을 때 이전의 공이 4개이상인지 체크하는 로직에서  마지막 부분에 4개이상의 구슬이 들어와있으면 pop_back() 해주고 점수 추가를 안해주는 실수를 함
 * 실수 2 : 실수 1을 해결하는 과정에서 empty() 체크를 안해줘서 index 오류가남 ㅋㅋㅋ
 * 지엽 3 : 구슬이 동시에 폭파 후 재폭파 이런식이다. (동시에 폭파하는 점을 고려못함.) --> 완전히 잘못푼게 된 것임
 *      >> 교훈
*/
pair<int,int> mv[4] = {
    {-1,0}, {1,0}, {0,-1}, {0,1}
};

pair<int,int> mv2[4] = {
    {0,-1}, {1,0}, {0,1}, {-1,0}
};
int n, map[50][50], dcount = 0;
queue<pair<int,int>> cmd;

void printMap() {
    cout<<"======"<<endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) 
            printf("%2d ", map[i][j]);
        cout<<endl;
    }

}

//1:큐에 구슬 넣기 (구슬 개수, 번호)
deque<pair<int,int>> balls;
void ballVector() {
    int cx = n/2, cy = n/2, cnt = 0;
    for (int i = 1 ; i < n ; i++) {
        for (int s = 0 ; s < i ; s++) {
            cx += mv2[cnt].first;
            cy += mv2[cnt].second;

            if (map[cx][cy] == -1) map[cx][cy] = 0;
            if (map[cx][cy] == 0) continue;

            //순회 코드
            if (balls.empty() || balls.back().second != map[cx][cy]) {
                balls.push_back(pair<int,int>(1, map[cx][cy]));
            }
            else {
                balls.back().first++;
            }
        }

        cnt = (cnt+1)%4; 
        for (int s = 0 ; s < i ; s++) {
            cx += mv2[cnt].first;
            cy += mv2[cnt].second;
            if (map[cx][cy] == -1) map[cx][cy] = 0;
            if (map[cx][cy] == 0) continue;
            //순회 코드
            if (balls.empty() || balls.back().second != map[cx][cy]) {
                balls.push_back(pair<int,int>(1, map[cx][cy]));
            }
            else {
                balls.back().first++;
            }
        }
        cnt = (cnt+1)%4; 
    }

    for (int s = 0 ; s < n ; s++) {
            cx += mv2[cnt].first;
            cy += mv2[cnt].second;

            if (map[cx][cy] == -1) map[cx][cy] = 0;
            if (map[cx][cy] == 0) continue;
            //순회 코드
            if (balls.empty() || balls.back().second != map[cx][cy]) {
                balls.push_back(pair<int,int>(1, map[cx][cy]));
            }
            else {
                balls.back().first++;
            }
    } 

    if (!balls.empty() && balls.back().first >= 4) {
        dcount += balls.back().first * balls.back().second;
        balls.pop_back();
    }
}

void vectorProcess() {
    int brkCnt = 0;
    pair<int,int> b;
    while(true) {
        deque<pair<int,int>> tmp; 
        brkCnt = 0;
        while(!balls.empty()) {
            b = balls.front();
            /*
            for (int i = 0 ; i < b.first ; i++) 
                cout<<b.second<<" ";
            */
            balls.pop_front();

            if (b.first >= 4) {
                brkCnt++;
                dcount += b.first * b.second;
                continue;
            }

            if (tmp.empty() || tmp.back().second != b.second) {
                tmp.push_back(b);
            }
            else
                tmp.back().first += b.first;
        } 
        //cout<<endl;
        balls = tmp;
        //cout<<brkCnt<<endl;
        if (!brkCnt) break;
    }
}

pair<int,int> nextBall() {
    if (balls.empty())
        return pair<int,int>(0,0);
    pair<int,int> retV = balls.front();  
    balls.pop_front();
    return retV;
}

//mode 1 : 인접4개, mode2 : 그룹화 복제
void setBall() {
    int cx = n/2, cy = n/2, cnt = 0, checker = 0;
    pair<int,int> nb = nextBall();
    for (int i = 1 ; i < n ; i++) {

        for (int s = 0 ; s < i ; s++) {
            cx += mv2[cnt].first;
            cy += mv2[cnt].second;
            //순회 코드 
            if (!nb.first) {
                map[cx][cy] = 0;
                continue;
            }
            else {
                map[cx][cy] = !checker ? nb.first : nb.second;
                checker++;
            }

            if (checker == 2) {
                nb = nextBall();
                checker = 0;
            }

        }

        cnt = (cnt+1)%4; 
        for (int s = 0 ; s < i ; s++) {
            cx += mv2[cnt].first;
            cy += mv2[cnt].second;
            //순회 코드
            if (!nb.first) {
                map[cx][cy] = 0;
                continue;
            }
            else {
                map[cx][cy] = !checker ? nb.first : nb.second;
                checker++;
            }

            if (checker == 2) {
                nb = nextBall();
                checker = 0;
            }
        }
        cnt = (cnt+1)%4; 
    }
    for (int s = 0 ; s < n ; s++) {
        cx += mv2[cnt].first;
        cy += mv2[cnt].second;
            if (!nb.first) {
                map[cx][cy] = 0;
                continue;
            }
            else {
                map[cx][cy] = !checker ? nb.first : nb.second;
                checker++;
            }

            if (checker == 2) {
                nb = nextBall();
                checker = 0;
            }
    } 
}

void run() {
    int sx = n/2, sy = n/2;
    while(!cmd.empty()) {
        int d = cmd.front().first, s = cmd.front().second;
        cmd.pop();

        for (int sx2 = sx + mv[d].first, sy2 = sy + mv[d].second ;s != 0;s--, sx2 += mv[d].first, sy2 += mv[d].second)
            map[sx2][sy2] = -1;
        //printMap();
        ballVector();

        /*
        for (int cc = 1 ; !balls.empty() ; cc++) {
            cout<<"["<<cc<<"]"<<balls.front().first<<", "<<balls.front().second<<endl;
            balls.pop_front();
        }
        */
        
        vectorProcess(); 
        setBall();
        //printMap();
        balls.clear();
    }
} 
int main(void)
{
    int m;
    cin>>n>>m;
    for (int i = 0 ; i < n ; i++) 
        for (int j = 0 ; j < n ; j++) 
            cin>>map[i][j];
    
    for (int i = 0 ; i < m ; i++) {
        int d,s;
        cin>>d>>s;
        cmd.push(pair<int,int>(--d, s));
    }
    
    run();
    cout<<dcount;
    return 0;
}
