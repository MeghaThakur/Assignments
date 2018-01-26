#include<stdio.h>
void swap(int* a, int* b);
int partition (int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);
void swap(int* a, int* b);
int swaps=0,comparison=0;
main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr, 0, n-1);
    for(int i=0;i<n;i++)
    {
    	printf("%d\n",arr[i]);
    }
    printf("swap: %d\n",swaps );
    printf("comparisons : %d\n",comparison );
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    
    int i = (low - 1); 
    int a,b;
 
    for (int j = low; j <= high- 1; j++)
    {
        
        if (arr[j] <= pivot)
        {
            i++;   
            swap(&arr[i],&arr[j]);
            swaps++;

        }
        comparison++;
    }
    
    swap(&arr[i + 1], &arr[high]);
    swaps++;
    return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
    	comparison++;
        int pi = partition(arr, low, high);
 
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


