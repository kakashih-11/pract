#include<iostream>
# define max 10
using namespace std;

class Hash
{
	long int arr[max];
	public:
		Hash()
		{
			for(int i=0;i<max;i++)
			{
				arr[i]=0;
			}
				
		}
		int hashFun(long int);
		void Insert();
		void Display();
	
};

int Hash::hashFun(long int a)
{
	return (a%10);
}

void Hash:: Insert()
{
	long int num;
	int count=0;
	cout<<"Please Enter the Number- "<<endl;
	cin>>num;
	
	int index=hashFun(num);
	
	
	while(index<10 && count<10)
	{
        	if (arr[index]==0)
        	{
        		arr[index]=num;
        		count++;
        		break;
        	}
    	else{
    	        if(index==max-1)
    	            index=0;
    	        else
    	        	index++;
    	   }
	}
	
	if(count==10)
	    cout<<"Hash table is full";
}
void Hash::Display()
{
	for(int i=0;i<max;i++)
	{
			long int temp=arr[i];
			if(temp==0)
			    cout<<i<<"------>NULL"<<endl;
			else
			{
			    cout<<i<<"------>"<<temp<<endl;
			}
		
	}
}

int main()
{
	int choice;
	Hash h;
	do{
		cout<<"Plese Enter Your Choice"<<endl;
		cout<<"1.Insert\n2.Display\n";
		cin>>choice;
		switch(choice)
		{
			case 1:h.Insert();
				break;
			
			case 2:h.Display();
				break;
		}
	}while(choice!=0);
	
	return 0;
}