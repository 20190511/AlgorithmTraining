//1033 ~ 1300 :2시간30분....
#include <iostream>
#include <vector>
using namespace std;
#define DEBUG false

int map[100][100], map2[100][100];
pair<int,int> mv[2] = {
    {1,0}, {0,1}
};
int n,k;
int maxH = 0, minW = 0, maxW = 0;

void printMap(int map[100][100]) {
    cout<<"====="<<endl;
    for (int i = 0 ; i < maxH+1 ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}


void rotate(int map2[100][100], int map[100][100], int w, int h) { 
    for (int i = 0 ; i < h; i++) {
        for (int j = 0 ; j < w ; j++) {
            map2[j][i] = map[i][w-j-1];
            map[i][w-j-1] = 0;
        }
    }
}
void firstRotate() {
    //h/2 : 높이, s/2 : 2층 가로길이
    int prevW;
    for (int h = 3, s = 2 ; s/2 + h/2 - 1 < maxW ; h++, s++) {
#if DEBUG
        //cout<<h/2<<","<<s/2<<","<<minW<<endl;
        //cout<<minW<<"~"<<minW + s/2 + h/2 - 1<<endl;
#endif
        rotate(map2, map, s/2, h/2);
        prevW = maxW;
        maxW -= s/2;
        maxH = (h+1)/2;
        for (int i = s/2 ; i < prevW ; i++) 
            map[0][i-s/2] = map[0][i];
        for (int i = maxW ; i < prevW ; i++)
            map[0][i] = 0;
        
        for (int i = 0 ; i < s/2 ; i++) {
            for (int j = 0 ; j < h/2 ; j++) {
                map[i+1][j] = map2[i][j];
                map2[i][j] = 0;
            }
        }
#if DEBUG
        printMap(map);
#endif
    } 
}

void appendFish() {
    int minF = 100000; //물고기 개수
    for (int i = 0 ; i < n ; i++) {
        minF = min(minF, map[0][i]);
    }
#if DEBUG
    cout<<"minFish = "<<minF;
#endif
    for (int i = 0 ; i < n ; i++) {
        if (minF == map[0][i])
            map[0][i]++;
    }
}

//map -> map2 -> map
int adjustFish() {
    for (int i = 0 ; i < maxH ; i++) {
        for (int j = 0 ; j < maxW ; j++) {
            if (!map[i][j])
                continue;
            map2[i][j] += map[i][j];
            for (int x = 0 ; x < 2 ; x++) {
                int dx = mv[x].first + i, dy = j + mv[x].second;
                if (dx < 0 || dx >= maxH || dy < 0 || dy >= maxW || !map[dx][dy])
                    continue;
                int diff = map[i][j] - map[dx][dy];
                if (diff < 0) {
                    diff = (-diff) / 5;
                    map2[i][j] += diff;
                    map2[dx][dy] -= diff;
                }
                else {
                    diff /= 5;
                    map2[dx][dy] += diff;
                    map2[i][j] -= diff;
                }
            }
        }
    }

#if DEBUG
    printMap(map2);
#endif
    //일렬놓기
    int minVal = 100000, maxVal = -1;
    for (int count = 0, j = 0 ; j < maxW ; j++) {
        for (int i = 0 ; i < maxH ; i++) {
            if (!map2[i][j])
                continue;
            else if (i > 0)
                map[i][j] = 0;
            map[0][count++] = map2[i][j];
            maxVal = max(maxVal, map2[i][j]);
            minVal = min(minVal, map2[i][j]);
            map2[i][j] = 0;
        }
    }
    maxW = n, maxH = 1;
#if DEBUG
    printMap(map);
    cout<<"max-min == "<<maxVal - minVal<<endl;
#endif
    return maxVal - minVal;
}

void secondRotate() {
    for (int count = 0, i = n/2-1 ; i >= 0 ; i--, count++) {
        map[1][count] = map[0][i];
    }
    for (int i = 0 ; i < n/2 ; i++) {
        map[0][i] = map[0][n/2 + i];
        map[0][n/2+i] = 0;
    }
    maxW = n/2;
    maxH = 2;

#if DEBUG
    cout<<"maxW = "<<maxW<<", maxH = "<<maxH<<endl;
    printMap(map);
#endif
    rotate(map2, map, maxW/2, 2);
#if DEBUG
    printMap(map);
    printMap(map2);
#endif
    rotate(map, map2, 2, maxW/2);
    for (int i = 0 ; i < 2 ; i++) {
        for (int j = 0 ; j < maxW/2 ; j++) {
            map[2+i][j] = map[i][j];
            map[i][j] = map[i][j+maxW/2];
            map[i][j+maxW/2] = 0;
        }
    }
    maxW /= 2;
    maxH *= 2;
#if DEBUG
    cout<<"maxW = "<<maxW<<", maxH = "<<maxH<<endl;
    printMap(map);
#endif
}

int run() {
    for (int i = 1 ; ; i++) {
        appendFish();  
        firstRotate();
        adjustFish(); 
        secondRotate();
        int retV = adjustFish();
        if (retV <= k) {
            return i;
        }
    }    
}

int main(void)  {
    int maxVal = 0, minVal = 100000;
    cin>>n>>k;
    for (int i = 0 ; i < n ; i++) {
        cin>>map[0][i];
        maxVal = max(maxVal, map[0][i]);
        minVal = min(minVal, map[0][i]);
    }
    maxH = 1, maxW = n;
#if DEBUG
    //printMap(map);
#endif

    if (maxVal - minVal <= k) {
        cout<<0;
        return 0;
    }
    cout<<run();
    return 0;
}
