#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = {-3,-5,7,-4,1,-8,3,-7,5,-9,5,-2,4};
	
	int N = sizeof(arr)/sizeof(arr[0]);

	int i=0,j=0,count=0;
	int sum = 0;
	

	while(i<N)
	{	
		while(i<N&&arr[i]<0)++i; // discards negative numbers which are occuring before any subarray 
		if(i<N)
		{
			count++;
			j=i;
			sum = 0;		 //initial sum for subarray is zero
			cout<<i;         //start index of subarray
			while(j<N)
			{
				sum+=arr[j];
				if(sum>=0)
					i=j+1;		//ensures to reconfigure the index when sum is positive 
				++j;
			}
			cout<<' '<<i-1<<endl; //end index of the subarray
		}
	}
	cout<<count<<endl;
	return 0;

}

