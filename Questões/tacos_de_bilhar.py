from collections import Counter

def main():
    c = int(input())
    consultas = list(map(int, input().split()))
    estoque = Counter(consultas)
    total = 0
    for key in estoque.keys():
        num = estoque[key]
        if num % 2 == 0:
            total += num
        else:
            total += num + 1

    print(total)
    

if __name__ == '__main__':
    main()