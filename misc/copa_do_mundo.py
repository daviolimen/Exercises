def main():
    times = 'ABCDEFGHIJKLMNOP'
    times2 = ''
    for i in range(0, 16, 2):
        m, n = map(int, input().split())
        string = times[i:i+2]
        if m > n:
            times2 += string[0]
        else:
            times2 += string[1]
    times = ''
    for i in range(0, 8, 2):
        m, n = map(int, input().split())
        string = times2[i:i+2]
        if m > n:
            times += string[0]
        else:
            times+= string[1]
    times2 = ''
    for i in range(0, 4, 2):
        m, n = map(int, input().split())
        string = times[i:i+2]
        if m > n:
            times2 += string[0]
        else:
            times2 += string[1]
    m, n = map(int, input().split())
    if m > n:
        print(times2[0])
    else:
        print(times2[1])

if __name__ == '__main__':
    main()