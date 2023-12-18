#include "sort.h"
void swap(int *x, int *y);


void quicksort_recursion(int array[], int low, int high, size_t size);

void quick_sort(int *array, size_t size);

int partition(int array[], int low, int high, size_t size);

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort_recursion(int array[], int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = partition(array, low, high, size);
        quicksort_recursion(array, low, pivot - 1, size);
        quicksort_recursion(array, pivot + 1, high, size);
    }
}

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_recursion(array, 0, size - 1, size);
}

int partition(int array[], int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
		print_array(array, size);
            }
        }
    }

    swap(&array[i + 1], &array[high]);
    print_array(array, size);

    return i + 1;
}
