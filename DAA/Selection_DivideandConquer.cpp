#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high);
int randomizedQuickSelect(int arr[], int low, int high, int k);
int findKthSmallest(int arr[], int size, int k);

int main()
{
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the value of k: ");
    scanf("%d", &k);

    int result = findKthSmallest(arr, n, k);

    if (result != -1)
        printf("The %dth smallest element is: %d\n", k, result);

    return 0;
}

// Helper function to partition the array
int partition(int arr[], int low, int high)
{
    int pivotIndex = low + rand() % (high - low + 1);
    int pivotValue = arr[pivotIndex];

    // Swap arr[pivotIndex] and arr[high]
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[high];
    arr[high] = temp;

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivotValue)
        {
            i++;
            // Swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i + 1] and arr[high]
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Helper function to perform randomized quickselect
int randomizedQuickSelect(int arr[], int low, int high, int k)
{
    if (low <= high)
    {
        int partitionIndex = partition(arr, low, high);

        if (partitionIndex == k)
            return arr[partitionIndex];
        else if (partitionIndex < k)
            return randomizedQuickSelect(arr, partitionIndex + 1, high, k);
        else
            return randomizedQuickSelect(arr, low, partitionIndex - 1, k);
    }

    // This should not happen if the input is valid
    return -1;
}

// Function to find the kth smallest element in an array
int findKthSmallest(int arr[], int size, int k)
{
    // Check if k is within the valid range
    if (k >= 1 && k <= size)
        return randomizedQuickSelect(arr, 0, size - 1, k - 1);
    else
    {
        printf("Invalid value of k\n");
        return -1;
    }
}
