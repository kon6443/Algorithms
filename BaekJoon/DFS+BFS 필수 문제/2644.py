from collections import deque

def printGraph(graph):
    for i in range(1,len(graph)):
        print(i,':',graph[i])

n = int(input())
x, y = map(int ,input().split())
m = int(input())

graph = [[] for _ in range(n+1)]
visited = [0] * (n+1)
count = 0

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

# printGraph(graph)

def bfs(x):
    q = deque([])
    q.append(x)
    visited[x] = 1
    while q:
        v = q.popleft()
        for item in graph[v]:
            if visited[item] == 0:
                visited[item] = visited[v] + 1
                # print(visited[item])
                q.append(item)

bfs(x)
print((visited[y]-1) if (visited[y]!=0) else (-1))
