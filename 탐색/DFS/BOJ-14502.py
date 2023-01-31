#Combinations가 무조건 재귀함수보단 빠르다.
import sys
import copy
from collections import deque
from itertools import combinations
input = sys.stdin.readline
n,m = map(int, input().split())
graph = [[0]*m for _ in range(n)]
origin = []
virus = []
for _ in range(n):
    origin.append(list(map(int,input().split())))
    
for x in range(n):
    for y in range(m):
        if origin[x][y] == 2:
            virus.append([x,y])


move = [(1,0),(-1,0),(0,1),(0,-1)]

def gprint(graph):
    for x in range(n):
        for y in range(m):
            print(graph[x][y], end=" ")
        print()
    print()
    print()

def safezone(graph):
    count = 0
    for x in range(n):
        for y in range(m):
            if graph[x][y] == 0:
                count += 1 
    return count
                
                
result = 0
def simul():
    global result
    graph = copy.deepcopy(origin)
    queue = deque(virus)
    while queue:
        px,py = queue.popleft()
        for dx,dy in move:
            nx,ny = px+dx, py+dy
            if 0<=nx<n and 0<=ny<m and graph[nx][ny] == 0:
                graph[nx][ny] = 2 
                queue.append([nx,ny])
    
    result = max(safezone(graph),result)
    

def count0():
    c = []
    for x in range(n):
        for y in range(m):
            if origin[x][y] == 0:
                c.append([x,y])
    return c 
    
case = list(combinations(count0(),3))
for item in case:
    x1,y1 = item[0]
    x2,y2 = item[1]
    x3,y3 = item[2]
    origin[x1][y1] = 1 
    origin[x2][y2] = 1 
    origin[x3][y3] = 1 
    simul()
    origin[x1][y1] = 0 
    origin[x2][y2] = 0
    origin[x3][y3] = 0 
print(result)


                
