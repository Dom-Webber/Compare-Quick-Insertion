#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
void insertionSort(int arr[], int n)
{
int i, key, j;
for (i = 1; i < n; i++) {
key = arr[i];
j = i - 1;

/* Move elements of arr[0..i-1], that are
greater than key, to one position ahead
of their current position */
while (j >= 0 && arr[j] > key) {
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
}

void swap(int* a, int* b)
{
int t = *a;
*a = *b;
*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
int pivot = arr[high]; // pivot
int i = (low - 1); // Index of smaller element

for (int j = low; j <= high- 1; j++)
{
// If current element is smaller than the pivot
if (arr[j] < pivot)
{
i++; // increment index of smaller element
swap(&arr[i], &arr[j]);
}
}
swap(&arr[i + 1], &arr[high]);
return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
if (low < high)
{
/* pi is partitioning index, arr[p] is now
at right place */
int pi = partition(arr, low, high);

// Separately sort elements before
// partition and after partition
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}

int main()
{
int length=5000;
int arr1[5000];
int r,i;
int arr[5000];
double total_time,total_time1;
clock_t start,end, start1, end1;
for (i = 0; i < length; i++)
{
r = rand();
arr[i]=r;
arr1[i]=r;
}
start=clock();
quickSort(arr, 0, length-1);
end=clock();
total_time=((double)(end-start))/CLOCKS_PER_SEC;
start1=clock();
insertionSort(arr1 , length);
end1=clock();
total_time1=((double)(end1-start1))/CLOCKS_PER_SEC;
printf("\n quick sort took %f seconds\n:",total_time);
printf("\n insertion sort took %f seconds\n:",total_time1);
return 0;
}
