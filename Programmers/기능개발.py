import math

def solution(progresses, speeds):
    answer = []
    requiredDays = []
    for i in range(len(progresses)):
        requiredDays.append(math.ceil((100-progresses[i])/speeds[i]))
    while True:
        if len(requiredDays)<=0: break
        # Subtracting ith value from every element in requiredDays list
        requiredDays = [x - abs(requiredDays[0]) for x in requiredDays]
        numOfPublish = 0
        for i in range(len(requiredDays)):
            if requiredDays[i]<=0:
                numOfPublish += 1
            else: break
        requiredDays = requiredDays[numOfPublish:]
        answer.append(numOfPublish)
    return answer

