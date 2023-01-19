"""
프로그래머스 60061 문제 : 기둥과 보 설치
https://school.programmers.co.kr/learn/courses/30/lessons/60061
"""
#0:기둥, 1:보
def check(info):
  size = len(info)
  res = True
  for i in range (size):
    x = info[i][0]
    y = info[i][1]
    how = info[i][2]
    if how == 0: #기둥
      if y==0 or [x,y-1,0] in info or [x-1,y,1] in info or [x,y,1] in info:
        continue
      else:
        return False
    else:
      if [x+1,y-1,0] in info or [x,y-1,0] in info or (
        [x+1,y,1] in info and [x-1,y,1] in info):
          continue
      else:
        return False
  return res      

def solution(n, build_frame):
  info = []
  qus = build_frame
  for i in range (len(qus)):
    x = qus[i][0]
    y = qus[i][1]
    how = qus[i][2]
    build = qus[i][3] #0:삭제, 1:설치
    if build == 1:
      info.append([x,y,how])
      if (check(info) == False):
        info.pop()
    else:
      info.remove([x,y,how])
      if (check(info) == False):
        info.append([x,y,how])

  #정렬
  result = sorted(info)
  return result

s1 = [[1, 0, 0, 1], [1, 1, 1, 1], [2, 1, 0, 1], [2, 2, 1, 1], [5, 0, 0, 1],
      [5, 1, 0, 1], [4, 2, 1, 1], [3, 2, 1, 1]]
s2 = [[0, 0, 0, 1], [2, 0, 0, 1], [4, 0, 0, 1], [0, 1, 1, 1], [1, 1, 1, 1],
      [2, 1, 1, 1], [3, 1, 1, 1], [2, 0, 0, 0], [1, 1, 1, 0], [2, 2, 0, 1]]
print(solution(5, s2))


"""
<<피드백>>
   1. 행렬 x,y 축 방향을 실 수 한 경우
     공책에다 풀이할 경우, 직접 구 경우의 수의 좌표를 적어 실수를 줄이자
      ex) check() 함수에서 info[i] 값이 [x,y,1] 이라면 가능한 보의 경우는
        1. 보 아래에 기둥이 있는 경우 (x,y-1), (x+1,y-1)
            [x,y-1,0], [x+1, y-1, 0]
        2. 보 양 옆에 보가 있는 경우 (x+1, y) and (x-1, y)
            [x+1,y,1] and [x-1,y,1]
      ex2) heck() 함수에서 info[i] 값이 [x,y,1] 이라면 가능한 기둥의 경우는
        1. 아래 기둥이 있는 경우 (x,y-1)
          [x,y-1,0]
        2. 기둥이 0층에 있는 경우 y==0
          y == 0
        3. 기둥 아래에 보가 있는 경우  (x-1,y) or (x,y)
          [x-1,y,1] ir [x,y,1]
  [파이썬 문법]
    2. [찾을 리스트 값] in 리스트
      [1,2,3] in lista : 를 하면 찾으면 True, 못 찾으면 False 를 낸다.
        *편리함
    3. 파이썬 list 문법
      :인덱스 위치 반환:
        1. index()
          -> a.index("준형") #준형 인덱스 번호 반환
      :연장:
        1. extend()
          연장하려면 a.extend(b) 도 되고 a = a+b 도 된다.
      :삭제:
        1. pop()
          -> pop(인덱스 번호)
        2. remove()
          -> remove(지울 값)
        3. del a[:4]
          -> 0~3번 인덱스까지 삭제
        4. .clear()
          -> 모든 요소 삭제
      :복사:
        1. b = a.copy()
      :역순 정렬:
        1. .sort(reverse=True)
        
  [파이썬 방식의 알고리즘]
    3. 기둥, 보 같이 여러가지 요소를 검사하는데, 그 요소가 리스트에 있는가 없는가 
    여부 정도의 간단한 문제라면! "a" in list 방식으로 풀이하는 것이 편리하다!
    4. 파이썬에서는 인덱스 값이 음수라도 계산을 하기 때문에,
      범위를 1~2칸 늘려주면 if() 할 때 유리할 수 있다.
        -> 범위가 음수가 되는것은 괜찮지만, len값 보다 커지면 오류를 낸다.
  [카카오, 프래그래머스]
    1. 보통 코드 문제가 함수로 나올 때, 리스트로 받는다면,
      진짜 리스트를 준다. (str->리스트 로 바꾸는 과정은 필요없다.)
"""
