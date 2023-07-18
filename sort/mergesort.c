/* 

Krystal Hong
I pledge my honor that I have abided by the Stevens Honor Sytsem.

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mergesort.h"

/* 

Functions to compare a and b 
a = b   0
a > b   1
a < b   -1

*/
int int_cmp(const void* a, const void* b){

    if(*(int *) a > *(int *)b){
        return 1;
    }
    else if(*(int *)a < *(int *)b){
        return -1;
    }else
    return 0;

}

int dbl_cmp(const void* a, const void* b){

    if(*(double *) a > *(double *)b){
        return 1;
    }
    else if(*(double *)a < *(double *)b){
        return -1;
    }else
    return 0;

}


/*

mergesort!
split them and then call mergesort again on the splits
pointers and take smaller num

*/

//array[a] = array[b] be sure to think of size loop the bytes!
void set(void *a, void *b, size_t elem_sz){
    char *a_p = (char *)a;
    char *b_p = (char *)b;
    for(size_t i = 0; i < elem_sz; i++){
        *(a_p + i) = *(b_p + i);
    }
}

void merge(void* array, int start, int mid, int end, size_t elem_sz, int (*comp)(const void*, const void*)){
    int start2 = mid + 1;
    char *mid_val = (char *)array + (mid * elem_sz);
    char *start2_val = (char *)array + (start2 * elem_sz);

    if(comp(mid_val, start2_val) != 1){
        return;
    }
    

    while(start <= mid && start2 <= end){
        char *start2_val = (char *)array + (start2 * elem_sz);
        char *start_val = (char *)array + (start * elem_sz);

        if(comp(start_val, start2_val) != 1){
            start++;
        }
        else{
            char value = *start2_val;
            int index = start2;


            while(index != start){
                char *index_val = (char *)array + (index * elem_sz);
                char *index_val_1 = (char *)array + ((index - 1) * elem_sz);
                set(index_val, index_val_1, elem_sz);
                index--;
            }
            *(start_val) = value;

            start++;
            mid++;
            start2++;
        }
    }


}
void merge_sorter(void* array, int l, int r, size_t elem_size, int (*comp)(const void*, const void*)){
    if(l < r){
        int m = 1 + (r - 1) / 2;

        merge_sorter(array, l, m, elem_size, comp);
        merge_sorter(array, m + 1, r, elem_size, comp);

        merge(array, l, m, r, elem_size, comp);
    }
}

void mergesort(void*  array, size_t len, size_t elem_sz, 
                int (*comp)(const void*, const void*)){
    
    int l = 0;
    int j = len -1;
    
    merge_sorter(array, l, j, elem_sz, comp );
    

}


