/1. Implement the insertion sort, merge sort, quick sort and counting sort algorithms./

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double time1, timedif;

void insertionSort(int arr[], int n);
void printArray(int arr[], int n);
void mergeSort(int arr[], int l, int r);

int main(){
	int arr[] = { 12, 22, 54, 3, 45, 71, 19, 11, 13, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int option = 7;
	printf("Given array is \n");
	printArray(arr, n);
	printf("Enter option 1 or 2 , Neo. ");
	scanf("%d",&option);
	switch(option){
	case 1: 
		time1 = (double) clock();
	    	time1 = time1 / CLOCKS_PER_SEC;
		insertionSort(arr, n);
		timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
		printf("\nSorted array by insertionSort \n");
		printArray(arr, n);
		printf("Time elapsed: %f seconds\n", timedif);
		break;
	case 2:
		time1 = (double) clock();
	    	time1 = time1 / CLOCKS_PER_SEC;
		mergeSort(arr, 0,n - 1);
		timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
		printf("\nSorted array by mergeSort \n");
		printArray(arr, n);
		printf("Time elapsed: %f seconds\n", timedif);
		break;
	default:
		if(option != 0)
			printf("Invalid option,Neo!");
	}
	
	return 0;
}


//insertion sort
void insertionSort(int arr[], int n){
	int temp;
	for (int i = 1; i < n; i++) {
		temp = arr[i];
		int j = i - 1;
		/sorted insertion/
		while (j >= 0 && temp < arr[j]) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}
}

//merge sort
void merge(int arr[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	//splitting
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	//merging back
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	//copying remaining elements of L[]
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copying remaining elements of R[]
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r){
	if (l < r) {
		int m = l + (r - l) / 2;
		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

//printing
void printArray(int arr[], int n){
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}