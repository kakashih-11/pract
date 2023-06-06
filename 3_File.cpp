#include<iostream> 
#include<fstream> 
using namespace std; 
class student 
{ 
	public: 
    	int roll;
	char div,name[10],address[10];
	
 		void getdata() 
 		{ 
 	 		cout<<"\nEnter Roll number: ";
			cin>>roll;
			cout<<"\nEnter Division: ";
			cin>>div;
			cout<<"\nEnter name: ";
			cin>>name;
			cout<<"\nAddress : ";
			cin>>address;
 		} 
 		void putdata() 
 		{ 
 	 		cout<<roll<<"\t\t"<<div<<"\t\t"<<name<<"\t\t"<<address<<endl;  
 		} 
}; 

int main() 
{ 
 	int n,i,ch;  
	int roll,flag=0;	
	char repeat;  	
	student s[20],s1;  	
	do{  	
		cout<<"\n1)Write data \n2)Read Data \n3)Add data \n4)Search Data \n5)Delete Data"<<endl;  
		cout<<"\nEnter the choice";	
		cin>>ch;  	
		switch(ch) 
 		{ 
 		case 1 :  {
			cout<<"\nHow many student:-"; 
 	 	 	cin>>n; 
 	 	 	fstream fout; 
 	 	 	fout.open("student.txt",ios::out);  	 	 	
            		if (fout.is_open())  	 	 	 	
				cout<<"\nfile is open"; 
 	 	 	else 
 	 	 	 	cout<<"\nFile is not created or opned";  	 	 	
                	for(i=0;i<n;i++) 
 	 	 	{ 
 	 	 	 	s[i].getdata(); 
 	 	 	 	fout.write((char*) & s[i],sizeof(s[i]));
 	 	 
 	 	 	} 
 	 	 	fout.close();  	 	 	
			break; 
			}
 	 	 	
 		case 2 :{
 	 	 	fstream fin; 
 	 	 	fin.open("student.txt",ios::in);  
			cout<<"\nRoll No. \tDivision \tName \tAddress"<<endl;	 	 	
            		while(fin.read((char*) & s1,sizeof(s1))) 
 	 	 	{ 
 	 	 	 	s1.putdata();  	 	 	 	
                		cout<<endl; 	 
 	 	 	} 
 	 	 	fin.close();  	 	 	
            		break; 
			}
 	 	 	
 		case 3 : {
 	 	 	cout<<"\nHow many student:-";  	 	 	
            		cin>>n;  	 	 	
            		fstream out;  	 	 	
            		out.open("student.txt",ios::app);  	 	 	
            		if (out.is_open())  	 	 	 	
            			cout<<"\nfile is open"; 
 	 	 	else 
 	 	 	 	cout<<"\nFile is not created or opned";  	 	 	
            		for(i=0;i<n;i++) 
 	 	 	{ 
 	 	 	 	s[i].getdata(); 
 	 	 	 	out.write((char*) & s[i],sizeof(s[i])); 
 	 	 	} 
 	 	 	out.close();  	 	 	
            		break; 
			}
		case 4: {
			cout<<"\nEnter roll number : ";
			
			cin>>roll;
			fstream fin; 
 	 	 	fin.open("student.txt",ios::in);  	 	 	
            		while(fin.read((char*) & s1,sizeof(s1))) 
 	 	 	{ 
				if(s1.roll ==roll)
				{
					cout<<"\nRecord found!"<<endl;
 	 	 	 		s1.putdata();  	 	 	 	
                			cout<<endl; 
					flag=1;
					break;
				}	 
 	 	 	} 
			if(fin.eof() && flag==0)
			{
				cout<<"\nRecord not found!"<<endl;
			}
 	 	 	fin.close(); 
			
			
			}
		case 5 :{
			cout<<"\nEnter roll number : ";
			cin>>roll;
			fstream fout,fin; 
			fin.open("student.txt",ios::in);
			fout.open("studentCopy.txt",ios::app);  	 	 	
            		while(fin.read((char*) & s1,sizeof(s1))) 
 	 	 	{ 
				if(s1.roll ==roll)
				{
					cout<<"\nRecord deleted!"<<endl;
 	 	 	 		s1.putdata();  	 	 	 	
                			cout<<endl; 
					flag=1;
				}
				else{
					fout.write((char*) & s1,sizeof(s[i]));
				}	 
 	 	 	} 
			if(fin.eof() && flag==0)
			{
				cout<<"\nRecord not found!"<<endl;
			}
 	 	 	fin.close(); 
			remove("student.txt");
			rename("studentCopy.txt","student.txt");
			fout.close();
			
			}
 	 	 	
 		default: 
			cout<<"\nEnter valid choice:"; 
 	 	 	break; 
 		} 
 	cout<<"Do you want repeat operation? y/n"; 
 	cin>>repeat; 
 	}while(repeat=='y'); 
 
 	return(0); 
} 
