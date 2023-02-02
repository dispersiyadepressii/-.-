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
		int i = 0, sum = 0;
		double sr;
		do  {   
		        sum = sum + C->n;
		        i++;
            }
		while((C = C->Next)!=NULL);
		sr=(double)sum/ i;
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
 				

int main()
{   
    int run = 1; 
    int g;
    A *pList = new A;

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
          }	 
	}
    return 0;}

