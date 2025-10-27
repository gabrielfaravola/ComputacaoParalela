#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TAM_VECTOR 100000000
#define NUM_THREADS 4 

long long global_sum = 0;
pthread_mutex_t mutex;

typedef struct{
	long start, end, *vector;
} struct_arg;

void *calculo_chunk(void *arg){
	struct_arg *args = (struct_arg *)arg;	
	long long sum = 0;
	
	for(long i = args->start; i <= args->end; i++){
		sum += args->vector[i];
	}
	pthread_mutex_lock(&mutex);
	global_sum += sum;
	pthread_mutex_unlock(&mutex);
}

int main(){
	long *vector = (long *) malloc(TAM_VECTOR * sizeof(long));
	long chunk,start,end;
	pthread_mutex_init (&mutex, NULL);
	pthread_t threads[NUM_THREADS];
	
	for(long i = 0; i < TAM_VECTOR; i++){
		vector[i] = i;
	}
	
	chunk = TAM_VECTOR / NUM_THREADS;
	
	for(int i = 0; i < NUM_THREADS; i++){
		start = chunk * i;
		
		if(i == NUM_THREADS - 1){
			end = start + chunk;
		} else end = start + chunk - 1;
		
		struct_arg *args = (struct_arg *)malloc(sizeof(struct_arg));
		args->vector = vector;
        	args->start = start;
        	args->end = end;
		
		pthread_create(&threads[i], NULL, calculo_chunk, (void *)args);
	}

	for (int i = 0; i < NUM_THREADS; i++) {
        	pthread_join(threads[i], NULL);
    	}

	pthread_mutex_destroy(&mutex);
	printf("Soma total = %lld\n", global_sum);
	free(vector);
}
