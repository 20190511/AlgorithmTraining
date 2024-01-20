//1114~1148 (safer:화장실) 11:57~13:00
#include <iostream>
using namespace std;

int map[20][20];
int n, totalMan = 0, result = 0x7FFFFFFF;

void printMap(int map[20][20]) {
    cout<<"======="<<endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }

}

void simulator(int x, int y, int d1, int d2) {
    int i,j;
    int maps[20][20] = {0,};
    int manCount[5] = {0,};
    int maxVal = -1, minVal = 0x7FFFFFFF;

    for (i = 0 ; i < x+d1 ; i++) {
        for (j = 0 ; j <= y ; j++) {
            manCount[0] += map[i][j];
            maps[i][j] = 1;
        }

        if (i >= x) {
            for (j = y-(i-x) ; j <= y ; j++) {
                manCount[0] -= map[i][j];
                maps[i][j] = 5;
            }
        }
    }
    maxVal = max(maxVal, manCount[0]);
    minVal = min(minVal, manCount[0]);

    for (i = 0 ; i <= x+d2 ; i++) {
        for (j = y+1 ; j < n ; j++) {
            manCount[1] += map[i][j];
            maps[i][j] = 2;
        }
        if (i >= x) {
            for (j = y+1 ; j <= y+(i-x) ; j++) {
                manCount[1] -= map[i][j];
                maps[i][j] = 5;
            }
        }
    }
    maxVal = max(maxVal, manCount[1]);
    minVal = min(minVal, manCount[1]);

    for (i = x+d1 ; i < n ; i++) {
        for (j = 0 ; j < y-d1+d2 ; j++) {
            manCount[2] += map[i][j];
            maps[i][j] = 3;
        }

        for (j = y-d1+(i-x-d1) ; j < y-d1+d2 ; j++) {
            maps[i][j] = 5;
            manCount[2] -= map[i][j];
        }
    }
    maxVal = max(maxVal, manCount[2]);
    minVal = min(minVal, manCount[2]);

    for (i = x+d2+1 ; i < n ; i++) {
        for (j = y-d1+d2 ; j < n; j++) {
            manCount[3] += map[i][j];
            maps[i][j] = 4;
        }

        for (j = y-d1+d2 ; j <= y+d2-(i-x-d2) ; j++) {
            maps[i][j] = 5;
            manCount[3] -= map[i][j];
        }
    }
    maxVal = max(maxVal, manCount[3]);
    minVal = min(minVal, manCount[3]);


    manCount[4] = totalMan - manCount[0] - manCount[1] - manCount[2] - manCount[3];
    maxVal = max(maxVal, manCount[4]);
    minVal = min(minVal, manCount[4]);
    result = min(result, maxVal-minVal);
}

void run() {
    for (int x = 0 ; x < n ; x++) {
        for (int y = 0 ; y < n ; y++) {

            for (int d1 = 1 ; d1 < n ; d1++) {
                for (int d2 = 1 ; d2 < n ; d2++) {
                    if ((x+d1+d2 >= n ||  y+d2-d1 < 0) ||
                        (x+d1 >= n || y-d1 < 0) ||
                        (x+d2 >= n || y+d2 >= n)) 
                        continue;

                    simulator(x,y,d1,d2);
                }
            }
        }
    }
}

int main(void)
{
    cin>>n;    
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin>>map[i][j];
            totalMan += map[i][j];
        }
    }

    run();
    //simulator(2,2,1,1);
    //simulator(2,4,2,1);
    cout<<result;
    return 0;
}
