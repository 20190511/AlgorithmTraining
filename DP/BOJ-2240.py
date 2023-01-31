"""
#dp[t][w][0] -> 1번나무, dp[t][w][1]->2번나무
로 두고 t초에 따른 w번 움직였을 당시 dp를 그려서 풀이한다.

ex)
    if tree[t] == 1:
    # 현재 1번나무인데 움직인다면  dp[i-1][w-1][0] <- i-1초에서 0번나무에서 1번나무로 넘어올 것 이므로
        dp[t][w][0] = dp[t-1][w-1][1] + 1 
    # 현재 1번나무인데 안 움직인다면, dp[i-1][w][1] <- i-1 초에서 1번나무에서 1번나무 그대로
        dp[t][w][0] = dp[t-1][w][0] + 1
    둘 중 큰 것으로 고르면 된다.
      (tree[t] == 2 이라면 1을 안 더해주면 된다.)
        
        즉, # 0->1번나무, 1->2번나무
        dp[t][w][0] = max(dp[t-1][w-1][1], dp[t-1][w][0])
        dp[t][w][1] = max(dp[t-1][w-1][0], dp[t-1][w][1])
        if tree[t] == 1:
            dp[t][w][0] += 1 
        else:
            dp[t][w][1] += 1 
        
        

"""

import sys
t,w = map(int, input().split())
dp = [[[0,0] for _ in range(w+1)] for _ in range(t+1)]
tree = []
for _ in range(t):
    tree.append(int(input()))
tree.insert(0,0)


for i in range(1, t+1):
    dp[i][0][0] = dp[i-1][0][0]
    if tree[i] == 1:
        dp[i][0][0] += 1 
    

for i in range(1,t+1):
    for j in range(1, w+1):
        dp[i][j][0] = max(dp[i-1][j-1][1], dp[i-1][j][0])
        dp[i][j][1] = max(dp[i-1][j-1][0], dp[i-1][j][1])
        
        
        if tree[i] == 1:
            dp[i][j][0] += 1
        else:
            dp[i][j][1] += 1

            
print(max(dp[t][w]))

            
    
