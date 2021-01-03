#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void){
    int array[10], min, i,index, j,count=0;
    srand((unsigned int)time(NULL));
    for (i = 0; i < 10;++i){
        array[i] = 0 + (int)(rand() *(9 + 1.0) / (1.0 + RAND_MAX));
        printf("array[%d]: %d\n", i, array[i]);
    }
    printf("\n");
    for (i = 0; i < 9; ++i){
        min = array[i];
        index = i;
        for (j = i + 1; j < 10; ++j){
            if(min > array[j]){
                min = array[j];
                index = j;
            }
            count++;
        }
        array[index] = array[i];
        array[i] = min;
    }
    for (i = 0; i < 10;++i){
        printf("array[%d]: %d\n",i, array[i]);
    }
    printf("比較回数: %d\n", count);
    return 0;
}
