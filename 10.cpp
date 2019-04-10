#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int u,v;
	float weight;

};
int parent[100];
struct comp
{
	 int index;
	 int x,y;
};
float distance(int x1,int x2,int y1,int y2)
{
	return (sqrt(pow(x2-x1,2)+pow(y2-y1,2)));
}
bool condition(edge e1,edge e2)
{
	return (e1.weight<e2.weight);
}

int find(int u)
{
	while(parent[u]>0)
	{
		u=parent[u];
	}
	return u;
}

void Union(int r1,int r2)
{
	if(abs(parent[r1])>abs(parent[r2]))
	{
		parent[r1]+=parent[r2];
		parent[r2]=r1;
	}
	else
	{
		parent[r2]+=parent[r1];
		parent[r1]=r2;
	}
}
int main()
{
	int noe,nov;
	cout<<"Enter the number of computers"<<endl;
	cin>>nov;
	if(nov==1)
	{	
		cout<<"Communication requires min 2 computers"<<endl;
		exit(0);
	}
	comp c[nov];
	cout<<"Enter the coordinates(x,y) of:"<<endl;
	int i=0;
	
	for(i=0;i<nov;i++)
	{
		c[i].index=i+1;
		cin>>c[i].x>>c[i].y;	
	}
	noe=nov*(nov-1)/2;
	edge e[noe];
	i=0;
	for(int j=0;j<nov;j++)
	{
		for(int k=j+1;k<nov;k++)
		{
			e[i].u=c[j].index;
			e[i].v=c[k].index;
			e[i].weight=distance(c[j].x,c[k].x,c[j].y,c[k].y);
			i++;		
		}			
	}
	sort(e,e+noe,condition);
	for(i=1;i<=noe;i++)
	 parent[i]=-1;	
	edge t[nov-1];
	int j=0; //size of t
	for(i=0;i<noe;i++)
	{
		if(j<nov)
		{
			int r1=find(e[i].u);
			int r2=find(e[i].v);
			if(r1!=r2)
			{
				Union(r1,r2);
				t[j].u=e[i].u;
				t[j].v=e[i].v;
				t[j].weight=e[i].weight;
				j++;
			}
		}
		else
		 break;
	
	}
	cout<<"--------------------------------------"<<endl;
	for(i=0;i<nov-1;i++)
	{
		cout<<t[i].u<<" "<<t[i].v<<" "<<t[i].weight<<endl;
	}
	
			
}
