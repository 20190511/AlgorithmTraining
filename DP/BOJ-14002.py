
""" 
문제를 잘못 이해했다
가장 긴 부분수열은 수열의 길이가 가장 긴 걸로 골라야되는데
value값이 가장 큰 부분수열을 골라버렸다.

길이가 가장 긴 부분수열 
dp[i] = max(dp[k], dp[i]) for k = 0 ... i-1 and seq[i] > seq[k]

"""
n = int(input())
seq = list(map(int, input().split()))
dp = [[0,0] for _ in range(n)]
dp[0][0] = 1 
dp[0][1] = 0

maxs = [1,0]
for i in range(1, n):
    for j in range(i):
        if seq[i] > seq[j] and dp[i][0] < dp[j][0]:
            dp[i][0], dp[i][1] = dp[j][0], j
    dp[i][0] += 1
    if maxs[0] < dp[i][0]:
        maxs[0], maxs[1] = dp[i][0], i 

result = [seq[maxs[1]]]
val = dp[maxs[1]][1]
for _ in range(maxs[0]-1):
    result.append(seq[val])
    val = dp[val][1]
result.reverse()
print(maxs[0])
print(*result)


    
            
            

