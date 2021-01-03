#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    int tmp,array[10],i, j,count=0;
    srand((unsigned int)time(NULL));
    for (i = 0; i < 10;++i){
        array[i] = rand();
        printf("array[%d] = %d\n", i, array[i]);
    }
    printf("\n");
    for (i = 0; i < 10; ++i){
        for (j = 0; j < 9 - i;++j){
            count++;
            if (array[9 - j - 1] > array[9 - j]){
                tmp = array[9 - j - 1];
                array[9 - j - 1] = array[9 - j];
                array[9 - j] = tmp;
            }
        }
    }
    for (i = 0; i < 10;++i){
        printf("array[%d] = %d\n",i,array[i]);
    }
    printf("比較回数: %d\n", count);
    return 0;
}
