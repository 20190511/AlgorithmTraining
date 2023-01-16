"""
최소비용 구하기 {다익스트라, 경로출력}
https://www.acmicpc.net/problem/11779

5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5
"""


import heapq
import sys
input = sys.stdin.readline

INF = int(1e9)
size = int(input())
n = int(input())
distance = [INF] * (size+1)
latest_path = [0] * (size+1)
graph = [[] for _ in range(size+1)]
for _ in range(n):
    a,b,c = map(int, input().split())
    graph[a].append((b,c))
start, target = map(int, input().split())

def dijkstra(start):
    distance[start] = 0 
    q = []
    heapq.heappush(q, (0,start))
    
    while q:
        length, node = heapq.heappop(q)
        if length > distance[node]:
            continue
        for item in graph[node]:
            cost = length + item[1]
            if cost < distance[item[0]]:
                distance[item[0]] = cost
                latest_path[item[0]] = node
                heapq.heappush(q, (cost, item[0]))

def navigate(path, target):
    navi = []
    count = 1
    next = path[target]
    while 0<next<INF:
        navi.append(next)
        next = path[next]
        count += 1
    navi.reverse()
    navi.append(target)
    return count, navi


dijkstra(start)
count, navi = navigate(latest_path, target)
print(distance[target])
print(count)
print(*navi)
