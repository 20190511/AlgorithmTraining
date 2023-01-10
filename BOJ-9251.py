"""
LCS 
if str[i] == str[j]:
    dp[i][j] = dp[i-1][j-1] + 1 
else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])\
    
    
    
ACAYKP
CAPCAK


ARALENGELFERT
RANGLER
"""

strA = input()
strB = input()
lenA,lenB = len(strA), len(strB)
dp = [[0 for _ in range(lenB+1)] for _ in range(lenA+1)]
for i in range(1, lenA+1):
    for j in range(1, lenB+1):
        if strA[i-1] == strB[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1 
        else:
            dp[i][j] = max(dp[i][j-1], dp[i-1][j])

print(dp[lenA][lenB])
