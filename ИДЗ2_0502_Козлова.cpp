#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class A
{
private:
    struct mass
    {
        int n;
        mass *Next;  
 
        mass()
        {
            Next = 0;
        }
    };
public:
    mass *M; 
    A()
    {
        M = NULL;
    }
    int Add(int ch);
    int Display();
    int MaxN();
    int MinN();
    double sar();
    double sgr();
    int count(int t);
    int vivod(int t);

    mass* GetLast()
    {
        mass *C = M;   
        if(C == NULL) 
		{
            return NULL;
        }
        while(C->Next!=NULL) {
            C = C->Next;
        }
        return C;
    };
};

int A::Add(int ch)
    {
        mass* NE = new mass;
            NE->n = ch;
            
        
        if(M!=NULL) 
		{ 
            GetLast()->Next = NE;   
        }
        else { 
            M = NE;
        }
        return 1;
    }
    
int A::Display()
    {   
        mass *C = M;   
        if(C == NULL) 
		{
            cout << "Empty" << endl;
            return 0;
            getchar();
        }
        else
        {
            do  {   
                cout << C->n<< endl << endl;
                }
            while((C = C->Next)!=NULL); 
            return 1;
        }
    }  

int A::MaxN()
	{
		mass *C = M; 
		int max= C->n;
		do  {   
		        if(C->n > max)
		          max = C->n;
            }
		while((C = C->Next)!=NULL);
		return max;
	} 

int A::MinN()
	{
		mass *C = M; 
		int min = C->n;
		do  {   
		        if(C->n < min)
		          min = C->n;
            }
		while((C = C->Next)!=NULL);
		return min;
	} 

double A::sar()
	{
		mass *C = M; 
		int i = 0, sum = 0, sr;
		do  {   
		        sum = sum + C->n;
		        i++;
            }
		while((C = C->Next)!=NULL);
		sr=sum/ i;
		return sr;
	} 

double A::sgr()
	{
		mass *C = M; 
		int i = 0, pr = 1;
		double srg, x;
		do  {   
		        pr = pr * C->n;
		        i++;
            }
		while((C = C->Next)!=NULL);
		x = 1.0/i;
		srg=pow((double)pr, x);
		return srg;
	}

int A::count(int t)
{
	mass *C = M;
	int m;
	do  {   
		   if(C->n > t)
		   {
		   	 m++;  
		   }
        }
	while((C = C->Next)!=NULL);
	return m;
}	

int A::vivod(int t)
{
	mass *C = M;
	int m;
	do  {   
		   if(C->n > t)
		   {
		   	   cout<<">t:"<<C->n<<endl;
		   }
        }
	while((C = C->Next)!=NULL);
	return 1;
}
 				

int main()
{   
    int run = 1; 
    int g, t, p, q;
    A *pList = new A;
    A *C = new A;
    A *D = new A;
    
    C->Add(2);
    C->Add(4);
    C->Add(6);
    C->Add(12);
    
    D->Add(3);
    D->Add(5);
    D->Add(7);
    D->Add(9);
    D->Add(11);
    D->Display();


    pList->Display();
    while(run)
    {
    	cout<<"Enter regim:"<<endl<<
          "0-exit"<<endl<<
		  "1-add"<<endl<<
		  "2-output all"<<endl<<
		  "3-max"<<endl<<
		  "4-min"<<endl<<
		  "5-srednee arifmeticheskoe"<<endl<<
		  "6-srednee geometricheskoe"<<endl<<
		  "7-idz"<<endl<<
		  ">>>>>>\n"<<endl<<endl;
		switch( _getch() )
          {
          	case '0':
   	        run=0;
   	        break;
   	        case '1':
	          cout<<"number:"<<endl;
	          cin>>g;
	          pList->Add(g);
	        break;  	
	        case '2':
	        	pList->Display();
	        break;		
	        case '3':
	        	cout<<"max:"<<pList->MaxN()<<endl;
	        break;  	
	        case '4':
	        	cout<<"min:"<<pList->MinN()<<endl;
	        break; 
			case '5':
	        	cout<<"srednee arifmeticheskoe:"<<pList->sar()<<endl;
	        break; 
	        case '6':
	        	cout<<"srednee geometricheskoe:"<<pList->sgr()<<endl;
	        break; 
	        case '7':
	        	cout<<"t:"<<endl;
	        	cin>>t;
	        	q = C->count(t);
	        	p = D->count(t);
	        	if(q > p)
	        	{
	        		cout<<"C:"<<endl;
					C->vivod(t);
					cout<<"D:"<<endl;
	        		D->vivod(t);
				}
				else
				{
					cout<<"D:"<<endl;
					D->vivod(t);
					cout<<"C:"<<endl;
					C->vivod(t);
				}
	        	  
	        break; 
          }	 
	}
    return 0;
}

