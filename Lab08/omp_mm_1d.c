#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1024
#define NUM_THREADS 4

double A[N][N], B[N][N], C[N][N];

void load_matrix(){
    #pragma omp parallel for
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            A[i][j] = 1.0;
            B[i][j] = 1.0;
            C[i][j] = 0.0;
        }
    }
}

int main() {
    double start, end;
    omp_set_num_threads(NUM_THREADS);

    // --- Static, 1 ---
    load_matrix();
    start = omp_get_wtime();
    
    #pragma omp parallel for schedule(static,1)
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    end = omp_get_wtime();
    printf("Tempo Static = %f segundos.\n", end - start);
    start = 0;
    end = 0;


    // --- Dynamic, 1 ---
    load_matrix();
    start = omp_get_wtime();
    
    #pragma omp parallel for schedule(dynamic,1)
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    end = omp_get_wtime();
    printf("Tempo Dynamic = %f segundos.\n", end - start);
    start = 0; 
    end = 0;
    

    // --- Guided ---
    load_matrix();
    start = omp_get_wtime();
    
    #pragma omp parallel for schedule(guided)
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    end = omp_get_wtime();
    printf("Tempo Guided = %f segundos.\n", end - start);
    start = 0;
    end = 0;

    return 0;
}
