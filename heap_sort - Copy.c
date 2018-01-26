#include<stdio.h>
#define N1 8001
#define N2 10000

void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void print(int arr[], int n);
void swap(int *r,int *s);
int swaps=0,comparisons=0;
void fill();
int n;
int arr[];
int main()
{
    fill();
   //n = sizeof(arr)/sizeof(arr[0]);
 
    heapSort(arr, n);
 
    printf("Sorted array is \n");
    //print(arr, n);
    
}
void heapify(int arr[], int n, int i)
{
    int largest = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2; 
 	printf("the value of l and r is %d,%d\n\n",l,r);
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
 	printf("I am looking for heapify process\n");
 	print(arr,n);
    if (largest != i)
    {
    	
        swap(&arr[i], &arr[largest]);
        swaps++;
         heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    	heapify(arr, n, i);
     for (int i=n-1; i>=0; i--)
    {
        swap(&arr[0], &arr[i]);
        swaps++;
 		printf("Here i am viewing the heap sort process\n");
 		print(arr,n);
        heapify(arr, i, 0);
    }
print(arr,n);
printf("The number of comparisons=%d\n",comparisons );
printf("The number of swaps=%d\n",swaps );
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

void fill(){

    int len = N2-N1+1,i , r , temp;
    

    //Fill array with desired numbers
    for( temp=0,i=N1; temp<len; i++,temp++ )
        arr[temp] = i;

    srand( time(NULL) );  //seed rand() c4

    //Fisher–Yates shuffle algorithm
    for( i=len-1; i>0; i-- ){	//n*C1
        r = rand()%i;   //random number	//n*C2
        //swaping using temp
         temp = arr[i]; //n*C3
        arr[i] = arr[r];
        arr[r] = temp; 
    }
 n = sizeof(arr)/sizeof(arr[0]);
    /*Random Numbers b/w N1-N2 are stored in Array num*/

    //print the array
    //for( i=0; i<len; i++ )
       // printf("%d,",num[i]);

}
 
