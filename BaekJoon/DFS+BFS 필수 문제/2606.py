from collections import deque

def main():
    global infected, graph, q
    graph = [[] for _ in range(c+1)]
    infected = [False] * (c+1)
    c = int(input())
    p = int(input())
    for _ in range(p):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    print(bfs(1))
    

def bfs(n):
    q = deque([])
    q.append(n)
    infected[n] = True
    answer = 0
    while q:
        v = q.popleft()
        for item in graph[v]:
            if not infected[item]:
                q.append(item)
                infected[item] = True
                answer = answer + 1
    return answer

def printAdjacencyList(list):
    print('Printing out adjacency list...')
    for i in range(1, len(list)):
        print(list[i])

if __name__ == '__main__':
    main()