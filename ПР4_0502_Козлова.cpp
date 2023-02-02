#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#define MAX 79

class Stroka
{
private:
	string s;
public:
	Stroka()
	{
		//char str[] = " text ne imeet znacheniya 332";
		cout<<"line:"<<endl;
		getline(cin, s);
		if( s.length() > MAX)
		{
			s.resize(MAX);
		}
		cout<<"you create line:"<<endl;
		cout<<s<<endl;
		cout<<"length of line:"<<endl;
		cout<<s.length()<<endl;
	}
	
	
	int nebykv();
	int firstA();
	int numofwords();

};

int Stroka::nebykv()
{
	int i = 0, n = 0;
	for(i = 0; i < s.length() && n != 1; i++)
	{
		if((s[i] >= 'A' && s[i] <= 'Z')||(s[i] >= 'a' && s[i] <= 'z'))
		   n=0;
		else   
		   n=1;	
	}
	
	return n;
}

int Stroka::firstA()
{
	if( s[0] == 'A' || s[0] == 'a')
	  return 1;
	return 0;  
}

int Stroka::numofwords()
{
	int i = 0, num = 0, a=0;
	for(i = 0; i < s.length(); i++)
	{
		a = i+1;
		if(s[i] == ' ')
		{
		
		if((s[a] >= 'A' && s[a] <= 'Z')||(s[a] >= 'a' && s[a] <= 'z'))
		  num++;
	}

	}
	if((s[1] >= 'A' && s[1] <= 'Z')||(s[1] >= 'a' && s[1] <= 'z'))
	num++;
	return num;
}

int main()
{
	Stroka A;
	cout<<"first symbol A"<<endl;
	if(A.firstA() == 0)
	  cout<<"false"<<endl;
    else
	cout<<"true"<<endl; 
	cout<<"line contains not only letters"<<endl;
	if(A.nebykv() == 0)
	  cout<<"false"<<endl;
    else
	cout<<"true"<<endl; 
	cout<<"number of words:"<<endl;
	cout<<A.numofwords()<<endl;
	return 1;
	
}
