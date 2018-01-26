#include<stdio.h>
#include<time.h>
int main()
{
		int cost_matrix[5][5]={{9,11,14,11,7},{6,15,13,13,10},{12,13,6,8,8},{11,9,10,12,9},{7,12,14,10,14}};
		int result[5][5];
		int smallest,small_i,small_j;
		int costTillNow=0;	
		int i,j,k,p,q;
		clock_t begin=clock();
		for(i=0;i<5;++i)
		{
			for(j=0;j<5;++j)
			{
				result[i][j]=0;
			}
		}
		for(i=0;i<5;++i)
		{
			smallest=cost_matrix[0][0];
			small_i=0;
			small_j=0;
			
			for(k=0;k<5;++k)
			{
				for(p=0;p<5;++p)
				{
					if(smallest>cost_matrix[k][p])
					{
						smallest=cost_matrix[k][p];
						small_i=k;
						small_j=p;
					}
				}
			}
			costTillNow=costTillNow+smallest;
			for(q=0;q<5;++q)
			{
				cost_matrix[q][small_j]=8288;
			}
			for(q=0;q<5;++q)
			{
				cost_matrix[small_i][q]=8288;
			}
			result[small_i][small_j]=1;
		}
		for(i=0;i<5;++i)
		{
			for(j=0;j<5;++j)
			{
				printf("%d\t",result[i][j]);
			}
			printf("\n");
		}
		
		printf("Minimum cost is %d",costTillNow);
		clock_t end=clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("Elapsed time: %.2f.\n",time_spent);
		
}
