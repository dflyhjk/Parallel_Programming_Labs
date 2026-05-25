#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <direct.h>

int main() {
int N;
printf("Matrix size: ");
scanf("%d", &N);

char fileA[200];
char fileB[200];

sprintf(fileA, "mtrx/A%d.txt", N);
sprintf(fileB, "mtrx/B%d.txt", N);

// Выделение памяти
double **A = (double**) malloc(N * sizeof(double*));
double **B = (double**) malloc(N * sizeof(double*));
double **C = (double**) malloc(N * sizeof(double*));

for (int i = 0; i < N; i++) {
    A[i] = (double*) malloc(N * sizeof(double));
    B[i] = (double*) malloc(N * sizeof(double));
    C[i] = (double*) malloc(N * sizeof(double));
}

// Чтение
FILE *inputA = fopen(fileA, "r");
FILE *inputB = fopen(fileB, "r");

if (inputA == NULL) {
printf("A failed\n");
}

if (inputB == NULL) {
    printf("B failed\n");
}

    if (inputA != NULL && inputB != NULL) {

        // Чтение матрицы A
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                fscanf(inputA, "%lf", &A[i][j]);
            }
        }

        // Чтение матрицы B
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                fscanf(inputB, "%lf", &B[i][j]);
            }
        }

        fclose(inputA);
        fclose(inputB);

    } else {
        printf("Error opening matrix\n");
        return 1;
    }

    // Время
    clock_t start = clock();

    // Перемножение матриц
    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {

            C[i][j] = 0;

            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    clock_t end = clock();

    double time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Объем задачи
    // 2*N^3 операций

    long long volume = 2LL * N * N * N;

    printf("Volume: %lld\n", volume);

    char outputFolder[] = "E:\\Parallel_Programming\\lab_1\\multiple\\mtrx\\";

    char outputName[200];
    sprintf(outputName, "%sC%d.txt", outputFolder, N);

    FILE *output = fopen(outputName, "w");

    if (output != NULL) {

        // Запись
        for (int i = 0; i < N; i++) {

            for (int j = 0; j < N; j++) {
                fprintf(output, "%.2lf ", C[i][j]);
            }
            fprintf(output, "\n");
        }

        printf("Time: %.6f seconds\n", time);
        fprintf(output, "Volume: %lld\n", volume);
        fclose(output);

    } else {
        printf("Error opening output file\n");
        return 1;
    }

    // Запись времени в файл для графика
    FILE *timing = fopen("E:\\Parallel_Programming\\lab_1\\multiple\\timing\\time_log.txt", "a");

    if (timing != NULL) {
        fprintf(timing, "%d %lf\n", N, time);
        fclose(timing);
    }

    // Освобождение памяти
    for (int i = 0; i < N; i++) {

        free(A[i]);
        free(B[i]);
        free(C[i]);
    }

    free(A);
    free(B);
    free(C);

    return 0;
}