def main():
    n = int(input())
    fita_inicial = input().split()
    fita_final = [float("inf") for _ in range(n)]
    for i in range(n):
        if fita_inicial[i] == '0':
            j = 0
            while ((i - j) >= 0):
                if (j < fita_final[i - j]):
                    if j > 9:
                        fita_final[i - j] = 9
                    else:
                        fita_final[i - j] = j
                j += 1
            j = 0
            while ((i + j) < n):
                if (j < fita_final[i + j]):
                    if j > 9:
                        fita_final[i + j] = 9
                    else:
                        fita_final[i + j] = j
                
                j += 1
    fita_final = list(map(str, fita_final))
    print(' '.join(fita_final))


if __name__ == '__main__':
    main()