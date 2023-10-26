def main():
    a = False
    b = False
    input()
    comandos = list(map(int, input().split()))
    for comando in comandos:
        if comando == 1:
            a = not a
        else:
            a = not a
            b = not b
    print(1 if a else 0)
    print(1 if b else 0)

if __name__ == '__main__':
    main()