"""
11404번 : 플로이드
https://www.acmicpc.net/problem/11404

풀이 : 일반적인 플로이드 워샬 알고리즘 + 입력받을 때 최소 간선인지 비교해서 받기.
"""

import sys
input = sys.stdin.readline
n = int(input())
m = int(input())
INF = int(1e7)
graph = [[INF]*(n+1) for _ in range(n+1)]
for _ in range(m):
    a,b,c = map(int, input().split())
    graph[a][b] = min(c, graph[a][b])


for x in range(1, n+1):
    for y in range(1, n+1):
        if x == y:
            graph[x][y] = 0


for k in range(1, n+1):
    for a in range(1, n+1):
        for b in range(1, n+1):
            graph[a][b] = min(graph[a][b], graph[a][k]+graph[k][b])

for a in range(1, n+1):
    for b in range(1, n+1):
        if graph[a][b] == INF:
            print(0, end=" ")
        else:
            print(graph[a][b], end=" ")
    print()
        
