"""
교훈 : 동시에 진행되는 그래프는 (BFS 겨우 제외, 시뮬레이션 그래프의 경우)
실시간으로 업데이트 하지 말고
time 별로 그래프를 돌린 후 업데이트를 하자

"""
import sys
input = sys.stdin.readline

#size,shart,smell_time
n,m,k = map(int,input().split())
graph = []
time_graph = [[[0,0] for _ in range(n)] for _ in range(n)]
shark_pos = [[-1,-1] for i in range(m+1)] #상어위치.

for i in range(n):
    lists = list(map(int,input().split()))
    graph.append(lists)
    for j in range(n):
        if lists[j]>0:
            time_graph[i][j] = [lists[j],1]
            shark_pos[lists[j]] = [i,j]
        
# up,down,left,right
di = [(0,0),(-1,0),(1,0),(0,-1),(0,1)]

shark_di = list(map(int,input().split()))
shark_di.insert(0,0)
shark_count = m


rule = []
for i in range(m):
    rule.append([])
    for j in range(4):
        rule[i].append([])
        rule[i][j] = list(map(int,input().split()))
    rule[i].insert(0,[])
rule.insert(0,[])


def gprint(graph):
    for i in range(n):
        for j in range(n):
            print(graph[i][j], end=" ")
        print()
    print()

def move(node,posx,posy,time):
    global shark_count
    direct = shark_di[node]
    px,py = posx,posy
    for item in rule[node][direct]:
        nx,ny = px+di[item][0],py+di[item][1]
        if 0<=nx<n and 0<=ny<n:
            #empty가 1개라도 있는가?
            tm = time-time_graph[nx][ny][1]
            if time_graph[nx][ny][1] != 0 and (0 < tm <=k):
                continue
            """
            if tm == 0 and time_graph[nx][ny][0] < node:
                shark_pos[node] = [-1,-1]
                shark_count -= 1 
                return
            time_graph[nx][ny][0] = node
            time_graph[nx][ny][1] = time
            if tm == 0 and time_graph[nx][ny][0] > node:
                shark_pos[time_graph[nx][ny][0]] = [-1,-1]
                shark_count -= 1 
            """
            shark_pos[node] = [nx,ny]
            shark_di[node] = item
            return
        
    for item in rule[node][direct]:
        nx,ny = px+di[item][0],py+di[item][1]
        if 0<=nx<n and 0<=ny<n:
            # 자신의 냄새
            tm = time-time_graph[nx][ny][1]
            if 0<tm<=k and (time_graph[nx][ny][0] == node):
                """
                time_graph[nx][ny][0] = node
                time_graph[nx][ny][1] = time
                """
                shark_pos[node] = [nx,ny]
                shark_di[node] = item
                return
    print(time_graph)
    
def simul():
    global shark_count
    t = 2
    #t<1001
    while t<1003:
        shark_len = len(shark_pos)
        if shark_count == 1:
            return t-2
            break
        for x in range(1, shark_len):
            posx, posy = shark_pos[x]
            if posx == -1:
                continue
            move(x,posx,posy,t)
        
        for x in range(1,shark_len):
            posx,posy = shark_pos[x]
            if posx == -1:
                continue
            if time_graph[posx][posy][1] == t and time_graph[posx][posy][0] < x:
                shark_pos[x] = [-1,-1]
                shark_count -= 1 
            else:
                time_graph[posx][posy][0] = x
                time_graph[posx][posy][1] = t
        t += 1 
    return -1
            
print(simul())


            
