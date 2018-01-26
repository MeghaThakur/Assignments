#include<stdio.h>
#include<time.h>
int modified_binary(int arr[],int l,int r,int key);
int main(int argc, char const *argv[])
{
	int arr[]={3,4,7,10,40};
	int n=sizeof(arr)/sizeof(arr[0]);
	int key=100;
	clock_t begin=clock();
	int result=modified_binary(arr,0,n-1,key);
	clock_t end=clock();
	if(result==-1)
	{
		printf("Number not found\n");
	}
	else
	{
		printf("number found at %d\n",result );
	}
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Elapsed time: %.2f.\n",time_spent);
	return 0;
}

int modified_binary(int arr[],int l,int r,int key)
{
	int mid=l+(r-l)/3;
	if(l<=r)
	{

		if(key==arr[mid])
		{
			return mid;
		}
		if(key<arr[mid])
		{
			return modified_binary(arr,0,mid-1,key);
		}
		else
		{
			return modified_binary(arr,mid+1,r,key);
		}

	}
	else
	{
		return -1;
	}

}