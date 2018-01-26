#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int petrol_1();
int petrol_2();
int c=8;	//litre
	int f=1;	//litre/km
	int r=1;	//litre/min
	int dist[]={2,7,12,15}; 	//km
	int n=sizeof(dist)/sizeof(dist[0]);
main()
{
	
	int wait1=petrol_1();
	int wait2=petrol_2();
	printf("%d\n",wait1 );
	printf("%d\n",wait2 );
}
int petrol_1()
{
	int wait1=0, left=dist[0],to_fill;
	
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			to_fill=(dist[1]-dist[0])*f;
			//left=left-dist[0];
			printf("Filled at pump number %d petrol : %d\n",i+1, to_fill );
		wait1=wait1+to_fill/r;
		printf("Waited for : %d minutes at pump number %d\n", to_fill/r, i+1);
		

		}
		if(i>0)
		{
		to_fill=(dist[i]-dist[i-1])*f;
		printf("Filled at pump number %d petrol : %d\n",i+1, to_fill );
		wait1=wait1+to_fill/r;
		printf("Waited for : %d minutes at pump number %d\n", to_fill/r, i+1);
		//left=8;
		}
	}
	return wait1;
}
int petrol_2()
{
	int wait2=0,left,to_fill;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			to_fill=c;
			
			printf("Filled at pump number %d petrol : %d\n",i+1, to_fill );
		wait2=wait2+to_fill/r;
		printf("Waited for : %d minutes at pump number %d\n", to_fill/r, i+1);
		}
		if(i>0)
		{
			left=c-(dist[i]-dist[i-1]);
			if (dist[i+1]-dist[i]>left)
			{
				continue;
			}
			else
			{
				to_fill=c;
				printf("Filled at pump number %d petrol : %d\n",i+1, to_fill );
		wait2=wait2+to_fill/r;
		printf("Waited for : %d minutes at pump number %d\n", to_fill/r, i+1);
			}
		}
	}
	return wait2;	
}