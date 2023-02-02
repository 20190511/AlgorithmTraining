""" DFS + 메모이제이션 : 경로 수 출력. """
import sys
input = sys.stdin.readline

n,m = map(int, input().split())
graph = []
times = [[-1]*m for _ in range(n)]

for _ in range(n):
    graph.append(list(map(int,input().split())))
    
move = [(-1,0),(1,0),(0,1),(0,-1)]


def dfs(start):
    px,py = start
    if px == n-1 and py == m-1:
        times[px][py] = 1
        return 1
    if times[px][py] != -1:
        return times[px][py]
    times[px][py] = 0
    
    for dx,dy in move:
        nx,ny = dx+px, dy+py
        if 0<=nx<n and 0<=ny<m and graph[nx][ny] < graph[px][py]:
            #상하좌우에서 구해온 dfs 다 더해줌.
            times[px][py] += dfs([nx,ny])
    
    print(times)
    return times[px][py]
    
    
    
dfs([0,0])
print(times[0][0])
