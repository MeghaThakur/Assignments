#include<stdio.h>
#include<stdlib.h>
int final[100],count=0;
void max_jump(int arr,int l,int r);

void calcuate(int arr[],int l,int m,int r);
int main(int argc, char const *argv[])
{
	int arr[100];
	for(int i=0;i<100;i++)
	{
		arr[i]=i;
	}
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int j=0;j<100;j++)
	{
		final[j]=0;
	}
	max_jump(arr,0,n-1);
	
	int max=final[0];
	//int m=sizeof(final)/sizeof(final[0]);
	for(int i=0;i<100;i++)
	{
		if(final[i]>max)
		{
			max=final[i];
		}
	}
	printf("%d\n",max );
	return 0;
}
void max_jump(int arr,int l,int r)
{
	if(l<r)
	{
int m=l+(r-l)/2;
max_jump(arr,l,m);
max_jump(arr,m+1,r);
calcuate(arr,l,m,r);
	}

}

void calcuate(int arr[],int l,int m,int r)
{
	int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int number;
    int L[n1], R[n2];
 	for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    
    i = 0; 
    j = 0; 
    k = l;
    for (int i = 0; i < n1-1; ++i)
    {
    	for (int j = 1;j < n1; ++j)
    	{
    		number=R[j]-R[i];
    	final[count]=number;
    	count++;	
    	}
    }
    for (int i = 0; i < n2-1; ++i)
    {
    	for (int j = 1; j < n2; ++j)
    	{
    		number=L[j]-L[i];
    	final[count]=number;
    	count++;	
    	}
    }

    while (i < n1 && j < n2)
    {
    	number=R[i]-L[i];
    	final[count]=number;
    	count++;
    	i++;
    	j++;
    }
}