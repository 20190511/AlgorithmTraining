#include <iostream>
#include <queue>
using namespace std;
int root[200];
int n,m;
queue<int> visit;


int find(int x) {
    if (root[x] == x)
        return x;
    else
        return find(root[x]);
}

void unions(int a, int b) {
    int t1 = find(a);
    int t2 = find(b);
    
    if (t1 < t2) root[t2] = t1;
    else root[t1] = t2;
}

void printUnion() {
    cout<<"====="<<endl;
    for (int i = 0 ; i < n ; i++) {
        cout<<root[i]<<" ";
    }
    cout<<endl;
}

int main(void) 
{
    cin>>n;
    cin>>m;
    int val;
    for (int i = 0 ; i < n ; i++)
        root[i] = i;

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++)  {
            cin>>val;
            if (val && j < i) 
                unions(i, j);
        }
    }

    for (int i = 0 ; i < m ; i++) {
        cin>>val;
        visit.push(--val); 
    }  

    //printUnion();
    int curV = find(visit.front());
    while (!visit.empty()) {
        int nextVisit = visit.front();
        visit.pop();
        if (find(nextVisit) != curV) {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

    return 0;
}
