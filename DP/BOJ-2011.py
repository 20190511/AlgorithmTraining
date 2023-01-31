
""" code : 1:A ~ 26:Z """
"""
dp[i][0] : code[i] 쓰는 경우 -> dp[i-1][0] + dp[i-1][1]
dp[i][1] : code[i-1]+code[i]를 쓰는 경우 -> dp[i-1][0] (=dp[i-2][0]+dp[i-2][1])

ex) 25114
여기서 4번째 1을 바라보고있다면
1만 따로 쓰겠다 -> dp[4][0] = dp[3][0] + dp[3][1]
앞의 1과 붙이겠다 -> dp[4][0] += dp[2][0] + dp[2][1] 인데 이게 dp[3][0] 과 같습니다. 

    check = 0
    if 0< int(code[i]) <= 9:
        dp[i][0] += dp[i-1][0] + dp[i-1][1]
        check += 1
    if code[i-1] != "0" and int(code[i-1])*10+int(code[i]) <= 26:
        dp[i][1] += dp[i-1][0]
        check += 1
    if check == 0:
        print(0)
        break
    
    
    
010443434

100232323
502302301
    """
code = input()
code_len = len(code)
dp = [[0,0] for _ in range (len(code))]

bs = True
if code[0] == "0":
    print(0)
    bs = False
else:
    dp[0][0] = 1
    
    
for i in range(1,code_len):
    if not bs:
        break
    check = 0
    if 0< int(code[i]) <= 9:
        dp[i][0] += dp[i-1][0] + dp[i-1][1]
        check += 1
    if code[i-1] != "0" and int(code[i-1])*10+int(code[i]) <= 26:
        dp[i][1] += dp[i-1][0]
        check += 1
    if check == 0:
        bs = False
        print(0)
        break

if bs:
    print(sum(dp[code_len-1])%1000000)
    


