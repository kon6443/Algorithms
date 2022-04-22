genres = ["classic", "pop", "classic", "classic", "pop", "K"]
plays = [500, 600, 150, 800, 2500, 300]

def solution(genres, plays):
    answer = []
    d = {} # hash
    dN = {} # for calculating genres rank

    # assigning into dictionary
    for i in range(len(genres)):
        if genres[i] in d:
            d[genres[i]].append((plays[i], i))
            dN[genres[i]] += plays[i]
        else:
            d[genres[i]] = [(plays[i], i)]
            dN[genres[i]] = plays[i]

    # sorting in descending order for genres rank popularity.
    rank = sorted(dN, key=lambda x:dN[x], reverse=True)

    # getting item(genres) in descending order.
    for item in rank:
        # sorting songs based on the number of plays in descending order.
        temp = sorted(d[item], key=lambda x:(x[0],-x[1]), reverse=True)
        # printing twice only.
        for i in range(2):
            answer.append(temp[i][1])
            # if a particular genre has only one song, break the loop.
            if len(d[item])<2: break
    return answer

print('my answer: ', solution(genres, plays))
print('answer should be: [4, 1, 3, 0, 5]')