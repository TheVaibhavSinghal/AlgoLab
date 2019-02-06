#include<bits/stdc++.h>
using namespace std;

int noc=0;
class q
{
 int a[100];

 int partition(int beg,int end)
 {
 
  int k=rand()%(end-beg)+beg;
  int pivot=a[k];
  int i=beg,j=end;
  int t;
  while(i<j)
  {
    while(a[i]<=pivot && i<end)
    {   
    	 i++;
    	 noc++;
    }
    while(a[j]>pivot && j>beg)
    {
        j--;
        noc++;
        if(j-1==k)
         j-=2;
    }
    if(i<j)
    {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
  }
  if(i>j)
  {
  	t=a[j];
  	a[j]=a[k];
  	a[k]=t;
  }
  return j;
 }
 
 public:
 void random()
 {
  for(int i=0;i<100;i++)
  {	
  	a[i]=rand()%10;
  }
 }
 void quickSort(int,int);
 void print();
}s[1000];
void q::quickSort(int beg,int end)
{
    if(beg<end)
    {
        int j=partition(beg,end);
        quickSort(beg,j-1);
        quickSort(j+1,end);
    }
}
void q::print()
{
    int i;
    for(i=0;i<100;i++)
        cout<<a[i]<<" ";

}
int main()
{
  for(int i=0;i<1000;i++)
   s[i].random();
  s[0].print();
  cout<<endl;
  s[1].print();
  cout<<endl;
  for(int i=0;i<1000;i++)
   s[i].quickSort(0,99);
  cout<<"Number of avg comparisons = "<<(float)noc/1000<<endl;
}


