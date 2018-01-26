#include <stdio.h>
bool isSubsetSum(int set[], int n, int sum);
int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum(set, n, sum) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;

}
bool isSubsetSum(int set[], int n, int sum)
{    bool subset[sum+1][n+1];
 
    
    for (int i = 0; i <= n; i++)
      subset[0][i] = true;
 
    
    for (int i = 1; i <= sum; i++)
      subset[i][0] = false;
 
     
     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= set[j-1])
           subset[i][j] = subset[i][j] || 
                                 subset[i - set[j-1]][j-1];
       }
     }
 
   for (int i = 0; i <= sum; i++)
     {
       for (int j = 0; j <= n; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     }
 
     return subset[sum][n];
}
 
