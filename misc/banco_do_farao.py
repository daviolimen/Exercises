from sys import maxsize


def solve(array):
    size = len(array)
    maior_soma = -maxsize
    maior_tamanho = 0
    for i in range(size):
        for j in range(i + 1, size + 1):
            subarr = array[i:j]
            soma = sum(subarr)
            if soma > maior_soma:
                maior_soma = soma
                tamanho = len(subarr)
                maior_tamanho = tamanho
            if soma == maior_soma:
                tamanho = len(subarr)
                if tamanho > maior_tamanho:
                    maior_tamanho = tamanho
    return (maior_soma, maior_tamanho)


def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        saldos = list(map(int, input().split()))
        q = int(input())
        for j in range(q):
            a, b = map(int, input().split())
            intervalo = saldos[a - 1:b]
            resposta = solve(intervalo)
            print(resposta[0], resposta[1])


if __name__ == '__main__':
    main()
