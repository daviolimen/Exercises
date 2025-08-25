def main():
    n, m = map(int, input().split())
    paises = [[i, 0, 0, 0] for i in range(1, n + 1)]
    for _ in range(m):
        o, p, b = map(int, input().split())
        paises[o - 1][1] += 1
        paises[p - 1][2] += 1
        paises[b - 1][3] += 1
    paises.sort(key=lambda x : 1010101 * x[1] + 10101 * x[2] + 101 * x[3] - x[0], reverse=True)
    for pais in paises:
        print(pais[0], end=' ')

if __name__ == '__main__':
    main()