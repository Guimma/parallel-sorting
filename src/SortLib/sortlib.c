#include "sortlib.h"

int* fillArray(int *array, int size){
    int i;
    for(i=0;i<size;i++)
        scanf("%i", &array[i]);
}

void printArray(int *array, int size){
    int i;
 
    (void) printf("[");
    for(i=0;i<size-1;i++)
        printf("%i,",array[i]);
 
    (void) printf("%i]\n",array[size-1]);
}

int getLargest(int *array, int size){
    int maior;
    maior = array[0];
    for(int i=1;i<size;i++)
        if(array[i]>maior)
            maior=array[i];
    return maior;
}