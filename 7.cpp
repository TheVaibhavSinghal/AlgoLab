#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int beg,int end,int l)
{
	int index=0;
	for(int i=beg;i<=end;i++)
	 if(a[i]==l)
	  index=i;
	  
	int t=a[beg];
	a[beg]=a[index];
	a[index]=t;
	
	int i=beg+1,j=end;
	int pivot=a[beg];
	
	while(i<j)
	{
		while(a[i]<=pivot && i<end)
		{
			i++;
		}
		while(a[j]>pivot && j>beg)
		{
			j--;
		}
		if(i<j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}	                                             
	t=a[j];
	a[j]=a[beg];
	a[beg]=t;
	
	return j+1;

}
int select(int a[],int beg,int end,int I,int n)
{
	if(n<=5)
	{
		int b[n],i=beg,j=0;
		while(i<=end)
		{
			b[j]=a[i];
			i++;
			j++;
		}
		sort(b,b+n);
		cout<<"Sorted array"<<endl;
		for(i=0;i<n;i++)
		 cout<<b[i]<<" ";
		cout<<endl;
		cout<<"I = "<<I<<endl;
		return b[I-beg-1];
	}
	//
	int m=floor(n/5),f=0,u=beg,s=ceil((float)n/5);
	cout<<m<<" "<<u<<" "<<s<<endl;
	int x[s];
	while(m>0)
	{
		x[f]=select(a,u,u+4,3,5);
		f++;
		u+=5;
		m--;
	}
	for(int g=0;g<floor(n/5);g++)
	 cout<<x[g]<<" ";
	cout<<endl;
	int z=n%5;
	if(z!=0)
	{
		cout<<z<<" "<<u<<endl;
		x[f]=select(a,u,u+z-1,ceil((float)z/2),z);
		cout<<x[f]<<endl;
		f++;	
	}
	int l=select(x,0,f-1,ceil((float)f/2),f);
	
	cout<<"median of medians "<<l<<endl;
	int i;
	for(i=0;i<n;i++)
	 cout<<a[i]<<" ";
	cout<<endl;
	int k=partition(a,beg,end,l);
	
	for(i=0;i<n;i++)
	 cout<<a[i]<<" ";
	cout<<endl<<"partition "<<k<<endl;
	cout<<"i "<<I<<endl;
	if(k==I)
	 return a[k-1];
	else if(I<k)
	{
		cout<<"beg,end "<<beg<<" "<<k-2<<endl;
		return(select(a,beg,k-2,I,k-beg-1));
	}
	else if(I>k)
	{
		cout<<"beg-end "<<k<<" "<<end<<" "<<end-k+1<<" "<<I<<endl;
		return(select(a,k,end,I,end-k+1));	
	}
}



int main()
{
	int n;
	cout<<"Enter the size ";
	cin>>n;
	int a[n],ca[n];
	cout<<"Enter the elements ";
	for(int i=0;i<n;i++)
	{
	 cin>>a[i];
	 ca[i]=a[i];
	}
	int k;
	cout<<"Enter k ";
	cin>>k;
	int y;
	//for(int i=1;i<=k;i++)
	//{
	//y=select(a,0,n-1,i,n);
	//cout<<i<<"TH smallest value is: "<<y<<endl;
	//for(int j=0;j<n;j++)
	// a[j]=ca[j];
	//}
	y=select(a,0,n-1,5,n);
	cout<<"5TH smallest value is: "<<y<<endl;
	//for(int j=0;j<n;j++)
	// a[j]=ca[j];
	//y=select(a,0,n-1,ceil((float)n/2),n);
	//cout<<"MEDIAN : "<<y<<" "<<endl;
}

	

