"""
풀이 2 : 인접리스트(BASE) + 인접행렬(순환간선체크용)

4 0 3 3
0 1 10
1 2 0 
2 1 0 
10 10 10 10


피드백 
    <벨만포드알고리즘의 구멍>
    0. 벨만-포드 알고리즘이 순환간선을 체크할 수 있지만,
        순환이 발견되는 즉시 Return을 해버리면,
        해당 Target 노드가 순환간선이랑 포함되는지의 여부를 알 수 없다는 한계가 있다.
        그래서 Target 노드와 순환간선(cur) 이 이어져있는지 BFS 를 이용하여 체크하면 된다.
        
    [실수주의] 그래서 Return 위치를 check()를 해서 True가 될 때만 Return을 해줘야한다.
        밖으로 빼버리면 Cycle이 2개 있어 가능한 것으로 판단되고 바로 Return될 수 있기 때문이다.
        
    
    <2. Idea 2. 간선을 n+1번 돌리고, n번째에 갱신되는 노드값을 INF로 바꿔버리는 기법>
"""

import sys
from collections import deque
input = sys.stdin.readline
INF = float(-1e9)

n,start,target,m = map(int,input().split())
dist = [INF]*n
edges = [] 
graph = [[] for _ in range(n+1)]
for _ in range(m):
    a,b,c = map(int,input().split())
    edges.append([a,b,-c])
    graph[a].append(b)

plus = list(map(int,input().split()))
for i in range(m):
    edges[i][2] += plus[edges[i][1]]

def check(cur):
    visited = [False]*n 
    visited[cur] = True
    q = deque([cur])
    
    while q:
        nexts = q.popleft()
        for item in graph[nexts]:
            if item == target:
                return True 
                
            if not visited[item]:
                visited[item] = True
                q.append(item)
    return False

def bf(start):
    dist[start] = plus[start]
    for i in range(n+1):
        if i == n and dist[target] == INF:
            print("gg")
            return False
        for j in range(m):
            cur, nexts, money = edges[j]
            if dist[cur] != INF and dist[nexts]<dist[cur]+money:
                dist[nexts] = dist[cur] + money
                if i == n-1:
                    #바로 return을 걸어버리면 Cycle이 2개가 존재하는 부분 등을 체크할 수 없음.
                    if check(cur):
                        print("Gee")
                        return False
    return True


if bf(start):
    print(dist[target])
