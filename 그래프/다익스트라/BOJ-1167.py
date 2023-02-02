"""
6
1 3 2 6 6 -1
2 4 4 -1
3 1 2 4 3 -1
4 2 4 3 3 5 6 -1
5 4 6 -1 
6 1 6


# 다익스트라던, BFS 던 2번 돌리면 풀 수 있는 문제.
1번노드로 가장 긴 노드를 찾는다
해당 노드를 이용해서 한 번 더 돌린다.
"""

import heapq
import sys
INF = int(1e9)

input = sys.stdin.readline
n = int(input())
graph = [[] for _ in range(n+1)]
for _ in range(n):
    temp = list(map(int, input().split()))
    node = temp[0]
    for i in range(1, len(temp)-1, 2):
        graph[node].append(temp[i:i+2])
        

def dijkstra(start):
    sets = [0,0] #거리 + 가장 먼 노드.
    dist = [INF]*(n+1)
    dist[0] = 0
    dist[start] = 0
    
    q = []
    heapq.heappush(q, (0,start))
    while q:
        lens,node = heapq.heappop(q)
        if lens > dist[node]:
            continue
        
        for item in graph[node]:
            cost = lens+item[1]
            if cost < dist[item[0]]:
                dist[item[0]] = cost
                heapq.heappush(q,(cost,item[0]))
                
                if sets[0] < cost:
                    sets[0] = cost
                    sets[1] = item[0]
    return sets
    
sets = dijkstra(1)
result , _ = dijkstra(sets[1])
print(result)
