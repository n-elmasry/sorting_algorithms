#include "sort.h"
/**
 * swap - Swaps two integers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * quicksort_recursion - Recursively sorts an array using quicksort
 * @array: Array to be sorted.
 * @low: Index of the low element.
 * @high: Index of the high element.
 * @size: Size of the array.
 */
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

/**
* quick_sort - sorts an array of integers in ascending order
* @array: array to be sorted
* @size: the size of the array
* Return: void
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursion(array, 0, size - 1, size);
}

/**
 * partition - Partitions an array and returns the index of the pivot.
 * @array: Array to be partitioned.
 * @low: Index of the low element.
 * @high: Index of the high element.
 * @size: Size of the array.
 * Return: Index of the pivot after partitioning.
*/
int partition(int array[], int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				swap(&array[i], &array[j]);
		print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}
