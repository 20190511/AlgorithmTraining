#include <iostream>
#include <string>
#include <queue>
using namespace std;

int obj[4][8] = {0};
int ptr[4] = {0,0,0,0};
queue<pair<int,int>> v;
int count;

void printMap() {
    for(int i = 0 ; i < 4 ; i++) {
        for (int j = 0 ; j < 8 ; j++) 
            cout<<obj[i][j]<<" ";
        cout<<endl;
    }
}


//회전하면  -> dfs
void rotate(int num, int dir, int depth, int lr) {
    if (num < 0 || num >= 4) 
        return;
    
    dir = depth == 0 ? dir : -dir;

    int left = num-1, right = num+1, rotCheck = false;
    //오른쪽 방향
    if (right < 4 && lr >= 0) {
        if (obj[num][(2+ptr[num]) % 8] != obj[right][(6+ptr[right]) % 8])  {
            rotate(right, dir, depth+1, 1);
            rotCheck = true;
        }
    }

    // 왼쪽 방향
    if (left >= 0 && lr <= 0) {
        if (obj[num][(6+ptr[num]) % 8] != obj[left][(2+ptr[left]) % 8]) {
            rotate(left, dir, depth+1, -1);
            rotCheck = true;
        }
    }

    //회전
    if (dir == 1)  {
        ptr[num] = (ptr[num] + 7) % 8;
    }
    else {
        ptr[num] = (ptr[num] + 1) % 8;
    }
}

void simulator() {
    for (int x = 0 ; x < count ; x++) {
        pair<int,int> e = v.front();
        v.pop();
        rotate(e.first-1, e.second, 0, 0);
        
    }

    int sums = 0 ;
    for (int i = 0 ; i < 4 ; i++) {
        if (obj[i][ptr[i]]) 
            sums += (1 << i);
    }
    cout<<sums;
}
int main(void)
{
    for (int i = 0 ; i < 4 ; i++) {
        string s;
        getline(cin, s);
        for (int j = 0 ; j < 8 ; j++) {
            obj[i][j] = s[j] - '0';
        }
    }

    cin>>count;
    for (int i = 0 ; i < count ; i++) {
        int a,b;
        cin>>a>>b;
        v.push(pair<int,int>(a,b));
    }

    simulator();
     
}
