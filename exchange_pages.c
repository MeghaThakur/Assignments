#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int find_present(int a,int s[],int n);
int find_min(int a[],int s[],int na,int n);
main()
{
	int a[]={1,2,3,1};
	int m[]={1,2,3,4};
	int na = sizeof(a)/sizeof(a[0]);
	int nm = sizeof(m)/sizeof(m[0]);
	int s[]={1,2};
	int n = sizeof(s)/sizeof(s[0]);
	clock_t begin=clock();
	for(int i=0;i<na;i++)
	{
		int r=find_present(a[i],s,n);
			if(r==1)
			{
				
				printf("Parsed : %d\n",a[i] );

			}

			else
			{
				int k=find_min(a,s,na,n);
				s[k]=a[i];
				printf("Exchanging index number : %d\n",k );
				printf("Parsed : %d\n",a[i] );
				
			}
		
	}
	 clock_t end=clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("Elapsed time: %.2f.\n",time_spent);
}
int find_present(int a,int s[],int n)
{
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]==a)
		{
			flag=1;
		}
		
	}
	if(flag==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
int find_min(int a[],int s[],int na,int n)
{
	int count[n];
	int counter;
	int index;
	count[0]=10000;
	for(int i=1;i<=n;i++)
	{
		counter=0;
		for(int j=0;j<na;j++)
		{
			if(a[j]==s[i-1])
			{
				counter++;

			}

		}
		count[i]=counter;
		if(count[i]<count[i-1])
		{
			index=i;
		}
	}
return index;
}