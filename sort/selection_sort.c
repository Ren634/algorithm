#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void){
    int lim = 10, min, i,index, j,count=0;
    int *array;
    array = (int *)calloc(lim, sizeof(int));
    srand((unsigned int)time(NULL));
    for (i = 0; i < lim;++i){
        array[i] = 0 + (int)(rand() *(9 + 1.0) / (1.0 + RAND_MAX));
        printf("array[%d]: %d\n", i, array[i]);
    }
    printf("\n");
    for (i = 0; i < lim - 1; ++i){
        min = array[i];
        index = i;
        for (j = i + 1; j < lim; ++j){
            if(min > array[j]){
                min = array[j];
                index = j;
            }
            count++;
        }
        array[index] = array[i];
        array[i] = min;
    }
    for (i = 0; i < lim;++i){
        printf("array[%d]: %d\n",i, array[i]);
    }
    printf("比較回数: %d\n", count);
    free(array);
    return 0;
}
