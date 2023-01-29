"""
19236번 : 청소년 상어
https://www.acmicpc.net/problem/19236


[풀이]
 : 빡센 구현 + DFS (한 지점을 끝까지 가서 최단경로 구하기)
"""
import sys
import copy
input = sys.stdin.readline


#반시계방향으로 구성.
move = [(-1,0),(-1,-1),(0,-1),(1,-1),(1,0),(1,1),(0,1),(-1,1)]

graph = [[]*4 for _ in range(4)]
fish_count = 0
for i in range(4):
    lists = list(map(int, input().split()))
    for j in range(0,7,2):
        temp = [lists[j],lists[j+1]-1]
        graph[i].append(temp)
        if 0<lists[j]<17:
            fish_count += 1 
            
def gprint(graph):
    for i in range(4):
        for j in range(4):
            print(graph[i][j], end=" ")
        print()
    print()
    print()
    
#상어번호 17
def move_fish(graph, fish_count):
    now = 0
    index = [0,0]
    for k in range(fish_count):
        temp = 17
        for i in range(4):
            for j in range(4):
                if now < graph[i][j][0] < temp:
                    temp = graph[i][j][0]
                    index = [i,j]
                    
        now = temp
        x,y = index
        for i in range(8):
            s = (graph[x][y][1]+i)%8
            nx,ny = x+move[s][0],y+move[s][1]
            if 0<=nx<4 and 0<=ny<4 and graph[nx][ny][0] < 17:
                graph[nx][ny][0],graph[x][y][0] = graph[x][y][0], graph[nx][ny][0]
                graph[nx][ny][1],graph[x][y][1] = graph[x][y][1], graph[nx][ny][1]
                graph[nx][ny][1] = s
                break
    return graph

result = graph[0][0][0]
fish_count -= 1 
graph[0][0][0] += 17
move_fish(graph,fish_count)
cur=[0,0]

result = []

    
def dfs(graph, cur,fish_count):
    cx,cy = cur
    for prod in range(1, 4):
        nx,ny = cx+move[graph[cx][cy][1]][0]*prod,cy+move[graph[cx][cy][1]][1]*prod
        if 0<=nx<4 and 0<=ny<4 and 0<graph[nx][ny][0]<17:
            g = copy.deepcopy(graph)
            g[nx][ny][0] = graph[cx][cy][0] + graph[nx][ny][0]
            g[cx][cy][0],g[cx][cy][1] = 0,0
            if fish_count-1 <= 0:
                result.append(g[nx][ny][0]-17)
                return
            g = move_fish(g, fish_count-1)
            result.append(g[nx][ny][0]-17)
            dfs(g,[nx,ny], fish_count-1)

dfs(graph, cur, fish_count)
print(max(result))
