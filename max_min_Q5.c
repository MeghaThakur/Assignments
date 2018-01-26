#include<stdio.h>
#include<time.h>
void find_max(int arr[],int l,int r);
void find_min(int arr[],int l,int r);
int arr[80000];
int max,min;
int main(int argc, char const *argv[])
{
	for(int i=0;i<80000;i++)
{
	arr[i]=i;
}
	int n=sizeof(arr)/sizeof(arr[0]);
	clock_t begin=clock();
	find_max(arr,0,n-1);
	printf("Maximum is%d\n",max );
	find_min(arr,0,n-1);
	printf("Minimum is %d\n",min );
	clock_t end=clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("Elapsed time: %.2f.\n",time_spent);
	return 0;
}
void find_max(int arr[],int l,int r)
{
	int max1,max2;
	int mid=l+(r-l)/2;
	if(l<r)
	{
	
	find_max(arr,l,mid);
	find_max(arr,mid+1,r);
	}	
	for(int i=0;i<=mid;i++)
	{
		max1=arr[l];
		if(arr[i]>max1)
		{
			max1=arr[i];
		}
	}
	for(int i=mid+1;i<=r;i++)
	{
		max2=arr[mid+1];
		if(arr[i]>max2)
		{
			max2=arr[i];
		}
	}
	if(max1>=max2)
	{
		max=max1;
	}
	else
	{
		max=max2;
	}
}
void find_min(int arr[],int l,int r)
{
	int min1,min2;
	int mid=l+(r-l)/2;
	if(l<r)
	{
	
	find_min(arr,l,mid);
	find_min(arr,mid+1,r);
	}	
	for(int i=0;i<=mid;i++)
	{
		min1=arr[l];
		if(arr[i]<min1)
		{
			min1=arr[i];
		}
	}
	for(int i=mid+1;i<=r;i++)
	{
		min2=arr[mid+1];
		if(arr[i]<min2)
		{
			min2=arr[i];
		}
	}
	if(min1>=min2)
	{
		min=min2;
	}
	else
	{
		min=min1;
	}
}





	