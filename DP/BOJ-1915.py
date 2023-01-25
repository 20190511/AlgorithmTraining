"""
1915번 : 가장 큰 정사각형
가장 가장자리들은 frame을 담당.
if graph[i][j] == 1:
    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1 (i = 1...n-1, j = 1 ...m-1)
    
[피드백]
 : 처음에 maxs를 0으로 reset 했는 실수
    -> 데이터가 1 by X 이거나 X by 1 (X is don't care) 이면 for문을 돌지않아서 maxs가 0으로 초기화되버리는 경우가발생한다.
        그래서 input 데이터를 받을 때, check를 둬서 1이하나라도 들어오면 maxs를 1로 초기화 시켜줘서 해결하였다.

2 4 
1111 
1111 

3 4 
1110
1011
1110

4 3
000 
011 
011 
011 

1 1 
0
"""
import sys
import copy
input = sys.stdin.readline
n,m = map(int, input().split())
graph = []

check = 0
for _ in range(n):
    s = input()
    tp = []
    for i in range(m):
        if s[i] == "1":
            check = 1 
        tp.append(int(s[i]))
    graph.append(tp)
    
maxs = check
for i in range(1, n):
    for j in range(1, m):
        if graph[i][j] == 1:
            graph[i][j] = min(graph[i-1][j-1], graph[i-1][j], graph[i][j-1]) + 1
            maxs = max(maxs, graph[i][j])
print(maxs*maxs)
