import heapq

def solution(scoville, K):
    answer = 0
    h = []
    heapq.heapify(h)
    for food in scoville:
        heapq.heappush(h, food)
    while h[0]<K:
        try:
            heapq.heappush(h, heapq.heappop(h) + 2*(heapq.heappop(h)))
        except IndexError:
            return -1
        answer += 1
    return answer

