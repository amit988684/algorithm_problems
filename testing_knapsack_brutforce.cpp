// #include<iostream>
#include<bits/stdc++.h>

using namespace std;


float KnapSack(float v[],float w[],int n,float M,float profit)
{
	if (M==0 || n<0 )
	{
		return profit;
	}
	if (w[n]>M)
	{
		return KnapSack(v,w,n-1,M,profit);
	}

	return max(KnapSack(v,w,n-1,M,profit),KnapSack(v,w,n-1,M-w[n],profit+v[n]));
}


int main()
{
	float v[10],w[10],profit=0,M;
	int n;
	cout<<"number of item";
	cin>>n;
	cout<<"max capacity";
	cin>>M;

	for(int i=0;i<n;i++)
	{
		cin>>w[i]>>v[i];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n-1; ++j)
		{
			if (((float)v[i]/(float)w[i])>((float)v[j]/(float)w[j]))
			{
				int temp = v[i];
				v[i]=v[j];
				v[j]=temp;

				temp = w[i];
				w[i]=w[j];
				w[j]=temp;
			}
		}
	}

	float maxvalue = KnapSack(v,w,n-1,M,profit);
	cout<<maxvalue<<endl;
}