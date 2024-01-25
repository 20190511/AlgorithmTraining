/**
 * 
 *  굉장히 많은 방식을 구현해보았으나 단순 BF BFS 방식으로는 절대로 해결할 수 없음.
 *  --> 새로운 알고리즘 방식 배움
 * 
 *  <벽을 부순 상태의 visited와 부시지않은 상태의 visited 룰 동시에 둔다>
 *      >> BFS를 하다가 1층에서 벽을 만나면 2층으로 넘겨서 푸는 방식인데 주의해야할 점이 있다.
 *          >> 처음에 BFS의 경로에서 재방문을 했을 때 값이 작은 값이면 새롭게 갱신하는 방식을 생각해보았지만 해당 문제에서는 필요가 없었다.
 *          >> (이유) ==> 해당 문제는 조건이 2개뿐이다. 벽을 1칸 부시느냐 , 안부시느냐 차이만 존재하므로 
*/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,m, map[1000][1000];
int visited[1000][1000][2] = {0,};

struct info {
    int first;
    int second;
    int floor;
};

void printMap(int map[1000][1000]) {
    cout<<"======"<<endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printVisited() {
    cout<<"======"<<endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cout<<visited[i][j][0]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------"<<endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cout<<visited[i][j][1]<<" ";
        }
        cout<<endl;
    }
}

//backtracking
pair<int,int> mv[4] = {
    {0,1}, {0,-1}, {1,0}, {-1,0}
};

void bfs() {
    queue<info> q;
    q.push((info){0,0,0});
    visited[q.front().first][q.front().second][0] = 1;
    
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second, f = q.front().floor;        
        q.pop();
        for (int i = 0 ; i < 4 ; i++) {
            int dx = x + mv[i].first, dy = y + mv[i].second;
            if (dx < 0 || dx >= n || dy < 0 || dy >= m || visited[dx][dy][f])
                continue;
            if (map[dx][dy] == 1) {
                if (f == 1)
                    continue;
                visited[dx][dy][1] = visited[x][y][0] + 1;
                q.push((info){dx,dy,1});
                continue;
            }
            
            visited[dx][dy][f] = visited[x][y][f] + 1;  
            q.push((info){dx,dy,f});

            if (dx == n-1 && dy == m-1)
                return;
        }
    }
}

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    cin.ignore();
    string s;
    for (int i = 0 ; i < n ; i++) {
        getline(cin, s);
        for (int j = 0 ; j < m ; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    if (n == 1 && m == 1) {
        cout<<1;
        return 0;
    }

    bfs();
    int minVal;
    int minVal1 = visited[n-1][m-1][0];
    int minVal2 = visited[n-1][m-1][1];
    if (minVal1 * minVal2 == 0) {
        if (minVal1)
            minVal = minVal1;
        else 
            minVal = minVal2;
    }
    else
        minVal = min(minVal1, minVal2);
    minVal = minVal == 0 ? -1 : minVal;
    cout<<minVal;
 
    return 0;
}
