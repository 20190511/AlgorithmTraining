//1100 ~ 1325
/**
 * 내머리도 빙글뱅글 돌아감
 * 	1. 보는 면의 시계/반시계 방향의 결정의 어려움 --> 일단 위,앞,오른쪽 시계방향의 거울이라고 생각하고 아래,뒤,왼 방향을 고려 (반대방향으로 회전)
 *  2. 최대한 돌린면이 같은 방향으로 배치되도록 설계했지만 위에서 아래로 굴리는 방향이랑 왼->오 방향으로 굴리는게 인덱스가 뒤집히는게 무조건 있음
 * 		그렇기에 위<->아래 와 왼<->오 방향이 혼합되는 F,B,L,R 연산에서 윗면,아랫면 <--> 왼,앞,오,뒷 면이 인접했을 때 발생되는 문제점에 대해서 고려해야함
 * 			: 해당 방식에서는 위 --> 앞 --> 아래 --> 뒤 를 돌릴때 아래 <--> 뒤 방향이 반대라서 
 * 
*/
//해시맵 도입
#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
#define DEBUG false

char color[6] = {'w', 'y', 'r', 'o', 'g', 'b'};
int n;
deque<pair<char,bool>> pairQ;

//위, 아래, 앞, 뒤, 왼, 오
int map[6][9] = {
	{0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1},
	{2,2,2,2,2,2,2,2,2},
	{3,3,3,3,3,3,3,3,3},
	{4,4,4,4,4,4,4,4,4},
	{5,5,5,5,5,5,5,5,5}
};


//위 아래 앞 뒤 왼 오
int spaceVector [6][9] = {
	{0,1,2,3,4,5,6,7,8},
	{6,7,8,3,4,5,0,1,2},
	{0,1,2,3,4,5,6,7,8},
	{2,1,0,5,4,3,8,7,6},
	{2,1,0,5,4,3,8,7,6},
	{0,1,2,3,4,5,6,7,8},
};

//뒤에서부터
void printMap() {
	string dir[] = {
		"위", "아래", "앞", "뒤", "왼", "오"
	};
	cout<<"====="<<endl;
	for (int i = 0 ; i < 6 ; i++) {
		cout<<"---"<<dir[i]<<"---"<<endl;
		for (int j = 0 ; j < 9 ; j++) {
			cout<<color[map[i][spaceVector[i][j]]]<<" ";
			if (j % 3 == 2)
				cout<<endl;
		}
		cout<<endl;	
	}
}

int moveSpace[6][3] = {
	{0,1,2},
	{6,7,8},
	{0,3,6},
	{2,5,8},
	{8,5,2},
	{6,3,0}
};


//돌려야되는 각 면에 정보  A->B->C->D 순으로 D에 C가 저장됨 (시계기준)
pair<int,int> moveInfo[6][4] = {
	{{4,0}, {3,0}, {5,0}, {2,0}},
	{{2,1}, {5,1}, {3,1}, {4,1}},

	{{0,1}, {5,2}, {1,0}, {4,3}},
	{{4,2}, {1,1}, {5,3}, {0,0}},

	{{0,2}, {2,2}, {1,2}, {3,4}},
	{{3,5}, {1,3}, {2,3}, {0,3}}
};


void cpyMap(pair<int,int> a, pair<int,int> b) {

	for (int i = 0 ; i < 3 ; i++) {
		if ((a.first == 1 && b.first == 5) || (a.first == 5 && b.first == 1))
			map[b.first][moveSpace[b.second][2-i]] = map[a.first][moveSpace[a.second][i]];
		else	
			map[b.first][moveSpace[b.second][i]] = map[a.first][moveSpace[a.second][i]];
	}
}

void rotate90(int s, bool type) {	

	if (s == 1 || s == 3 || s == 4)
		type = !type;
	int tmp1[3][3], tmp2[3][3] = {0,};

	int idx = 0;
	for (int i = 0 ; i < 3 ; i++) {
		for (int j = 0 ; j < 3; j++)
			tmp1[i][j] = map[s][spaceVector[s][idx++]];
	}

	for (int i = 0 ; i < 3 ; i++) {
		for (int j = 0 ; j < 3 ; j++) {
			if (type)
				tmp2[i][2-j] = tmp1[j][i];
			else
				tmp2[j][i] = tmp1[i][2-j];
		}
	}

	idx = 0;	
	for (int i = 0 ; i < 3 ; i++) {
		for (int j = 0 ; j < 3; j++) {
			map[s][spaceVector[s][idx++]] = tmp2[i][j];
		}
	}
}

//dir : true (시계), false(반시계)
void rotateMap(int space, bool dir) {
	rotate90(space, dir);
	if (dir) {
		//3번꺼 저장
		int tmp[3];
		for (int i = 0 ; i < 3 ; i++)
			tmp[i] = map[moveInfo[space][3].first][moveSpace[moveInfo[space][3].second][i]];

		for (int i = 2 ; i >= 0 ; i--) {
			cpyMap(moveInfo[space][i], moveInfo[space][i+1]);
		}
		//3->0 :: 4(왼), 0(위) 방향은 양극단에 있어 rotate 에서 고려되지 않아서 Bug 발생
		for (int i = 0 ; i < 3 ; i++)
			map[moveInfo[space][0].first][moveSpace[moveInfo[space][0].second][i]] = space == 2 || space == 3 ? tmp[2-i] : tmp[i];
	}
	else  {
		//0번꺼 저장
		int tmp[3];
		for (int i = 0 ; i < 3 ; i++)
			tmp[i] = map[moveInfo[space][0].first][moveSpace[moveInfo[space][0].second][i]];
		for (int i = 1 ; i <= 3 ; i++) {
			cpyMap(moveInfo[space][i], moveInfo[space][i-1]);
		}
		//0->3
		for (int i = 0 ; i < 3 ; i++)
			map[moveInfo[space][3].first][moveSpace[moveInfo[space][3].second][i]] = space == 2 || space == 3 ? tmp[2-i] : tmp[i];
	}
}

void printFront() {
	for (int i = 0 ; i < 9 ; i++) {
		cout<<color[map[0][i]];
		if (i % 3 == 2)
			cout<<endl;
	}
}

void mapSetting() {
	for (int i = 0 ; i < 6 ; i++) 
		for (int j = 0 ; j < 9 ; j++)
			map[i][j] = i;
}
void run() {
	mapSetting();
	while(!pairQ.empty()) {
		char d = pairQ.front().first, dir = pairQ.front().second;
		int cvtDir = -1;
		pairQ.pop_front();
		
		if (d == 'U') cvtDir = 0;
		else if (d == 'D') cvtDir = 1;
		else if (d == 'F') cvtDir = 2;
		else if (d == 'B') cvtDir = 3;
		else if (d == 'L') cvtDir = 4;
		else if (d == 'R') cvtDir = 5;
		rotateMap(cvtDir, dir);
#if DEBUG
		string s = dir ? "+" : "-";
		cout<<d<<s<<endl;
		printMap();
#endif
	}
	printFront();
}

int main(void)
{
#if DEBUG
	freopen("test.txt", "r", stdin);
#endif

	cin>>n;
	while(n--) {
		int cnt;
		char space, dir;
		bool cdir;
		cin>>cnt;
		while(cnt--) {
			cin>>space>>dir;
			cdir = dir == '+' ? true : false;
			pairQ.push_back(pair<char,char>(space, cdir));
		}
		run();
	}
	return 0;
}
