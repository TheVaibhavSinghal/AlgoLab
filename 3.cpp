#include<bits/stdc++.h>
using namespace std;
int B=0,E=0;
int b1=0,e1=0,b2=0,e2=0;
class DNA
{
char S[20];
char F[20];
int s[20];
int f[20];
int b1,e1,b2,e2;
public:
    void read();
    int bruteForce(int []);
    int IncDesign(int[]);
    int divideConquer(int [],int,int);
    int pruning(int []);
    void print(int [],int,int);
    int* c2d(char []);
    void check();
}d;
void DNA::read()
{
    cin>>S;
    for(int i=0;i<20;i++)
    {
        switch(S[i])
        {
            case 'A':s[i]=2;break;
            case 'C':s[i]=1;break;
            case 'G':s[i]=-1;break;
            case 'T':s[i]=-2;break;
        }
    }
    cin>>F;
    for(int i=0;i<20;i++)
    {
        switch(F[i])
        {
            case 'A':f[i]=2;break;
            case 'C':f[i]=1;break;
            case 'G':f[i]=-1;break;
            case 'T':f[i]=-2;break;
        }
    }
   
}

int DNA::bruteForce(int a[])
{
    int i,j,k,maxsum=0,sum=0;
    B=0,E=0;
    for(i=0;i<20;i++)
    {
        for(j=i;j<20;j++)
        {
            sum=0;
            for(k=i;k<=j;k++)
            {
                sum+=a[k];            
            }
            if(sum>maxsum)
            {    maxsum=sum;
                 B=i;
                 E=j;
            }    
        }
    }
    print(a,B,E);
    return maxsum;
}
int DNA::IncDesign(int a[])
{
    int i,j,maxsum=0,sum=0;
    B=0,E=0;
    for(i=0;i<20;i++)
    {
        sum=0;
        for(j=i;j<20;j++)
        {
            sum+=a[j];            
            if(sum>maxsum)
            {    maxsum=sum;
                B=i;
                E=j;
            }    
        }
    }
    print(a,B,E);
    return maxsum;
}
int DNA::divideConquer(int a[],int start,int end)
{
    int lsum,rsum,rosum=0,losum=0,mid,s1,e1;
    mid=(start+end)/2;
    int sum,i;
    B=0,E=0;
    if(start==end)   
    {
        if(a[start]<0)
         return 0;
        else
         return a[start];    
    }
    lsum=divideConquer(a,start,mid);
    rsum=divideConquer(a,mid+1,end);
    sum=0;
    for(i=mid;i<20;i++)
    {       sum+=a[i];
            if(sum>rosum)
            {
                rosum+=a[i];
                e1=i;
            }
    }
    sum=0;
    for(i=mid-1;i>=start;i--)
    {
          sum+=a[i];
          if(sum>losum)
          {
            losum+=a[i];
            s1=i;
          }
    }    
    if(lsum>rsum && lsum>losum+rosum)
    {
        B=start;
        E=mid;
      
        return lsum;
    }
    else if(rsum>lsum && rsum>losum+rosum)
    {
        B=mid+1;
        E=end;
        return rsum;
    }
    else
    {
        B=s1;
        E=e1;
       
        return losum+rosum;
    }
}
int DNA::pruning(int a[])
{
    int i=0,csum=0,sum=0;
    B=0,E=0;
    for(i=0;i<20;i++)
    {
        csum+=a[i];
        if(csum<0)
        {    csum=0;
             B=i+1;
        }
        if(csum>sum)
        {
            sum=csum;
            E=i;
        }   
    }
    print(a,B,E);
    return sum;
}

void DNA::print(int a[],int BEG,int END)
{
    int i=0;
    for(i=BEG;i<END;i++)
    {
        switch(a[i])
        {
            case  2 : cout<<"A";break;
            case  1 : cout<<"C";break;
            case -1 : cout<<"G";break;
            case -2 : cout<<"T";break;
        }
    }
    cout<<endl;
}
void DNA::check()
{
    int son,father;
    son=pruning(s);
    father=pruning(f);
    if(abs(son-father)<10)
        cout<<"PRUNING\t\tRelated\tSon:"<<son<<"\tFather:"<<father<<endl;
    else
        cout<<"PRUNING\t\tNot Related\tSon:"<<son<<"\tFather:"<<father<<endl;
 
    son=IncDesign(s);
    father=IncDesign(f);
    if(abs(son-father)<10)
        cout<<"INC\t\tRelated\tSon:"<<son<<"\tFather:"<<father<<endl;
    else
        cout<<"INC\t\tNot Related\tSon:"<<son<<"\tFather:"<<father<<endl;
    son=bruteForce(s);
    father=bruteForce(f);
    if(abs(son-father)<10)
        cout<<"bForce\t\tRelated\tSon:"<<son<<"\tFather:"<<father<<endl;
    else
        cout<<"bForce\t\tNot Related\tSon:"<<son<<"\tFather:"<<father<<endl;    
    son=bruteForce(s);
    father=bruteForce(f);  
    son=divideConquer(s,0,20);
    father=divideConquer(f,0,20);
    if(abs(son-father)<10)
     {   cout<<"DC\t\tRelated\tSon:"<<son<<"\tFather:"<<father<<endl;
        
    }
    else
    {    cout<<"DC\t\tNot Related\tSon:"<<son<<"\tFather:"<<father<<endl;
        
    }
     
}

int main()
{
    d.read();
    d.check();
}
