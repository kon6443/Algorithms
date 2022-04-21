def solution(brown, yellow):
    sum = brown + yellow
    for height in range(1, sum+1):
        if (sum%height)==0:
            width = sum/height
            if width>=height and brown==2*width+2*height-4:
                return [width, height]