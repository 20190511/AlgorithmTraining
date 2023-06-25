/**
  문제자체는 무난한데.. 시간이 0.3초로 매우 타이트하다.
  해당 시간을 보고 힌트를 얻었어야한다.
  1. 입력받을 때 같은 위치에 입력이 안들어온다는 점 + 시간에 따라 모든 나무가 1씩 자란다는 점을 통해
      배열 정렬구조가 바뀌지 않음을 파악하고 우선순위큐 priority_queue 대신 vector를 사용했어야했다.
  2. Vector가 deque보다 빠르다는 점 주의 
  3. ios::sync_base_stdio(false) --> cin.tie(NULL) 을 잘 사용할 것
**/

#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#define ENTER while(fgetc(stdin) != '\n');
using namespace std;

struct {
    int feed;
    int death;
    vector<int> q; 
}element[10][10];

struct {
    int x;
    int y;
}moving[] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

int base_feed[10][10];
int total_tree = 0;

int n,m,k;



void print_data(){
    cout<<"-----------------------------"<<endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cout<<element[i][j].feed<<" ";
        }
        cout<<endl;
    }

    cout<<"tree : info"<<endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (!element[i][j].q.empty())
                cout<<"tree ["<<i+1<<"],["<<j+1<<"] tree age is = ";
            for (int k = 0 ; k < element[i][j].q.size() ; k++) {
                cout << element[i][j].q[k]<<" ";
                if (k == element[i][j].q.size()-1)
                    cout<<endl;
            }
        }
    }
    cout<<"-----------------------------"<<endl;
}

void spring()
{
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            element[i][j].death = 0;
            int k;
            int del = 0;
            for (k = element[i][j].q.size()-1 ; k >= 0 ; k--)
            {
                if (element[i][j].feed >= element[i][j].q[k]) {
                    element[i][j].feed -= element[i][j].q[k]; 
                    element[i][j].q[k]++;
                }
                else {
                    del = 1;
                    break;
                }
            }

            if (!element[i][j].q.empty() && del) {
                for (int s = 0 ; s <= k ; s++) {
                    total_tree--;
                    element[i][j].death += element[i][j].q[0] / 2;
                    element[i][j].q.erase(element[i][j].q.begin());
                }
            }
        }
    }
}

void summer()
{
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            element[i][j].feed += element[i][j].death;
            element[i][j].death = 0;
        }
    }
}

void fall()
{
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            element[i][j].death = 0;
            for (int k = 0 ; k < element[i][j].q.size(); k++)
            {
                if (element[i][j].q[k] % 5 == 0) {
                    for (int f = 0 ; f < 8 ; f++) {
                        int dx = moving[f].x; int dy = moving[f].y;
                        int x = dx + i;
                        int y = dy + j;
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            element[x][y].q.push_back(1);
                            total_tree++;
                        }
                    } 
                } 
            }
            element[i][j].feed += base_feed[i][j];
        }
    }
}

void process()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0 ; i < k ; i++) {
        spring();
        summer();
        fall();
        // winter();
        //print_data();
    } 
    cout<<total_tree<<endl;
}

int main(void)
{
    int x,y,age;
    scanf("%d %d %d", &n, &m, &k);
    ENTER

    char tmp_data[50];    
    for (int i = 0 ; i < n ; i++) {
        fgets(tmp_data, 50, stdin);
        char* tkn = strtok(tmp_data, " ");
        for (int j = 0; tkn != NULL ; j++) {
            base_feed[i][j] = atoi(tkn);
            element[i][j].feed = 5;
            tkn = strtok(NULL, " ");
        }
    }

    for (int i = 0 ; i < m ; i++) {
        fgets(tmp_data, 50, stdin);
        x = atoi(strtok(tmp_data, " ")) - 1;
        y = atoi(strtok(NULL, " ")) - 1;
        age = atoi(strtok(NULL, " "));
        element[x][y].q.push_back(age);
        total_tree++;
    }

    process();
    exit(0);

}
