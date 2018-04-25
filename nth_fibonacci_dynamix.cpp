#include<iostream>
using namespace std;

int ar[100]={0};
int count=0;
int fibo(int n)
{
		count++;

	if (n==0)
	{
		return 0;
	}

	if (n==1 || n==2)
	{
		return 1;
	}

	if (ar[n]!=0 && n>2)
	{
		return ar[n];
	}
	else
	{
		ar[n]=fibo(n-1)+ fibo(n-2);
		return ar[n];
	}

}

int main()
{
	int n;
	cin>>n;
	cout<<fibo(n);
	cout<<" Count took = "<<count<<endl;
	
	for (int i = 0; i < n; ++i)
	{
		cout<<ar[i]<<" "<<endl;		
	}
}