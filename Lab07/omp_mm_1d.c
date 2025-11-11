#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1024
#define NUM_THREADS 4

int main() {
    int i, j, k;

    double **A = malloc(N * sizeof(double*));
    double **B = malloc(N * sizeof(double*));
    double **C = calloc(N, sizeof(double*));

    for(i = 0; i < N; i++){
        A[i] = malloc(N * sizeof(double));
        B[i] = malloc(N * sizeof(double));
        C[i] = calloc(N, sizeof(double));
    }

    #pragma omp parallel for
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            A[i][j] = 1.0;
            B[i][j] = 1.0;
        }
    }

    omp_set_num_threads(NUM_THREADS);
    double start = omp_get_wtime();
    
    #pragma omp parallel for private(j,k)
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            for(k = 0; k < N; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    double end = omp_get_wtime();
    printf("Tempo = %f segundos.\n", end - start);

    for(i = 0; i < N; i++){
        free(A[i]);
	      free(B[i]);
	      free(C[i]);
    }
  
    free(A);
    free(B);
    free(C);

    return 0;
}
