def main():
    nums = [int(input()) for _ in range(10)]
    crescente = sorted(nums)
    string1 = ''
    for num in crescente:
        string1 += str(num) + ' '
    string1.strip()
    crescente.reverse()
    string2 = ''
    for num in crescente:
        string2 += str(num) + ' '
    string2.strip()
    print(string1)
    print(string2)

if __name__ == '__main__':
    main()