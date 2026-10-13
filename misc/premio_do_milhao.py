def main():
    n = int(input())
    milhao = 0
    dias = 0
    while milhao < 1000000:
        dias += 1
        milhao += int(input())
    print(dias)

if __name__ == '__main__':
    main()