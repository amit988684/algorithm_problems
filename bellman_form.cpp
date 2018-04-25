#include<iostream>
#include<stdlib.h>

using namespace std;
int u[100]={0},v[100]={0},d[100]={0},wt[100]={0};

void bellman(int vertices_no,int e,int s)
{
	for (int i = 0; i < 100; ++i)
	{
		wt[i]=99;
	}

	wt[s]=0;

	for (int i = 0; i < vertices_no; ++i)
	{
		for (int j = 0; j < e; ++j)
		{
			if (wt[u[j]] != 99)
			{
				if (wt[v[j]]>d[j]+wt[u[j]])
				{
				   wt[v[j]]=d[j]+wt[u[j]];
				}
			}
		}	
	}
}


int main()
{
    int vertices_no; 
    int e;
    cout<<"enter the number of vertices";
    cin>>vertices_no;
    cout<<"etner the number of edges";
    cin>>e;
    int s;

    cout<<"enter the source --- destination --- weight \n";
    for (int i = 0; i < e; ++i)
    {
    	cin>>u[i]>>v[i]>>d[i];
    }
 
 cout<<"etner the srouyce";
 cin>>s;

    bellman(vertices_no,e,s);

    cout<<"The Source is : "<<s<<endl;
    
    for (int i = 0; i < vertices_no; ++i)
    {
    	if (wt[i]!=99)
    	{
    	cout<<i<<"  ---  >  "<<wt[i]<<endl;	
    	}
    	else
    	cout<<i<<"  ---  >  "<< "No Path from source"<<endl;	

    	
    }
    return 0;
}