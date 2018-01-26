#include<stdio.h>
#include<time.h>
void selection_sort(int arr[],int n);
int main()
{
	int arr[]={8,7,12,2,1,199,700};
	int n = sizeof(arr)/sizeof(arr[0]);
	clock_t begin=clock();
	selection_sort(arr,n);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Elapsed time: %.2f.\n",time_spent);
	
	return 0;
}
void selection_sort(int arr[],int n)
{
	int temp,swaps=0,comparisons=0,min;
	for (int i = 0; i < n-1; i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[min]>arr[j])
			{
				min=j;
				temp=arr[i];
				arr[i]=arr[min];
				arr[min]=temp;
				swaps++;
			}
			comparisons++;
		}
	}
	printf("%d\n",swaps );
	printf("%d\n",comparisons );
}