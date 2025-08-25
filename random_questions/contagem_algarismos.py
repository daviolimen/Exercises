from collections import Counter

def main():
    n = int(input())
    string = ''
    for _ in range(n):
        string += input()
    contador = {i : 0 for i in range(0, 10)}
    contador = Counter(contador)
    contador.update(string)
    for i in range(0, 10):
        print(f'{i} - {contador[str(i)]}')

if __name__ == '__main__':
    main()