#include<stdio.h>
#include<math.h>
#include<time.h>
void bubble_sort(int arr[],int n);
int main()
{
int arr[]={7,8,6,2,9,10,1};
int n = sizeof(arr)/sizeof(arr[0]);
clock_t begin=clock();
bubble_sort(arr,n);
clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("Elapsed time: %.2f.\n",time_spent);
}
void bubble_sort(int arr[],int n)
{
	int temp,swaps=0,comparisons=0;
for(int i=0;i<n-1;i++)
{
	for(int j=0;j<n-i-1;j++)
	{
		if(arr[j]>arr[j+1])
		{
			
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j]=temp;
			swaps++;
		}
		comparisons++;

	}

}
printf("%d\n",swaps );
printf("%d\n",comparisons );
}