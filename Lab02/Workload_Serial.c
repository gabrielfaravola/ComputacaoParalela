#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <sys/wait.h>

#define VECTOR_SIZE 200000000
#define NUM_PROCESSES 4

// Função que simula uma carga de trabalho pesada
void heavy_work(double *vector, int start, int end) {
    int i;
    for (i = start; i < end; ++i) {
        vector[i] = sin(vector[i]) * cos(vector[i]) + sqrt(vector[i]);
    }
}

void paralelismo_work(double *vector, int start, int end) {
    int chunk_size = (end - start) / NUM_PROCESSES;
    pid_t pids[NUM_PROCESSES];

    for (int i = 0; i < NUM_PROCESSES; i++) {
        int local_start = start + i * chunk_size;
        int local_end = (i == NUM_PROCESSES - 1) ? end : local_start + chunk_size;

        pid_t pid = fork();
        
        if (pid == 0) { // Processo filho
            heavy_work(vector, local_start, local_end);
            exit(0);
            
        } else if (pid > 0) { // Processo pai
            pids[i] = pid;
            
        } else { // Erro na criação do processo
            perror("fork");
            exit(1);
        }
    }

    // Processo pai espera todos os filhos terminarem
    for (int i = 0; i < NUM_PROCESSES; i++) {
        waitpid(pids[i], NULL, 0);
    }
}

int main() {
    double *vector = (double *) malloc(VECTOR_SIZE * sizeof(double));
    for (int i = 0; i < VECTOR_SIZE; i++) vector[i] = (double) i;
    
    struct timespec start_time, end_time;

    // Versão sequencial
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    heavy_work(vector, 0, VECTOR_SIZE);
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double time_seq = (end_time.tv_sec - start_time.tv_sec) +
                      (end_time.tv_nsec - start_time.tv_nsec) / 1e9;
    printf("Versão sequencial executou em %f segundos\n.", time_seq);

    // Recarregar o vetor
    for (int i = 0; i < VECTOR_SIZE; i++) vector[i] = (double) i;

    // Versão paralela
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    paralelismo_work(vector, 0, VECTOR_SIZE);
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double time_par = (end_time.tv_sec - start_time.tv_sec) +
                      (end_time.tv_nsec - start_time.tv_nsec) / 1e9;
    printf("Versão paralela executou em %f segundos.\n", time_par);

    // Verificação
    printf("Resultado de verificacao: vector[10] = %f\n", vector[10]);

    double speedup = time_seq/time_par;
    printf("O programa foi %fx mais rápido.\n",speedup);

    free(vector);
    return 0;
}
