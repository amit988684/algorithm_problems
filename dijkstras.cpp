#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void Dijkstras(int nodes);
void printFunction(int nodes,int d[]);
int findMinValue(int m[],int d[],int nodes);

int graph[9][9] ;
int s = 0;
int main()
{

  int numberOfNodes;
	cout<<"Enter the number of nodes in the graph : ";
	cin>>numberOfNodes;
	for(int i=0;i<numberOfNodes;i++){
     for (size_t j = 0; j < numberOfNodes; j++) {
       cin>>graph[i][j];
     }
   }

Dijkstras(numberOfNodes);
  return 0;

}



void Dijkstras(int nodes)
{
  int d[nodes],m[nodes],prev[nodes],u;

  for (size_t i = 0; i < nodes; i++) 
  {
    if (graph[s][i]!=0) 
    {
      d[i] = graph[s][i];
  	}
  
    else
    {
      d[i] = INT_MAX;
    }
      m[i] = 0;
      prev[i]=-1;
  }
  m[s] = 1;
  d[s] = 0;

  for (size_t i = 1; i < nodes; i++) {
    u = findMinValue(m,d,nodes);

    // find
    m[u] = 1;
    for (size_t w = 0; w < nodes; w++) {
      if (graph[u][w]==0) {
        continue;
      }
      if (m[w] != 0) {
        continue;
      }
      if (d[w]>(d[u] + graph[u][w]))
      {
        d[w] = d[u] + graph[u][w];
        prev[w] = u;
      }
    }
  }

  printFunction(nodes,d);
}


void printFunction(int nodes,int d[])
{
  for (size_t i = 1; i < nodes; i++) {
    cout<<i<<" - "<<d[i]<<endl;
  }
}
	
int findMinValue(int m[],int d[],int nodes)
{
  int index,min=INT_MAX;

  for (size_t i = 0; i < nodes; i++)
  {
    if (m[i]==0)
    {
      if (d[i]<min)
      {
        min = d[i];
        index = i;
      }
    }

  }
  return index;
}
