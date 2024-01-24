//09:10 ~ 10:22 (70분)
//실수없었음.
// 진한블록 처리 -> 연한블록 처리 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct inputs
{
    int shape;
    int x;
    int y;    
};

bool green[6][4] = {0,};
bool blue[4][6] = {0,};
int t, score = 0;
queue<inputs> q;
void printMap() {
    cout<<"========"<<endl;
    cout<<"----Green----"<<endl;
    for (int i = 0 ; i < 6 ; i++) {
        for (int j = 0 ; j < 4 ; j++)
            cout<<green[i][j]<<" ";
        cout<<endl;
    }

    cout<<"----Blue----"<<endl;
    for (int i = 0 ; i < 4 ; i++) {
        for (int j = 0 ; j < 6 ; j++)
            cout<<blue[i][j]<<" ";
        cout<<endl;
    }
}

int counter() {
    int counts = 0;
    for (int i = 0 ; i < 6 ; i++) 
        for (int j = 0 ; j < 4 ; j++)
            if(green[i][j])
                counts++;
    for (int i = 0 ; i < 4 ; i++) 
        for (int j = 0 ; j < 6 ; j++)
            if(blue[i][j])
                counts++;
    return counts;
}
void move(inputs txy) {
    int shape = txy.shape, x1 = txy.x, y1 = txy.y;
    int x2= shape == 3 ? x1+1 : x1, y2= shape == 2 ? y1+1 : y1; 

    //Blue
    for (int y = 0 ; y < 6 ; y++) {
        int sy = y2 > y1 ? y+1 : y;
        if (sy >= 6 || blue[x1][y] || blue[x2][sy]) {
            blue[x1][y-1] = blue[x2][sy-1] = true;
            break;
        }
        else if (y == 5)
            blue[x1][y] = blue[x2][sy] = true;
    }
    
    //Green
    for (int x = 0 ; x < 6 ; x++) {
        int sx = x2 > x1 ? x+1 : x;
        if (sx >= 6 || green[x][y1] || green[sx][y2]) {
            green[x-1][y1] = green[sx-1][y2] = true;
            break;
        }
        else if (x == 5)
            green[x][y1] = green[sx][y2] = true;
    }
}

void delBlock() {
    //blue
    for (int i = 2 ; i < 6 ; i++) { 
        if (blue[0][i] && blue[1][i] && blue[2][i] && blue[3][i]) {
            score++;
            for (int m = 0 ; m < 4 ; m++) {
                for (int j = i ; j >= 1 ; j--) {
                    blue[m][j] = blue[m][j-1];
                }
                blue[m][0] = false;
            }
        }
    }
    int dels = 0;
    for (int i = 0 ; i < 2 ; i++) {
        if (blue[0][i] || blue[1][i] || blue[2][i] || blue[3][i]) {
            dels++;
        }
    }
    while(dels--) {
        for (int m = 0 ; m < 4 ; m++) {
            for (int j = 5 ; j >= 1 ; j--) {
                blue[m][j] = blue[m][j-1];
            }
            blue[m][0] = false;
        }
    }
     
    
    //green
    for (int i = 2 ; i < 6 ; i++) { 
        if (green[i][0] && green[i][1] && green[i][2] && green[i][3]) {
            score++;
            for (int m = 0 ; m < 4 ; m++) {
                for (int j = i ; j >= 1 ; j--) {
                    green[j][m] = green[j-1][m];
                }
                green[0][m] = false;
            }
        }
    }

    dels = 0;
    for (int i = 0 ; i < 2 ; i++) {
        if (green[i][0] || green[i][1] || green[i][2] || green[i][3]) {
            dels++;
        }
    }
    while (dels--) {
        for (int m = 0; m < 4; m++) {
            for (int j = 5; j >= 1; j--) {
                green[j][m] = green[j - 1][m];
            }
            green[0][m] = false;
        }
    }
}

void run() {
    while(!q.empty()) {
        move(q.front());
        delBlock();

        //debug;
        q.pop();
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>t;
    for (int i = 0 ; i < t ; i++) {
        int s,x,y;
        cin>>s>>x>>y;
        inputs txy = {s,x,y};
        q.push(txy);
    }

    run(); 
    cout<<score<<"\n"<<counter()<<endl;
    return 0;
}

