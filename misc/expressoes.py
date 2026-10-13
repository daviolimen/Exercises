def main():
    t = int(input())
    for _ in range(t):
        a = input()
        lista = []
        for c in a:
            if c in ('(', '[', '{'):
                lista.append(c)
            else:
                if not lista:
                    print('N')
                    break
                ida = lista.pop()
                if ((ida == '(' and c == ')') or (ida == '[' and c == ']') or (ida == '{' and c == '}')):
                    continue
                print('N')
                break
        else:
            if not lista:
                print('S')
            else:
                print('N')


if __name__ == '__main__':
    main()
