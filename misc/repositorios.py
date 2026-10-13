def main():
    c, n = map(int, input().split())
    instalados = {}
    novos = {}
    for _ in range(c):
        p, v = map(int, input().split())
        instalados[p] = v
    for _ in range(n):
        p, v = map(int, input().split())
        if p not in novos.keys():
            novos[p] = set()
        novos[p].add(v)
    for program, versions in novos.items():
        best_version = max(versions)
        if program in instalados.keys():
            if best_version > instalados[program]:
                print(f"{program} {best_version}")
        else:
            print(f"{program} {best_version}")


if __name__ == '__main__':
    main()