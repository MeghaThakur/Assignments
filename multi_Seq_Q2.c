#include<stdio.h>
#include<limits.h>
#include<time.h>
int Mult(int p[], int n); 
int main()
{
    int arr[] = {1, 2, 3, 4};
    clock_t begin=clock();
    int size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Min multiplications===> %d ",
                       Mult(arr, size));
 clock_t end=clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("Elapsed time: %.2f.\n",time_spent);
    getchar();
    return 0;
}

int Mult(int p[], int n)
{

    int m[n][n]; 
    int i, j, k, L, q;
    
    for (i=1; i<n; i++)
        m[i][i] = 0;
 
    
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
 
    return m[1][n-1];
}
 
