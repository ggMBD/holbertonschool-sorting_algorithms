#include "sort.h"

/**
 * swap - Swaps two elements in an array and prints the array
 * @a: Index of the first element to swap
 * @b: Index of the second element to swap
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: The array to partition
 * @left: Starting index of the partition
 * @right: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the pivot element after partitioning
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}


	}
	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}


/**
 * quicksort - Recursive function to perform Quick Sort
 * @array: The array to be sorted
 * @left: Starting index of the array or subarray
 * @right: Ending index of the array or subarray
 * @size: Size of the array
 */
void quicksort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		quicksort(array, size, left, part - 1);
		quicksort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: The array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, size, 0, size - 1);
}
