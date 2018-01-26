#include<stdio.h>
#include<stdlib.h>
int find_max();
void vertex_cover();
void count();
int arr[3][3]={{0,1,0},{1,0,1},{0,1,0}};
	int row = sizeof(arr) / sizeof(arr[0]);
	int column = sizeof(arr[0])/sizeof(arr[0][0]);
	int sum[3];
int main(int argc, char const *argv[])
{
	for(int i=0;i<row;i++)
	{
		sum[row]=0;
	}
	vertex_cover();
	return 0;
}
void vertex_cover()
{
	int final[5];
	for (int i = 0; i < 5; ++i)
	{
		final[i]=0;
	}
	count();
	int counter=0;
	for(int i=0;i<row;i++)
	{
		
		if(sum[i]>0)
		{
			int k=find_max();
			final[counter]=k;
			sum[k]=0;
			counter++;
			for(int j=0;j<column;j++)
			{
				if(arr[k][column]==1)
				{
					sum[j]=0;
				}
			}
		}
	}
	printf("I am in main()\n");
for(int i=0;i<counter-1;i++)
{
	printf("%d\n",final[i] );
}

}
void count()
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			if(arr[i][j]==1)
			{
				sum[i]=sum[i]+1;
			}
		}
	}
	printf("I am in counter()\n");
	for(int i=0;i<row;i++)
{
	printf("%d\n",sum[i] );
}
}
int find_max()
{
	int j=0;
	int max=sum[0];
	for(int i=1;i<row;i++)
	{
		if(sum[i]>max)
		{
			j++;
		}
	}
	return j;
}