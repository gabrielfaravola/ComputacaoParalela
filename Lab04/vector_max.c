#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define TAM_VECTOR 1000000000
#define NUM_THREADS 4

typedef struct{
	long start, end, *vector;
} struct_arg;

void *max(void *arg) {
    struct_arg *args = (struct_arg *)arg;
    long maior = 0;

    for (long i = args->start; i <= args->end; i++) {
        if (args->vector[i] > maior) maior = args->vector[i];
    }

    return (void *)maior;
}


int main(){
	long *vector = (long *) malloc(TAM_VECTOR * sizeof(long));
	long chunk,start,end;
	pthread_t threads[NUM_THREADS];
	void* return_max = NULL;
	long maior = 0;

	srand(time(NULL));

	for(long i = 0; i < TAM_VECTOR; i++){
		vector[i] = rand() % 99999999;
	}

	chunk = TAM_VECTOR / NUM_THREADS;

	for(int i = 0; i < NUM_THREADS; i++){
		start = chunk * i;

		if(i == NUM_THREADS - 1){
			end = start + chunk;
		} else end = start + chunk - 1;

		struct_arg *args = (struct_arg *) malloc(sizeof(struct_arg));
		args->vector = vector;
        	args->start = start;
        	args->end = end;

		pthread_create(&threads[i], NULL, max, (void *)args);
	}

	for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], &return_max);
		long result_max = (long) return_max;
		if(result_max > maior) maior = result_max;
	}	

	printf("Maior valor: %d\n", maior);

	free(vector);
	return 0;
}
