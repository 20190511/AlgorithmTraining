import sys
import copy
from collections import deque
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

def dfs(graph,start):
    px,py = start
    graph[px][py] = 2
    for dx,dy in move:
        nx,ny = dx+px,dy+py
        if 0<=nx<n and 0<=ny<m and graph[nx][ny] == 0:
            dfs(graph,[nx,ny])
    
    
def simul(count):
    global result
    if count == 3:
        graph = copy.deepcopy(origin)
        for item in virus:
            dfs(graph,item)
        
        result = max(safezone(graph),result)
    else:
        for i in range(n):
            for j in range(m):
                if origin[i][j] == 0:
                    origin[i][j] = 1 
                    count += 1 
                    simul(count)
                    origin[i][j] = 0
                    count -= 1 
    

simul(0)
print(result)

                
