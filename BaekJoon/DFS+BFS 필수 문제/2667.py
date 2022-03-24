
def dfs(x, y):
    global visited, numOfApt
    numOfApt = numOfApt + 1
    visited[x][y] = 1
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0<=nx<len(square) and 0<=ny<len(square):
            if visited[nx][ny] == 0 and square[nx][ny] == 1:
                dfs(nx,ny)

n = int(input())
visited = [[0]*(n) for _ in range(n)]
square = []
for _ in range(n):
    square.append(list(map(int, input())))
# up, down, left, right
dy = [1, -1, 0, 0]
dx = [0, 0, -1, 1]
numOfApt = 0
aptList = []
for i in range(n):
    for j in range(n):
        if square[i][j] == 1 and visited[i][j] == 0:
            dfs(i, j)
            aptList.append(numOfApt)
            numOfApt = 0
aptList.sort()

print(len(aptList))
for i in range(len(aptList)):
    print(aptList[i])
