"""
 1007번 : 벡터 매칭
 [https://www.acmicpc.net/problem/1007]

문제 key : 여러 점의 벡터의 합을 구할 때 Tip 
 n개의 벡터 중 (n은 짝수일 때,) n/2 개는 더해야하는 벡터이고, n/2개는 빼야되는 백터임을 알 수 있다.
    그렇게 모든 조합을 계산하면 된다. (20C10 = 184,756)
    ex(A+B+C+D 값을 구해서 (A,B) 를 뺴주면 (C,D)를 구할 수 있다.)
 핵심2. Combinations 중 나머지값도 사용하는 문제의 경우 Combinations() 리스트의 절반값만 사용해도 된다.
    (ex) A,B 를 선택하더라도, C,D를 활용하는 문제 즉, [A,B], [C,D] 로 쓰는 문제)
 
문법 Tip : sqrt 를 사용해야할 땐, pow(value,0.5) 를 이용하자
"""

import sys
from itertools import combinations
import math
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    size = n//2
    sumx,sumy = 0,0
    pos = []
    for _ in range(n):
        x,y = map(int,input().split())
        pos.append([x,y])
        sumx += x 
        sumy += y
    lists = list(combinations(pos, size))
    min_val = int(1e9)
    for item in lists:
        sx,sy = 0,0
        for x,y in item[:len(lists)//2]:
            sx += x 
            sy += y 
        sx2,sy2 = sumx-sx, sumy-sy
        min_val = min(min_val,math.sqrt((sx-sx2)**2+(sy-sy2)**2))
    print(min_val)

    
    
