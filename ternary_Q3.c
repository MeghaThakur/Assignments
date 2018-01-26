#include<stdio.h>
#include<time.h>
long int ternary_search(long int arr[],long int l,long int r,long int key);
main()
{
long int arr[100000];
for(long int i=0;i<100000;i++)
{
	arr[i]=i;
}
long int result;
long int key=10256;
long int n = sizeof(arr)/ sizeof(arr[0]);
clock_t begin=clock();
result=ternary_search(arr,0,n-1,key);
clock_t end=clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("Elapsed time: %.2f.\n",time_spent);
if(result==-1)
{
printf("Element not found");
}
else
{
printf("Index:%d",result);
}
}

long int ternary_search(long int arr[],long int l,long int r,long int key)
{
long int mid1=l+(r-l)/3;
long int mid2=mid1+(r-mid1)/2;
if(l<=r)
{
if(key==arr[mid1])
{
return mid1;
}
if(key==arr[mid2])
{
return mid2;
}
if(key<arr[mid1])
{
return ternary_search(arr,l,mid1-1,key);
}
if(key<arr[mid2]&&key>arr[mid1])
{
return ternary_search(arr,mid1,mid2,key);
}
if(key>arr[mid2])
{
return ternary_search(arr,mid2+1,r,key);
}
}
else
{
return -1;
}

}

