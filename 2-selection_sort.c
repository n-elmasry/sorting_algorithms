#include "sort.h"
/**
*selection_sort - sorts an array of integers in ascending order
*@array:  array to be sorted
*@size: size of the array
*Return: void
*/
void selection_sort(int *array, size_t size)
{
	int smallest, temp;
	size_t i, j;

	if (array == NULL || size == 0)
	return;


	for (i = 0; i < size - 1 ; i++)
	{
		smallest = i;

	for (j = i + 1; j < size; j++)
	{
		if (array[j] < array[smallest])
		{
			smallest = j;
		}
	}
	if (array[smallest] != array[i])
	{
		temp = array[i];
		array[i] = array[smallest];
		array[smallest] = temp;
		print_array(array, size);
	}
	}
}
