"""
10942 : 팰린드롬?
https://www.acmicpc.net/problem/10942
if a == b:
  dp[a][b] = True
elif a+1 == b:
  dp[a][b] = (seq[a] == seq[b])
if a+1 > b (a.k.a else:)
  dp[a][b] = (dp[a+1][b-1] and seq[a] == seq[b]) 
  
  
추가 설명
dp가 a와b 간격이 좁은 것부터 처리해줘야한다.
왜냐하면, dp[5][1] 을 계산하려면 미리 dp[4][2]가 처리가 되어있어야되기 때문

그래서
a,b = i, n-labs+1 로 설정해두고 for문을 2번 돌려서 풀었다. 생각보다 꼬이는 내용이 많으므로 잘 생각할것.


  """

import sys
input = sys.stdin.readline
n = int(input())
seq = list(map(int, input().split()))
seq.insert(0,0)
m = int(input())
dp = [[0]*(n+1) for _ in range(n+1)]


labs = n
a,b = 1,1
for labs in range (n,0,-1):
  for i in range(1, labs+1):
    a, b = i, n-labs+i
    if a == b:
      dp[a][b] = 1
    elif a+1 == b:
      dp[a][b] = 1 if seq[a]==seq[b] else 0
    else:
      dp[a][b] = 1 if dp[a+1][b-1] == 1 and seq[a]==seq[b] else 0
      
for _ in range(m):
  a,b = map(int, input().split())
  print(dp[a][b])




