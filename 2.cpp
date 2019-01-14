#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
int size=10;
class search
{
 int a[100],x;
 float lcmp,bscmp;
 public:
 search()
 {
 	lcmp=0;
 	bscmp=0;
 }
 void linearsearch();
 void binarysearch();
 void array();
 void avgtime();
 void sort();
 void print();
}s;

void search::linearsearch()
{
	for(int i=0;i<size;i++)
	{
	  lcmp++;
	  if(a[i]==x)	
	 	break;
	}
}
void search::binarysearch()
{
	int beg=0,end=size-1,mid;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		bscmp++;
		if(x<a[mid])
		{
			end=mid-1;
		}
		else if(x>a[mid])
		{
			beg=mid+1;
		}
		else if(x==a[mid])
		{
			break;
		}
	}
}
void search::array()
{
	for(int i=0;i<size;i++)
	{	a[i]=rand()%100;
		cout<<a[i]<<" ";
	}
	x=rand()%100;
	cout<<endl<<x<<endl;
}
void search::sort()
{
	int i=0,j=0,t;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}
void search::avgtime()
{
	cout<<"Linear Search:\t"<<lcmp/5<<"\tBinary Search:\t"<<bscmp/5<<endl;
}

void search::print()
{
	for(int i=0;i<size;i++)
	{	
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main()
{
  for(int i=0;i<5;i++)
  {
  	s.array();
  	s.linearsearch();
  	s.sort();
  	s.print();
  	s.binarysearch();
  	cout<<"------------------------------------------------------------------------"<<endl;
  }
  s.avgtime(); 
return 0;
}
