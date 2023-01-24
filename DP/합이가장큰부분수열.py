"""
// 합이 가장 큰 부분수열 구하기
# dp[i] = max(dp[0 ... k] if val[i] > dp[k]) , 0<= k < i
# count[i] = max dp[k] 의 count[k] + 1 
"""
n = int(input())
seq = list(map(int, input().split()))
dp = [0]*n
dp[0] = seq[0]

def result(maxs,seq,dp):
    max_val, index = maxs
    temp = max_val-seq[index]
    res = [seq[index]]
    for i in range(index, -1, -1):
        if dp[i] == temp:
            res.append(seq[index])
            temp -= seq[index]
    res = res.reverse()
    print(res)
    return res


maxs = [seq[0],0] #val,index
for i in range(1, n):
    val = count = 0
    for j in range(i):
        if seq[i] > seq[j] and val < dp[j]:
            val = dp[j]
    dp[i] = val+seq[i]
    if maxs[0] < dp[i]:
        maxs[0] = dp[i]
        maxs[1] = i

max_val, index = maxs
temp = max_val - seq[index]
res = [seq[index]]
for i in range(index, -1, -1):
    if dp[i] == temp:
        res.append(seq[i])
        temp -= seq[i]
res.reverse()
print(len(res))
for i in range(len(res)):
    print(res[i], end=" ")
