def main():
    n = int(input())
    secoes = list(map(int, input().split()))
    soma_total = sum(secoes)
    soma_parcial = 0
    for i in range(n):
        soma_parcial += secoes[i]
        if soma_parcial == (soma_total - soma_parcial):
            print(i + 1)
            return

if __name__ == '__main__':
    main()