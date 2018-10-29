#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void printArr(int* arr, int len);
void quicksort(int* arr, int len);
void parallelQuicksort(int* arr, int len);
void copyArr(int* arr, int n, int* newArr);
bool isSorted(int* arr, int n);

void main()
{
    int n = 10000;
    int arr[n];
    int* unorderedArr = (int *)malloc(n * sizeof(int));
    int buffer = -1;
    int i;
    
    // Reads n entries from stdin
    for(i = 0; i < n; i++)
    {
        scanf("%d", &buffer);
        arr[i] = buffer;
    }

    copyArr(arr, n, unorderedArr);

    // Run sorting here

    clock_t startTime;
    clock_t endTime;

    startTime = clock();

    quicksort(arr, n);

    endTime = clock();

    printf("Sequential:\t%ld\n", (endTime - startTime));

    startTime = clock();

    parallelQuicksort(unorderedArr, n);

    endTime = clock();

    printf("Parallel:\t%ld\n", (endTime - startTime));

    free(unorderedArr);
}

// Determines if an array is sorted
bool isSorted(int* arr, int n)
{
    int i;

    for(i = 1; i < n; i++)
        if (arr[i] < arr[i - 1]) return false;

    return true;    
}

// Copies an array into another
void copyArr(int* arr, int n, int* newArr)
{
    int i;

    for(i = 0; i < n; i++) newArr[i] = arr[i];
}

// Prints and integer array 'arr' of length 'len'
void printArr(int* arr, int len)
{
    int i = 0;

    for(i = 0; i < len; i++) printf("%d\t", arr[i]);
    
    printf("\n");
}