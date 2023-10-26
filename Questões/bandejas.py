def main():
    n = int(input())
    copos = 0
    for _ in range(n):
        l, c = map(int, input().split())
        if l > c:
            copos += c
    print(copos)

if __name__ == '__main__':
    main()