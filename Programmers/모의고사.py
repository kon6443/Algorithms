def solution(answers):
    answer = []
    student_answers = [
        [1,2,3,4,5],
        [2,1,2,3,2,4,2,5,],
        [3,3,1,1,2,2,4,4,5,5]
    ]
    temp0 = temp1 = temp2 = 0
    answer_sheet = [0,0,0]
    for item in answers:
        if item == student_answers[0][temp0%len(student_answers[0])]:
            answer_sheet[0] += 1
        temp0 +=1 
        if item == student_answers[1][temp1%len(student_answers[1])]:
            answer_sheet[1] += 1
        temp1 +=1 
        if item == student_answers[2][temp2%len(student_answers[2])]:
            answer_sheet[2] += 1
        temp2 +=1 
    maxNum = max(answer_sheet)
    for i in range(len(answer_sheet)):
        if answer_sheet[i] == maxNum:
            answer.append(i+1)
    return answer