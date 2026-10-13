def main():
    alfabeto = 'abcdefghijklmnopqrstuvwxyz'
    nums = '22233344455566677778889999'
    entrada = input().lower()
    resposta = ''
    for char in entrada:
        if char in alfabeto:
            idx = alfabeto.index(char)
            resposta += nums[idx]
        else:
            resposta += char
    print(resposta)

if __name__ == '__main__':
    main()