def main():
    n = int(input())
    matriz = []
    for _ in range(n):
        row = list(map(int, input().split()))
        matriz.append(row)
    soma = sum(matriz[0])
    for row in matriz:
        if sum(row) != soma:
            print(-1)
            return
    for i in range(n):
        column_sum = 0
        for row in matriz:
            column_sum += row[i]
        if column_sum != soma:
            print(-1)
            return
    
    diagonal_sum1, diagonal_sum2 = 0, 0
    for i in range(n):
        diagonal_sum1 += matriz[i][i]
        diagonal_sum2 += matriz[i][n - 1 - i]
    if diagonal_sum1 != soma or diagonal_sum2 != soma:
        print(-1)
        return
    print(soma)
    return
if __name__ == '__main__':
    main()