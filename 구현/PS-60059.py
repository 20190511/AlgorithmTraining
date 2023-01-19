"""
프로그래머스(KAKAO2020) 60059번 : 자물쇠와 열쇠
https://school.programmers.co.kr/learn/courses/30/lessons/60059
"""

def tp (key):
    newL = []
    l = len(key)
    for i in range (l):
        newL.append([0 for _ in range (l)])
        
    for x in range (l):
        for y in range (l):
            newL[x][l-y-1] = key[y][x]
    return newL

def clearList (l, newL):
    for x in range (len(l)):
        for y in range (len(l)):
            l[x][y] = newL[x][y]

def check(c, klen, llen):
    for x in range (klen, klen+llen):
        for y in range (klen, klen+llen):
            if c[x][y] != 1:
                return False
    return True
            
            
def solution(key, lock):
    klen = len(key)
    llen = len(lock)
    
    newSize = llen + klen*2
    
    checkList = []
    newL = []
    for i in range (newSize):
        checkList.append([0 for _ in range (newSize)])
        newL.append([0 for _ in range (newSize)])
        
    for x in range (klen, klen+llen):
        for y in range (klen, klen+llen):
            newL[x][y] = lock[x-klen][y-klen]
    
    clearList(checkList, newL)
    for T in range (4):
        key = tp(key)
        for a in range (klen+llen):
            for b in range (klen+llen):
                for x in range (klen):
                    for y in range (klen):
                        checkList[a+x][b+y] += key[x][y]
                if check(checkList, klen, llen) == True:
                    return True
                clearList(checkList, newL)
    return False
 """
 피드백
	 1. 2차원 리스트 만들기.
		a = []
		for j in range (행길이):
			a.append([0 for _ in range(열길이)]
	
	 2. key 가 움직일 때, 개별 요소 비교할 때
		checkList[a+x][b+y] += key[x][y]
	
	 3. 행렬 90도 돌리는 알고리즘
	
	 4. 파이썬 매개변수(parameter) 에 리스트 삽입시,
 레퍼런스처럼 취급됨.
 
 """
