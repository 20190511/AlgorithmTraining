/**
  많은 교훈을 준 문제 
  에러처리를 해줘야하는 부분
  0. 주의! : 빈공간은 되도록이면 에러처리하라. 안전하게 풀라..
  1. 한 라인을 합치는 과정에서 동시과정으로 보고 동시에 블록이 병합되면 안된다. checor[x][?][?] 체크
    ==> checkor 배열로 true false를 체크해줬다.
  2. 한 라인을 합치는 과정에서 2번 이상 연속으로 블록이 병합될 수 없다. checkor[x][i][k]  체크
  3. checkor는 빈 공간 이동 시 같이 옮겨주는 것이 편함

  
  4. 디버그 방법 
    -> 입출력 재지정을 통해 텍스트 파일로 변환한 후
    origin, v 를 결과를 값 찾기를 통해 역추적결과를 통해 파일을 분석해보기
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int maxValue = 0;

void printMap(vector<vector<int>> v) {
    cout<<endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

int maxMap(vector<vector<int>> v) {
    int maxV = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            maxV = max(maxV, v[i][j]);
        }
    }
    return maxV;
}

int c = false;
void printMap2(vector<vector<int>> origin, vector<vector<int>> v) {
    printMap(origin);
    cout<<endl<<" --> "<<endl;
    printMap(v);
}
void simulator(vector<vector<int>> v, int count) {
    //주의 연속합치기 오류 발생!!
    if (count > 5) {
        return;
    }

    vector<vector<int>> origin = v;
    int checkor[4][20][20] = {0,};
    //왼쪽 
    for (int i = 0 ; i < n ; i++) {
        for (int s = 1 ; s < n ; s++) {
            for (int k = s ; k > 0 ; k--) {
                if (v[i][k] == 0)
                    continue;
                if (v[i][k-1] == 0) {
                    v[i][k-1] = v[i][k];
                    v[i][k] = 0;
                    checkor[0][i][k-1] = checkor[0][i][k];
                    checkor[0][i][k] = 0;
                }
                else if (v[i][k] == v[i][k-1] && !checkor[0][i][k-1] && !checkor[0][i][k]) {
                    v[i][k] = 0;
                    v[i][k-1] *= 2;
                    checkor[0][i][k-1] = true;
                    maxValue = max(v[i][k-1], maxValue);
                }
                else
                    break;
            }
        }
    }

    simulator(v, count+1);
    v = origin;
    //위쪽
    for (int i = 0 ; i < n ; i++) {
        for (int s = 1 ; s < n ; s++) {
            for (int k = s ; k > 0 ; k--) {
                if (v[k][i] == 0)
                    continue;
                if (v[k-1][i] == 0) {
                    v[k-1][i] = v[k][i];
                    v[k][i] = 0;
                    checkor[1][k-1][i] = checkor[1][k][i];
                    checkor[1][k][i] = 0;
                }
                else if (v[k][i] == v[k-1][i] && !checkor[1][k-1][i] && !checkor[1][k][i]) {
                    v[k][i] = 0;
                    v[k-1][i] *= 2;
                    checkor[1][k-1][i] = true;
                    maxValue = max(v[k-1][i], maxValue);
                }
                else
                    break;
            }
        }
    }
    simulator(v, count+1);
    v = origin;

    //오른쪽
    for (int i = 0 ; i < n ; i++) {
        for (int s = n-2 ; s >= 0 ; s--) {
            for (int k = s ; k < n-1 ; k++) {
                if (v[i][k] == 0)
                    continue;
                if (v[i][k+1] == 0) {
                    v[i][k+1] = v[i][k];
                    v[i][k] = 0;
                    checkor[2][i][k+1] = checkor[2][i][k];
                    checkor[2][i][k] = 0;
                }
                else if (v[i][k] == v[i][k+1] && !checkor[2][i][k+1] && !checkor[2][i][k]) {
                    v[i][k] = 0;
                    v[i][k+1] *= 2;
                    checkor[2][i][k+1] = true;
                    maxValue = max(v[i][k+1], maxValue);
                }
                else
                    break;
            }
        }
    }
    
    simulator(v, count+1);
    v = origin;


    //아래
    for (int i = 0 ; i < n ; i++) {
        for (int s = n-2 ; s >= 0 ; s--) {
            for (int k = s ; k < n-1 ; k++) {
                if (v[k][i] == 0)
                    continue;
                if (v[k+1][i] == 0) {
                    v[k+1][i] = v[k][i];
                    v[k][i] = 0;
                    checkor[3][k+1][i] = checkor[3][k][i];
                    checkor[3][k][i] = 0;
                }
                else if (v[k][i] == v[k+1][i] && !checkor[3][k+1][i] && !checkor[3][k][i]) {
                    v[k][i] = 0;
                    v[k+1][i] *= 2;
                    checkor[3][k+1][i] = true;
                    maxValue = max(v[k+1][i], maxValue);
                }
                else
                    break;
            }
        }
    }

    simulator(v, count+1);
    v = origin;
}

//20::45
int main(void)
{
    vector<vector<int>> v;
    cin>>n;
    for (int i = 0 ; i < n ; i++) {
        v.push_back(vector<int>());
        for (int j = 0 ; j < n ; j++) { 
            int d;
            cin>>d; 
            maxValue = max(maxValue, d);
            v[i].push_back(d);
        }
    }


    simulator(v, 1);
    cout<<maxValue;
    return 0;
}
