#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define MAX_NUM     101
#define INF         300
int n,m;
vector <string> graph;
int vec[MAX_NUM][MAX_NUM];
int main(void)
{
    pair<int,int> move[4] = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };

    for (int i = 0 ; i < MAX_NUM ; i++)
        for (int j = 0 ; j <MAX_NUM ; j++)
            vec[i][j] = INF;

    cin >> n >> m;
    getchar();
    for (int i = 0; i < m; i++)
    {
        string line;
        getline(cin, line);
        graph.push_back(line);
    }

    priority_queue<pair<int,int>> q;

    q.push(pair<int,int>(0,0));
    vec[0][0] = 0;
    while (!q.empty())
    {
        pair<int,int> p = q.top();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = p.first + move[i].first, yy = p.second + move[i].second;
            if (xx < 0 || xx >= m || yy < 0 || yy >= n) 
                continue;
            if (vec[xx][yy] > vec[p.first][p.second] + graph[xx][yy] - '0') {
                vec[xx][yy] = vec[p.first][p.second] + graph[xx][yy] - '0';
                q.push(pair<int,int>(xx,yy));
            }
        }
    }

    cout<<vec[m-1][n-1];
    exit(0);
}
