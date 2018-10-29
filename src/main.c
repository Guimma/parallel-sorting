#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void printArr(int* arr, int len);
void quicksort(int* arr, int len);
void parallelQuicksort(int* arr, int len);
void copyArr(int* arr, int n, int* newArr);
bool isSorted(int* arr, int n);

void _quickSort(int* arr, int n);
void _mergeSort(int* arr, int n);
void _countingSort(int* arr, int n);
void _heapSort(int* arr, int n);

void main(int argc, char **argv)
{
    int n = 10000;
    int arr[n];
    int buffer = -1;
    int i;

    // Reads input from file
    FILE * fp = fopen("input/input.txt","r");

    for(i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &buffer);
        arr[i] = buffer;
    }

    fclose(fp);

    if (argc == 0)
    {
        // Execute all sorting algorithms
        _quickSort(arr, n);
        _mergeSort(arr, n);
        _countingSort(arr, n);
        _heapSort(arr, n);
    }
    else
    {
        switch (argv[0][0])
        {
            case 'Q':
            case 'q':
                _quickSort(arr, n);
                break;

            case 'M':
            case 'm':
                _mergeSort(arr, n);
                break;

            case 'C':
            case 'c':
                _countingSort(arr, n);
                break;

            case 'H':
            case 'h':
                _heapSort(arr, n);
                break;

            default:
                printf("Unsupported argument: %c\n", argv[0][0]);
                break;
        }
    }

}

// Run and time Quicksort
void _quickSort(int* arr, int n)
{
    clock_t startTime;
    clock_t endTime;

    int* unorderedArr = (int *)malloc(n * sizeof(int));

    // Saves an unsorted copy of the array
    copyArr(arr, n, unorderedArr);

    startTime = clock();

    quicksort(arr, n); // Sequential Quicksort

    endTime = clock();

    printf("Sequential:\t%ld\n", (endTime - startTime));

    startTime = clock();

    parallelQuicksort(unorderedArr, n); // Parallel Quicksort

    endTime = clock();

    printf("Parallel:\t%ld\n", (endTime - startTime));

    free(unorderedArr);
}

// Run and time Mergesort
void _mergeSort(int* arr, int n)
{
    clock_t startTime;
    clock_t endTime;

    int* unorderedArr = (int *)malloc(n * sizeof(int));

    // Saves an unsorted copy of the array
    copyArr(arr, n, unorderedArr);

    startTime = clock();

    // Sequential Mergesort

    endTime = clock();

    printf("Sequential:\t%ld\n", (endTime - startTime));

    startTime = clock();

    // Parallel Mergesort

    endTime = clock();

    printf("Parallel:\t%ld\n", (endTime - startTime));

    free(unorderedArr);
}

// Run and time Countingsort
void _countingSort(int* arr, int n)
{
    clock_t startTime;
    clock_t endTime;

    int* unorderedArr = (int *)malloc(n * sizeof(int));

    // Saves an unsorted copy of the array
    copyArr(arr, n, unorderedArr);

    startTime = clock();

    // Sequential Countingsort

    endTime = clock();

    printf("Sequential:\t%ld\n", (endTime - startTime));

    startTime = clock();

    // Parallel Countingsort

    endTime = clock();

    printf("Parallel:\t%ld\n", (endTime - startTime));

    free(unorderedArr);
}

// Run and time Heapsort
void _heapSort(int* arr, int n)
{
    clock_t startTime;
    clock_t endTime;

    int* unorderedArr = (int *)malloc(n * sizeof(int));

    // Saves an unsorted copy of the array
    copyArr(arr, n, unorderedArr);

    startTime = clock();

    // Sequential Heapsort

    endTime = clock();

    printf("Sequential:\t%ld\n", (endTime - startTime));

    startTime = clock();

    // Parallel Heapsort

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