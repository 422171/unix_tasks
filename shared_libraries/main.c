#include <stdio.h>
#include "header.h"

#define MAX 20

int main() {
	int arr[] = {36, 12, 19, 7, 39, 71, 2, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	printf("The array is-\n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	int x = 10;
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1) ? printf("Element is not present"
							" in array")
				: printf("Element is present at index %d", result);
	printf("\n");
	quickSort(arr, 0,n- 1);
	printf("Sorted array: \n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
