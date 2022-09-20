def solution(priorities, location):
    answer = 1
    while priorities:
        if location == 0 and priorities[location] == max(priorities):
            priorities = priorities[1:]
            break
        elif priorities[0] == max(priorities):
            priorities = priorities[1:]
            location -= 1
            if location<0:
                location = len(priorities)-1
            answer += 1
        else:
            cursor = priorities[0]
            priorities = priorities[1:]
            priorities.append(cursor)
            location -= 1
            if location<0:
                location = len(priorities)-1
    return answer

