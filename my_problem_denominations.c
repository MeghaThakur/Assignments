#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
int n = sizeof(deno)/sizeof(deno[0]);
void findMin(int V);
int main()
{
   int n = 93;
  printf("The denominations are:\n");
   findMin(n);
   return 0;
}

void findMin(int V)
{
  int count=V;
for(int i=n-1;i>=0;i--)
{
  while(deno[i]<=count)
  {
    count=count-deno[i];
    printf("%d\n",deno[i] );
  }
}

}

