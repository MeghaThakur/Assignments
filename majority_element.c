#include<stdio.h>
#include<stdlib.h>
int get_frequency(int arr[],int key);

int majority_element(int arr[],int l,int r);
int main(int argc, char const *argv[])
{
	int arr[]={2,3,2,2,2,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int major=majority_element(arr,0,n-1);
	printf("%d\n", major);

	return 0;
}
int majority_element(int arr[],int l,int r)
{
	int k,z;
		int m=l+(r-l)/2;
		k=majority_element(arr,l,m);
		z=majority_element(arr,m+1,r);
		if(l==r)
	{
		return arr[l];
	}
		if(k==z)
		{
			return arr[l];
		}
		int lcount=get_frequency(arr,k);
		int rcount=get_frequency(arr,z);
		if(lcount>k+1)
		{
			return k;
		}
		else if(rcount>k+1)
		{
			return z;
		}
		else
		{
			return 0;
		}
	
	if(l==r)
	{
		return arr[l];
	}
}
int get_frequency(int arr[],int x)
{
	int n = sizeof(arr)/sizeof(arr[0]);
	int count = 0;
    int i;

    for (i = 0; i < n; ++i)
    {
        if ( arr[i]=x)
        {
            count = count + 1 ;
        }      
        else
        {
            count = count ;
        } 
    }
    return count;
}