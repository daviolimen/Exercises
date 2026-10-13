from math import gcd

input()
lista = list(map(int, input().split()))
print(gcd(*lista))