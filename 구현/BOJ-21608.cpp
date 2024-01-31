//1017 ~ 1110 : 실수없었고 operator 에 대한 예제적용 성공.
#include <iostream>
#include <queue>
using namespace std;

struct calc {
    int x;
    int y;
    int like;
    int empty;
    const bool operator>(calc &b)const {
        if (like != b.like) 
            return like > b.like;
        else if ((like == b.like) && (empty != b.empty))
            return empty > b.empty;
        else if ((like == b.like) && (empty == b.empty) && (x != b.x))
            return x < b.x;
        else 
            return y < b.y;
    }
    const void operator=(calc &b) {
        x = b.x;
        y = b.y;
        like = b.like;
        empty = b.empty;
    }
};
int n, sums = 0;
int map[20][20];
int people[400][5], sort_people[401][4];

void printMap() {
    cout<<"========="<<endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++)
            cout<<map[i][j]<<" ";
        cout<<endl;
    }
}
void run() {
    pair<int,int> mv[4] = {
        {0,1}, {0,-1}, {1,0}, {-1,0}
    };

    for (int p = 0 ; p < n*n ; p++) {
        int m = people[p][0];
        sort_people[m][0] = people[p][1];
        sort_people[m][1] = people[p][2];
        sort_people[m][2] = people[p][3];
        sort_people[m][3] = people[p][4];

        calc optimal = {20, 20, 0, 0};
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (map[i][j])
                    continue;

                calc ptr = {i,j,0,0};
                for (int k = 0 ; k < 4 ; k++) {
                    int dx = i + mv[k].first, dy = j + mv[k].second;
                    if (dx < 0 || dx >= n || dy < 0 || dy >= n)
                        continue;
                    if (!map[dx][dy]) {
                        ptr.empty++;
                        continue;
                    } 
                    for (int l = 1 ; l <= 4 ; l++)
                        if (people[p][l] == map[dx][dy]) {
                            ptr.like++;
                            continue;
                        }
                            
                }
                if (optimal > ptr)
                    continue; 
                else 
                    optimal = ptr;
                
            }
        }
        map[optimal.x][optimal.y] = m;
    }
    
    int sc[5] = {0,1,10,100,1000};
    // 만족도 조사
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            int minSums = 0, man = map[i][j];
            for (int k = 0 ; k < 4 ; k++) {
                int dx = i + mv[k].first, dy = j + mv[k].second;
                if (dx < 0 || dx >= n || dy < 0 || dy >= n)
                    continue;
                for (int p = 0 ; p < 4 ; p++)
                    if (map[dx][dy] == sort_people[man][p]) {
                        minSums++;
                        break;    
                    }
            }
            sums += sc[minSums];
        }
    }
    cout<<sums;
}
int main(void)
{
    cin.tie(0)->sync_with_stdio(false);
    cin>>n; 
    for (int i = 0 ; i < n*n ; i++) {
        for (int j = 0 ; j < 5 ; j++) {
            cin>>people[i][j];
        }
    }
    run();
    return 0;
}
