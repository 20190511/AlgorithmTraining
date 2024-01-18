//1057 ~ 1230
/**
 * 
 * 새롭게 안 방법
 *  operator 연산자에 대해서 새롭게 정리
 *  struct 안에 bool operator< (const obj &a) const { return 원변수 < a.원변수}
 *      -> 함수 뒤에 const가 붙는 이유는 객체지향 언어에서 원객체를 이 함수를 통해 변경시키지 않는다는 의미.
 * 
 * 실수 요인
 *  : 보통 테스트케이스가 다 맞으면 경계선에서 오류가 난 것이다.
 *     -> 이번 실수요인은 데이터값이 1 ~ 100 까지 들어오는데 counter 배열을 counter[100] 으로 둔 실수로 인하여 처리가 안됨
 *  : 문제 데이터 범위를 좀 더 잘 볼 것
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct obj {
    int val;
    int count;
    
    obj(int a, int b) {
        val = a, count = b;
    }
    
    bool operator<(const obj& ob) const {
        if (count == ob.count)  
            return val > ob.val;
        else
            return count > ob.count;
    }
};

int map[100][100];
vector<priority_queue<obj>> rv;

int n=3,m=3; //행 열 크기
int r,c,k;
bool checker() {
    if (r < n && c < m && map[r][c] == k)
        return true;
    else 
        return false;
}

void rotate() {
    int map2[100][100] = {0,};
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            map2[y][x] = map[x][y];
        }
    }

    int tmp = n;
    n = m;
    m = tmp;
    memcpy(map,map2,sizeof(int)*100*100);
}

int run() {
    for (int i = 0; i < 101 ; i++) {
        if (checker())
            return i;
        int rmode = false;
        if (n < m)  {
            rotate();
            rmode = true;
        }

        if (n >= m) {
            int rowCount[100] = {0,} , maxRow = 0;
            
            for (int x = 0 ; x < n ; x++) {
                vector<int> save;
                int counter[101] = {0,};
                for (int y = 0 ; y < m ; y++) {
                    if (map[x][y] == 0)
                        continue;
                    if (!counter[map[x][y]])    
                        save.push_back(map[x][y]);
                    counter[map[x][y]]++;
                }

                priority_queue<obj> pq; 
                while(!save.empty()) {
                    pq.push(obj(save.back(), counter[save.back()]));
                    save.pop_back();
                }

                int xx = 0; 
                while(!pq.empty()) {
                    if (xx >= 100)
                        break;
                    obj o = pq.top();
                    pq.pop();
                    map[x][xx++] = o.val;
                    map[x][xx++] = o.count;
                }
                rowCount[x] = xx;
                maxRow = max(rowCount[x], maxRow);
            }

            m = maxRow;
            for (int x = 0 ; x < n ; x++) {
                int adder = maxRow - rowCount[x];
                for (int k = rowCount[x] ; k < maxRow ; k++)
                    map[x][k] = 0;
            }
        }
        if (rmode) 
            rotate(); 
    }

    return -1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>r>>c>>k;
    r--,c--;
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            cin>>map[i][j];
        }
    }

    cout<<run();    
    return 0;
}
