//0841 ~ 1029 :  1시간50분 최장시간.. 
//문제가 어려움.
/**
 * 
 * 그래프 구성부터 직접 짜야됨. -> 
 *      >> 이는 pair<int,int> map 형태로 짤 순 있음. 단 벡터따라가면서 논리적으로 짜야됨
 *         ex) 노드번호로 map을 구성하면 안됨 (중복되는 번호가 윷놀이에 존재하기 때문) == 각 노드를 가상의 번호를 주면서 해당 번호에 대한 score를 따로 주고 구성해야함
 *      
 *  실수1 : FINAL return 부분을 잘못 설정함
 *  실수2 : Map의 20점 scroe 노드번호는 5번인데 20으로 설정해서 이상한곳으로 간 실수
 *  실수3 : 2차 for문이 주어졌을 떄 for문을 잘못 설정한 실수
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define FINAL   32

struct obj {
    int n;
    int red;
    int blue;
};

int maxCount = 0;
int horse[4] = {0,0,0,0};
pair<int,int> map[33];
int inputs[10];
int scoreBoard[33] = {
    //10-5, 20:10, 30:15, 40:20
    //10 -> 13,16,19 = {21,22,23}    
    //20 -> 22,24 = {24,25}
    //30 -> 28,27,26 = {26,27,28}
    //25 == 29
    //25 -> 30,35 = {30,31}
    0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,
    13,16,19,22,24,28,27,26,25,30,35 
};

void makeMap() {
    for (int i = 0 ; i < 33 ; i++)
        map[i].first = -1;

    for (int i = 0 ; i < 20 ; i++) {
        map[i].second = i+1;
    }
    
    map[5].first = 21;
    map[10].first = 24;
    map[15].first = 26;

    for (int i = 21 ; i < 23 ; i++)
        map[i].second = i+1;
    for (int i = 24 ; i < 25 ; i++)
        map[i].second = i+1;
    for (int i = 26 ; i < 28 ; i++)
        map[i].second = i+1;

    map[23].second = map[25].second = map[28].second = 29;
    for (int i = 29 ; i < 31 ; i++)
        map[i].second = i+1;
    map[31].second = 20;
    map[20].second = FINAL;
}

int nextPos(int curPos, int count) {
    for (int i = 0 ; i < count ; i++) {
        curPos = (i==0 && map[curPos].first != -1) ? map[curPos].first : map[curPos].second;
        if (curPos == FINAL)
            return FINAL;
    }
    return curPos;
}


//backtracking
void simulator(int score, int idx) {
    bool endCheck = true;

    /*
    for (int i = 0 ; i < 4 ; i++)
        cout<<horse[i]<<"["<<scoreBoard[horse[i]]<<"] ";
    cout<<"("<<score<<"), idx="<<idx<<endl; 
    */
    

    for (int i = 0 ; i < 4 ; i++) {
        if (horse[i] != FINAL)
            endCheck = false;
    }

    if (idx >= 10 || endCheck) {
        maxCount = max(maxCount, score);
        return;
    }

    for (int i = 0 ; i < 4 ; i++) {
        int origin = horse[i], next= nextPos(horse[i], inputs[idx]);
        if (horse[i] >= FINAL)
            continue;

        int con = false;
        for (int j = 0 ; j < 4 ; j++) {
            if (i != j && next < FINAL && next == horse[j]) {
                con = true;
                continue;
            }
        } 
        if (con)
            continue;

        horse[i] = next;
        simulator(score + scoreBoard[horse[i]], idx+1);
        horse[i] = origin;
    }
}

int main(void)
{
    for (int i = 0 ; i < 10 ; i++)
        cin>>inputs[i];

    int horse[4] = {0,0,0,0};
    makeMap();
    simulator(0, 0);
    cout<<maxCount;
    return 0;
}
