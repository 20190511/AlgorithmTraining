"""
프로그래머스 (KAKAO2020) 60057번 : 
https://school.programmers.co.kr/learn/courses/30/lessons/60057
"""
def solution(s):
    slen = len(s)
    result = slen

    #문자를 절반만큼 짜르면 된다.
    for i in range (1, slen//2 + 1):
        cut = s[0:i]
        count = 1
        tplist = ""
        for j in range (i, slen, i):
            if cut == s[j:j+i]:
                count += 1   
            else:
                tplist += str(count) + cut if count > 1 else cut
                cut = s[j:j+i]
                count = 1 
        tplist += str(count) +cut if count > 1 else cut
        result = min (result, len(tplist))
    answer = result
    return answer
"""
피드백 : 
	 1. 문자열을 찾지 못하였을 경우에도
	 pointer += i 를 해줘야함. (find_ch 만큼 값이 커져야 하니까)
	
	 2. for 문에서 s_len//2 + 1 을 해줘야함, 
		그래야 그 부분까지 체크하니까 
		
	 3. pointer 을 초기 설정할 때, 문자열 크기만큼 설정해줘야 하니
		pointer = i 로 해줘야함
		
	 4. 파이썬에서 d = "123" 이라 하였을 때
d[1:20] 을 해줘도 알아서 리스트 만큼 짤라즘

 << 피드백 >>
	 1. 파이썬에서 리스트를 자를 때, 범위가 넘어가도 짤린다.
		ex) li = "123123"
			print(li[2:40]) 해도 컴파일된다.
			
	 2. 나머지를 처리할 때, for문을 나와서 한 번 더 처리해주면 된다.
	
	 3. 제시문을 잘보자!

"""
