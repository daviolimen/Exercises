def main():
    palavra = input()
    consoantes = 'bcdfghjklmnpqrstvwxyz'
    cifra =      'aaeeeiiiiooooouuuuuuu'
    vogais = 'aeiou'
    resposta = ''
    for letra in palavra:
        if letra in vogais:
            resposta += letra
        else:
            index = consoantes.find(letra)
            resposta += letra
            resposta += cifra[index]
            if index == 20:
                resposta += letra
            else:
                resposta += consoantes[index + 1]
    print(resposta)

if __name__ == '__main__':
    main()