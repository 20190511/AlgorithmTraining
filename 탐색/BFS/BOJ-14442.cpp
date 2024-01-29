#include <iostream>
#include <queue>
using namespace std;

struct obj{
    int x;
    int y;
    int floor;
};

int visited[11][1000][1000];
int map[1000][1000];
int n,m,k;
queue<obj> q;
pair<int,int> mv[4] = {
    {0,1}, {0,-1}, {1,0}, {-1,0}
};


void printMap() {
    cout<<"=========="<<endl;
    for (int x = 0 ; x <= k ; x++) {
        cout<<"-------"<<endl;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                cout<<visited[x][i][j]<<" ";
            }
            cout<<endl;
        }
    }
}


int minVal() {    
    int val = 0x7FFFFFFF;
    for (int i = 0 ; i <= k ; i++) {
        visited[i][n-1][m-1] = !visited[i][n-1][m-1] ? 0x7FFFFFFF : visited[i][n-1][m-1];
        val = min(val, visited[i][n-1][m-1]);
    }
    return val == 0x7FFFFFFF ? -1 : val;
}

void run() { 
    while(!q.empty()) {
        int x = q.front().x, y = q.front().y, f = q.front().floor;
        q.pop();
        for (int i = 0 ; i < 4 ; i++) {
            int dx = x + mv[i].first, dy = y + mv[i].second;
            if (dx < 0 || dx >= n || dy < 0 || dy >= m || (map[dx][dy] && f >= k) || visited[f][dx][dy])
                continue;

            if (map[dx][dy]) {
                if (visited[f+1][dx][dy])
                    continue;
                visited[f+1][dx][dy] = visited[f][x][y] + 1;
                q.push((obj){dx,dy,f+1});
                continue;
            }

            visited[f][dx][dy] = visited[f][x][y] + 1;
            q.push((obj){dx,dy,f});
        }
    }
}

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    cin.ignore();
    string s;
    for (int i = 0 ; i < n ; i++) {
        getline(cin, s);
        for (int j = 0 ; j < m ; j++)
            map[i][j] = s[j] - '0';
    }

    visited[0][0][0] = 1;
    q.push((obj){0,0,0});
    run(); 
    cout<<minVal();
    return 0;
}
