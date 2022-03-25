from operator import itemgetter
import math

fees = [180, 5000, 10, 600]
records = ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]

def strToMin(time):
    h, m = time.split(':')
    h = int(h) * 60
    m = int(m)
    return h+m

# r = [[] for _ in range(len(records))]
# for i in range(len(records)):
#     time, plate, history = records[i].split(' ')
#     r[i].append(strToMin(time))
#     r[i].append(plate)
#     r[i].append(history)
# sortedList = sorted(r, key=itemgetter(1)) 

# print2DList(sortedList)

d = dict()
for item in records:
    time, plate, history = item.split(' ')
    if plate in d:
        d[plate].append([strToMin(time), history])
        # print(plate,':', d[plate])
    else:
        d[plate] = [[strToMin(time), history]]
        # print(plate, 'registered.')

rList = list(d.items())
rList.sort()

answer = []
# default time, default fee, unit time, unit fee
dt, df, ut, uf = fees
for vehicle in rList:  # rotating vehicles using for loops
    t = 0
    for action in vehicle[1]:
        #subtracting for in action and adding for out action
        if action[1] == "IN": 
            t -= action[0] # subtract time for in action
        else: 
            t += action[0] # adding time for out
    if vehicle[1][-1][1] == "IN": # if the last action was IN
        t += strToMin('23:59') # exiting at 23:59
    if t <= dt: 
        answer.append(df)
    else: 
        answer.append(df + math.ceil((t-dt) / ut) * uf)
print(answer)
