#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int comparisons=0,swaps=0;
void merge(int arr[], int l, int m, int r);
void merge_sort(int arr[], int l, int r);
int main()
{
    int arr[100000];
    for(int i=100000;i<0;i--)
    {
        arr[i]=i;
    }
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n",arr_size );
    clock_t begin=clock();
    merge_sort(arr, 0, arr_size - 1);
    clock_t end=clock();
    printf("%d\n",swaps);
    printf("%d\n",comparisons);
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Elapsed time: %.2f.\n",time_spent);
   }
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
 	for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    
    i = 0; 
    j = 0; 
    k = l;
    while (i < n1 && j < n2)
    {
	comparisons++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
	    swaps++;
        }
        else
        {
            arr[k] = R[j];
            j++;
	    swaps++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        
        int m = l+(r-l)/2;
 
        
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
   
}
