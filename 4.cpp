#include<bits/stdc++.h>
using namespace std;
int nof=0;
class lab
{
    int n1;
    int a[10][10];
    
    
public:
    int n2;int b[100];
    int celeb();
    void dosa(int);
    void flip(int);
    int check(int []);
    int sort();
    void print();
}l;
int lab::check(int s[])
{
    int count=0;
    for(int i=0;i<n1;i++)
        if(s[i]==1)
            count++;
    return count;
}

int lab::celeb()
{
	int i=0,j=0;
	cout<<"enter the no of celebs";
	cin>>n1;
	
	int s[n1];
	for(i=0;i<n1;i++)
	    s[i]=1;

	
	cout<<"enter the relationship matrix(row knows column)\n";
	for(i=0;i<n1;i++)
	{
	    for(j=0;j<n1;j++)
	    {
	        cin>>a[i][j];
	    }
	}

	while(check(s)>1)
	{
	    i=0,j=1;
	    while(i<n1 && j<n1)
	    {
	        if(s[i]==1 && s[j]==1)
	        {
	            if(i!=j)
	            {
	                if(a[i][j]==1)
	                {    s[i]=0; i++;}
	                else 
	                {    s[j]=0; j++;}
	            }
	            else
	            {
	                j++;
	            }
	        }
	   }          
	}
	int pos=0,flag=1;
	for(i=0;i<n1;i++)
	{
	    if(s[i]==1)
	    {    
	        pos=i; break;
	    }
	}
	for(i=0;i<n1;i++)
	{
	    if(a[i][pos] == a[pos][i] && pos!=i)
	        flag=0;
	}
	if(flag==1)
	    return pos+1;
	else
	    return -1;
}
void lab::flip(int end)
{
    int size=end+1;
    int m[size],i;
    for(i=0;i<size;i++)
    {
        m[i]=b[end-i];
    }
    for(i=0;i<size;i++)
    {
        b[i]=m[i];
    }
    nof++;
}
void lab::dosa(int n) //n arraysize
{
    if(n>1)
    {
    int i=0,max,maxpos=0;
    max=b[0];
    for(i=1;i<n;i++)
    {
        if(b[i]>max)
        { max=b[i];maxpos=i;}
    }
    if(maxpos!=0 && maxpos!=n-1)
        flip(maxpos);
        
    if(maxpos!=n-1)
        flip(n-1); //n-1 pos
    dosa(n-1); //n-1 array size
    }
}
void lab::print()
{
    for(int i=0;i<n2;i++)
        cout<<b[i]<<" ";
    cout<<endl;
}

int main()
{
    int ch;
    cout<<"1.Celebrity problem\n2.Dosa flipping problem\nEnter choice";
    cin>>ch;
    if(ch==1)
        cout<<l.celeb();
    else if(ch==2)
    {
        cout<<"enter the no of dosas";
        cin>>l.n2;
        for(int i=0;i<l.n2;i++)
            cin>>l.b[i];
        l.dosa(l.n2);
        l.print();
        cout<<endl<<nof;
    }       
}
