"""
DFS 호출을 하면 결국 제자리로 돌아올 수 있기 때문에
역순으로 가장 깊은 곳부터 체크하면서 돌아올 수 있다.

주의할 점은 move 방향에 따른, 4방향 중 return되서 돌아온 값 중
가장 큰 값을 메모이제이션 해주어야 한다는 점이다.

그 역할을 temp 변수가 해주고 있다.,

temp = max(temp, times[nx][ny]+1) #재귀호출 필요없이 바로 1 추가 (경로를 이미 탐색한 경우)
temp = max(dfs([nx,ny]+1, temp)) #재귀호출 사용. (한 번도 경로탐색을 안한 경우)


<주의할 점 2>
    :파이썬의 재귀함수 최대값이 많아질 경우.
    sys.setrecursionlimit(횟수) 를 지정하여 늘려줄 수 있다.
"""

import sys
sys.setrecursionlimit(40000) #재귀함수 최대호출 기한
input = sys.stdin.readline
n = int(input())
times = [[0]*n for _ in range(n)]
graph = []

for _ in range(n):
    graph.append(list(map(int, input().split())))
    
move = [(1,0),(-1,0),(0,1),(0,-1)]
max_time = 0
def dfs(start):
    global max_time
    px,py = start
    temp = 1
    for dx,dy in move:
        nx,ny = px+dx, py+dy
        if 0<=nx<n and 0<=ny<n and graph[nx][ny] > graph[px][py]:
            if times[nx][ny] == 0:
                temp = max(dfs([nx,ny])+1, temp)
            else:
                # 지금가서 얻어온 times[nx][ny] vs temp
                temp = max(temp, times[nx][ny]+1)
            
    times[px][py] = temp
    max_time = max(max_time, temp)
    return temp
    
for x in range(n):
    for y in range(n):
        dfs([x,y])
        
print(max_time)
        
