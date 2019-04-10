#include<bits/stdc++.h>
using namespace std;
int beg=-1,end=-1;
struct node
{
	char c;
	int freq;
	node *lcptr;
	node *rcptr;
	int encode[10];
}n[10];
node *hptr;

int ltable[128][10];

class huffman
{
	char text[100];
	int encodedtext[1000];
	int etend;
	public:
		void read();
		void htree();
		void code(struct node *ptr,int arr[],int top);
		void printencodedtext();
		void decode();
};

bool freqsort(node n1,node n2)
{
	return(n1.freq<n2.freq);
}	

void huffman::read()
{
	cout<<"Enter the text\n";
	cin>>text;
	int i,j,check=0;
	for(i=0;i<strlen(text);i++)
	{
		check=0;
		for(j=0;j<=end;j++)
		{
			if(n[j].c==text[i])
			{
				n[j].freq++;
				check=1;
				break;
			}
		}
		if(beg==-1)
			beg=0;
		if(check==0)
		{
			end++;
			n[end].c=text[i];
			n[end].freq=1;
			n[end].lcptr=NULL;
			n[end].rcptr=NULL;
			for(int i=0;i<10;i++)
				n[end].encode[i]=-666;
		}
	} 
}

void huffman::htree()
{
	while(end-beg>0)
	{
		sort(n+beg,n+(end+1),freqsort);
		end++;
		n[end].freq=n[beg].freq+n[beg+1].freq;
		n[end].c='\0';
		for(int i=0;i<10;i++)
			n[end].encode[i]=-666;
		n[end].lcptr=&n[beg];
		n[end].rcptr=&n[beg+1];
		beg+=2;
	}
	hptr=&n[beg];  //beg=end
	
}

void huffman::code(struct node *ptr,int arr[],int top)
{
	if(ptr->lcptr)
	{	arr[top]=0;
		code(ptr->lcptr,arr,top+1);
	}
	
	if(ptr->rcptr)
	{
		arr[top]=1;
		code(ptr->rcptr,arr,top+1);
	}
	
	if(ptr->lcptr==NULL && ptr->rcptr==NULL)
	{
		for(int i=0;i<top;i++)
			ptr->encode[i]=arr[i];
	}


}

void huffman::printencodedtext()
{
	int i=0,j=0,k=0;
	for(;i<1000;i++)
		encodedtext[i]=-666;
	cout<<"Given text:\t"<<text<<endl<<"Encoded text:\t";
	i=0;
	while(i<strlen(text))
	{
		for(j=0;j<10;j++)
			if(ltable[(text[i])][j]!=-666)
			{	cout<<ltable[(text[i])][j];
				encodedtext[k]=ltable[(text[i])][j];
				k++;
			}
		i++;
	}
	cout<<endl;
	for(i=0;i<k;i++)
		if(encodedtext[i]!=-666)
			cout<<encodedtext[i];
	etend=k;		
	cout<<endl;
}

void huffman::decode()
{
	struct node *ptr=hptr;
	for(int i=0;i<etend;i++)
	{
		if(encodedtext[i]==0)
		{
			ptr=ptr->lcptr;
		}
		else
		{
			ptr=ptr->rcptr;
		}
		if(ptr->lcptr==NULL && ptr->rcptr==NULL)
		{
			cout<<ptr->c;
			ptr=hptr;
		}
	
	}

}
void print(struct node *ptr)
{
 if(ptr!=NULL)
 {
 	print(ptr->lcptr);
 	cout<<ptr->c<<"---"<< ptr->freq<<"---";
 	for(int i=0;i<10;i++)
 	{	
 		ltable[(int)ptr->c][i]=ptr->encode[i];
 		if(ptr->encode[i]!=-666)
 			cout<<ptr->encode[i];
 		else
 			break;
 	}
 	cout<<endl;
 	print(ptr->rcptr);
 }
}

void printlookup()
{
	int i,j;
	for(i=0;i<128;i++)
	{
		for(j=0;j<10;j++)
			if(ltable[i][j]!=-666)
				cout<<ltable[i][j];
		cout<<" ";
	}
	cout<<endl;

}
int main()
{
	for(int i=0;i<128;i++)
	{
		for(int j=0;j<128;j++)
			ltable[i][j]=-666;
	}

	int a[10];
	huffman h;
	h.read();
	h.htree();
	h.code(hptr,a,0);
	print(hptr);
	cout<<"----------------------"<<endl;
	printlookup();
	cout<<endl;
	h.printencodedtext();
	h.decode();
	cout<<endl;
	
}
