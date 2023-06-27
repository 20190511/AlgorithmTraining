#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define ENTER while(fgetc(stdin) != '\n');
using namespace std;

struct pos{
    int x;
    int y;

    pos(int _x, int _y) : x(_x), y(_y) {};
    pos() : x(0), y(0) {};
};

pos moving[4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
char origin[10][10];
int n,m;


void print_data(char miro[][10], pos* ps) {
    cout<<"-------------"<<endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cout<<miro[i][j];
        }

        cout<<endl;
    }
    cout<<"red , blue"<<endl;
    cout<<ps[0].x<<","<<ps[0].y<<endl;
    cout<<ps[1].x<<","<<ps[1].y<<endl;
    cout<<"-------------"<<endl;
}

// 0:일반적, 1: 빨간 공이 빠짐, 2 : 파란 공이 빠짐
int tilt (char (*miro)[][10], pos* data, int mode) {
    int n_size = (mode % 2 == 0) ? n : m;
    int x = data->x; int y = data->y;
    char color = (*miro)[x][y];
    int dx = x; int dy = y; 
    for (int i = 0 ; i < n_size ; i++) {
        int tmpx = dx + moving[mode].x;
        int tmpy = dy + moving[mode].y;

        if (tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < m) {
            if ((*miro)[tmpx][tmpy] == '.') {
                dx = tmpx;
                dy = tmpy;
            }
            else if ((*miro)[tmpx][tmpy] == 'O') {
                (*miro)[x][y] = '.';
                data->x = -1;
                data->y = -1;
                if (color == 'B')
                    return 2; 
                else
                    return 1;
            }
        }
        else
            break;
    }
    
    (*miro)[x][y] = '.';
    (*miro)[dx][dy] = color;
    data->x = dx;
    data->y = dy;
    return 0;
}

int success = 11;
int count = 0;
// pos[0] : Red, pos[1]: Blue
void simul(char miro[10][10], pos* set, int depth)
{
    char cpy[10][10];
    pos back_pos[2];
    memcpy(back_pos, set, sizeof(pos) * 2);
    memcpy(cpy, miro, 100);
    if (depth >= 11)
        return;
    
    for (int i = 0 ; i < 4 ; i++) {
        int second = 3;
        int d1 = set[0].x * moving[i].x + set[0].y * moving[i].y;
        int d2 = set[1].x * moving[i].x + set[1].y * moving[i].y;
        second = d1 > d2 ? 1 : 0;
        
        int first = 1 - second;

        int check1 = tilt(&cpy, &set[first], i);
        int check2 = tilt(&cpy, &set[second], i);
        if (check1 == 2 || check2 == 2){ 
            memcpy(cpy, miro, 100);
            memcpy(set, back_pos, sizeof(pos) * 2); 
            continue;
        }
        else if (check1 == 1 || check2 == 1) {
            success = depth < success ? depth : success;        
            return;
        }

#ifdef DEBUG
        if ((depth == 1 && i == 3 && count == 0) ||
        (depth == 2 && i == 2 && count == 1) ||
        (depth == 3 && i == 1 && count == 2) ||
        (depth == 4 && i == 0 && count == 3) ||
        (depth == 5 && i == 3 && count == 4) ||
        (depth == 6 && i == 2 && count == 5)) {
            count++;
            cout<<"depth:"<<depth<<", mode: "<<i<<endl;
            if (depth == 5)  
                print_data(miro, set);
            print_data(cpy, set);
            cout<<"---------------------------------------------"<<endl;
        }
        if (depth == 5 && count == 4) {
            cout<<"origin : "<<i<<endl;
            print_data(miro,set);
            print_data(cpy, set);
        }
#endif
    
        simul(cpy, set, depth+1);
        memcpy(cpy, miro, 100);
        memcpy(set, back_pos, sizeof(pos) * 2);
    }
}

// 빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패
//#define DEBUG
int main(void)
{
    scanf("%d %d", &n, &m);
    ENTER;
    char line[15];
    pos data[2];
    for (int i = 0 ; i < n ; i++) {
        fgets(line, 15, stdin);
        for (int j = 0 ; j < m ; j++) {
            char var = line[j];
            origin[i][j] = var;
            if (var == 'R')
                data[0] = pos(i,j);
            if (var == 'B')
                data[1] = pos(i,j);
        }
    }

#ifdef DEBUG
    int var = tilt(&origin, &data[0], 0);
    var = tilt(&origin, &data[0], 1);
    if (var)
        cout<<"die!\n"<<endl;
    print_data(origin, data);
#endif

    simul(origin, data, 1);
    if (success == 11)
        cout<<-1;
    else
        cout<<success;
    exit(0);
}
