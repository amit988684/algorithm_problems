#include<iostream>
using namespace std;

int main()
{
	float w[10],v[10],max_value,x[10];
	int n;

	cin>>n>>max_value;
	for (int i = 0; i < n; ++i)
		cin>>w[i]>>v[i];




	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if(w[i]/v[i]>w[j]/v[j])
			{
				int temp = v[i];
				v[i]=v[j];
				v[j] = temp;

				temp = w[i];
				w[i]=w[j];
				w[j]=temp;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (max_value>w[i])
		{
			x[i]=1.0;
			max_value -=w[i];
		}
		else
		{
			x[i]=max_value/w[i];
			max_value=0;
		}
	}

	float max_profit=0;
	for (int i = 0; i < n; ++i)
	{
		max_profit+=x[i]*v[i];
	}

	cout<<max_profit;


}