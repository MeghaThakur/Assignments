#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int get_frequency(int arr[],int x,int n);

int majority_element(int arr[],int l,int r);
int main(int argc, char const *argv[])
{
	int arr[1000000];
	for(int i=0;i<1000000;i++)
{
	arr[i]=100;
}
clock_t begin=clock();
	int n = sizeof(arr)/sizeof(arr[0]);
	int major=majority_element(arr,0,n-1);
	printf("%d\n", major);
 clock_t end=clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("Elapsed time: %.2f.\n",time_spent);
	return 0;
}
int majority_element(int arr[],int l,int r)
{
	int k,z;
	int n = sizeof(arr)/sizeof(arr[0]);
	//n=(l-r)+1;
	if(l==r)
	{
		return arr[0];
	}
		int m=l+(r-l)/2;
		k=majority_element(arr,l,m);
		z=majority_element(arr,m+1,r);
		
		if(k==z)
		{
			return k;
		}
		int lcount=get_frequency(arr,k,n);
		int rcount=get_frequency(arr,z,n);
		if(lcount>m+1)
		{
			return k;
		}
		else if(rcount>m+1)
		{
			return z;
		}
		else
		{
			return 0;
		}
}
int get_frequency(int arr[],int x,int n)
{
	
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