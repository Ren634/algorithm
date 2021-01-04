#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define lim 7

void build_heap(int *, int);
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

    return 0;
}

void build_heap(int *array,int i){
    int parent = i, child = parent * 2 + 1;
    while(child < lim){
        if (array[child] < array[child + 1]){
            ++child;
        }
        if(array[parent] < array[child]){
            swap(&array[parent],&array[child]);
        }
        ++parent;
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
    for (i = 0 ;i <= lim / 2;++i){
        build_heap(array,i);
    }
    for (int j = 0; j < lim;++j){
        printf("array[%d]: %d\n", j, array[j]);
    }
    printf("\n");

    for (i = 0; i < (lim - i) / 2;++i){
        swap(&array[0], &array[lim - 1 - i]);
        build_heap(array, i);
    }
}
