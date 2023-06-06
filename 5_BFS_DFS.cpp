#include<iostream>
#include<string.h>
#include<queue>
#include<stack>
using namespace std;

struct node
{
	string name;
	node* next;
};

class graph
{
	int No;
	string dept[20];
	node *head[20];
	public:
		graph()
		{
			for(int i=0;i<20;i++)
			{
				head[i]=NULL;
			}
		}
		void createGraph();
		void display();
		void BFS();
		void DFS();
		inline int findIndex(string current)
		{
			int i=0;
			while(current!=head[i]->name)
			{
				i++;
			}
			return i;
		}
		
		// int searchIndex(string start)
		// {
		// 	int i=0,flag=0;
		// 	while(i<No )
		// 	{
				
		// 		if(dept[i] == start)
		// 		{
		// 			flag=1;
		// 			break;
		// 		}
		// 		i++;
		// 	}
		// 	if(flag==1)
		// 		return i;
		// 	else
		// 	{
		// 		cout<<"\nStarting dept not found. Enter correct dept."<<endl;
		// 		return 0;

		// 	}
		// }

};

void graph:: createGraph()
{
	int n;
	node* temp=NULL;
	cout<<"\nEnter number of depts: "<<endl;
	cin>>No;
	for(int i=0;i<No;i++)
	{
		node* nnode=new node;
		nnode->next=NULL;
		cout<<"Enter name of root dept: ";
		cin>>nnode->name;
		head[i]=nnode;
		cout<<"\nEnter No. of adjacent dept of "<<head[i]->name<<" : ";
		cin>>n;
		temp=head[i];
		for(int j=0;j<n;j++)
		{	
				
			node* nnode=new node;
			nnode->next=NULL;
			cout<<"Enter name of connected dept: ";
			cin>>nnode->name;
			temp->next=nnode;;
			temp=nnode;
		}
	}
}	

void graph::display()
{
	node* temp=NULL;
	for(int i=0;i<No; i++)
	{
		temp=head[i]->next;
		cout<<"\n"<<head[i]->name<<" : ";
		while(temp!=NULL)
		{
			cout<<temp->name<<",";
			temp=temp->next;
		}
	}
}

//_________________________BFS_______________________________

void graph::BFS()
{
    node *temp;
	int visited[20];
    queue<string>q1;
    int i=0;
    for(int i=0;i<No;i++)
     {
        visited[i]=0;
     }
    string current;

    temp=head[0];
    q1.push(head[0]->name);
    visited[0]=1;
   
    while(!q1.empty())
    {   
        current=q1.front();
        q1.pop();
        cout<<current;
        i=findIndex(current);
		
		temp=head[i];
		while(temp!=NULL)
		{   
			i=findIndex(temp->name);
				
			if(visited[i]==0)
			{   
			visited[i]=1;
			q1.push(temp->name);
			} 
			temp=temp->next; 
		}
    }
    
}

//_________________________DFS_______________________________

void graph::DFS()
{
    node *temp;
    stack<string>q1;
    int flag=0,i=0,visited[20];
    for(int i=0;i<No;i++)
    {
        visited[i]=0;
    }
    string current;

    temp=head[0];
    q1.push(head[0]->name);
    visited[0]=1;
    cout<<q1.top();
    while(temp!=NULL)
    {
    	i=findIndex(temp->name);
		if(visited[i]==0)
		{
			q1.push(temp->name);
			cout<<temp->name;
			temp=head[i];
			visited[i]=1;
		}
     	temp=temp->next;
    }

    while(!q1.empty())
    {
        current=q1.top();
        q1.pop();
        i=findIndex(current);
    	temp=head[i];
		while(temp!=NULL)
		{  
			i=findIndex(temp->name);
			if(visited[i]==0)
			{   
				q1.push(temp->name);
				cout<<temp->name;
				visited[i]=1;
			}
			temp=temp->next;
		}

    }
}

int main()
{
	graph g;
	g.createGraph();
	g.display();
	cout<<"\nBFS: ";
	g.BFS();
	cout<<"\nDFS: ";
	g.DFS();
	return 0;
}

