#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b;
	int weight;
};
struct listnode
{
	int vertex;
	int weight;
	listnode *next;
};
void printlist(struct listnode *hptr)
{
	while(hptr)
	{
		cout<<"("<<hptr->vertex<<","<<hptr->weight<<") ";
		hptr=hptr->next;
	}

}
int checklist(struct listnode *hptr,int x)
{
	while(hptr)
	{
		if(hptr->vertex==x)
			return 1;
		hptr=hptr->next;
	}
	return 0;

}
int main()
{
	int noe,nov;
	cout<<"enter the number of vertices"<<endl;
	cin>>nov;
	node n[100];
	cout<<"enter the edges and weights (-666 -666 -666) to exit"<<endl;
	int v1,v2,w;
	int i=0;
	while(1)
	{
		cin>>v1>>v2>>w;
		if(v1==-666 && v2==-666 && w==-666)
			break;
		else
		{	n[i].a=v1;
			n[i].b=v2;
			n[i].weight=w;
			i++;
		}
	}
	noe=i;
	for(int i=0;i<noe;i++)
	{
		cout<<n[i].a<<n[i].b<<n[i].weight<<endl;
	}
 	listnode* arr[nov+1];
 	for(int i=1;i<nov+1;i++)
 		arr[i]=NULL;
	for(int i=0;i<noe;i++)
	{
		if(checklist(arr[n[i].a],n[i].b)==0)
		{
			listnode *ptr1=new listnode;
			ptr1->vertex=n[i].b;
			ptr1->weight=n[i].weight;
			ptr1->next=arr[n[i].a];
			arr[n[i].a]=ptr1;
		}
		if(checklist(arr[n[i].b],n[i].a)==0)
		{
			listnode *ptr2=new listnode;
			ptr2->vertex=n[i].a;
			ptr2->weight=n[i].weight;
			ptr2->next=arr[n[i].b];
			arr[n[i].b]=ptr2;
		}
	}
	cout<<"-----------------------------"<<endl;
	for(int i=1;i<nov+1;i++)
	{	cout<<i<<" : ";
		printlist(arr[i]);
		cout<<endl;
	}
}
