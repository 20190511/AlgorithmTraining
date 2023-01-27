"""
1753번 : 최단경로
https://www.acmicpc.net/problem/1753
기본 다익스트라 문제

"""
import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)
n,m = map(int, input().split())
start = int(input())

graph = [[] for _ in range(n+1)]
distance = [INF] * (n+1)
for _ in range(m):
  a,b,c = map(int, input().split())
  graph[a].append((b,c))

distance[start] = 0
q = []
heapq.heappush(q, (0,start))
while q:
  lens,now = heapq.heappop(q)
  if lens > distance[now]:
    continue
  for item in graph[now]:
    cost = lens + item[1]
    if cost < distance[item[0]]:
      distance[item[0]] = cost
      heapq.heappush(q, (cost, item[0]))

for item in distance[1:]:
  if item == INF:
    print("INF")
  else:
    print(item)

