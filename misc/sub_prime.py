def main():
    b, n = map(int, input().split())
    while (b != 0):
        reservas = [int(x) for x in input().split()]
        divida = [0 for _ in range(b)]
        for _ in range(n):
            d, c, v = map(int, input().split())
            divida[d - 1] += v
            divida[c - 1] -= v
        for i in range(b):
            if reservas[i] >= divida[i]:
                continue
            else:
                print('N')
                break
        else:
            print('S')
        b, n = map(int, input().split())

if __name__ == '__main__':
    main()