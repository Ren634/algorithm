#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define lim 10
#define array_size lim - 1

void build_heap(int *, int, int);
void swap(int *, int *);
void heap_sort(int *);

int main(void){
    int count, i;
    int *array;
    array = (int *)calloc(lim, sizeof(int));
    srand((unsigned int)time(NULL));
    for (i = 0; i < lim;++i){
        array[i] = 0 + (int)(rand() *(9 + 1.0) / (1.0 + RAND_MAX));
        printf("array[%d]: %d\n", i, array[i]);
    }

    printf("\n");
    heap_sort(array);

    for (i = 0; i < lim;++i){
        printf("array[%d]: %d\n", i, array[i]);
    }
    free(array);
    return 0;
}

void build_heap(int *array,int i,int length){
    int parent = i, child = parent * 2 + 1;
    while(child <= length){
        if (child < length && array[child] < array[child + 1]){
            ++child;
        }
        if(array[parent] >= array[child]){
            break;
        }
        swap(&array[parent],&array[child]);
        parent = child;
        child = parent * 2 + 1;
    }
}

void swap(int *x, int *y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void heap_sort(int *array){
    int i;
    for (i = (array_size - 1) / 2; i >= 0; --i){
        build_heap(array, i,array_size);
    }
    for (int j = 0; j < lim;++j){
        printf("array[%d]: %d\n", j, array[j]);
    }
    printf("\n");

    for (i = array_size;i >= 1 ; --i){
        swap(&array[0], &array[i]);
        build_heap(array, 0,i - 1);
    }
}
