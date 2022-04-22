def solution(m, n, puddles):
    answer = 0
    maps = [[1]*m for _ in range(n)]
    distance = [[0]*m for _ in range(n)]
    for item in puddles:
        x, y = map(int, item)
        maps[y-1][x-1] = 0
    distance[0][0] = 1
    for i in range(n):
        for j in range(m):
            if maps[i][j]==0:
                continue
            elif maps[i][j]==1 and distance[i][j]==0:
                distance[i][j]=distance[i-1][j]+distance[i][j-1]
    answer = distance[-1][-1] % 1000000007
    return answer