#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <sys/wait.h>

#define VECTOR_SIZE 1000
#define NUM_PROCESSES 4

int Soma_Parcial(int start, int end, double* vector){
    int soma = 0;
    for(int i = start; i < end; i++){
        soma = soma + vector[i];
    }
    return soma;
}

int main(){
    double *vector = (double *) malloc(VECTOR_SIZE * sizeof(double));
    for (int i = 0; i < VECTOR_SIZE; i++) vector[i] = (double) i;

    int pipefd[2];
    pid_t pids[NUM_PROCESSES];

    int chunk_size = VECTOR_SIZE / NUM_PROCESSES;

    for(int i = 0; i < NUM_PROCESSES; i++){
        int start = i * chunk_size;
        int end = start + chunk_size;

        pid_t pid = fork();

        if(pid == 0){ // Processo filho
            int soma = Soma_Parcial(start, end, vector);
            printf("Soma = %d\n", soma);
            exit(0);

        } else if(pid > 1){ // Processo pai
            pids[i] = pid;

        } else{ // Erro
            printf("Erro na criação do processo.\n");
            exit(1);
        }

        for (int i = 0; i < NUM_PROCESSES; i++) {
            waitpid(pids[i], NULL, 0);
        }
    }

}