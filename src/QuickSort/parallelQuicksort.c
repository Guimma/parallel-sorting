void parallelQuicksortRecursive(int* arr, int start, int end);
void swap(int* arr, int i, int j);

// Quicksort entry-point
void parallelQuicksort(int* arr, int len)
{
    if (len > 0)
        parallelQuicksortRecursive(arr, 0, len - 1);
}

// Recursive quicksort implementarion
void parallelQuicksortRecursive(int* arr, int start, int end)
{
    int i = start;
    int j = end;
    int pivot = arr[(i + j) / 2]; // Get the element in the middle of the array and set it as the pivot

    if (start < end)
    {
        while(i <= j)
        {
            // Increment i until the value it's pointed at is greater than the pivot
            while (arr[i] < pivot) i++;

            // Decrement j until the value it's pointed at is lesser than the pivot
            while (arr[j] > pivot) j--;

            if (i <= j)
            {
                swap(arr, i, j);
                i++;
                j--;
            }
        }
        
        #pragma omp parallel sections
        {
            #pragma omp section
            parallelQuicksortRecursive(arr, start, j); // Calls quicksort on the left-most part of the array

            #pragma omp section
            parallelQuicksortRecursive(arr, i,   end); // Calls quicksort on the right-most part of the array
        }

    }
}
