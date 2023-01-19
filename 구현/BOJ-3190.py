"""
백준 3190 : 뱀 문제
https://www.acmicpc.net/problem/3190
문제
 'Dummy' 라는 도스게임이 있다. 이 게임에는 뱀이 나와서 기어다니는데, 사과를 먹으면 뱀 길이가 늘어난다. 
 뱀이 이리저리 기어다니다가 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.
게임은 NxN 정사각 보드위에서 진행되고, 몇몇 칸에는 사과가 놓여져 있다. 보드의 상하좌우 끝에 벽이 있다. 
게임이 시작할때 뱀은 맨위 맨좌측에 위치하고 뱀의 길이는 1 이다. 뱀은 처음에 오른쪽을 향한다.
뱀은 매 초마다 이동을 하는데 다음과 같은 규칙을 따른다.
먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 
즉, 몸길이는 변하지 않는다.
사과의 위치와 뱀의 이동경로가 주어질 때 이 게임이 몇 초에 끝나는지 계산하라.
입력
첫째 줄에 보드의 크기 N이 주어진다. (2 ≤ N ≤ 100) 다음 줄에 사과의 개수 K가 주어진다. (0 ≤ K ≤ 100)
다음 K개의 줄에는 사과의 위치가 주어지는데, 첫 번째 정수는 행, 두 번째 정수는 열 위치를 의미한다. 
사과의 위치는 모두 다르며, 맨 위 맨 좌측 (1행 1열) 에는 사과가 없다.
다음 줄에는 뱀의 방향 변환 횟수 L 이 주어진다. (1 ≤ L ≤ 100)
다음 L개의 줄에는 뱀의 방향 변환 정보가 주어지는데,  정수 X와 문자 C로 이루어져 있으며. 
게임 시작 시간으로부터 X초가 끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다는 뜻이다. 
X는 10,000 이하의 양의 정수이며, 방향 전환 정보는 X가 증가하는 순으로 주어진다.
출력
첫째 줄에 게임이 몇 초에 끝나는지 출력한다.
예제 입력 1 
6
3
3 4
2 5
5 3
3
3 D
15 L
17 D
예제 출력 1 
9
예제 입력 2 
10
4
1 2
1 3
1 4
1 5
4
8 D
10 D
11 D
13 L
예제 출력 2 
21
예제 입력 3 
10
5
1 5
1 3
1 2
1 6
1 7
4
8 D
10 D
11 D
13 L
"""
from collections import deque
def direction(cur, c):
  di = 0
  if c == "L":
    di = (10000 + cur - 1) % 4
  else:
    di = (10000 + cur + 1) % 4
  return di
    


N = int(input())
S = int(input())
board = [[0]*(N+1) for _ in range (N+1)]
for i in range (S):
  applex, appley = map(int, input().split())
  board[applex][appley] = 1
L = int (input())
info = []
total = 0
for i in range (L):
  t, c = map(str, input().split())
  prev = total
  total = int(t)
  current = total - prev
  info.append([current, c])

# right, down, left, up
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


snail = deque()
snail.append([1,1])  #snail 길이
pointer = [1,1]
time = 0 #time
cur = 0 #현재방향
goto = info[0][0] #직진횟수
count = 0 #1만큼 증가
idx = 0 #info[idx]
while True:
  if count < goto or time >= total:
    if time == total:
      cur = direction(cur, info[idx][1])
    time += 1
    count += 1
    nx = pointer[0] + dx[cur]
    ny = pointer[1] + dy[cur]

    if nx < 1 or nx > N or ny < 1 or ny >N :
      break
    elif board[nx][ny] == 2:
      break
    elif board[nx][ny] == 1:
      board[nx][ny] = 2
      snail.append([nx, ny])
      pointer[0] = nx
      pointer[1] = ny
    else:
      board[nx][ny] = 2
      snail.append([nx, ny])
      pointer[0] = nx
      pointer[1] = ny
      board[snail[0][0]][snail[0][1]] = 0
      snail.popleft()
  else:
    if (idx < L):
      count = 0
      goto = info[idx+1][0]
      cur = direction(cur, info[idx][1])
      idx += 1
      
print (time)
print(snail[0][0], snail[0][1])

"""
<피드백>
   1. 문제 해석 오류 : 
    게임 시작 시간으로부터 X초가 끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다
      :: 이를, X초 마다 바뀌는것으로 해석하는 실수 하였음
   1-2. 문제 분석 :
    시작마다 90도 방향을 오른쪽, 왼쪽으로 한다는 것은, 회전을 한다고 생각할 수 있다.
      회전을 하므로 dx,dy 를 오른쪽->아래->왼쪽->위 방향으로 짜놓고, "L" -> -1 , "D" -> +1 을 해준다.
        (이때, 0보다 작은 수가 올 경우, 인덱스 오류가 날 수 있으므로 + 4의 배수 중 가장 큰 10,000 을 더해놓고 시작한다.)
          (10_000 + cur - 1) or (10_000 + cur + 1)
   2. 코드 분석
    << A: cur 분기가 복잡해졌는데, while 뒷 부분에 info[idx][0] 이 회전할 시간이 되었음을 판단하는 구문을 넣는게 더 쉽다. >>
   idx = 0
   while True:
    nx = pointer[0] + dx[cur]
    ny = pointer[1] + dy[cur]
    if x < 1 or nx > N or ny < 1 or ny >N ):
     ... 중략 ...
    if idx < L and time == info[idx][0]:
      cur = direction(cur, info[idx][1])
      idx += 1
  << B. popleft() 와 pop(0) 는 같은 구문이다. 참고하자 >>
  << C. snail.pop() 을 하기전에, 보드에 해당 위치에 0으로 바꾸는 과정을 빼먹는 실수가 잦음. >>
  << D. 변수명을 조금 더 구체적으로 쓰고, input 변수는 대문자로 사용하여 혼용을 막자>>
  << E. 이중 리스트 선언 시>>
    snail = [[1,1]]      #선언 시, [[]] 두 번
    snail.append([1,1])   #추가 시, [] 1번인 점을 기억하기
"""
