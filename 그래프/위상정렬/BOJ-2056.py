"""
2056번 : 작업
https://www.acmicpc.net/problem/2056
전형적인 위상정렬 문제. input 과정만 생각하면 되는 문제
"""
import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
ide = [0]*(n+1)
ide[0] = 1e9
graph = [[] for _ in range(n+1)]
cost = [0]*(n+1)
for i in range(1, n+1):
    temp = list(map(int,input().split()))
    cost[i],ide[i]= temp[0], temp[1]
    for item in temp[2:]:
        graph[item].append(i)

q = deque()
times = cost.copy()
for i in range(1, n+1):
    if ide[i] == 0:
        q.append(i)
        
while q:
    now = q.popleft()
    for item in graph[now]:
        ide[item] -= 1 
        times[item] = max(times[item], times[now]+cost[item])
        if ide[item] == 0:
            q.append(item)
print(max(times))
    
