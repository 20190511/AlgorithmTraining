# AlgorithmTraining
# 백준 및 프로그래머스 풀이 모음집
---
# 문제집 
1. [DFS/DFS](https://www.acmicpc.net/workbook/view/7313)
2. [시뮬레이션(구현)](https://www.acmicpc.net/workbook/view/7316)
3. [DP](https://www.acmicpc.net/workbook/view/7319), [DP2](https://www.acmicpc.net/problemset?sort=ac_desc&algo=25)
4. [다익스트라](https://www.acmicpc.net/workbook/view/10433), [벨만포드](https://www.acmicpc.net/workbook/view/1602), [플로이드-워샬](https://www.acmicpc.net/workbook/view/10318)
5. [그래프](https://www.acmicpc.net/workbook/view/9562), [크루스칼](https://www.acmicpc.net/workbook/view/9907), [위상 정렬](https://www.acmicpc.net/workbook/view/9738)
6. [그리디](https://www.acmicpc.net/workbook/view/7320)
---
## Dynamic Programming (DP)
0. [합이 가장 큰 부분수열](https://github.com/20190511/AlgorithmTraining/blob/main/DP/%ED%95%A9%EC%9D%B4%EA%B0%80%EC%9E%A5%ED%81%B0%EB%B6%80%EB%B6%84%EC%88%98%EC%97%B4.py)
1. [LCS](https://www.acmicpc.net/problem/9251) : [BOJ-9251](https://github.com/20190511/AlgorithmTraining/blob/main/DP/BOJ-9251.py)
2. [동전](https://www.acmicpc.net/problem/9084) : [BOJ-9084](https://github.com/20190511/AlgorithmTraining/blob/main/DP/BOJ-9084.py) 
3. [동전1](https://www.acmicpc.net/problem/2293) : [BOJ-2293](https://github.com/20190511/AlgorithmTraining/blob/main/DP/BOJ-2293.py)
4. [동전2](https://www.acmicpc.net/problem/2294) : [BOJ-2294](https://github.com/20190511/AlgorithmTraining/blob/main/DP/BOJ-2294.py)
5. [가장 긴 증가하는 부분 수열4](https://www.acmicpc.net/problem/14002) : [BOJ-14002](https://github.com/20190511/AlgorithmTraining/blob/main/DP/BOJ-14002.py)
6. [가장 큰 정사각형](https://www.acmicpc.net/problem/1915) : [BOJ-1915](https://github.com/20190511/AlgorithmTraining/blob/main/DP/BOJ-1915.py)
7. [팰린드롬?](https://www.acmicpc.net/problem/10942) : [BOJ-10942](https://github.com/20190511/AlgorithmTraining/blob/main/DP/BOJ-10942.py)
8. [★색상환](https://www.acmicpc.net/problem/2482) : [BOJ-2482](https://github.com/20190511/AlgorithmTraining/blob/main/DP/BOJ-2482.py)
9. [자두나무](https://www.acmicpc.net/problem/2240) : [BOJ-2240](https://github.com/20190511/AlgorithmTraining/blob/main/DP/BOJ-2240.py)
10. [암호코드](https://www.acmicpc.net/problem/2011) : [BOJ-2011](https://github.com/20190511/AlgorithmTraining/blob/main/DP/BOJ-2011.py)
11. [욕심쟁이 판다:DFS+memoization (최장길이)](https://www.acmicpc.net/problem/1937) : [BOJ-1937](https://github.com/20190511/AlgorithmTraining/blob/main/DP/BOJ-1937.py)
12. [내리막 길:DFS+memoization (경로 수)](https://www.acmicpc.net/problem/1520) : [BOJ-1520](https://github.com/20190511/AlgorithmTraining/blob/main/DP/BOJ-1520.py)
13. [내리막길: DFS+Memoization](https://www.acmicpc.net/problem/1520): [BOJ-1520](https://github.com/20190511/AlgorithmTraining/blob/main/DP/BOJ-1520.cpp)
      ```Text
      해당 문제는 매우 좋은 문제이다.
      내리막길의 경로의 수를 총합해서 구해줘야한다.

      해당 문제의 아이디어는 재귀호출 시 자동으로 메모이제이션 기능을 활용할 수 있다는 점에 있다.
      >> dp 를 모두 -1 로 초기화 해준다
      >> -1 이면 초기값이므로 DFS 진행, -1이 아닌 0이상의 수라면 경로이므로 계속 탐색을 한다..
      >> dp[x][y] += dfs(x,y); 형태로 이전에 왔던 길을 기록해둔다. (Memoization) 활용.
      ```
14. []
<br>7-A. DP 정리
---
## 그래프 (Graph)
### 다익스트라 (Dijkstra)
1. [최소비용 구하기2](https://www.acmicpc.net/problem/11779) : [BOJ-11779](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC/BOJ-11779.py)
2. [최단경로](https://www.acmicpc.net/problem/1753) : [BOJ-1753](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC/BOJ-1753.py)
3. [트리의 지름](https://www.acmicpc.net/problem/1167) : [BOJ-1167](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC/BOJ-1167.py)
4. [특별한 최단 경로](https://www.acmicpc.net/problem/1504) : [BOJ-1504](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC/BOJ-1504.cpp)
5. [알고스팟](https://www.acmicpc.net/problem/1261) : [BOJ-1261](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC/BOJ-1261.cpp)
6. [파티](https://www.acmicpc.net/problem/1238) : [BOJ-1238_C++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC/BOJ-1238.cpp)
7. [녹색 옷 입은 애가 젤다지?](https://www.acmicpc.net/problem/4485) : [BOJ-4485_C++_10분정도걸림](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC/BOJ-4485.cpp)
### 밸만포드 (Bellman-Ford)
1. [오민식의 고민](https://www.acmicpc.net/problem/1219) : [BOJ-1219](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%EB%B0%B8%EB%A7%8C%ED%8F%AC%EB%93%9C/BOJ-1219.py "인접행렬"), [BOJ-1219(2)](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%EB%B0%B8%EB%A7%8C%ED%8F%AC%EB%93%9C/BOJ-1219(2).py "인접리스트Base+인접행렬")
### 플로이드-워샬 (Floyd-Warshall)
1. [플로이드](https://www.acmicpc.net/problem/11404) : [BOJ-11404](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%ED%94%8C%EB%A1%9C%EC%9D%B4%EB%93%9C-%EC%9B%8C%EC%83%AC/BOJ-11404.py)
### 위상정렬 : (Topological)
1. [ARM Craft](https://www.acmicpc.net/problem/1005) : [BOJ-1005](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%EC%9C%84%EC%83%81%EC%A0%95%EB%A0%AC/BOJ-1005.py)
2. [최종 순위](https://www.acmicpc.net/problem/3665) : [BOJ-3665](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%EC%9C%84%EC%83%81%EC%A0%95%EB%A0%AC/BOJ-3665.py)
3. [작업](https://www.acmicpc.net/problem/2056) : [BOJ-2056](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%EC%9C%84%EC%83%81%EC%A0%95%EB%A0%AC/BOJ-2056.py)
### 크루스칼 : (Kruskal)
1. [행성 터널](https://www.acmicpc.net/problem/2887) : [BOJ-2887](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%ED%81%AC%EB%A3%A8%EC%8A%A4%EC%B9%BC/BOJ-2887.py) + [BOJ-2887 간선 최소화 과정 풀이 설명](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%ED%81%AC%EB%A3%A8%EC%8A%A4%EC%B9%BC/BOJ-2887(%ED%96%89%EC%84%B1%20%ED%84%B0%EB%84%90)%20%ED%92%80%EC%9D%B4%EC%A0%95%EB%A6%AC.pdf)
2. [전기가 부족해](https://www.acmicpc.net/problem/10423) : [BOJ-10423](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%ED%81%AC%EB%A3%A8%EC%8A%A4%EC%B9%BC/BOJ-10423.py)
---
## 수학 (math)
1. [벡터 매칭|Combinations+math.sqrt()](https://www.acmicpc.net/problem/1007) : [BOJ-1007](https://github.com/20190511/AlgorithmTraining/blob/main/%EC%88%98%ED%95%99/BOJ-1007.py)
2. [신기한 소수 : 소수판별 root까지](https://www.acmicpc.net/problem/2023) : [BOJ-2023_C++](https://github.com/20190511/AlgorithmTraining/blob/main/%EC%88%98%ED%95%99/BOJ-2023.cpp)
3. [놀이 공원 : SetUnion 문제](https://www.acmicpc.net/problem/1561) : [BOJ-1561](https://github.com/20190511/AlgorithmTraining/blob/main/%EC%88%98%ED%95%99/BOJ-1561.cpp)

---
## 구현 (Realizng)
1. [뱀](https://www.acmicpc.net/problem/3190) : [BOJ-3190](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-3190.py)
2. [럭키스트레이트](https://www.acmicpc.net/problem/18406) : [BOJ-18406](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-18406.py)
3. [치킨배달](https://www.acmicpc.net/problem/15686) : [BOJ-15686](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-15686.py)
4. [문자열압축](https://school.programmers.co.kr/learn/courses/30/lessons/60057) : [PS-60057](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/PS-60057.py)
5. [자물쇠와 열쇠](https://school.programmers.co.kr/learn/courses/30/lessons/60059) : [PS-60059](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/PS-60059.py)
6. [기둥과 보 설치](https://school.programmers.co.kr/learn/courses/30/lessons/60061) : [PS-60061](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/PS-60061.py)
7. [하늘에서 별똥별이 빗발친다](https://www.acmicpc.net/problem/14658) : [BOJ-14658](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-14658.py)
8. [어른 상어](https://www.acmicpc.net/problem/19237) : [BOJ-19237](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-19237.py)
9. [감시](https://www.acmicpc.net/problem/15683) : [BOJ-15683_C++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-15683.cpp)
10. [나무 재테크](https://www.acmicpc.net/problem/16235) : [BOJ-16235_C++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ_16235.cpp)
11. [치즈](https://www.acmicpc.net/problem/2638) : [BOJ-2638_C++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ_2638.cpp)
12. [구슬 탈출2](https://www.acmicpc.net/problem/13460) : [BOJ_13460_c++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ_13460.cpp)
13. [2048(Easy)](https://www.acmicpc.net/problem/12100) : [BOJ-12100_c++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-12100.cpp), [BOJ_12100_c++II](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-12100_2.cpp)
14. [로봇 청소기](https://www.acmicpc.net/problem/14503) : [BOJ-14503_c++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-14503.cpp)
15. [톱니바퀴](https://www.acmicpc.net/problem/14891) : [BOJ-14891_c++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-14891.cpp)
16. [경사로](https://www.acmicpc.net/problem/14890) : [BOJ-14890_c++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-14890.cpp)
17. [사다리 조작](https://www.acmicpc.net/problem/15684) : [BOJ-15684_c++ => 실수 교훈](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-15684.cpp)
18. [드래곤 커브](https://www.acmicpc.net/problem/15685) : [BOJ-15685_c++ => 회전문제에 대한 교훈](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-15685.cpp)
19. [미세먼지 안녕!](https://www.acmicpc.net/problem/17144) : [BOJ-17144_c++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-17144.cpp)
20. [낚시왕](https://www.acmicpc.net/problem/17143) : [BOJ-17143_c++ 좌표이동 관련 구현 테크닉](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-17143.cpp)
21. [이차원 배열과 연산자 오버로딩](https://www.acmicpc.net/problem/17140) : [BOJ-17140_c++ 연산자오버로딩, 범위실수](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-17140.cpp)
22. [게리멘더링 2](https://www.acmicpc.net/problem/17779) : [BOJ-17779_C++ 복잡한 구현 재풀이 추천](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-17779.cpp)
23. [새로운 게임2](https://www.acmicpc.net/problem/17837) : [BOJ-17837](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-17837.cpp)
24. [원판 돌리기](https://www.acmicpc.net/problem/17822) : [BOJ-17822_회전 포인터 풀이 교훈](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-17822.cpp)
25. [주사위 윷놀이](https://www.acmicpc.net/problem/17825) : [BOJ-17825_어려운 구현문제, 실수다수유발](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-17825.cpp)
26. [모노미노도미노2](https://www.acmicpc.net/problem/20061) : [BOJ-20061_c++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-20061.cpp)
27. [스타트 택시](https://www.acmicpc.net/problem/19238) : [BOJ-19238_c++, BFS 탐색에 대한 교훈이 있음](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-19238.cpp)
28. [컨베이어 벨트 위의 로봇](https://www.acmicpc.net/problem/20055) : [BOJ-20055_C++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-20055.cpp)
29. [마법사 상어와 파이어볼](https://www.acmicpc.net/problem/20056) : [BOJ-20056_C++ 실수다수, 문제이해부족](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-20056.cpp)
30. [마법사 상어와 토네이도](https://www.acmicpc.net/problem/20057) : [BOJ-20057_C++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-20057.cpp)
31. [마법사 상어와 파이어스톰](https://www.acmicpc.net/problem/20058) : [BOJ-20058_C++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-20058.cpp)
32. [상어 초등학교](https://www.acmicpc.net/problem/21608) : [BOJ-21608_C++, 연산자오버로딩](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-21608.cpp)
33. [상어 중학교](https://www.acmicpc.net/problem/21609) : [BOJ-21609_C++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-21609.cpp)
34. [마법사 상어와 비바라기](https://www.acmicpc.net/problem/21610) : [BOJ-21610_C++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-21610.cpp)
35. [마법사 상어와 블리자드](https://www.acmicpc.net/problem/21611) : [BOJ-21611_C++(어려운 구현, 문제지문 설명미흡)](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-21611.cpp)
36. [주사위 굴리기 2](https://www.acmicpc.net/problem/23288) : [BOJ-23288_C++_BFS Memoization 팁](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-23288.cpp)
37. [주사위 굴리기](https://www.acmicpc.net/problem/14499) : [BOJ-14499_C++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-14499.cpp)
38. [온풍기 안녕!](https://www.acmicpc.net/problem/23289) : [BOJ-23289_C++_중요한 실수함](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-23289.cpp)
39. [마법사 상어와 복제](https://www.acmicpc.net/problem/23290) : [BOJ_C++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-23290.cpp)
40. [어항 정리](https://www.acmicpc.net/problem/23291) : [BOJ-23291_C++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-23291.cpp)
41. [큐빙](https://www.acmicpc.net/problem/5373) : [BOJ_5373_C++_어려운구현](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-5373.cpp)
42. [벽 부수고 이동하기 3](https://www.acmicpc.net/problem/16933): [BOJ-16933_C++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-16933.cpp)  
  -- BFS에서는 Queue와 for문 특성상 다익스트라처럼 거리체크를 할 필요가 없다. 이는 벽 부시기 알고리즘에서도 통용된다.  
  -- visited[11][1000][1000] 을 visited[10][1000][1000] 으로 두고 틀렸다. 범위 체크에 조금 더 여유를 부리는 것도 좋다.
43. [확장 게임](https://www.acmicpc.net/problem/16920) : [BOJ-16920_C++](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B5%AC%ED%98%84/BOJ-16920.cpp)  
  -- 반복해가며 BFS 를 돌리는 문제인데 시간초과 위험이 있다.  
  -- 마치 경계를 확장해나가는 형태처럼 새롭게 추가되는 녀석들만 추가하면 되었다.  
---
## 탐색 (Searching)
### BFS (Breadth Find Searching)
1. [토마토](https://www.acmicpc.net/problem/7576) : [BOJ-7576](https://github.com/20190511/AlgorithmTraining/blob/main/%ED%83%90%EC%83%89/BFS/BOJ-7576.py)
2. [불!](https://www.acmicpc.net/problem/4179) : [BOJ-4179](https://github.com/20190511/AlgorithmTraining/blob/main/%ED%83%90%EC%83%89/BFS/BOJ-4179.py)
3. [아기 상어](https://www.acmicpc.net/problem/16236) : [BOJ-16236](https://github.com/20190511/AlgorithmTraining/blob/main/%ED%83%90%EC%83%89/BFS/BOJ-16236.py)
4. [적록색맹](https://www.acmicpc.net/problem/10026) : [BOJ-10026_C++](https://github.com/20190511/AlgorithmTraining/blob/main/%ED%83%90%EC%83%89/BFS/BOJ-10026.cpp)
5. [연구소 3](https://www.acmicpc.net/problem/17142) : [BOJ-17142_C++ 조합구현 + 반례처리](https://github.com/20190511/AlgorithmTraining/blob/main/%ED%83%90%EC%83%89/BFS/BOJ-17142.cpp)
6. [벽 부수고 이동하기](https://www.acmicpc.net/problem/2206) : [BOJ_2206_C++ 벽을 부신케이스 vs 안 부시긴 케이스 visit 따로구현](https://github.com/20190511/AlgorithmTraining/blob/main/%ED%83%90%EC%83%89/BFS/BOJ-2206.cpp)
7. [벽 부수고 이동하기2](https://www.acmicpc.net/problem/14442) : [BOJ-14442_c++](https://github.com/20190511/AlgorithmTraining/blob/main/%ED%83%90%EC%83%89/BFS/BOJ-14442.cpp)
### DFS (Depth Find Searching)
1. [청소년 상어](https://www.acmicpc.net/problem/19236) : [BOJ-19236](https://github.com/20190511/AlgorithmTraining/blob/main/%ED%83%90%EC%83%89/DFS/BOJ-19236.py)
2. [연구소](https://www.acmicpc.net/problem/14502) : [BOJ-14502(combinations)](https://github.com/20190511/AlgorithmTraining/blob/main/%ED%83%90%EC%83%89/DFS/BOJ-14502.py), [BOJ-14502(재귀함수)](https://github.com/20190511/AlgorithmTraining/blob/main/%ED%83%90%EC%83%89/DFS/BOJ-14502(%EC%9E%AC%EA%B7%80%ED%95%A8%EC%88%98).py)
3. [테트로미노](https://www.acmicpc.net/problem/14500) : [BOJ-14500](https://github.com/20190511/AlgorithmTraining/blob/main/%ED%83%90%EC%83%89/DFS/BOJ-14500.cpp)
---
