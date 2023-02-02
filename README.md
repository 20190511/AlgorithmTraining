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
<br>7-A. DP 정리
---
## 그래프 (Graph)
### 다익스트라 (Dijkstra)
1. [최소비용 구하기2](https://www.acmicpc.net/problem/11779) : [BOJ-11779](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC/BOJ-11779.py)
2. [최단경로](https://www.acmicpc.net/problem/1753) : [BOJ-1753](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC/BOJ-1753.py)
3. [트리의 지름](https://www.acmicpc.net/problem/1167) : [BOJ-1167](https://github.com/20190511/AlgorithmTraining/blob/main/%EA%B7%B8%EB%9E%98%ED%94%84/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC/BOJ-1167.py)
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
---
## 탐색 (Searching)
### BFS (Breadth Find Searching)
1. [토마토](https://www.acmicpc.net/problem/7576) : [BOJ-7576](https://github.com/20190511/AlgorithmTraining/blob/main/%ED%83%90%EC%83%89/BFS/BOJ-7576.py)
2. [불!](https://www.acmicpc.net/problem/4179) : [BOJ-4179](https://github.com/20190511/AlgorithmTraining/blob/main/%ED%83%90%EC%83%89/BFS/BOJ-4179.py)
3. [아기 상어](https://www.acmicpc.net/problem/16236) : [BOJ-16236](https://github.com/20190511/AlgorithmTraining/blob/main/%ED%83%90%EC%83%89/BFS/BOJ-16236.py)
### DFS (Depth Find Searching)
1. [청소년 상어](https://www.acmicpc.net/problem/19236) : [BOJ-19236](https://github.com/20190511/AlgorithmTraining/blob/main/%ED%83%90%EC%83%89/DFS/BOJ-19236.py)
2. [연구소](https://www.acmicpc.net/problem/14502) : [BOJ-14502(combinations)](https://github.com/20190511/AlgorithmTraining/blob/main/%ED%83%90%EC%83%89/DFS/BOJ-14502.py), [BOJ-14502(재귀함수)](https://github.com/20190511/AlgorithmTraining/blob/main/%ED%83%90%EC%83%89/DFS/BOJ-14502(%EC%9E%AC%EA%B7%80%ED%95%A8%EC%88%98).py)
---
