#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define N_VECTOR 100000000

int main(){
	long *A = malloc(N_VECTOR * sizeof(long));
    long *B = malloc(N_VECTOR * sizeof(long));
	long *C = malloc(N_VECTOR * sizeof(long));
	
	#pragma omp parallel for
	for(long i = 0; i < N_VECTOR; i++){
		A[i] = i;
		B[i] = i;
	}
	
	double start = omp_get_wtime();

	#pragma omp parallel for	
	for(long i = 0; i < N_VECTOR; i++){
		C[i] = A[i] + B[i];
	}

	double end = omp_get_wtime();
	printf("Tempo = %f segundos.\n", end - start);

	free(A);
	free(B);
	free(C);

   	return 0;
}
