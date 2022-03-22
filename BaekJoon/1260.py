
def main():
    print('Problem 1260 starting... Enter your input: ')
    N, M, startingNum = map(int, input().split())
    list = [[None for _ in range(2)] for _ in range(M)]
    dfs = []
    bfs = []
    for i in range(M):
        temp1, temp2 = map(int, input().split())
        list[i][0] = temp1
        list[i][1] = temp2
    dfs.append(startingNum)
    while len(dfs)!=M:
        if(startingNum not in dfs):
            dfs.append(findConnectedVertex(startingNum, list))
    print(dfs)
        
def findConnectedVertex(target, list):
    return_value = []
    for i in range(len(list)):
        if(list[i][0]==target):
            return_value.append(list[i][1])
        elif(list[i][1]==target): 
            return_value.append(list[i][0])
    return findMinInList(return_value)

def findMinInList(list):
    return_value = list[0]
    for item in list:
        if(return_value>item):
            return_value = item
    return return_value

def mainn():
    target = 4
    list2 = [[1,2],[1,3],[1,4],[2,4],[3,4]]
    print(findTargets(target,list2))

if __name__ == '__main__':
    main()