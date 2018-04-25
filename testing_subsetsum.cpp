#include<iostream>
using namespace std;

bool SubSetSum(int array[],int sum,int n)
{
	if (sum==0)
	{
		return true;
	}
	if (sum!=0 && n<=0)
	{
		return false;
	}

	if (array[n]<=sum)
	{
		return SubSetSum(array,sum,n-1) || SubSetSum(array,sum-array[n],n-1);
	}
	return SubSetSum(array,sum,n-1);
}



int main()
{
	int array[10],n=0,sum;
	cin>>n;
	cout<<"enter the sum";
	cin>>sum;
	for (int i = 0; i < n; ++i)
	{
		cin>>array[i];
	}

	if (SubSetSum(array,sum,n-1))
	{
		cout<<"yes";
	}
	else
		cout<<"no";

	return 0;
}