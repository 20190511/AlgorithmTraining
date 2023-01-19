#1523 ~ #1609 combination 구현 전
"""
15686번 :치킨배달
https://www.acmicpc.net/problem/15686
"""
from itertools import combinations
def findChicken(maps):
  size = len(maps)
  chicken = []
  house = []
  for i in range(size):
    for j in range(size):
      if maps[i][j] == 2:
        chicken.append([i+1, j+1])
      if maps[i][j] == 1:
        house.append([i+1, j+1])
  return house, chicken

def countPath(house, chicken):
  xpath = house[0] - chicken[0]
  ypath = house[1] - chicken[1]
  if xpath < 0:
    xpath = -xpath
  if ypath <0 :
    ypath = -ypath
  sums = xpath + ypath
  return sums

def sumS(l):
  sums = 0
  for i in l:
    sums += i
  return sums

"""
def comb (chicken, maxs):
  pivot = [i for i in range(1, maxs+1)]
  while True:
    if pivot[len(pivot)-1] == len(chicken) and 
"""
  
size, maxs = map(int, input().split())
maps = [[0]*size for _ in range(size)]
for i in range(size):
  maps[i] = list(map(int, input().split()))

house = []
chicken = []
house, chicken = findChicken(maps)

resultL = []
comb = list(combinations(chicken,maxs))
for i in range (len(comb)):
  ls = []
  for c in range(len(house)):
    small = []
    for h in range(maxs):
      small.append(countPath(house[c],comb[i][h]))
    val = min(small)
    ls.append(val)
  resultL.append(sumS(ls))

result = min(resultL)
print(result)

"""
<< 피드백 >>
   1. 순열 및 조합 알고리즘 사용 시 from itertools 를 활용한다.
      ※ 해당 값 변경 가능
      
       a. 조합 : from itertools import combinations
          val = list(combinations(lists, num))
       b. 순열 : from itertools import permutations
          val = list(permutations(lists,num))
       C. 중복조합 : from itertools import combinations_with_replacement
          val = list(combinations_with_replacement(lists,num))
   2. 절대값의 경우에는 import 할 필요없이, abs() 해주면 된다.
   3. 리스트에서 특정 값 개수 세주는 기능 ** 그냥 def 함수로 구현하는 것이 편할 수도 있다. (복잡한 겨우 사용)
      from collections import Counter
      counter = Counter([1,1,1,1,1,3,2,4])
      print(Counter(1)) # 횟수 출력.
"""
