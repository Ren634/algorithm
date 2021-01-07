#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define LIM 10
#define ARRAY_SIZE LIM - 1

void merge_sort(int *, int, int);

int main(void){
    int i;
    int *array;
    array = (int *)calloc(LIM, sizeof(int));
    srand((unsigned int)time(NULL));
    for (i = 0; i < LIM; ++i){
        array[i] = 0 + (int)(rand() * (9 + 1.0) / (1.0 + RAND_MAX));
        printf("array[%d]: %d\n", i, array[i]);
    }
    printf("\n");

    merge_sort(array,0,ARRAY_SIZE);

    for (i = 0; i < LIM; ++i){
        printf("array[%d]: %d\n", i, array[i]);
    }

    free(array);

    return 0;
}

void merge_sort(int *array, int left, int right){
    int mid,i,j,k;
    if (left < right){
        int *tmp;
        tmp = (int *)calloc(right + left + 1, sizeof(int));
        mid = (left + right) / 2;
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        for (i = left; i <= mid;++i){
            tmp[i] = array[i];
        }
        for (j = mid + 1; j <= right;++j){
            tmp[j] = array[right - (j - (mid + 1))];
        }
        i = left;
        j = right;
        for (k = left; k <= right; ++k){
            if(tmp[i] > tmp[j]){
                array[k] = tmp[j--];
            }else{
                array[k] = tmp[i++];
            }
        }
            free(tmp);
    }
}
