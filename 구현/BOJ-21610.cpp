//1144 ~ 1227 : 실수없었음 빠름
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cloudObj{
    int x;
    int y;
    int value;
};

int n, map[50][50];
pair<int,int> mv[8] = {
    {0,-1}, {-1,-1}, {-1,0}, {-1,1}, 
    {0,1}, {1,1}, {1,0}, {1,-1}
};
queue<pair<int,int>> v;
void printMap() {
    cout<<"======"<<endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++)
            cout<<map[i][j]<<" ";
        cout<<endl;
    }
}

int run() {
    int curCount = 0;
    vector<pair<int,int>> cloud;
    queue<cloudObj> ccloud;
    cloud.push_back(pair<int,int> (n-1,0));
    cloud.push_back(pair<int,int> (n-1,1));
    cloud.push_back(pair<int,int> (n-2,0));
    cloud.push_back(pair<int,int> (n-2,1));
    while(!v.empty()) {
        curCount = 0;
        int d = v.front().first, s = v.front().second;
        v.pop();
        bool prevCloud[50][50] = {0,};
        while(!cloud.empty()) {
            int cx = cloud.back().first + s*mv[d].first, cy = cloud.back().second + s*mv[d].second;
            cloud.pop_back();
            cx = (cx+n*s)%n, cy = (cy+n*s)%n;
            prevCloud[cx][cy] = true;
            map[cx][cy]++; 
            ccloud.push((cloudObj){cx,cy,0});
        }
        // printMap();  // 1차 성공

        //물복사
        for (int sz = 0 ; sz < ccloud.size() ; sz++) {
            int cx = ccloud.front().x, cy = ccloud.front().y, water = 0;
            ccloud.pop();

            for (int i = 1 ; i < 8 ; i+=2) {
                int dx = cx + mv[i].first, dy = cy + mv[i].second;
                if (dx < 0 || dx >= n || dy < 0 || dy >= n)
                    continue;
                if (map[dx][dy])
                    water++;
                
            }
            ccloud.push((cloudObj){cx,cy,water});
        }

        while(!ccloud.empty()) {
            map[ccloud.front().x][ccloud.front().y] += ccloud.front().value;
            ccloud.pop();
        }
        
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                curCount += map[i][j];
                if (prevCloud[i][j])
                    continue;
                else if (map[i][j] >= 2) {
                    curCount -=2;
                    map[i][j] -= 2;
                    cloud.push_back(pair<int,int>(i,j)); 
                }
            }
        }
    }
    return curCount;
}

int main(void)
{
    int m;
    cin>>n>>m;
    for (int i = 0 ; i < n ; i++) 
        for (int j = 0 ; j < n ; j++)
            cin>>map[i][j];
    vector<int> q; 
    for (int i = 0 ; i < m ; i++) {
        int d,s;
        cin>>d>>s;
        v.push(pair<int,int>(--d, s));
    }

    cout<<run();
    return 0;
}
