from collections import defaultdict

def printDictList(dict):
    for key in dict:
        print(key,':', end=' ')
        for value in dict[key]:
            print(value, end=' ')
        print()
    print()

def makeDict(tickets):
    routes = defaultdict(list)
    for departure, arrival in tickets:
        routes[departure].append(arrival)
    return routes

def dfs(routes):
    stack = ["ICN"] # Initial airport code
    path = []
    while len(stack) > 0:
        top = stack[-1]
        # top is not in routes or there is not routes[top]
        if top not in routes or len(routes[top]) == 0:
            path.append(stack.pop())
        else: # top is in routes or len(routes[top])>0
            stack.append(routes[top].pop(0))
    return path[::-1]
    
def solution(tickets):
    answer = []
    
    # tickets into dictionary 
    routes = makeDict(tickets)

    # sorting routes
    for r in routes:
        routes[r].sort()
        
    answer = dfs(routes)
    return answer