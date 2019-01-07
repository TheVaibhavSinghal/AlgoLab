#include<iostream>
#include<stdlib.h>
using namespace std;
class sort
{
	int a[10],a1[10],a2[10];
	float bCmp,sCmp,iCmp;
	
	public:
	sort()
	{
	 bCmp=sCmp=iCmp=0;
	}
	void bSort();
	void sSort();
	void iSort();
	void input();
	void print(int n);
	void printarray1();
	void printarray2();
	void printarray3();
};
void sort::bSort()
{
 int i,j,t,swap;
 for(i=0;i<10;i++)
 {
 	swap=0;
 	for(j=0;j<10-i-1;j++)
 	{
 	 if(a[j]>a[j+1])
 	 {
 	  t=a[j];
 	  a[j]=a[j+1];
 	  a[j+1]=t;
 	  swap=1;
 	 }
 	 bCmp++;
 	}
 	if(swap==0)
 	 break;
 }
}
void sort::sSort()
{
 int i,j,t,max,pos;
 max=a1[0];
 pos=0;
 for(i=0;i<10;i++)
 {
 	max=a1[0];
 	pos=0;
 	for(j=1;j<10-i;j++)
 	{
 	 if(a1[j]>max)
 	 {	max=a1[j];
 	 	pos=j;
 	 }
 	 sCmp++;
 	}
 	t=a1[10-i-1];
 	a1[10-i-1]=a1[pos];
 	a1[pos]=t;
 }
}
void sort::iSort()
{
	int i,j,t;
	for(i=0;i<10;i++)
	{
		for(j=i;j>0;j--)
		{
			iCmp++;
			if(a2[j]<a2[j-1])
			{
				t=a2[j];
				a2[j]=a2[j-1];
				a2[j-1]=t;
			}
			else
			 break;
			
		}
	}
	
}
void sort::input()
{
 int i=0;
 for(i=0;i<10;i++)
 {	
 	a[i]=rand()%100;
 	a1[i]=a[i];
 	a2[i]=a[i];
 }
}
void sort::print(int n)
{
	cout<<"Bubble Sort\t\t:\t"<<bCmp/n<<endl;
	cout<<"Selection Sort\t\t:\t"<<sCmp/n<<endl;
	cout<<"Insertion Sort\t\t:\t"<<iCmp/n<<endl;

}
void sort::printarray1()
{
 for(int i=0;i<10;i++)
  cout<<a[i]<<" ";
  cout<<endl;
}
void sort::printarray2()
{
 for(int i=0;i<10;i++)
  cout<<a1[i]<<" ";
  cout<<endl;
}
void sort::printarray3()
{
 for(int i=0;i<10;i++)
  cout<<a2[i]<<" ";
  cout<<endl;
}		
int main()
{
	sort s;
	int n;
	cout<<"Enter the number of arrrays you want to sort";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		s.input();
		s.printarray1();
		s.bSort();
		s.printarray1();
		s.sSort();
		s.printarray2();
		s.iSort();
		s.printarray3();
	}
	s.print(n);
	return 0;	
}
