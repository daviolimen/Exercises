def main():
    n, m = map(int, input().split())
    matriz = []
    for _ in range(n):
        matriz.append(list(map(int, input().split())))
    for i in range(n):
        i_row = i
        if 2 in matriz[i]:
            i_column = matriz[i].index(2)
            break
    current_row = i_row
    current_column = i_column
    visited = set()
    counter = 1
    while matriz[current_row][current_column] != 3:
        counter += 1
        coordinates = (current_row, current_column)
        visited.add(coordinates)
        if current_row < n - 1:
            if matriz[current_row + 1][current_column] == 1 or matriz[current_row + 1][current_column] == 3:
                if (current_row + 1, current_column) not in visited:
                    current_row = current_row + 1
                    continue
        if current_row > 0:
            if matriz[current_row - 1][current_column] == 1 or matriz[current_row - 1][current_column] == 3:
                if (current_row - 1, current_column) not in visited:
                    current_row = current_row - 1
                    continue
        if current_column < m - 1:
            if matriz[current_row][current_column + 1] == 1 or matriz[current_row][current_column + 1] == 3:
                if (current_row, current_column + 1) not in visited:
                    current_column = current_column + 1
                    continue
        if current_column > 0:
            if matriz[current_row][current_column - 1] == 1 or matriz[current_row][current_column - 1] == 3:
                if (current_row, current_column - 1) not in visited:
                    current_column = current_column - 1
                    continue
        current_row = i_row
        current_column = i_column
        counter = 1
    print(counter)

if __name__ == '__main__':
    main()