void quicksortRecursive(int* arr, int start, int end);
void swap(int* arr, int i, int j);

// Quicksort entry-point
void quicksort(int* arr, int len)
{
    if (len > 0)
        quicksortRecursive(arr, 0, len - 1);
}

// Recursive quicksort implementarion
void quicksortRecursive(int* arr, int start, int end)
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

        quicksortRecursive(arr, start, j); // Calls quicksort on the left-most part of the array
        quicksortRecursive(arr, i,   end); // Calls quicksort on the right-most part of the array
    }
}

// Swaps two values in an integer array
void swap(int* arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
