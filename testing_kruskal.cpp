#include<iostream>
using namespace std;

struct Set
{
	int nodes;
	int *parent,*rank;

	Set(int node){
		nodes=node;
		parent = new int[node];
		rank = new int[node];

		for (int i = 0; i < node; ++i)
		{
			parent[i]=-1;
			rank[i]=0;
		}
	}

	int findParent(int x)
	{
		if (parent[x]!=-1)
		{
			return findParent(parent[x]);
		}
			return x;
	}

	void mergeTrees(int x,int y)
	{
		if (rank[x]>rank[y])
		{
			parent[y]=x;
		}
		else
			parent[x]=y;
		if (rank[x]==rank[y])
		{
			rank[x]++;
		}
	}

};

void Kruskal(int w[],int s[],int d[],int edges,int nodes)
{
	int mcst=0;
	Set myset(nodes);
	for (int i = 0; i < edges; ++i)
	{
		int p1 = myset.findParent(s[i]);
		int p2 = myset.findParent(d[i]);

		if (p1 == p2)
		{
			continue;
		}
		myset.mergeTrees(p1,p2);
		mcst+=w[i];
	}
	cout<<"\nminimum = "<<mcst<<endl;

}


void Sort(int w[],int s[],int d[],int n)
{
	for (int i = 0; i <n; ++i)
	{
		for (int j = 0; j<n-i-1; ++j)
		{
			if (w[j] > w[j+1])
			{
				swap(w[j],w[j+1]);
				swap(s[j],s[j+1]);
				swap(d[j],d[j+1]);

			}

		}
	}
}



int main()
{
	int n,e;
	cin>>n>>e;
	int w[e],s[e],d[e];

	for (int i = 0; i < e; ++i)
	{
		cin>>w[i]>>s[i]>>d[i];
	}

	Sort(w,s,d,e);
	Kruskal(w,s,d,e,n);

	return 0;
}