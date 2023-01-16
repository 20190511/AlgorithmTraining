"""
coin개수만큼 반복
    (coin[i]<=i<=goals)
    dp[i] = min(dp[i-coin[i]]+1, dp[i])
    
3 7
3
5
9

3 15
1
5
12

#반례 중요
2 10
2
3
"""

import sys
n, k = map(int, sys.stdin.readline().split())
coins = []
for _ in range(n):
    coins.append(int(sys.stdin.readline().strip()))
coins.sort() #sort 하나 추가
dp = [100001]*(k+1) #min 범위로 해야될 것이라서. 그리고 0번값 초기화 필요없음.
dp[0] = 0

for c in range(0, n):
    coin = coins[c]
    for i in range(coin, k+1):
          dp[i] = min(dp[i-coin]+1, dp[i])
      
result = dp[-1]
if result == 100001:
    print(-1)
else:
    print(dp[-1])

