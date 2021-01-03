#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    int tmp,lim= 10,i, j,count=0;
    int *array;
    array = (int *)calloc(lim, sizeof(int));
    srand((unsigned int)time(NULL));
    for (i = 0; i < lim;++i){
        array[i] = 0 + (int)(rand() *(9 + 1.0) / (1.0 + RAND_MAX));
        printf("array[%d] = %d\n", i, array[i]);
    }
    printf("\n");
    for (i = 0; i < lim; ++i){
        for (j = 0; j < lim - i - 1;++j){
            count++;
            if (array[lim - 1 - j - 1] > array[lim - j -1]){
                tmp = array[lim -1  - j - 1];
                array[lim - 1 - j - 1] = array[lim - 1 - j];
                array[lim - 1 - j] = tmp;
            }
        }
    }
    for (i = 0; i < lim;++i){
        printf("array[%d] = %d\n",i,array[i]);
    }
    printf("比較回数: %d\n", count);
    free(array);
    return 0;
}
