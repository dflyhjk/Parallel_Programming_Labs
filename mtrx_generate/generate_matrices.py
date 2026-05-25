import random
import os


def create_matrix(n):
    matrix = []
    i = 0

    while i < n:
        row = []
        j = 0

        while j < n:
            row.append(random.randint(-100, 100))
            j += 1

        matrix.append(row)
        i += 1

    return matrix


def save_matrix(matrix, filename):
    file = open(filename, "w")

    i = 0
    while i < len(matrix):
        j = 0

        while j < len(matrix[i]):
            file.write(str(matrix[i][j]))

            if j != len(matrix[i]) - 1:
                file.write(" ")

            j += 1

        file.write("\n")
        i += 1

    file.close()


# Ввод размера матрицы
N = int(input("Введите размер N: "))

folder_name = r"E:\Parallel_Programming\lab_1\multiple\mtrx"

if not os.path.exists(folder_name):
    os.mkdir(folder_name)

# Создание матриц
A = create_matrix(N)
B = create_matrix(N)

# Пути к файлам
file_A = os.path.join(folder_name, f"A{N}.txt")
file_B = os.path.join(folder_name, f"B{N}.txt")

# Сохранение
save_matrix(A, file_A)
save_matrix(B, file_B)

print(f"Матрицы сохранены: {file_A} и {file_B}")