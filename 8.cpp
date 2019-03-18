#include<bits/stdc++.h>
using namespace std;

struct object
 {
  float weight,price;
 };
bool checkPrice(object,object);
bool checkPriceWeight(object,object);
class coinproblem
{
 int amt;
 int den[10],f[10],n;
 public:
 void coin();

}l;
class ks
{
 object o[10];
 int n,cap;
 float f[10];
 public:
 void ksprice();
 void kspriceWeight();
  void kspriceWeightFrac();
 
}k;

bool checkPrice(object o1,object o2)
{
	return (o1.price>o2.price);
}
bool checkPriceWeight(object o1,object o2)
{
	float x=(float)o1.price/o1.weight;
	float y=(float)o2.price/o2.weight;
	return (x>y);
}

void ks::ksprice()
{
	int i;
	cout<<"Enter the capacity: ";
	cin>>cap;
	cout<<"Enter the number of objects: ";
	cin>>n;
	cout<<"Enter the weight and price of each object:\n";
	for(i=0;i<n;i++)
	 cin>>o[i].weight>>o[i].price;
	sort(o,o+n,checkPrice);
	for(int k=0;k<n;k++)
		 f[k]=0;
	for(i=0;i<n;i++)
	{
		if(cap>=o[i].weight)
		{
			f[i]=1;
			cap-=o[i].weight;
		}
		else
			f[i]=0;
	}
	for(i=0;i<n;i++)
	{
		cout<<"Price:"<<setprecision(2)<<o[i].price<<"\tWeight:"<<o[i].weight<<"\tFrequency:"<<setprecision(0)<<f[i]<<endl;			
	}

}
void ks::kspriceWeight()
{
	int i;
	cout<<"Enter the capacity: ";
	cin>>cap;
	cout<<"Enter the number of objects: ";
	cin>>n;
	cout<<"Enter the weight and price of each object:\n";
	for(i=0;i<n;i++)
	 cin>>o[i].weight>>o[i].price;
	sort(o,o+n,checkPriceWeight);
	for(int k=0;k<n;k++)
		 f[k]=0;
	for(i=0;i<n;i++)
	{
		if(cap>=o[i].weight)
		{
			f[i]=1;
			cap-=o[i].weight;
		}
		else
			f[i]=0;
	}
	for(i=0;i<n;i++)
	{
		cout<<setprecision(2)<<"PricePerWeight:"<<(float)o[i].price/o[i].weight<<"\tWeight:"<<o[i].weight<<"\tFrequency:"<<setprecision(0)<<f[i]<<endl;			
	}

}

void ks::kspriceWeightFrac()
{
	int i;
	cout<<"Enter the capacity: ";
	cin>>cap;
	cout<<"Enter the number of objects: ";
	cin>>n;
	cout<<"Enter the weight and price of each object:\n";
	for(i=0;i<n;i++)
	 cin>>o[i].weight>>o[i].price;
	sort(o,o+n,checkPriceWeight);
	for(int k=0;k<n;k++)
		 f[k]=0;
	for(i=0;i<n;i++)
	{
		if(cap>0)
		{
			if(cap>=o[i].weight)
			{
				f[i]=1;
				cap-=o[i].weight;
			}
			else
			{
				f[i]=cap/o[i].weight;
				cap=0;
			}
		
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<setprecision(2)<<"PricePerWeight:"<<(float)o[i].price/o[i].weight<<"\tWeight:"<<o[i].weight<<"\tFrequency:"<<f[i]<<endl;			
	}

}




void coinproblem::coin()
{
	int i,j,k,amount;
	cout<<"Enter the amt: ";
	cin>>amt;
	amount=amt;
	cout<<"Enter the number of denomination: ";
	cin>>n;
	cout<<"Enter the denominations: ";
	for(i=0;i<n;i++)
	 cin>>den[i];
	sort(den,den+n,greater<int>());
	for(j=0;j<n;j++)
	{
		amt=amount;
		for(k=0;k<n;k++)
		 f[k]=0;
		for(i=j;i<n;i++)
		{
			f[i]=amt/den[i];
			amt-=f[i]*den[i];	
		}
		if(amt==0)
		 break;
    }
	if(amt!=0)
	 cout<<"Change not possible"<<endl;
	else
	 for(i=0;i<n;i++)
	{
		cout<<"Denomination:"<<den[i]<<"\tFrequency:"<<f[i]<<endl;			
	}
}

int main()
{
 int ch;
 
 while(ch!=5)
 {
 	cout<<"-----------------------------------------------------------------------\n1.Coin Exchange\n2.KS Price\n3.KS PPW\n4.KS Fractional\n5.Exit\nEnter your choice";
 	cin>>ch;
 	switch(ch)
 	{
 		case 1: l.coin();break;
 		case 2: k.ksprice();break;
 		case 3: k.kspriceWeight();break;
 		case 4: k.kspriceWeightFrac();break;
 	//default: cout<<"Invalid input"; break;
 	}
 }
}
