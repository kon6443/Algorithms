def solution(n, times):
    answer = 0
    left = min(times)
    right = max(times)*n
    # Looping is done when left is greater than right.
    # It means mid=avg(min+max) has been decided.
    # Therefore, no more searching.
    while left<=right:
        mid = (left+right) // 2
        est = 0
        for time in times:
            est += mid//time
            if est>=n:
                # temporary answer, not done yet.
                answer = mid
                right = mid - 1
                break
        # at the end of ONE looping, 
        # but estimated people is still less than var n.
        if est<n:
            left = mid + 1
    return answer