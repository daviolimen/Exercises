def main():
    n = int(input())
    tabuleiro = [list(map(int, input().split())) for _ in range(n)]
    pesos = set()
    somas_linhas = []
    for i in range(n):
        soma_linha = sum(tabuleiro[i])
        somas_linhas.append(soma_linha)
    somas_colunas = []
    for i in range(n):
        soma_coluna = sum(tabuleiro[x][i] for x in range(n))
        somas_colunas.append(soma_coluna)
    for i in range(n):
        for j in range(n):
            peso = somas_linhas[i] + somas_colunas[j] - 2 * tabuleiro[i][j]
            pesos.add(peso)
    print(max(pesos))

if __name__ == '__main__':
    main()