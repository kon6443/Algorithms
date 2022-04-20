def dfs(numbers, target):
    if len(numbers)==0 and target==0:
        return 1
    elif len(numbers)==0:
        return 0
    else:
        answer = 0
        answer += dfs(numbers[:-1], target+numbers[-1])
        answer += dfs(numbers[:-1], target-numbers[-1])
        return answer
    
def solution(numbers, target):
    answer = dfs(numbers, target)
    return answer