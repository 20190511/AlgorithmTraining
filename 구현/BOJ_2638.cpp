/** 
  > 문제 자체는 매우 쉽다. + 근데 주의해야될 점이 있다.
  >> 치즈로 둘러싼 부분은 내부로 친다는 점인데 이는 문제의 가장자리는 안채워진다는 점을 통해 알 수 있다.
    --> 가장자리를 Queue에 넣고 BFS를 돌리면 된다. (기술적으로 x --> X , X --> x 로 바꾸어 BFS 수행할 것)

  2. 저렇게 모든 데이터가 공백을 두고 받는다면 cin>>x>>y;  cin>>data (이중 for문) 으로 받을 수도 있다.
      ++ ios::io_base::sync_with_stdio(false);
         cin.tie(NULL); 를 이용해서 받으면 입출력 속도를 높여줄 수 있다.
*/
  

#include <iostream>
#include <string>
#include <queue>
#define ENTER while(fgetc(stdin) != '\n');

struct pos {
    int x;
    int y;
};

pos dd[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
using namespace std;
char miro[100][100];
int n_cheese = 0;
int n,m;

// #define DEBUG
int main (void)
{
    queue<pair<int,int>> q;
    queue<pair<int,int>> jjam;
    scanf("%d %d", &n, &m);
    ENTER;
    char line[210];
    for (int i = 0 ; i < n ; i++) {
        fgets(line, 210, stdin);
        for (int j = 0 ; j < m ; j++) {
            char data = line[j*2];
            miro[i][j] = data;
            if (data == '1') {
                q.push(make_pair(i,j));
                n_cheese++;
            }
        }
    }

    int count;
    miro[0][0] = 'x';
    for (count = 0 ; !q.empty() ; count++) {

        //외부 BFS 수행
        queue<pair<int,int>> qu;
        qu.push(make_pair(0,0));
        qu.push(make_pair(n-1,0));
        qu.push(make_pair(0,m-1));
        qu.push(make_pair(n-1,m-1));
        if (miro[0][0] == 'x')
            miro[0][0] = 'X';
        else if (miro[0][0] == 'X') 
            miro[0][0] = 'x';
        
        while(!qu.empty()) {
            pair<int,int> ex = qu.front();
            qu.pop();
            int x = ex.first; int y = ex.second;
            for (int k = 0 ; k < 4 ; k++) {
                int dx = x + dd[k].x; int dy = y + dd[k].y;
                if (dx >= 0 && dx < n && dy >= 0 && dy < m)  { 
                    if (miro[dx][dy] == '0' || (miro[dx][dy] != miro[0][0] && miro[dx][dy] != '1')) {
                        miro[dx][dy] = miro[0][0];
                        qu.push(make_pair(dx,dy));
                    }
                }
            }
        }

        int down = n_cheese;
        for (int i = 0; i < down; i++) {
            pair<int, int> a = q.front();
            q.pop();
            int x = a.first; int y = a.second;
            int overlap = 0;
            for (int k = 0 ; k < 4 ; k++) {
                int dx = x + dd[k].x; int dy = y + dd[k].y;
                if (dx >= 0 && dx < n && dy >= 0 && dy < m)  { 
                    if (miro[dx][dy] == 'x' || miro[dx][dy] == 'X')
                        overlap++;
                }

                if (overlap >= 2) {
#ifdef DEBUG
                    cout<<"del :: "<<x<<" "<<y<<endl;
#endif
                    overlap = -1;
                    n_cheese--;
                    jjam.push(make_pair(x,y));
                    break; 
                }
            }

            if (overlap != -1)
                q.push(make_pair(x,y));
        }

        while(!jjam.empty()) {
            pair<int,int> tmp = jjam.front();
            jjam.pop();
            miro[tmp.first][tmp.second] = '0';
        }
#ifdef DEBUG
        cout<<"count : "<<count<<endl;
#endif
    }

    cout<<count;
    exit(0);

}
