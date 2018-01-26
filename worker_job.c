#include<stdio.h>
#include<stdlib.h>
#include<time.h>
	int a[]={
		{15,13,14,17},
		{11,12,15,13},
		{13,12,10,,11},
		{15,17,14,16}
	};
	int row = sizeof(a) / sizeof(a[0]);
	int column = sizeof(a[0])/sizeof(a[0][0]);
	int oppo_row[row][column];
main()
{

	int decision[row][column];
	int oppo_column[row][column];
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			oppo_row[i][j]=a[i][j]-min_of_rows(i);
		}
	}
	for(int j=0;j<column;j++)
	{
		for(int i=0;i<row;i++)
		{
			oppo_column[i][j]=oppo_row[i][j]-min_of_columns(j);
		}
	}
	for(int j=0;j<column;j++)
	{
		for(int i=0;i<row;i++)
		{ 
			if(oppo_row[i][j]==0)
			{
				for(int k=j+1;k<column;k++)
				{
					if(oppo_row[i][k]==0)
					{
						
					}
				}
			}

		}
	}
}
int min_of_rows(int i)
{
	int min;
	min=a[i][0];
	for(int j=0;j<column;j++)
	{
		if(a[i][j]<min)
		{
			min=a[i][j];
		}
	}
	return min;
}
int min_of_columns(int j)
{
	int min;
	min=oppo_row[0][j];
	for(int i=0;i<row;i++)
	{
		if(oppo_row[i][j]<min)
		{
			min=oppo_row[i][j];
		}
	}
	return min;
}