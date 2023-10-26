def main():
    matriz = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    maior = -1 * 10**6
    for i in range(3):
        for j in range(3):
            matriz[i][j] = int(input())
            if matriz[i][j] > maior:
                maior = matriz[i][j]
    for i in range(3):
        for j in range(3):
            if matriz[i][j] == maior:
                matriz[i][j] = -1
    for row in matriz:
        print(row[0], row[1], row[2])

if __name__ == '__main__':
    main()