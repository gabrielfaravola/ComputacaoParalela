#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define TAM_VECTOR 100000000

int main(){
	long *A = malloc(TAM_VECTOR * sizeof(long));
    long *B = malloc(TAM_VECTOR * sizeof(long));
	long *C = malloc(TAM_VECTOR * sizeof(long));
	
	for(long i = 0; i < TAM_VECTOR; i++){
		A[i] = i;
		B[i] = i;
	}
	
	double start = omp_get_wtime();

	#pragma omp parallel for	
	for(long i = 0; i < TAM_VECTOR; i++){
		C[i] = A[i] + B[i];
	}

	double end = omp_get_wtime();

	printf("Tempo = %f.\n", end-start);

	free(A);
	free(B);
	free(C);

   	return 0;
}
