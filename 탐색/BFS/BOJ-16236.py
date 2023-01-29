"""
<핵심>
현재 pos에서 모든 경로를 찾은 후 조건에 가장부합하는 최단경로를 더해준다.

문제에서 
거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
이 지점을 보면 for문을 위에서부터 오른쪽으로 탐색하면서 찾아볼 수 있겠다는 판단을 할 수 있다.

<공부할 부분>
while, for 문 안의 break와 continue(for문 한 사이클만 무시하고 돌린다는 개념)
"""


import sys
import copy
from collections import deque
input = sys.stdin.readline
n = int(input())
graph = []
babe = []
obj = []
babe_size = 2
eat_fish = 0
fish_count = 0
for i in range(n):
    temp = list(map(int, input().split()))
    graph.append(temp)
    for j in range(n):
        if temp[j] == 9:
            babe = [i,j]
            graph[i][j] = 0
        if 0<temp[j]<9:
            fish_count += 1 
    

move = [(-1,0), (0,-1), (0,1), (1,0)]
times = [[-1]*n for _ in range(n)]
def sizeup():
    global babe_size, eat_fish, fish_count
    fish_count -= 1
    if babe_size == eat_fish+1:
        eat_fish = 0
        babe_size += 1
    else:
        eat_fish += 1 

#최단경로를 다 표시한 다음 -> 최단경로를 계속 더해가는 방식.
def bfs(start):
    global babe_size, eat_fish
    t = copy.deepcopy(times)
    queue = deque([start])
    t[start[0]][start[1]] = 0
    
    while queue:
        px,py = queue.popleft()
        for dx,dy in move:
            nx,ny = px+dx, py+dy
            if 0<=nx<n and 0<=ny<n and t[nx][ny] == -1:
                if graph[nx][ny] <= babe_size:
                    t[nx][ny] = t[px][py] + 1 
                    queue.append([nx,ny])
    return t   


def find_short(t):
    shortest = 1e9
    x,y = -1,-1
    for i in range(n):
        for j in range(n):
            if 0<graph[i][j]<babe_size and -1<t[i][j]<shortest:
                x,y = i,j 
                shortest = t[i][j]
    return x,y,shortest

start = babe  
result = 0 
while fish_count > 0:
    t = bfs(start)
    nextX,nextY,temp_time = find_short(t)
    if nextX == -1:
        break
    else:
        sizeup()
        graph[nextX][nextY] = 0
        start = [nextX,nextY]
        result += temp_time

print(result)
"""
6
0 0 0 0 0 0
1 3 3 3 3 0
0 3 9 0 3 0
0 3 0 0 3 0
0 3 3 3 3 0
0 0 0 0 0 0
"""
    
