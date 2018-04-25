#include<iostream>
using namespace std;

double ar[100]={0};
int count=0;
double fact(int n)
{	
	count++;
	if (n==1 || n==0)
	{
		return 1;
	}
	if (ar[n]!=0)
	{
		return ar[n];
	}
	else{
		ar[n] =n*fact(n-1);
		return ar[n];
	}

}

int main()
{
	int n,r;
	cin>>n>>r;
	double nCr=fact(n)/(fact(n-r)*fact(r));
	cout<<nCr<<" - took - ";
	cout<<count<<" count\n";
}