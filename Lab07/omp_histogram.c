#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define NUM_PIXELS 100000000
#define NUM_VALUES 256

int main() {
    int *pixels = malloc(NUM_PIXELS * sizeof(int));
    int histogram[NUM_VALUES] = {0};
    long i;
    
    srand(time(NULL));

    for(i = 0; i < NUM_PIXELS; i++){
        pixels[i] = rand() % 256;
    }

    double start = omp_get_wtime();
    
    #pragma omp parallel for
    for(i = 0; i < NUM_PIXELS; i++){
        histogram[pixels[i]]++;
    }

    for(int v = 0; v < 256; v++){
        printf("Valor %3d → %d vezes\n", v, histogram[v]);
    }
    
    double end = omp_get_wtime();

    printf("Tempo = %f.\n", end-start);

    free(pixels);
    return 0;
}
