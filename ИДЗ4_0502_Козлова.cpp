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
	int len;
public:
	
	int Strokaf();
	int nebykv();
	int firstA();
	int numofwords();
	
	int display();
	const char* Run();
	
	string operator = ( const string &str);
	
	

};

int Stroka::Strokaf()
{
		cout<<"line:"<<endl;
		getline(cin, s);
		len = s.length();
		if( len > MAX)
		{
			s.resize(MAX);
		}
		cout<<"you create line:"<<endl;
		cout<<s<<endl;
		cout<<"length of line:"<<endl;
		cout<<len<<endl;
	}

int Stroka::nebykv()
{
	int i = 0, n = 0;
	for(i = 0; i < len && n != 1; i++)
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
	for(i = 0; i < len; i++)
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

int Stroka::display()
{
	cout<<s<<endl;
	return 1;
}

string Stroka::operator = (const string &str)
{
	int len2 = str.length(), i, n;
	if(len2 >= len)
	n = len;
	else
	n = len2;
	for(i=0; i < n; i++)
	{
		s[i] = str[i];
	}
	
}

const char* Stroka::Run()
{
	if( len < 20)
	{
		int i = 0, n = 0;
		while(s[i] != '}' && i < len)
		{
			i++;
		}
		if(s[i] == '}')
		{
			string str;
			n = i;
			for(i = 0; i< n; i++)
			str[i] = s[i];
			const char* p = str.c_str();
			return p;
		}
		else
		return "'}' is not found";
		
	}
	else
	return "length >= 20";
}

	

int main()
{
	Stroka S1;
	S1.Strokaf();
	cout<<"first symbol A"<<endl;
	if(S1.firstA() == 0)
	  cout<<"false"<<endl;
    else
	cout<<"true"<<endl; 
	cout<<"line contains not only letters"<<endl;
	if(S1.nebykv() == 0)
	  cout<<"false"<<endl;
    else
	cout<<"true"<<endl; 
	cout<<"number of words:"<<endl;
	cout<<S1.numofwords()<<endl;
	Stroka S2;
	S2 = S1;
	cout<<S2.Run()<<endl;
	cout<<"S2"<<endl;
	S2.display();	
	return 1;
	
}
