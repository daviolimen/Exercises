def main():
    n = int(input())
    resposta = 0
    for _ in range(n):
        x1, y1, x2, y2 = map(int, input().split())
        dx = abs(x2 - x1)
        dy = abs(y2 - y1)
        resposta += dx**2 + dy**2
    print(resposta)

if __name__ == '__main__':
    main()