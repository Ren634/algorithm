#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void){
    int tmp,i,j,lim = 10,count=0;
    int *array;
    array = (int *)calloc(lim, sizeof(int));
    srand((unsigned int)time(NULL));
    for (i = 0; i < lim;++i){
        array[i] = 0 + (int)(rand() *(9 + 1.0) / (1.0 + RAND_MAX));
        printf("array[%d]: %d\n", i, array[i]);
    }

    printf("\n");

    for (i = 0; i < lim;++i){
        tmp = array[i];
        for (j = 0; j < i; ++j){
            if(tmp < array[i - j - 1]){
                array[i - j] = array[i - j - 1];
                array[i - j - 1] = tmp;
            }else if(tmp > array[i - j - 1]){
                break;
            }
            count++;
        }
    }
    for (i = 0; i < lim;++i){
        printf("array[%d]: %d\n", i, array[i]);
    }
    printf("比較回数: %d\n", count);
    free(array);
    return 0;
}
