"""
dp table을 dp[n][m] 으로 만든다. (n=i번쨰, m=색칠 갯수)
dp[i][j] 번째 값을 구하려면 i번째 값을 선택을 안하는 경우 + 선택을 하는 경우로 계산
    dp[i-1][j] + dp[i-2][j-1] (선택하면 i-2번째에 j-1개까지의 개수, 선택을 안하면 i-1번째의 j까지 색칠한 값을 구하면된다.) 

문제는 마지막 칸은 1번 칸에 색을 칠하려면, 1번칸에 색칠되어있는 경우의수를 제하여야한다.
    -> 1번칸을 색칠했다 치면, dp[2~i-2][j-1] 를 고려하면된다. 즉 dp[i-3][j-1] 로 정리할 수 있다.
        (즉 n-3 칸 중 j-1 개까지 색칠된 경우의 수 + 색칠 안하는 경우의수.)
dp[N][K]
"""

n = int(input())
m = int(input())
dp = [[0]*(m+1) for _ in range(n+1)] #처음엔 1로 세팅
mod = 1000000003
for i in range(1, n+1):
    dp[i][0] = 0
    dp[i][1] = i


for i in range(1, n+1):
    for j in range(2, m+1):
        if i >= j*2:
            if i == n+1:
                dp[i][j] = (dp[i-3][j-1] + dp[i-1][j])%mod
            else:
                dp[i][j] = (dp[i-2][j-1]+dp[i-1][j])%mod
        
print(dp[n][m])
    
