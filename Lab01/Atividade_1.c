#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();

    if(pid < 0){
        printf("Comando fork falhou.\n");
        return 1;

    } else if(pid == 0){
        printf("Eu sou o filho. Meu PID é %d, e o PID do meu pai é %d.\n",getpid(), getppid());
        printf("Finalizando programa");

    } else{
        printf("Eu sou o programa pai. Meu PID é %d.\n", getpid());
        wait(NULL);
        printf("Finalizando programa.\n");
    }
    return 0;
}