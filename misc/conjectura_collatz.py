def main():
    n = int(input())
    counter = 0
    while n != 1:
        counter += 1
        if n % 2 == 0:
            n /= 2
        else:
            n = 3 * n + 1
    print(counter)

if __name__ == '__main__':
    main()