#include <iostream>  
#include<time.h>
using namespace std;  
 
struct Result  
{  
   int max1;  
   int max2;  
};  

Result FirstSecondMax(int A[], int l, int r)  
{  
     
    Result res;  
    res.max1 = A[l];  
    res.max2 = A[l];  
     
    if (l == r) return res;  
	if (r - l == 1)  
    {  
        if (A[r] >= A[l])  
        {  
            res.max1 = A[r];  
            res.max2 = A[l];  
        }  
        else  
        {  
            res.max1 = A[l];  
            res.max2 = A[r];  
        }  
          
        return res;  
    }  
  
   int m = (l + r)/2;  
     
    
   Result lres = FirstSecondMax(A, l, m);  
   Result rres = FirstSecondMax(A, m + 1, r);  
  
   if (rres.max1 >= lres.max1)  
   {  
 
       res.max1 = rres.max1;  
  
       if (rres.max2 >= lres.max1)  
       {  
           res.max2 = rres.max2;  
       }  
       else  
       {  
           res.max2 = lres.max1;  
       }  
   }  
  
   else  
   {  
      
       res.max1 = lres.max1;  
  
       if (lres.max2 >= rres.max1)  
       {  
           res.max2 = lres.max2;  
       }  
       else  
       {  
           res.max2 = rres.max1;  
       }  
  }  
  
   return res;  
}  

int main()  
{    
    int A[100] ;      
    for(int i=0;i<100;i++)
  {
    A[i]=i;
  }
  clock_t begin=clock();
    Result res = FirstSecondMax(A, 0, 100);  
    clock_t end=clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("Elapsed time: %.2f.\n",time_spent);
    cout << res.max1 << " : " << res.max2 << endl;  
}