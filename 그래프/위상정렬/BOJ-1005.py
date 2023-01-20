"""
1005번 : ARM Craft
https://www.acmicpc.net/problem/1005

[풀이]
:위상정렬(인접노드 제거기술) + DP문제:max(times[item], times[now]+cost[item])

"""
import sys
from copy import deepcopy
from collections import deque
input = sys.stdin.readline
T = int(input())
result = []
for _ in range(T):
    n,k = map(int, input().split())
    cost = []
    cost = list(map(int, input().split()))
    cost.insert(0,0)
    indegree = [0]*(n+1) 
    graph = [[] for _ in range(n+1)]
    for i in range(k):
        #a->b
        a,b = map(int, input().split())
        indegree[b] += 1
        graph[a].append(b)
    target = int(input())
    times = deepcopy(cost)
    
    queue = deque()
    for i in range(1, n+1):
        if indegree[i] == 0:
            queue.append(i)
    
    while queue:
        now = queue.popleft()
        for item in graph[now]:
            indegree[item] -= 1 
            times[item] = max(times[item], times[now]+cost[item])
            if indegree[item] == 0:
                queue.append(item)
    result.append(times[target])
print(*result)

    
        
