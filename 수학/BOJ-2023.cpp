#include <iostream>
#include <queue>
using namespace std;

queue<int> v = queue<int>({2,3,5,7});

int n, val = 1, val2 = 1;

bool isPrime(int val) {
    for (int i = 2 ; i*i <= val ; i++)  {
        if (!(val % i))
            return false;
    }
    return true;
}

void run() {
    while(!v.empty())  {
        int next = v.front() * 10;
        v.pop();
        if (n == 1) {
            cout<<next/10<<endl;
        }
        else if (!(next / val)) {
            for (int i = 0 ; i <= 9 ; i++) {
                int nnext = next + i;
                if (isPrime(nnext)) {
                    if (next / val2) 
                        cout<<nnext<<endl;
                    else
                        v.push(nnext);
                }
            }
        }
    }
}

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for (int i = 0 ; i < n ; i++, val*=10);
    val2 = val / 10;
    run();
    return 0; 
        
}
