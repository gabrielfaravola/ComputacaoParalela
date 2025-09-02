#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

#define VECTOR_SIZE 1000
#define NUM_PROCESSES 4

int soma_parcial(int start, int end, double* vector) {
    int soma = 0;
    for (int i = start; i <= end; i++) {  // <= para incluir end
        soma += vector[i];
    }
    return soma;
}

int main() {
    double *vector = (double *) malloc((VECTOR_SIZE + 1) * sizeof(double)); // +1 para incluir posição 1000
    for (int i = 0; i <= VECTOR_SIZE; i++) vector[i] = (double) i;

    int pipes[NUM_PROCESSES][2];
    
    pid_t pids[NUM_PROCESSES];
    int chunk_size = (VECTOR_SIZE + 1) / NUM_PROCESSES;
    int total_sum = 0;

    struct timespec start_time, end_time;

    // Criação dos pipes
    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("pipe");
            exit(1);
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &start_time); // marcador inicial

    // Criação dos filhos
    for (int i = 0; i < NUM_PROCESSES; i++) {
        int start = i * chunk_size;
        int end = (i == NUM_PROCESSES - 1) ? VECTOR_SIZE : (start + chunk_size - 1);

        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(1);

        } else if (pid == 0) { // filho
            close(pipes[i][0]); // filho não lê
            int partial_sum = soma_parcial(start, end, vector);
            write(pipes[i][1], &partial_sum, sizeof(int));
            close(pipes[i][1]);
            exit(0);

        } else { // pai
            pids[i] = pid;
            close(pipes[i][1]); // pai não escreve
        }
    }

    // Pai lê resultados dos filhos e soma
    for (int i = 0; i < NUM_PROCESSES; i++) {
        int partial_sum;
        read(pipes[i][0], &partial_sum, sizeof(int));
        close(pipes[i][0]);
        total_sum += partial_sum;
    }

    // Espera todos os filhos terminarem
    for (int i = 0; i < NUM_PROCESSES; i++) {
        waitpid(pids[i], NULL, 0);
    }

    clock_gettime(CLOCK_MONOTONIC, &end_time); // marcador final

    double final_time = (end_time.tv_sec - start_time.tv_sec) +
                        (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    printf("Soma total: %d\n", total_sum);
    printf("Tempo total: %f segundos\n", final_time);

    free(vector);
    return 0;
}

