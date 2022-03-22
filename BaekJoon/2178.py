
def main():
    n, m = map(int, input().split())
    list = [[] for _ in range(n)]
    for i in range(n):
        temp = int(input())
        list[i].append(temp)
    for i in range(n):
        print(list[i])

if __name__ == '__main__':
    main()