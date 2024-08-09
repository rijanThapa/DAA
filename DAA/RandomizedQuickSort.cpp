#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition_left(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

int partition_right(int arr[], int low, int high) {
    srand(time(NULL));
    int r = low + rand() % (high - low + 1);  // Fix range to include 'high'
    swap(&arr[r], &arr[high]);
    return partition_left(arr, low, high);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition_right(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;


    printf("Enter the number of elements: ");
    scanf("%d", &n);

  
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

   
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

   
    printf("Original array: ");
    printArray(arr, n);

    
    quicksort(arr, 0, n - 1);

   
    printf("Sorted array: ");
    printArray(arr, n);

   
    free(arr);

    return 0;
}

