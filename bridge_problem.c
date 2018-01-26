#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sort();
int a[]={15,10,14,17,2};
int count;
int n=sizeof(a)/sizeof(a[0]);
main()
{
	clock_t begin=clock();
	sort();	
	move_a_to_b();
		clock_t end=clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("Elapsed time: %.2f.\n",time_spent);
		

	return 0;
}

void sort()
{
	int t;

	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}

}

void move_a_to_b()
{
	
	int m=n;
	int i=0;
	do
	{	
		printf("%d and %d going\n",a[0],a[i+1] );
		count=count+a[i+1];
		if(m>2)
		{
		printf("%d returning\n",a[0]);
		count=count+a[0];
		}
		i++;
		m--;
	}while(m>=2);
printf("The total count of time is:%d\n",count);

}



