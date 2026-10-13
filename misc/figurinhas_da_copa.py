def main():
    n, c, m = map(int, input().split())
    carimbadas = set(input().split())
    compradas = set(input().split())
    print(len(carimbadas.difference(compradas)))


if __name__ == '__main__':
    main()
