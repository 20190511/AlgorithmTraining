#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n,e;
int graph[801][801] = {0};

/**
 * Infinity 값을 무지성으로 정하면 안된다.
 * 노드 개수가 20,000 개 이기 때문에 간선의 최댓값은
 * 최소한 19,997 * 1000 = 19997000 이 되어야하고
 * long 자료형으로 표현하는게 좋다
*/
typedef long long ll;
#define INF     20000000LL

ll dijkstra(int start, int eo) {
    ll vec[801];
    fill(&vec[0], &vec[801], INF);

    priority_queue<int> q;
    int val;
    q.push(start);
    vec[start] = 0;
    while (!q.empty()) {
        val = q.top();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (graph[val][i] && (vec[i] > graph[val][i] + vec[val])) {
                vec[i] = vec[val] + graph[val][i];
                q.push(i);
            }
        }
    }

    return vec[eo];
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >>n>>e;  
    for (int i = 0 ; i < e ; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b] = graph[b][a] = c;
    }
    int u,v;
    cin>>u>>v;

    ll sumA = INF, sumB = INF;
    ll uv = INF;
    //1->u->v->N
    sumA = dijkstra(1, u);
    uv = dijkstra(u, v);
    sumA += uv;
    sumA += dijkstra(v, n);

    //1->v->u->N
    sumB = dijkstra(1, v);
    sumB += uv;
    sumB += dijkstra(u, n);

    if (sumA >= INF && sumB >= INF) {
        cout<<-1;
        exit(0);
    }

    cout<<min(sumA, sumB);
    exit(0);
}
