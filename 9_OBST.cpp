#include<iostream>
#include<queue>
#define max 20;
using namespace std;


class obst
{

	string k[20];
	float P[20];
	float Q[20];
	float W[20][20];
	float C[20][20];
	int R[20][20];
	int Nk;
	public:
		void getData();
		void display();
};

 void obst :: getData()
{
int i;
	cout<<"\nEnter number of keys: ";
	cin>>Nk;
	cout<<"\nEnter keys in assending order: ";
	for(i=0;i<Nk;i++)
	{
		cin>>k[i];
	}
	cout<<"\nEnter successfull probabilities: ";
	for(i=1;i<=Nk;i++)
	{
		cin>>P[i];
	}
	cout<<"\nEnter unsuccessfull probabilities: ";
	for(i=0;i<Nk+1;i++)
	{
		cin>>Q[i];
	}
	for(i=0;i<Nk+1;i++)
	{
		W[i][i]=Q[i];
		C[i][i]=0;
		R[i][i]=0;
		if(i+1<=Nk)
		{
			W[i][i+1]=P[i+1]+Q[i+1]+W[i][i];
	      		C[i][i+1]=W[i][i+1];
	      		R[i][i+1]=i+1;
			
		}
	}

	int cost,d,j,root;
	for(d=2;d<Nk+1;d++)
	{
		
		for(int i=0;i<Nk;i++)
		{
			j=i+d;
			if(j<=Nk+1)
			{
			W[i][j]=P[j]+Q[j]+W[i][j-1];
			C[i][j]=9999;
			for(int k=i+1;k<=j;k++)
			{
				cost=C[i][k-1]+C[k][j];
				if(cost<C[i][j])
				{
					C[i][j]=cost;
					root=k;
				}
			}
			C[i][j]=C[i][j]+W[i][j];
			R[i][j]=root;
			cout<<"\nCost and root for diff "<<d<<"="<<C[i][j]<<"\t"<<R[i][j];
			}
			
		}
	}
}

void obst::display()
{
	queue<int>q1;
	q1.push(0);
	q1.push(Nk-1);
	int i,j,k;
	cout<<"\nRoot \t Left \t Right "<<endl;
	while(!q1.empty())
	{
		i=q1.front();
		q1.pop();
		j=q1.front();
		q1.pop();
		k=R[i][j];
		cout<<"\n"<<k<<"\t";
		if(R[i][k-1]!=0)
		{
			cout<<R[i][k-1]<<"\t";
			q1.push(i);
			q1.push(k-1);
		}
		else
		{
			cout<<"Null\t";
		}
		if(R[k][j]!=0)
		{
			cout<<R[k][j]<<"\t";
			q1.push(k);
			q1.push(j);
		}
		else
		{
			cout<<"Null\t";
		}
	}
}

int main()
{
	obst ob;
	ob.getData();
	ob.display();
	return 0;
}
