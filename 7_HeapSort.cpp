#include<iostream>
using namespace std;

class HeapSort
{

	public :
	void Sort(int Marks[], int n);
	private:
	void Heap(int Marks[],int n,int i);
		
};

void HeapSort :: Sort(int Marks[], int n){
	int temp,i;
	for(i=(n/2)-1;i>=0;i--)
	{
		Heap(Marks,n,i);
	}
	//delete max up to till count=0
	for(i=n-1;i>=0;i--)
	{
		temp=Marks[i];
		Marks[i]=Marks[0];
		Marks[0]=temp;
		Heap(Marks,i,0);		
	}	
}
void HeapSort :: Heap(int Marks[], int n, int i)
{
	int largest=i;
	int left=(2*i + 1);
	int right = (2*i + 2);
	if(left<n && Marks[left]>Marks[largest])
	{
		largest=left;
	}
	if(right<n && Marks[right] > Marks[largest])
	{
		largest=right;
	}
	if(largest != i)
	{
		int temp=Marks[i];
		Marks[i]=Marks[largest];
		Marks[largest]=temp;
		Heap(Marks,n,largest);
	}
}

int main()
{
	int Marks[10];
	int n,i;
	HeapSort h;
	cout<<"\nEnter size : ";
	cin>>n;
	cout<<"\nEnter marks : ";
	for(i=0;i<n;i++)
	{
		cin>>Marks[i];
	}

	cout<<"\nMarks : "<<endl;
	h.Sort(Marks,n);
	cout<<"\nMarks : "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<Marks[i]<<endl;
	}
	cout<<"\nMin marks: " << Marks[0];
	cout<<"\nMax marks: " << Marks[n-1];
	

	return 0;
}
