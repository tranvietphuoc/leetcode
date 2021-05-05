#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void merge(float **src, int src_len, float *dest, int dest_len) {
    // allocate new array
    int size = src_len + dest_len;
    float *tmp = (float*)malloc(sizeof(float) * src_len);
    memcpy(tmp, *src, src_len * sizeof(float));  // copy a src array to tmp array

    *src = (float*)realloc(*src, sizeof(float) * size);
    if(*src == NULL){
        printf("There's no free memory to allocate.\n");
    }
    // copy tmp array to new src array
    for(int i = 0; i < src_len; i++) {
        (*src)[i] = tmp[i];
    }
    // print dest array
    for(int i = 0; i < dest_len; i++) {
        printf("%.2f ", *(dest + i));
    }
    // merge dest array to src array
    for(int i = 0; i < dest_len; i++) {
        (*src)[src_len + i] = dest[i];
    }
    free(tmp);
}

void append(float **arr, int len,  float value) {
    float *tmp = (float*)malloc(sizeof(float) * len);
    if(!tmp) {
        printf("There's no memory to allocate.");
    }
    memcpy(tmp, *arr, len * sizeof(float));
    *arr = realloc(*arr, sizeof(float) * (len + 1));
    (*arr)[len] = value;
}



void c2iteration(float g, float x0, float q, float eps, int N) {
    /*
     * g is function
     *
     */

    if(q < 0 || q >= 1){
        printf("Ham so khong phai la ham co.");
    }
    float *x = (float*)malloc(sizeof(float) * N) ;
    float *ss = (float*)malloc(sizeof(float) * N);
    float err = eps + 1;
    append(&x, N, x0);
    append(&ss, N, err);
    int n = 1;
    while(n < N) {
        float x1 = 0.0;
        err = q / (1 - q) * fabs(x0 - x1);
        n += 1;
        append(&x, N, x1);
        append(&ss, N, err);
        x0 = x1;
    }
}

int main() {
    float *arr1 = (float*)malloc(sizeof(float) * 3);
    for(int i = 0; i < 3; i++) {
        arr1[i] = i;
    }
    float arr2[] = {4, 5, 6};
    int src = 3;
    int dest = 3;
    merge(&arr1, src, arr2, dest);
    printf("\nArray after merge:\n");
    for(int i = 0; i < src + dest; i++){
        printf("%.2f ", arr1[i]);
    }

    // free memory
    free(arr1);
}
