"""
백준 3665번 : 최종순위
https://www.acmicpc.net/problem/3665


[내풀이]
각 노드의 진입차수가 몇 개인지 여부로 판단.
    if indegree 가 순위가 매겨진다 => 가능
    if indegree 가 겹치는게 존재한다?
        사이클이 존재한다 -> IMPOSSIBLE
        사이클이 존재X -> ?
        
        
[피드백]
    방향그래프에서 사이클 여부 판단.
        -> 위상정렬을 시도하였을 때, queue가 모든 노드를 거치지 않고 중단된 경우
    위상정렬 시, 여러 그래프가 생길 수 있는 여부 판단.
        -> indegree[now] == 0: 일 때가 2개이상있을 때,
        
        
    중요문법!
        그래프에 list를 변경시키면서 넣고싶은 경우 .copy()를 꼭 넣어야 한다.
            graph.append(lists.copy())
    
"""

import sys
from collections import deque
input = sys.stdin.readline
T = int(input())
results = []
for _ in range(T):
    n = int(input())
    rank_past = list(map(int,input().split()))
    rank_past.insert(0,0)
    graph = [[] for _ in range(n+1)]
    indegree = [0] * (n+1)
    ranks = [0] *(n+1)
    
    
    for i in range(1, n+1):
        ranks[rank_past[i]] = i
        indegree[rank_past[i]] = i-1
        for j in range(i+1, n+1):
            graph[rank_past[i]].append(rank_past[j])
    m = int(input())
    for _ in range(m):
        a,b = map(int,input().split())
        if ranks[a] < ranks[b]:
            indegree[a] += 1
            indegree[b] -= 1
            graph[a].remove(b)
            graph[b].append(a)
        else:
            indegree[a] -= 1 
            indegree[b] += 1 
            graph[a].append(b)
            graph[b].remove(a)
    
    queue = deque()
    for i in range(1,n+1):
        if indegree[i] == 0:
            queue.append(i)
            
    result = []
    types = ""
    while queue:
        now = queue.popleft()
        result.append(now)
        count = 0
        for item in graph[now]:
            indegree[item] -= 1
            if indegree[item] == 0:
                count += 1 
                queue.append(item)
        if count > 1:
            types = "?"
            break
    if types == "?":
        print("?")
    elif len(result) != n:
        print("IMPOSSIBLE")
    else:
        print(*result)

                
        
        
    
    
    
