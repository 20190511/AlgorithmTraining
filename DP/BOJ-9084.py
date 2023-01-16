"""
동전
https://www.acmicpc.net/problem/9084

[내 풀이]
 1. 첫 블럭은 coin 1번 으로 할 수 있는 금액을 모두 1로 초기화시켜준다.
 2. for문을 돌면서 goals까지 차례대로 금액을 아래와같이 초기화시켜준다 (누적 초기화)
    ex) dp[i] 번째 경우의수는 coin[i] 를 사용 안했는 경우의수 + coin[i] 를 하나라도 사용했을 경우의수 이다.
      즉, dp[i] = dp[i] + dp[i-coin[i]] 이 된다.
        #tip, 리스트는 배열과 달리 coin[i] 역시 접근 시간이 걸리므로, c = coin[i] 로 해놓고 풀면 좋다.

3
2
1 2
1000
3
1 5 10
100
2
5 7
22
"""

import sys
t = int(sys.stdin.readline().strip())
result = []
for _ in range(t):
  n = int(sys.stdin.readline().strip())
  coins = list(map(int, sys.stdin.readline().split()))
  goals = int(sys.stdin.readline().strip())
  dp = [0] * (goals+1)

  #첫 동전은 초기화
  for i in range(goals+1):
    if i%coins[0] == 0:
      dp[i] = 1

  """ dp[i] = dp[i] + dp[i-coin[i]] """
  for c in range(1, n):
    coin = coins[c]
    for i in range(coin, goals+1):
      dp[i] += dp[i-coin]
  result.append(dp[-1])

for item in result:
  print(item)
