def main():
    n = int(input())
    registros = set()
    for _ in range(n):
        registros.add(int(input()))
    print(len(registros))