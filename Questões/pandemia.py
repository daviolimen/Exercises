amigos, reunioes = map(int, input().split())
individuo, fim = map(int, input().split())
infectados = set([individuo])

for _ in range(fim - 1):
    input()

for _ in range(reunioes - fim + 1):
    participantes = set(list(map(int, input().split()))[1:])
    if len(participantes.intersection(infectados)) != 0:
        infectados = infectados.union(participantes)

print(len(infectados))