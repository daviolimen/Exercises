from math import gcd

def main():
    rival, turma = map(int, input().split())
    for i in range(turma, 1, -1):
        if gcd(rival, i) == 1:
            print(i)
            break

if __name__ == "__main__":
    main()
