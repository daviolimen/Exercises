def main():
	l, c = map(int, input().split())
	matriz = []
	for i in range(l):
		matriz.append(input())
	for i in range(l):
		if 'o' in matriz[i]:
			coord = (i, matriz[i].index('o'))
			break
	visited = set()
	while coord not in visited:
		visited.add(coord)
		if coord[0] < l - 1:
			if matriz[coord[0] + 1][coord[1]] == 'H':
				if (coord[0] + 1, coord[1]) not in visited:
					coord = (coord[0] + 1, coord[1])
					continue
		if coord[0] > 0:
			if matriz[coord[0] - 1][coord[1]] == 'H':
				if (coord[0] - 1, coord[1]) not in visited:
					coord = (coord[0] - 1, coord[1])
					continue
		if coord[1] < c - 1:
			if matriz[coord[0]][coord[1] + 1] == 'H':
				if (coord[0], coord[1] + 1) not in visited:
					coord = (coord[0], coord[1] + 1)
					continue
		if coord[1] > 0:
			if matriz[coord[0]][coord[1] - 1] == 'H':
				if (coord[0], coord[1] - 1) not in visited:
					coord = (coord[0], coord[1] - 1)
					continue
	print(coord[0] + 1, coord[1] + 1)

if __name__ == '__main__':
	main()