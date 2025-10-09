#include <stdio.h>
#include <omp.h>
#define MAX 100

int main(){
    int A[MAX],B[MAX],C[MAX];

    for(int i = 0; i<MAX; i++){
        A[i] = i;
        B[i] = i;
    }

    #pragma omp parallel for
    for(int i = 0; i<MAX; i++) C[i] = A[i] + B[i];

    #pragma omp parallel for
    for(int i = 0; i<MAX; i++) printf("%d\n",C[i]);
}