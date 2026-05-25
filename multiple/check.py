import numpy as np
import subprocess

def read_matrix(filename, N):
    with open(filename, "r") as f:
        matrix = []

        for i in range(N):
            line = f.readline().strip()
            row = [float(x) for x in line.split()]
            matrix.append(row)

    return np.array(matrix)

def run_c_program():
    subprocess.run([f"E:\\Parallel_Programming\\lab_1\\multiple\\main.exe"], cwd=r"E:\Parallel_Programming\lab_1\multiple", check=True)

def compare(N):
    A = read_matrix(f"E:\\Parallel_Programming\\lab_1\\multiple\\mtrx\\A{N}.txt", N)
    B = read_matrix(f"E:\\Parallel_Programming\\lab_1\\multiple\\mtrx\\B{N}.txt", N)
    C = read_matrix(f"E:\\Parallel_Programming\\lab_1\\multiple\\mtrx\\C{N}.txt", N)

    C_expected = A @ B

    print(np.array_equal(C_expected, C))

if __name__ == "__main__":
    N = int(input("N = "))
    run_c_program()
    compare(N)