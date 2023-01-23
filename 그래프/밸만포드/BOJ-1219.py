"""
풀이 1 : 인접행렬 
반례
4 0 3 5
0 1 0
0 3 5
0 3 5
1 2 0
2 1 0
0 5 5 10

5
"""
import sys
from collections import deque
input = sys.stdin.readline
INF = float(-1e9)

n,start,target,m = map(int,input().split())
dist = [INF]*n
graph = [[] for _ in range(n+1)]
for _ in range(m):
    a,b,c = map(int, input().split())
    graph[a].append([b,c])
salary = list(map(int, input().split()))

for i in range (n):
    for j in range(len(graph[i])):
        graph[i][j][1] = salary[graph[i][j][0]] - graph[i][j][1]


def check(i):
    visited = [False] * n 
    visited[i] = True
    queue = deque([i])
    while queue:
        nexts = queue.popleft()
        for item,trash in graph[nexts]:
            if item == target:
                return True
            if not visited[item]:
                queue.append(item)
                visited[item] = True
    return False
    
def bf(start):
    dist[start] = salary[start]
    
    for i in range(n+1):
        if i == n and dist[target] == INF:
            print("gg")
            return
        for j in range(n):
            if dist[j] == INF:
                continue
            for nexts, length in graph[j]:
                if dist[nexts] < dist[j] + length:
                    dist[nexts] = dist[j] + length
                    if i == n-1:
                        if check(j):
                            print("Gee")
                            return False
    return True
if bf(start):
    print(dist[target])
