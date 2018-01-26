#include <stdio.h>
#include<time.h>
#define N1 8001
#define N2 10000

void main(){

    int len = N2-N1+1,i , r , temp;
    int num[len];

    //Fill array with desired numbers
    for( temp=0,i=N1; temp<len; i++,temp++ )
        num[temp] = i;
clock_t begin = clock();
    srand( time(NULL) );  //seed rand() c4

    //Fisher–Yates shuffle algorithm
    for( i=len-1; i>0; i-- ){	//n*C1
        r = rand()%i;   //random number	//n*C2
        //swaping using temp
         temp = num[i]; //n*C3
        num[i] = num[r];
        num[r] = temp; 
    }

    /*Random Numbers b/w N1-N2 are stored in Array num*/

    //print the array
    for( i=0; i<len; i++ )
        printf("%d,",num[i]);
clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("Elapsed time: %.2f.\n",time_spent);
}