#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef vector<vector<pair<int, bool>>> map;
int n, maxVal = 0;

map rotate90(map &v) {
    map nm = v;
    for (int i = 0 ; i < n ; i++) 
        for (int j = 0 ; j < n ; j++) {
            nm[j][n-1-i] = v[i][j];
            nm[j][n-1-i].second = true;
        }
    return nm;
}

#define MAXCOUNT    5
void simulator(map v, int count) {    
    if (count > MAXCOUNT)
        return;
    map origin = v;
    for (int i = 0 ; i < 4 ; i++) {
        origin = rotate90(origin);
        map cmap = origin;
        for (int x = 0; x < n; x++) {
            for (int a = 1; a < n; a++) {
                for (int b = a; b > 0; b--) {
                    if (cmap[x][b].first == 0)
                        continue;
                    else if (cmap[x][b-1].first == 0) {
                        cmap[x][b-1] = cmap[x][b];
                        cmap[x][b] = pair<int,bool>(0,true);
                    }
                    else if (cmap[x][b].first == cmap[x][b-1].first && cmap[x][b].second && cmap[x][b-1].second) {
                        cmap[x][b] = pair<int,bool>(0,true);
                        cmap[x][b-1].first *= 2;
                        cmap[x][b-1].second = false;
                        maxVal = max(maxVal, cmap[x][b-1].first);
                    }
                    else
                        break;
                }
            }
        }
        simulator(cmap, count+1); 
    }
}

int main(void)
{
    cin>>n;
    map v;
    for (int i = 0 ; i < n ; i++) {
        v.push_back(vector<pair<int,bool>>());
        for (int j = 0 ; j < n ; j++) {
            int s;
            cin>>s;
            maxVal = max(maxVal, s);
            v[i].push_back(pair<int,bool>(s, true));
        } 
    }

    simulator(v, 1);
    cout<<maxVal;
    return 0;    
}
