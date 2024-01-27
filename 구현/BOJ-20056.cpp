//1055 (경계 조건 없음)
#include <iostream>
#include <vector>

using namespace std;
struct obj {
    int x;
    int y;
    int m;
    int s;
    int d;
};

vector<obj> runBall;
int N,M,K;
pair<int,int> dir[8] = {
    {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}
};
//합쳐지면 질량 : 질량합 / 5, 속력 : 속력합 / 합쳐진 개수
    //방향 : 모두 홀 or 짝 : 0,2,4,6 아니면 1,3,5,7

void printMap(vector<obj> map[50][50]) {
    cout<<"================\n";
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            cout<<"(";
            if (map[i][j].empty())
                cout<<"0";
            for (int k = 0 ; k < map[i][j].size() ; k++)  {
                cout<<map[i][j][k].m;
                if (k != map[i][j].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<endl;
    }
}

int run() {
    int curSum = 0;
    vector<obj> map[50][50]; //내부적으로는 vector맵 사용해야함
    for (int i = 0 ; i < K ; i++) {
        curSum = 0;
        vector<pair<int,int>> nq;
        while(!runBall.empty()) {
            obj cObj = runBall.back();
            runBall.pop_back();
            int nx = cObj.x + (dir[cObj.d].first)*cObj.s, ny = cObj.y + dir[cObj.d].second * cObj.s;
            nx = (nx+N*cObj.s)%N;
            ny = (ny+N*cObj.s)%N;
            cObj.x = nx, cObj.y = ny;
            map[nx][ny].push_back(cObj);
            if (map[nx][ny].size() == 1) 
                nq.push_back(pair<int,int>(cObj.x, cObj.y));
        }

        //합쳐지지 않은 상태
        while(!nq.empty()) {
            pair<int,int> xy = nq.back();
            nq.pop_back();
            if (map[xy.first][xy.second].size() == 1) {
                runBall.push_back(map[xy.first][xy.second].front());
                curSum += map[xy.first][xy.second].front().m;
                map[xy.first][xy.second].pop_back();
                continue;
            }
            int mSum = 0, sSum = 0, sCount = 0, oddCount = 0, evenCount = 0;
            while(!map[xy.first][xy.second].empty()) {
                mSum += map[xy.first][xy.second].back().m;
                sSum += map[xy.first][xy.second].back().s; 
                if (map[xy.first][xy.second].back().d % 2 == 0) 
                    evenCount++;
                else
                    oddCount++;
                sCount++;
                map[xy.first][xy.second].pop_back();
            }
            if (mSum/5 == 0)
                continue;
            int dd = !(oddCount*evenCount) ? 0 : 1;
            for (int x = 0 ; x < 4 ; x++) {
                obj b = {xy.first, xy.second, mSum/5, sSum/sCount, dd + x*2};
                curSum += b.m;
                runBall.push_back(b);
                //디버그
                //map[xy.first][xy.second].push_back(b);
            }
        }
    }

    return curSum;
}

int main(void) {
    cin>>N>>M>>K;
    for (int i = 0 ; i < M ; i++) {
            int x,y,m,s,d;
            cin>>x>>y>>m>>s>>d;
            x--,y--;
            obj a = {x,y,m,s,d};
            runBall.push_back(a);
    }
    cout<<run();
            
    return 0;
}
