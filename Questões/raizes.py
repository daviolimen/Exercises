from math import sqrt

def main():
    n = int(input())
    lista = list(map(float, input().split()))
    for num in lista:
        resposta = sqrt(num)
        print('{:.4f}'.format(resposta))
        

if __name__ == '__main__':
    main()