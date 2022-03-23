from collections import deque
    # for i in range(n):
    #     maze.append(list(input()))
    #     for j in range(m):
    #         maze[i][j] = int(maze[i][j])

def main():
    n, m = map(int, input().split())
    maze = []
    # getting inputs, spliting and coverting to int type
    for _ in range(n):
        maze.append(list(map(int, input())))
    dx = [-1, 0, 1, 0]
    dy = [0, -1, 0, 1]
    attendance = [[0] * m for _ in range(n)]
    q = deque([(0, 0)]) # deque([(0, 0)])
    # assign the first location as 1 using given information from the problem.
    attendance[0][0] = 1
    while q:
        x, y = q.popleft()
        # print out the final value once get destination.
        if x == n-1 and y == m-1:
            print(attendance[x][y])
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            # when new x and y locations are inside of the maze
            if 0 <= nx < n and 0 <= ny < m: 
                # next location is not explored and not a wall
                if attendance[nx][ny] == 0 and maze[nx][ny] == 1:
                    # adding up current steps and + 1 as well
                    attendance[nx][ny] = attendance[x][y] + 1
                    q.append((nx, ny))

def print2DList(maze):
    for i in range(len(maze)):
        for j in range(len(maze[0])):
            print(maze[i][j], end=' ')

if __name__ == '__main__':
    main()