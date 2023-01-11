"""
동전 1
https://www.acmicpc.net/problem/2293
BOJ-9084와 동일한데, 동전이 오름차순으로 배열이 안되어있어 sort() 하나 추가
  sort 구현해야한다면 quick sort가 적절할 것.

(0<=i<=goals 까지)
  dp[i] = 1 if i % 3 == 0: (if coin is smallest coin)
  dp[i] = dp[i] + dp[i-coin] (if coin is not smallest coin)
"""
import sys
n, k = map(int, sys.stdin.readline().split())
coins = []
for _ in range(n):
    coins.append(int(sys.stdin.readline().strip()))
coins.sort() #sort 하나 추가

dp = [0] * (k+1)
for i in range(k+1):
    if i % coins[0] == 0:
        dp[i] = 1 

for c in range(1, n):
    coin = coins[c]
    for i in range(coin, k+1):
        dp[i] += dp[i-coin]
    
print(dp[-1])
