from collections import deque

def solution(prices):
    answer = []
    q = deque(prices)
    while q:
        price = q.popleft()
        count = 0
        for item in q:
            count += 1
            if price>item:
                break
        answer.append(count)
    return answer

