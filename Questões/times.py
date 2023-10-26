def main():
    n, t = map(int, input().split())
    jogadores = []
    times = [[] for _ in range(t)]
    for _ in range(n):
        nome, h = input().split()
        h = int(h)
        jogadores.append((h, nome))
    jogadores.sort()
    itr = n - 1
    while itr >= 0:
        for i in range(t):
            if itr < 0:
                break
            times[i].append(jogadores[itr][1])
            itr -= 1
    for time in times:
        time.sort()
    for i in range(t):
        print(f"Time {i + 1}")
        for jogador in times[i]:
            print(jogador)
        print()

if __name__ == '__main__':
    main()  