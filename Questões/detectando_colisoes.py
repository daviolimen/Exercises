def main():
    x = [[0, 0], [0, 0]]
    y = [[0, 0], [0, 0]]
    x[0][0], y[0][0], x[0][1], y[0][1] = map(int, input().split())
    x[1][0], y[1][0], x[1][1], y[1][1] = map(int, input().split())
    if (x[0][1] < x[1][0] or x[1][1] < x[0][0] or y[0][1] < y[1][0] or y[1][1] < y[0][0] or x[0][0] > x[1][1] or x[1][0] > x[0][1] or y[0][0] > y[1][1] or y[1][0] > y[0][1]):
        print(0)
    else:
        print(1)

if __name__ == '__main__':
    main()