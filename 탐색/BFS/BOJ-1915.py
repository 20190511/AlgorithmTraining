"""
1. 가장 큰 정사각형
너무 전형적인 BFS 문제
피드백 : max_time 설정 부분을 함부로 0으로 설정하지 말것
"""
import sys 
from collections import deque
input = sys.stdin.readline


# 0:안익은, 1:익은, -1:없는
m,n = map(int, input().split())
graph = []
for _ in range(n):
    graph.append(list(map(int,input().split())))
    
tomato = []
for a in range(n):
    for b in range(m):
        if graph[a][b] == 1:
            tomato.append([a,b])
            
def bfs(graph, tomato):
    queue = deque(tomato)
    move = [(1,0),(-1,0),(0,1),(0,-1)]
    maxtime = 0
    if queue:
        maxtime = 1 
    while queue:
        cx,cy = queue.popleft()
        for dx,dy in move:
            nx,ny = cx+dx, cy+dy
            if 0<=nx<n and 0<=ny<m:
                if graph[nx][ny] == 0:
                    graph[nx][ny] = graph[cx][cy] + 1 
                    queue.append([nx,ny])
                    maxtime = max(maxtime,graph[nx][ny])
    return maxtime
        

maxtime = bfs(graph,tomato)

bools = True
for a in range(n):
    if bools == False: 
        break
    for b in range(m):
        if graph[a][b] == 0:
            bools = False
            break

if bools:
    print(maxtime-1)
else:
    print("-1")
    

    
    
