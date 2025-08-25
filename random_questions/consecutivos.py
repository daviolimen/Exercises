def main():
    n = int(input())
    arr = input().split()
    atual = arr[0]
    contador = 0
    maior_contador = 0
    for num in arr:
        if num == atual:
            contador += 1
        else:
            if contador > maior_contador:
                maior_contador = contador
            contador = 1
            atual = num
    if contador > maior_contador:
        maior_contador = contador
    print(maior_contador)

if __name__ == '__main__':
    main()
