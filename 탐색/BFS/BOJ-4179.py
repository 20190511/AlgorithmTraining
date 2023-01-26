"""
4179번 불! : https://www.acmicpc.net/problem/4179
#불이 여러개 있을 수 있음 (지훈이는 한명인건 맞음)

[풀이]
 1. 일단 집에 불을 먼저 질러서 불 time graph를 먼저 완성한다. (BFS로 구현하면됨.)
 2. 지훈이는 이후 불 fire_time[nx][ny] > ji_time[x][y] + 1 인지 확인 후 BFS를 수행한다.
    ->만약 벽 밖으로 나갈 수 있으면 result에 추가해뒀다가 max 연산을 수행한다.O(result 선형시간)
    

[피드백]
 : 같은 시간에 동시에 돌리려고 하면 굉장히 골아픈 문제다. 


"""

from collections import deque
import copy
import sys
input = sys.stdin.readline
n,m = map(int,input().split())
graph = []
fire = []
ji = []
for i in range(n):
    line = input()
    temp = []
    for j in range(m):
        if line[j] == "J":
            ji = [i,j]
        if line[j] == "F":
            fire.append([i,j])
        temp.append(line[j])
    graph.append(temp)

fire_time = [[1e9]*m for _ in range(n)]
ji_time = [[-2]*m for _ in range(n)]
ji_time[ji[0]][ji[1]] = 0 

for x,y in fire:
    fire_time[x][y] = 0

move = [(1,0),(-1,0),(0,1),(0,-1)]
f,j = deque(fire),deque([ji])
reuslt = []
graph_test = copy.deepcopy(graph)

while f:
    fx,fy = f.popleft()
    for dx,dy in move:
        fnx,fny = fx+dx, fy+dy
        if 0<=fnx<n and 0<=fny<m:
            if graph_test[fnx][fny] =="J" or graph_test[fnx][fny] ==".":
                 graph_test[fnx][fny] = "F"
                 fire_time[fnx][fny] = fire_time[fx][fy] + 1 
                 f.append([fnx,fny])

while j:
    jx,jy = j.popleft()
    for dx,dy in move:
        jnx,jny = jx+dx, jy+dy
        if 0<=jnx<n and 0<=jny<m:
            if graph[jnx][jny] == "." and ji_time[jx][jy]+1 < fire_time[jnx][jny]:
                j.append([jnx,jny])
                graph[jnx][jny] = "J"
                ji_time[jnx][jny] = ji_time[jx][jy] + 1 
        else:
            reuslt.append(ji_time[jx][jy] + 1)

if len(reuslt) == 0:
    print("IMPOSSIBLE")
else:
    re = min(reuslt)
    print(re)

        
"""
5 5
#####
#.F.#
###J#
#...#
#...#

5 5
#####
#J..#
##.##
#..F#
##.##

4 4
####
#JF#
#..#
#..#
ans : 3

3 3
###
#J.
#.F
ans: IMPOSSIBLE

4 6
######
......
#.J###
#F####
ans : 5 

5 4
####
#...
#.##
#.J#
####
ans : 6

7 7
#######
#J#####
#.....#
#.#.#.#
#.#.#.#
F.#.#.#
##F.#.#
ans: 10

7 7
#######
#J###F#
#.....#
#.#.#.#
#.#.#.#
F.#.#.#
##F.#.#
ans: IMPOSSIBLE
"""
