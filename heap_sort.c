#include<stdio.h>
#include<time.h>
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void print(int arr[], int n);
void swap(int *r,int *s);
int swaps=0,comparisons=0;

int main()
{
    int arr[600000];
    for(int i=600000;i<0;i--)
    {
        arr[i]=i;
    }
    int n = sizeof(arr)/sizeof(arr[0]); 
    heapSort(arr, n);    
}
void heapify(int arr[], int n, int i)
{
    int largest = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2; 
 	if (l < n && arr[l] > arr[largest])
    {
        largest = l;
        
    }
    comparisons++;
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
        
    }
    comparisons++; 	
 	//int(arr,n);
    if (largest != i)
    {    	
        swap(&arr[i], &arr[largest]);
        swaps++;
         heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    clock_t begin=clock();
    for (int i = n / 2 - 1; i >= 0; i--)
    	heapify(arr, n, i);
     for (int i=n-1; i>=0; i--)
    {
        swap(&arr[0], &arr[i]);
        swaps++;
 		//print(arr,n);
        heapify(arr, i, 0);
    }
    clock_t end=clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Elapsed time: %.2f.\n",time_spent);
//print(arr,n);
printf("%d\n",comparisons );
printf("%d\n",swaps );
}
 
void print(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        printf("%d",arr[i]);
}
 void swap(int* r,int* s)
{
int t;
t=*r;
*r=*s;
*s=t;
}
 
