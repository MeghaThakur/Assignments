#include <stdio.h>
#include <math.h>
#include<time.h>
void insertion_sort(int arr[], int n);
int main()
{
    int arr[] = {9056,9556,8968};
    int n = sizeof(arr)/sizeof(arr[0]);
 	clock_t begin=clock();
    insertion_sort(arr, n);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Elapsed time: %.2f.\n",time_spent);
}
void insertion_sort(int arr[], int n)
{
   int i, key, j,swaps=0,comparisons=0;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
	swaps++;
	comparisons++;
       }
       arr[j+1] = key;
	comparisons++;

   }
printf("%d\n",swaps);
printf("%d",comparisons);
}

