
def main():
    n = int(input())
    square = []
    for _ in range(n):
        square.append(list(map(int, input())))

    print2DList(square)

def print2DList(l):
    for i in range(len(l)):
        for j in range(len(l[0])):
            print(l[i][j], end=' ')
        print()

if __name__ == '__main__':
    main()