#include<bits/stdc++.h>
using namespace std;
int noc=0;
class q
{
 int a[100];
 void random()
 {
  for(int i=0;i<100;i++)
  	a[i]=rand()%10;
 }
 int partition(int beg,int end)
 {
  int pivot=a[beg];
  int i=beg+1,j=end;
  int t;
  while(i<j)
  {
    while(a[i]<=pivot && i<=end)
    {    i++; noc++;}
    while(a[j]>pivot && j>beg)
    {    j--; noc++;}
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
  	a[j]=a[beg];
  	a[beg]=t;
  }
  return j;
 }
 
 public:
 void quickSort(int,int);
 void print();
 q()
 {
  random();
 }
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
   s[i].quickSort(0,99);
  cout<<"Number of avg comparisons = "<<(float)noc/1000<<endl;
}


