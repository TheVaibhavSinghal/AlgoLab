#include<bits/stdc++.h>
using namespace std;
float inf=numeric_limits<float>::infinity();
int nov,noe=0;
float c[100][100];
float RoutingTable1[100][100];
float RoutingTable2[100][100];
void Dijkstra(int s)
{
	//cout<<nov<<endl;
	int mark[nov],i,j;
	float dist[nov],temp[nov];
	for(i=0;i<nov;i++)
	{
		mark[i]=0;
		dist[i]=c[s][i];
	}
	mark[s]=1;
	dist[s]=0;
	int k=1,markedindex;
	for(k=1;k<nov;k++)
	{
	
		j=0;
		for(i=0;i<nov;i++)
		{
			if(mark[i]==0)
				temp[j++]=dist[i];
		}
		sort(temp,temp+j);
		for(i=0;i<nov;i++)
		{
			if(mark[i]==0 && dist[i]==temp[0])
			{	mark[i]=1;
				break;
			}
		}
		markedindex=i;
		for(i=0;i<nov;i++)
		{
			if(dist[i]>dist[markedindex]+c[markedindex][i])
				dist[i]=dist[markedindex]+c[markedindex][i];
		}
	}
	for(i=0;i<nov;i++)
		RoutingTable1[s][i]=dist[i];
	
}

void Bellman(int s)
{
	int i,j;
	float dist[nov];
	for(i=0;i<nov;i++)
	{
		dist[i]=inf;
	}
	dist[s]=0;
	int flag=0;
	for(int i=0;i<nov;i++)
	{
		for(int j=0;j<nov;j++)
		{
			  for(int k=0;k<nov;k++)
			  {
			  		if(i==nov-1)
			  		{	
			  			if(dist[k]>dist[j]+c[j][k])
			  				flag++;
			  		}
			  		else if(dist[k]>dist[j]+c[j][k])
			  			dist[k]=dist[j]+c[j][k];
			  		
			  }
		}
		
	}
	if(flag!=0)
		cout<<"Negative edge cycle";
	else
		/*for(i=0;i<nov;i++)
			cout<<dist[i]<<" ";*/
		for(i=0;i<nov;i++)
			RoutingTable2[s][i]=dist[i];
	
}
int main()
{
	int i,j,v1,v2,w;
	cout<<"Enter the number of vertices ";
	cin>>nov;
	
	for(i=0;i<nov;i++)
	{	for(j=0;j<nov;j++)
		{
			c[i][j]=inf;		
		}	
	}
	//cout<<"Enter the adjacency matrix weights (enter 100 for no edge)
	cout<<"Enter the vertices of edge and corresponding weight (-1 -1 -1 to end) (starts from 0)\n";
	while(1)
	{
		cin>>v1>>v2>>w;
		if(v1==-1 && v2==-1 && w==-1)
			break;
		else
		 {
			c[v1][v2]=w;
			noe++;
		}
	}
	/*cout<<"-------------------------"<<endl; 
	for(i=0;i<nov;i++)
	{	
		for(j=0;j<nov;j++)
		{
				cout<<c[i][j]<<" ";	
		}	
		cout<<endl;
	}*/
	/*int s;
	cout<<"Enter the source vertex ";
	cin>>s;
	*/
	//Dijkstra(s);
	
	for(i=0;i<nov;i++)
		Dijkstra(i);
	for(i=0;i<nov;i++)
		Bellman(i);
	//Bellman(s);
	cout<<"---------------------"<<endl;
	for(i=0;i<nov;i++)
	{	for(j=0;j<nov;j++)
			cout<<RoutingTable1[i][j]<<"\t";
		cout<<endl;
	}
	cout<<"---------------------"<<endl;
	for(i=0;i<nov;i++)
	{	for(j=0;j<nov;j++)
			cout<<RoutingTable2[i][j]<<"\t";
		cout<<endl;
	}
}
