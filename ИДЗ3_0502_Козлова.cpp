#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Date
{
private:
    struct D  
    {
        int day;
	    int month;
	    int year;
	    int sum;
        D *Next;  
    };
public:
	D *L;
	
	int set(int num1, int num2, int num3);
	int dec();
	const char* timeofyear();
	int display();
	int maxd();


};

int Date::set(int num1, int num2, int num3)
{
	D *NewElement = new D;
	
	if (NewElement == NULL)
	return 0;
	
	if (num1 >= 1 && num1 <= 31)
		    NewElement->day = num1;
		else
		{
			cout<<"incorrect day value , automatic value (1) entered"<<endl;
			NewElement->day = 1;
		}
		if (num2 >= 1 && num2 <= 12)
		    NewElement->month = num2;
		else
		{
			cout<<"incorrect month value , automatic value (1) entered"<<endl;
			NewElement->month = 1;
		}
		if (num3 >= 1)
		    NewElement->year = num3;
		else
		{
			cout<<"incorrect year value , automatic value (2000) entered"<<endl;
			NewElement->year = 2000;
		}
	
	NewElement->Next = L;
	L = NewElement;
	return 1;	
}

int Date::display()
{
	printf( "%i.%i.%i \n", L->day, L->month, L->year);  
	return 1;     
} 

int Date::maxd()
{
	int i, max = 0, day, month, year;
	for(i = 1; i <= 3; i++)
	{
		L->sum = L->day + L->month*100 + L->year*10000;
		if(L->sum > max)
		    max = L->sum;
		L = L->Next;
		
	}
	day = max%100;
	max = (max - day)/100;
	month = max%100;
	max = max - month;
	year = max/100;
	cout<<"pozdnee:"<<day<<"."<<month<<"."<<year<<endl;
	
	return 1;
	
}

int Date::dec()
{
	if (L->day <= 10 )
	  return 1;
	if (L->day > 10 && L->day <= 20 )
	  return 2;
	if (L->day > 20 )
	  return 3;    
}

const char* Date::timeofyear()
{
	if( L->month == 12 || L->month == 1 || L->month == 2 )
	return "winter";
	if( L->month == 3 || L->month == 4 || L->month == 5 )
	return "spring";
	if( L->month == 6 || L->month == 7 || L->month == 8 )
	return "summer";
	if( L->month == 9 || L->month == 10 || L->month == 11 )
	return "autumn";      
}


int main()
{
	int run;
	int num1, num2, num3;
	cout<<"create 3 data:"<<endl;
	Date *ListStart = new Date;
	
	for(run = 1; run <= 3; run++)
	{
		cout<<"day:"<<endl;
   	    cin>>num1;
   	    cout<<"month:"<<endl;
   	    cin>>num2;
   	    cout<<"year:"<<endl;
   	    cin>>num3;
   	    ListStart->set(num1, num2, num3);   
   	    ListStart->display();
   	    cout<<"decade of the month:"<<ListStart->dec()<<endl;
   	    cout<<"time of year:"<<ListStart->timeofyear()<<endl;
	}
	
	ListStart->maxd();
	
	return 1;
}
