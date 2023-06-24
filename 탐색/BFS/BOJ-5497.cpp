#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define SIZE 100
char range[SIZE][SIZE];
int visit[SIZE][SIZE] = {0,};
int n;

int move_x[] = {0,1,0,-1};
int move_y[] = {-1,0,1,0};

int main(void)
{
    cin>>n;
    while(fgetc(stdin) != '\n');
    char data[SIZE];
    for (int i = 0 ; i < n ; i++) {
        fgets(data, n+1, stdin);
        for (int j = 0 ; j < n ; j++)
            range[i][j] = data[j];
        while(fgetc(stdin) != '\n');
    }

    int normal_range = 0;    
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (visit[i][j] == 1)
                continue; 
            queue<pair<int,int>> q;
            pair<int,int> p(i,j);
            q.push(p);
            normal_range++;
            while (!q.empty()) {
                pair<int,int> p = q.front();
                q.pop();
                int x = p.first; int y = p.second;
                char color = range[x][y];
                visit[x][y] = 1;
                for (int k = 0 ; k < 4 ; k++) {
                    int dx = x + move_x[k];
                    int dy = y + move_y[k];
                    if (dx >= 0 && dx < n && dy >= 0 && dy < n) {
                        if (visit[dx][dy] != 1 && color == range[dx][dy]) {
                            visit[dx][dy] = 1;
                            pair<int,int> p2(dx,dy);
                            q.push(p2);
                        }
                    }
                }
            }
        }
    }

    int special_range = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (visit[i][j] == 0)
                continue; 
            queue<pair<int,int>> q;
            pair<int,int> p(i,j);
            q.push(p);
            special_range++;
            while (!q.empty()) {
                pair<int,int> p = q.front();
                q.pop();
                int x = p.first; int y = p.second;
                char color = range[x][y];
                visit[x][y] = 0;
                for (int k = 0 ; k < 4 ; k++) {
                    int dx = x + move_x[k];
                    int dy = y + move_y[k];
                    if (dx >= 0 && dx < n && dy >= 0 && dy < n) {
                        if (color != 'B') {
                            if (visit[dx][dy] != 0 && (range[dx][dy] == 'R' || range[dx][dy] == 'G')) {
                                visit[dx][dy] = 0;
                                pair<int,int> p2(dx,dy);
                                q.push(p2);
                            }
                        }
                        else if (visit[dx][dy] != 0 && color == range[dx][dy]) {
                            visit[dx][dy] = 0;
                            pair<int,int> p2(dx,dy);
                            q.push(p2);
                        }
                    }
                }
            }
        }
    }

    cout<<normal_range<<" "<<special_range<<endl;


    exit(0);
}
