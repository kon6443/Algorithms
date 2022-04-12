def print2DList(l):
    for i, item in enumerate(l):
        print(i,':[',end='')
        for j in range(len(l[i])):
            print(l[i][j], end=' ')
        print(']')

def dfs(ith, attendance, computers):
    for i in range(len(computers)):
        if computers[ith][i]==1 and attendance[i]==False:
            attendance[i] = True
            dfs(i, attendance, computers)

def solution(n, computers):
    answer = 0
    attendance = [False] * n
    for ith in range(n):
        if attendance[ith] == False:
            attendance[ith] = True
            answer += 1
            dfs(ith, attendance, computers)
    return answer