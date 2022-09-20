def printDictionary(d):
    for key in d:
        print(key,': ',d[key])

def solution(clothes):
    d = {}
    for item in clothes:
        if item[1] in d:
            d[item[1]].append(item[0]) 
        else:
            d[item[1]] = [item[0]]
    l = []
    for key in d:
        l.append(len(d[key])+1)
    answer = 1
    for item in l:
        answer *= item
    # get rid of the case that is all clothes are not put on
    return answer-1