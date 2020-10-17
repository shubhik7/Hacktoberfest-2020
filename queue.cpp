#include<iostream>
#include<string>
using namespace std;

struct queue{
	int s=50;
	int r=-1;
	int f=-1;
	int el[50];
};

void enque(struct queue &q,int x)
{
	if((q.r+1)%q.s==q.f)
	cout<<"queue full !";
	else{
		if(q.f==-1)
		{
			q.f=0;
			q.r=0;
		}
		else{
			q.r=(q.r+1)%q.s;
		}
		q.el[q.r]=x;
	}
}

int deque(struct queue &q)
{
	if(q.f==-1)
	cout<<"empty!";
	else{
		int t;
		if(q.f==q.r)
		{
			t=q.el[q.f];
			q.f=-1;q.r=-1;
		}
		else{
		    
			t=q.el[q.f];
			q.f=(q.f+1)%q.s;
		}
		return t;
	}
}

void bsortq(struct queue &q,int n)
{
    int g=n,p;
    while(n--)
    {
        int mina=100000000,minindex=0;
        for(int i=0 ;i<n+1 ;i++)
        {
            p=deque(q);
            if(p<mina)
            {
                minindex=i;
                mina=p;
            }
            enque(q,p);
        }
        for(int i=0 ;i<g-n-1;i++)
        enque(q,deque(q));
        
        for(int i=0 ;i<g ;i++)
        {
            if(i==minindex)
            p=deque(q);
            else
            {
                int l=deque(q);
                enque(q,l);
            }
        }
        enque(q,p);
    }
}

int main()
{
    int a[10]={2,98,34,76,2222,44,779,432,90,0},n=10;
    struct queue q;
    for(int i=0 ;i< n;i++)
    enque(q,a[i]);
    bsortq(q,n);
    for(int i=0 ;i< n;i++)
    cout<<deque(q)<<" ";
    
    
}

