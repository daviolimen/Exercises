from collections import Counter

def main():
    n = int(input())
    letras = 'abcdefghijklmnopqrstuvwxyz'
    a = input()
    b = input()
    listA = [char for char in a if char in letras]
    listB = [char for char in b if char in letras]
    listA.sort()
    listB.sort()
    if listA == listB:
        print('S')
    else:
        print('N')

if __name__ == '__main__':
    main()