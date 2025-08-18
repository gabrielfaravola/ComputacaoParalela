#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n;

    printf("Digite o número de forks do programa: ");
    scanf("%d", &n);
    printf("\n");

    pid_t pid;

    for (int i = 0; i < n; i++) {
        pid = fork();

        if (pid < 0) {
            printf("Comando fork falhou.\n");
            return 1;

        } else if (pid == 0) {
            // Processo filho
            printf("Eu sou o filho %d. Meu PID é %d, e o PID do meu pai é %d.\n", i + 1, getpid(), getppid());
            printf("Finalizando programa filho %d[%d].\n", getpid(), i + 1);
            return 0;  // Filho termina aqui
        }

    }

    printf("Eu sou o programa pai. Meu PID é %d.\n", getpid());
    printf("Aguardando os filhos terminarem...\n\n");

    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    printf("\nTodos os filhos terminaram. Finalizando programa pai.\n");
    return 0;
}
