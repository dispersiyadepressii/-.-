#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date()
	{
		day = 1;
		month = 1;
		year = 2000;
	}
	
	Date(int num)
	{
		if (num >= 1 && num <= 31)
		    day = num;
		else
		{
			cout<<"incorrect day value , automatic value (1) entered"<<endl;
			day = 1;
		}
		month = 3;
		year = 2021;
	}
	
	Date(int num1, int num2, int num3)
	{
		if (num1 >= 1 && num1 <= 31)
		    day = num1;
		else
		{
			cout<<"incorrect day value , automatic value (1) entered"<<endl;
			day = 1;
		}
		if (num2 >= 1 && num2 <= 12)
		    month = num2;
		else
		{
			cout<<"incorrect month value , automatic value (1) entered"<<endl;
			month = 1;
		}
		if (num3 >= 1)
		    year = num3;
		else
		{
			cout<<"incorrect year value , automatic value (2000) entered"<<endl;
			year = 2000;
		}
	}
	
	int dec();
	void timeofyear();
	int display();

};

int Date::dec()
{
	if (day <= 10 )
	  return 1;
	if (day > 10 && day <= 20 )
	  return 2;
	if ( day > 20 )
	  return 3;    
}

void Date::timeofyear()
{
	if( month == 12 || month == 1 ||month == 2 )
	  cout<<"winter"<<endl<<endl;
	if( month == 3 || month == 4 ||month == 5 )
	  cout<<"spring"<<endl<<endl;
	if( month == 6 || month == 7 ||month == 8 )
	  cout<<"summer"<<endl<<endl;
	if( month == 9 || month == 10 ||month == 11 )
	  cout<<"autumn"<<endl<<endl;      
}

int Date::display()
{
	if ( day >= 10 && month >= 10)
	  cout<<day<<"."<<month<<"."<<year<<endl<<endl;
	if ( day < 10 && month >= 10)
	  cout<<"0"<<day<<"."<<month<<"."<<year<<endl<<endl;
	if ( day >= 10 && month < 10)
	  cout<<day<<".0"<<month<<"."<<year<<endl<<endl;
	if ( day < 10 && month < 10)
	  cout<<"0"<<day<<".0"<<month<<"."<<year<<endl<<endl;   
	return 1;     
} 

int main()
{
	int run;
	int num1, num2, num3;
	cout<<"there are 3 examples:"<<endl;
	Date A;
	Date B(6, 8, 2002);
	Date C(22);
	cout<<"Date A() , A:"<<endl;
	A.display();
	cout<<"Date B(6, 8 , 2002) /* this is my birthday */ , B:"<<endl;
	B.display();
	cout<<"Date C(22) , C:"<<endl;
	C.display();
	cout<<"decade of A:";
	cout<<A.dec()<<endl<<endl;
	cout<<"decade of B:";
	cout<<B.dec()<<endl<<endl;
	cout<<"decade of C:";
	cout<<C.dec()<<endl<<endl;
	cout<<"time of year of A:";
	A.timeofyear();
	cout<<"time of year of B:";
	B.timeofyear();
	cout<<"time of year of C:";
	C.timeofyear();
	cout<<"day:"<<endl;
   	    cin>>num1;
   	    cout<<"month:"<<endl;
   	    cin>>num2;
   	    cout<<"year:"<<endl;
   	    cin>>num3;
   	Date D(num1, num2, num3);
   	cout<<"your date:"<<endl;
	D.display();
	cout<<"decade:";
	cout<<D.dec()<<endl<<endl;
	cout<<"time of year:";
	D.timeofyear();       
	return 1;
}
