#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIM 10
#define ARRAY_SIZE LIM - 1
int main(void) {
    int i;
    int *array;
    srand((unsigned int)time(NULL));
    array = (int *)calloc(LIM, sizeof(int));
    for (i = 0; i < LIM; ++i) {
        array[i] = 0 + (int)(rand() * (9 + 1.0) / (1.0 + RAND_MAX));
        printf("%d\n", array[i]);
    }
    return 0;
}
