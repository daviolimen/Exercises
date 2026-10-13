def main():
    n, r = map(int, input().split())
    resposta = int((n * (n - 1)) / 2 - r)
    print(resposta)

if __name__ == '__main__':
    main()