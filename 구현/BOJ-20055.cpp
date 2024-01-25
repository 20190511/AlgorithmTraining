/**
 * 1144 ~ 1258
 *  :너무 큰 실수를 했다. robots[100]으로 둬버렸다.
 * 
 * 실제 풀이시간은 10분정도밖에 걸리지 않았는데......
*/
#include <iostream>
using namespace std;
int belt[200];
bool robots[200];
int n,m,k;
void printBelt(int k) {
    cout<<"+======+"<<endl;
    for (int i = 0 ; i < 2*n ; i++, k++) {
        k %= 2*n;
        cout<<belt[k];
        if (i < n && robots[k])
            cout<<"(O) ";
        else
            cout<<"(X) ";
        
        if (i == n-1)
            cout<<endl;
    }
    cout<<endl;
}

int run() {
    int process = 1, broken = 0, end, rotate = n*2;
    for (int i = rotate-1 ; broken < k ; process++, i--) {
        i = i < 0 ? i + rotate : i;
        end = (i + n - 1) % rotate;
        robots[end] = false;
        for (int count = 2, j = end-1 ; count < n ; j--, count++) {
            j = j < 0 ? j + rotate : j;
            if (robots[j] && !robots[(j+1)%rotate] && belt[(j+1)%rotate]) {
                robots[j] = false;
                robots[(j+1)%rotate] = true;
                belt[(j+1)%rotate]--;
                if (belt[(j+1)%rotate] == 0)
                    broken++;
            }
        }
        robots[end] = false;

        if (belt[i])  {
            robots[i] = true;
            belt[i]--;
            if (belt[i] == 0)
                broken++;
        }
        
        //cout<<process<<endl; 
        
    } 
    return process-1;
}

int main(void)
{
    cin>>n>>k;
    for (int i = 0 ; i < 2*n ; i++) {
        cin>>belt[i]; 
    }
    cout<<run();
}
