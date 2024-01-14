//1050 ~ 1130
#include <iostream>
#include <vector>
using namespace std;

int n, l, count = 0;
int map[100][100];
int rmap[100][100];

//가로축 검사
int checker(int map[100][100], int num, int debug) {
    int x = num, curNum = map[num][0];
    bool stair[100] = {false,};

    for (int y = 1 ; y < n ; y++) {
        int abs = curNum - map[x][y];
        if (abs == 0)
            continue;
        else if (abs * abs == 1) { //무조건 왼쪽방향으로 검사, 단 설치는 왼,오른쪽 검사 
            int lcount = 0, ty = y;
            if (curNum < map[x][y]) { //앞으로 설치
                for (lcount = 0, ty = y-1; lcount < l ; lcount++, ty--) {
                    //cout<<num<<", "<<debug<<"] "<<y<<","<<ty<<"<--debug"<<endl;
                    if (ty < 0 || ty >= n || stair[ty] || curNum != map[x][ty])
                        return 0;
                    stair[ty] = true; 
                }
            }
            else { //오른쪽으로 설치
                for (lcount = 0, ty = y; lcount < l ; lcount++, ty++) {
                    if (ty < 0 || ty >= n || stair[ty] || map[x][y] != map[x][ty])
                        return 0;
                    stair[ty] = true; 
                }
            }
            curNum = map[x][y];
        }
        else 
            return 0;
    }
    return 1;
}
void run() {
    for (int i = 0 ; i < n ; i++) { 
        count += checker(map, i, 0);
        count += checker(rmap, i, 1);
    }
}

int main(void)
{
    cin>>n>>l;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            int k;
            cin>>k;
            map[i][j] = rmap[j][n-i-1] = k;
        }
    }    

    run();
    cout<<count;
    return 0;

}
