#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);  
    for(int j = low; j <= high - 1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void QuickSort(int arr[], int low, int high)
{
    if(low < high)  
    {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

void printArr(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);  
    }
    printf("\n");
}

void print_max(int a[], int n, int max)
{
    if(a == NULL || n <= 0)
    {
        printf("NO CAN DO\n");
        return;
    }
    QuickSort(a, 0, n-1);
    printf("Sorted array: ");
    printArr(a, n);
    
    int temp[n];  
    int index = 0;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += a[i];
        temp[index++] = a[i];
        if(sum >= max)
        {
            printf("The numbers that sum to %d or greater are:\n", max);
            for(int j = 0; j < index; j++)
            {
                printf("%d ", temp[j]);
            }
            printf("\nSum: %d\n", sum);
            return;
        }
    }
    printf("No subset found that sums to %d or greater\n", max);
}

int main()
{
    int arr[] = {12, 37, 38, 39, -15, -8, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = 50;  
    print_max(arr, n, max);
    return 0;
}
