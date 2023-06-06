#include<iostream>
#include<string>
using namespace std;

struct detail
{
    string name;
    long int number;
};

class telp
{
    public:
    int size;
    telp()
    {
        cout<<"Enter size of Hash Table= ";
        cin>>size;
    }
    struct detail B[10];
    struct detail A[10];
    void initial();
    void hashz();
    void display();
    void search();

};

void telp::initial()
{
    for(int i=0;i<size;i++)
    {
        B[i].name="NULL";
        B[i].number=0000;
        A[i].name="NULL";
       A[i].number=0000;
    }
}


void telp::hashz()
{ 
    char Na[10];
    long int No; 
    cout<<"Enter Name n Telephone No of Client: ";
    cin>>Na>>No;
   int sum=0,i=0;
    while(Na[i]!='\0')
    {
        sum=sum+int(Na[i]);
        i++;
    }
    int homeaddress=sum%size;
    
    // linear probing
    int j;
    for(j=homeaddress;j<size;(j=(j+1)%size))
    {
            
            if(A[j].name=="NULL")
            {       A[j].name=Na;
                A[j].number=No;
                break;
            }
            
    }
    
    // Quadratic probing
    
    int h=0,o=0;
    //for(int k=homeaddress;k<size;k=(k+1)%size)
    for(int k=0;k<=(size-1)/2;k++)
    {   
        h=homeaddress+o*o;
        h=h%size;   
            if(B[h].name=="NULL")
            {       B[h].name=Na;
                B[h].number=No;
                break;
            }
            o++;
    }  
}
void telp::display()
{
    cout<<"\n \nlinear probing \n\n";
    for(int i=0;i<size;i++)
    {
            cout<<i<<".  ";
        cout<<A[i].name<<"    ";
       cout<<A[i].number<<"\n";
    }
    cout<<"\n \nQuadratic probing \n";
    for(int j=0;j<size;j++)
    {
            cout<<j<<".  ";
        cout<<B[j].name<<"    ";
       cout<<B[j].number<<"\n";
    }
}

void telp::search()
{   char nam[10];
    cout<<"Enter Name of Client which Telephone u Want to Search: ";
    cin>>nam;
    int i=0,t=0,l=0,o=0,h=0;
    while(nam[i]!='\0')
    {
        t=t+int(nam[i]);
        i++;
    }
    t=t%size;
    for(int j=t;j<size;j=(j+1)%size)
    {
            l++;
            if(A[j].name==nam)
            {  
            cout<<"\n Telephone number of "<<nam<<" is "<<A[j].number<<"\n"; 
                break;
            }
            if(j==t-1)
            {
                cout<<"Client Detail  Not Found\n";
                break;
            }
    }
    cout<<"\n Number of Comparission in Linear Probing="<<l<<"\n";
    
    l=0;
    for(int k=0;k<=(size-1)/2;k++)
    {   
        h=t+o*o;
        h=h%size;
        l++;    
            if(B[h].name==nam)
            {   
                cout<<"\n Telephone No of "<<nam<<" is "<<A[h].number<<"\n";    
                break;
            }
            o++;
            
    }
    cout<<"\n Number of comparission in Quadratic Probing= "<<l<<"\n";
    
    
}
int main()
{
    telp ob;
    int ch;
    ob.initial();
    do{
        cout<<"\nWhich Operaton u want to Perform\n1.Insert Client Data\n2.Search Client Detail\n3.Display Data of HashTable\n4.Exit\nEnter ur Choise: ";
        cin>>ch;
        switch(ch)
        {
            case 1:ob.hashz();
                break;
            case 2:ob.search();
                break;
            case 3:ob.display();
                break;
            case 4:cout<<"Program is Terminated...!!!\n";
                break;
            default:cout<<"Invalid Choice...\n";
        }
    }while(ch!=4);
    return 0;
}
