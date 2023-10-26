def main():
    risada = input()
    vogais = 'aeiou'
    vogais_risada = ''
    for letra in risada:
        if letra in vogais:
            vogais_risada += letra
    if vogais_risada == vogais_risada[::-1]:
        print('S')
        return
    print('N')

if __name__ == '__main__':
    main()