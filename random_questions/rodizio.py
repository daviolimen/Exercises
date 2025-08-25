def main():
    p, n = map(int, input().split())
    carnes = []
    for _ in range(n):
        peso, prot = map(int, input().split())
        carnes.append((peso, prot))
    carnes.sort(key=lambda x : x[1] / x[0] if x[0] else 0, reverse=True)
    proteinas = 0
    consumido = 0
    for carne in carnes:
        if consumido + carne[0] <= p:
            consumido += carne[0]
            proteinas += carne[1]
    print(proteinas)

if __name__ == '__main__':
    main()