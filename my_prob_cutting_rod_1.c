
#include<stdio.h>
#include<limits.h>
int cut_rod(int price[], int n);
int max(int a, int b);
int main()
{
    int arr[] = {1, 4, 8, 9, 100, 17, 19, 22};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Max Profit is:  %d\n", cut_rod(arr, size));
    getchar();
    return 0;
}

int cut_rod(int price[], int n)
{
   int val[n+1];
   val[0] = 0;
   int i, j;
 
   for (i = 1; i<=n; i++)
   {
       int max_val = INT_MIN;
       for (j = 0; j < i; j++)
         max_val = max(max_val, price[j] + val[i-j-1]);
       val[i] = max_val;
   }
 
   return val[n];
}
int max(int a, int b) 
{
 return (a > b)? a : b;
}

