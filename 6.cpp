#include<bits/stdc++.h>
using namespace std;
class lab
{
 char w[11][10],m[11][20],w1[10][10],m1[10][20];
 public:
 void merge(int,int);
 void mergeSort(int,int);
 void read();
 void print();
 void newWord(char[],char[],int);
}l;
void lab::read()
{
	for(int i=0;i<10;i++)
	{
		cout<<"Word: ";
		cin>>w[i];
		cout<<"Meaning: ";
		cin>>m[i];
		cout<<"-------------------------------"<<endl;
	}
}
void lab::mergeSort(int beg,int end)
{
	if(beg<end)
	{
		int mid=(beg+end)/2;
		mergeSort(beg,mid);
		mergeSort(mid+1,end);
		merge(beg,end);
	}
}
void lab::merge(int beg,int end)
{
	char w1[10][10],m1[10][20];
	int i=beg,k=beg,mid=(beg+end)/2;
	int j=mid+1;
	while(i<=mid && j<=end)
	{
		if(strcmp(w[i],w[j])<=0)
		{
			strcpy(w1[k],w[i]);
			strcpy(m1[k],m[i]);
			k++;
			i++;	
		}
		else
		{
			strcpy(w1[k],w[j]);
			strcpy(m1[k],m[j]);
			k++;
			j++;
		}
	}

	for(;i<=mid;i++)
	{
		strcpy(w1[k],w[i]);
		strcpy(m1[k],m[i]);
		k++;			
	}
	for(;j<=end;j++)
	{
		strcpy(w1[k],w[j]);
		strcpy(m1[k],m[j]);
		k++;			
	}
	
	for(i=beg;i<=end;i++)
	{
		strcpy(w[i],w1[i]);
	}
}
void lab::print()
{
	for(int i=0;i<10;i++)
		cout<<w[i]<<" ";
}
void lab::newWord(char word[],char meaning[],int end)
{
 int i=0,k=0,c=0;
 char w1[11][10],m1[11][20];
    while(i<=end && c==0)
	{
		if(strcmp(w[i],word)<=0)
		{
			strcpy(w1[k],w[i]);
			strcpy(m1[k],m[i]);
			k++;
			i++;	
		}
		else
		{
			strcpy(w1[k],word);
			strcpy(m1[k],meaning);
			k++;
			c++;
		}
	}

	for(;i<=end;i++)
	{
		strcpy(w1[k],w[i]);
		strcpy(m1[k],m[i]);
		k++;			
	}
	if(c==0s)
	{
		strcpy(w1[k],word);
		strcpy(m1[k],meaning);
		k++;			
	}
	
	for(i=0;i<=end;i++)
	{
		strcpy(w[i],w1[i]);
	}
}
int main()
{
	char word[10],meaning[20];
	l.read();
	l.mergeSort(0,9);
	l.print();
	cout<<endl;
	cout<<"enter a NEW word and meaning ";
	cin>>word>>meaning;
	l.newWord(word,meaning,9);
	l.print();
   
	
}
