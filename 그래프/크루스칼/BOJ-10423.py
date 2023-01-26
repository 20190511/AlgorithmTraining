"""
10423번 : 전기가 부족해
https://www.acmicpc.net/problem/10423

발전소 bools -> 발전소끼리는 일단은 0번이랑 묶어놓는다. cost=0
+ 최소신장트리 : 크루스칼 알고리즘
find and union 알고리즘 구현
"""
from collections import deque
import sys
input = sys.stdin.readline
n,m,k = map(int,input().split())
power = list(map(int,input().split()))
edges = []
for _ in range(m):
    a,b,cost = map(int, input().split())
    edges.append((cost,a,b))
edges.sort()

p = [i for i in range(n+1)]

def find(p,x):
    if x != p[x]:
        p[x] = find(p,p[x])
    return p[x]

def union(p,a,b):
    a,b = find(p,a), find(p,b)
    if a<b: p[b] = p[a]
    else: p[a] = p[b]
    
for num in power:
    union(p,num,0)
    
result = 0 
for cost,x,y in edges:
    if find(p,x) != find(p,y):
        union(p,x,y)
        result += cost
print(result)
    
