#include<iostream>
using namespace std;

struct node
{
	int key;
	string mean;
	int factor ;
	node* left,*right;
};

class AVL
{
	node* root;
	public:
		AVL()
		{
			root =NULL;
		}
		void createTree();
		void inorder(node* temp);
		int height(node* root);
		void balancefactor(node* root);
		void display()
		{
			cout<<"\nkeyword \tMeaning \tBalance Factor"<<endl;
			inorder(root);
		}
		void dislayHeight()
		{
			cout<<"\nHeight of Tree = "<<height(root)<<endl;
		}
		node *createNode()
		{
			node* nnode = new node;
			cout<<"\nEnter keyword: ";
			cin>>nnode->key;
			cout<<"\nEnter meaning : ";
			cin>>nnode->mean;
			nnode->left=nnode->right = NULL;
			nnode->factor = 0;
			return nnode;
		}
		
};

void AVL::createTree()
{
	node* nnode = createNode();
	if(root == NULL)
	{
		root = nnode;
		root->factor = 0;
	}
	else
	{
		node* temp = root;
		//temp->factor=balancefactor(temp);
		while(true)
		{
			
			
			if(nnode->key < temp->key)
			{
				if(temp->left == NULL)
				{
					temp->left = nnode;
					cout<<"\nLeft";
					break;
				}
				else{
				temp = temp->left;
				}		
			}
			else
			{
				if(temp->right == NULL)
				{
					temp->right = nnode;
					cout<<"\nRight";
					break;
				}
				else
				{
					temp = temp->right;
				}
			}	
		}
		
	}
	balancefactor(root);
	
}

void AVL :: inorder(node* temp)
{
	if(temp != NULL)
	{
      		inorder(temp->left);
                cout<<"\t"<<temp->key<<"\t"<<temp->mean<<"\t"<<temp->factor<<endl;
                inorder(temp->right);
        }
}


int AVL :: height(node* temp)
{
    int d1,d2;
    if(temp==NULL)
        return 0;
    if(temp->left == NULL && temp->right == NULL)
        return 1;
    d1 = height(temp->left);
    d2 = height(temp->right);
    if(d1>d2)
        return d1+1;
    else
        return d2+1;
}

void AVL::balancefactor(node* root)
{
	if(root != NULL)
	{
		int factor = height(root->left)-height(root->right);
		root->factor = factor;
		balancefactor(root->left);
		balancefactor(root->right);
	}	
}

int main()
{
	AVL obj;
	int choice;
	obj.createTree();
	do
	{
		cout<<"==========Menu=========";
		cout<<"\n1)Create AVL \n2)Height \n3)Display \n0)Exit"<<endl;
		cout<<"\nEnter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: obj.createTree();
				break;
			case 2: obj.dislayHeight();
				break;
			case 3: obj.display();
				break;
			default:
				if(choice == 0)
				{
					cout<<"\nExited"<<endl;
				}
				else
					cout<<"Invalid choice!"<<endl;
				break;
		}
	}while(choice != 0);
	return 0;
}
