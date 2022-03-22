from collections import deque

def main():
    N, M, V = map(int, input().split())
    global graph, visited, queue
    graph = [[] for _ in range(N+1)]
    visited = [False] * (N+1)
    for _ in range(M):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    # sorting a graph
    for i in range(1, N+1):
        graph[i].sort()
    dfs(V)
    visited = [False] * (N+1)
    print()
    bfs(V)
    print()

def bfs(n):
    queue = deque([])
    queue.append(n)
    visited[n] = True
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        for item in graph[v]:
            if not visited[item]:
                queue.append(item)
                visited[item] = True

def dfs(n):
    print(n, end=' ')
    visited[n] = True
    for item in graph[n]:
        if not visited[item]:
            dfs(item)
            
def printAdjacencyList(graph):
    print('printing graph after sorting...')
    for i in range(1, len(graph)):
        print(graph[i])

if __name__ == '__main__':
    main()