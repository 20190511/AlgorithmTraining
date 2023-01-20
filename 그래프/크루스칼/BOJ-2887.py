"""
백준2887번 : 행성터널
https://www.acmicpc.net/problem/2887


[풀이]
크루스칼 알고리즘은 맞다.
근데 N개수가 100,000 이라 모든 Edge를 리스트로 저장하면 50,000 * 100,001 = 대략50억 이기 때문에
    모든 Edge를 저장할 수 없다!

문제를 잘 읽어보면, 통로갯수는 N-1개로 정해져있다.
그러므로, x,y,z의 위치 값을 따로 받아서 모두 정렬시킨후(위치값이랑 같이)
정렬된 값을 바탕으로 xn ~ xn-1의 길이 (xn-1 - xn) 로 Edge를 구성한다.
x,y,z 다 합치면 3(N-1) 개의 Edge 리스트로 크루스칼 알고리즘을 구하면 답을 구할 수 있다.
해당 과정은 pdf로 첨부하여 설명할 예정이다.

5
11 -15 -15
14 -5 -15
-1 -1 -5
10 -4 -1
19 -4 19
"""
import sys
def find(p,x):
    if x != p[x]:
        p[x] = find(p,p[x])
    return p[x]

def union(p,a,b):
    a,b = find(p,a),find(p,b)
    if a<b: p[b]=a 
    else: p[a]=b
input = sys.stdin.readline
n = int(input())
cost = []
par = [i for i in range(n)]
xpos = []
ypos = []
zpos = []
for i in range(n):
    x,y,z = map(int,input().split())
    xpos.append((x,i))
    ypos.append((y,i))
    zpos.append((z,i))
xpos.sort()
ypos.sort()
zpos.sort()

for i in range(1,n):
    cost.append((xpos[i][0]-xpos[i-1][0],xpos[i][1],xpos[i-1][1]))
    cost.append((ypos[i][0]-ypos[i-1][0],ypos[i][1],ypos[i-1][1]))
    cost.append((zpos[i][0]-zpos[i-1][0],zpos[i][1],zpos[i-1][1]))
cost.sort()
result = 0
for c, a, b in cost:
    if find(par,a) != find(par,b):
        result += c 
        union(par,a,b)
print(result)
