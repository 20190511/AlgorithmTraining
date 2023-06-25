/**
  피드백 : 
  1. Cpp 에서 구조체는 typedef 를 쓰지 않아도 이름으로 바로 접근이 가능
  1-2. 구조체 생성자를 설정할 경우, 기본생성자 default 생성자를 꼭 만들어줄 것 (객체배열에서 유용함)
  2. 해당 문제처럼 함수 내에서 배열의 값들을 변경하고 싶은 경우 Call by Reference 를 해줘야함
      ex) 함수 formal paramter 에서 char (*arr)[8][8] a --> 사용 시 (*arr)[4][4] 이런식으로 접근
      ex) 함수 actual Paramter 에서 넘겨줄 때 &arr 로 넘겨주면 됨
  3. ★ 되도록이면 "U", "D" 이런 정보들은 한 배열로 저장할 것. 그래야 유리함.
  4. 문자열 입력 처리할 때, fgets를 쓰는 경우 범위보다 크게 잡아서 \n까지 받기 
  4-2. scanf 사용 시 \n문자가 버퍼에 남아있으므로 위의 ENTER 처럼 입력부 설정해주기.
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#define ENTER while(fgetc(stdin) != '\n');

struct pos {
    int x;
    int y;
    
    pos(int _x, int _y) : x(_x), y(_y) {};
    pos() : x(0), y(0) {};
};

char arr[8][8];
int n,m;
int n_cctv = 0;
int result_value = 64;

string ps[5][4] = {
    {"U", "D", "L", "R"},
    {"LR", "UD", "RL", "DU"},
    {"UR", "RD", "DL", "LU"},
    {"LUR", "URD", "RDL", "DLU"},
    {"URDL", "URDL", "URDL","URDL"}
};

pos go (char ps)
{
    switch(ps) {
        case 'U':
            return pos(-1,0);
            break;
        case 'R':
            return pos(0,1);
            break;
        case 'D':
            return pos(1,0);
            break;
        case 'L':
            return pos(0,-1);
            break;
    }
}


//일자확인 -> 데이터 채워지면 #
void make_arr (char (*arr)[8][8], pos cur, char num, int idx){
    int strsize = ps[num - '0'][idx].length();
    int big = n > m ? n : m;
    for (int i = 0; i < strsize; i++)
    {
        pos d = go(ps[num - '0'][idx][i]);
        int x,y;
        for (int k = 1 ; k < big ; k++) {
            x = cur.x + d.x * k;
            y = cur.y + d.y * k;
            if (x >= 0 && x < n && y >= 0 && y < m) {
                if ((*arr)[x][y] == '6')
                    break;
                else if ((*arr)[x][y] == '0') {
                    (*arr)[x][y] = '#';
                }
            }
        }
    }
}

void result(char arr[8][8]) {
    int count = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (arr[i][j] == '0')
                count++;
        }
    }

    if (count < result_value)
        result_value = count;

}


void solve(char arr[8][8], pos* cctv, int depth)
{
    if (depth > n_cctv)
        return;

    char arr2[8][8];
    memcpy(arr2, arr, 64);

    for (int i = 0 ; i < 4 ; i++) {
        int x = cctv[depth-1].x; int y = cctv[depth-1].y;
        make_arr(&arr2, cctv[depth-1], arr[x][y]-1, i);
        solve(arr2, cctv, depth+1);
        if (depth == n_cctv)
        {
            result(arr2);
        }
        memcpy(arr2, arr, 64);
    }
}

int main(void)
{
    scanf("%d %d",&n, &m);
    ENTER
    pos cctv[8];
    char line[30];
    for (int i = 0 ; i < n ; i++) {
        fgets(line, 20, stdin);
        for (int j = 0 ; j < m ; j++) {
            arr[i][j] = line[j*2];

            if (arr[i][j] != '0' && arr[i][j] != '6') {
                cctv[n_cctv++] = pos(i,j);
            }
        }
    }

    if (n_cctv == 0)
        result(arr);
    else
        solve(arr, cctv, 1);
    cout<<result_value;
    exit(0);
}
