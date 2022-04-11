def dfs(numbers, target):
    if len(numbers)==0 and target==0:
        return 1
    elif len(numbers)==0:
        return 0
    else:
        res = 0
        res += dfs(numbers[:-1], target+numbers[-1])
        res += dfs(numbers[:-1], target-numbers[-1])
        return res
    
def solution(numbers, target):
    answer = dfs(numbers, target)
    return answer