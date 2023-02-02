#include <cstdlib>
#include <conio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;



template <typename T>
class Posl
{
private:
    T *PoslPtr;
    int n;
    int top; 
public:
    Posl(int = 10);
    ~Posl(); 
    int Add(const T value); 
    int Display();
    int Sort(int n);
    T Otr();
};

template <typename T>
Posl<T>::Posl(int s)
{
    n = s > 0 ? s: 10;   
    PoslPtr = new T[n]; 
    top = -1; 
}
 

template <typename T>
Posl<T>::~Posl()
{
    delete [] PoslPtr; 
}

template <typename T>
int Posl<T>::Add(const T value)
{
    if (top == n - 1)
        return 0; 
 
    top++;
    PoslPtr[top] = value; 
 
    return 1; 
}
 

template <typename T>
int Posl<T>::Display()
{
    for (int i = n -1; i >= 0; i--)
        cout << "|" << setw(4) << PoslPtr[i] << endl;
        return 1;
}

template <typename T>
int Posl<T>::Sort(int n)
{
	for (int i = 0; i < n-1; i++)
	{
		T d = PoslPtr[i];
		int h;
		for (int k = i; k < n; k++)
        {
        	if(d > PoslPtr[k])
        	{
        		h=k;
        		d = PoslPtr[k];
			}
		} 
		T c;
		if(h != i)
		{
			c=PoslPtr[i];
			PoslPtr[i]= PoslPtr[h];
			PoslPtr[h]=c;
		}
		h = i+1;
	}
	return 0;
}

template <typename T>
T Posl<T>::Otr()
{
	T a = PoslPtr[1];
	T b = PoslPtr[0];
	T rast = abs(a - b);
	for (int i = 0; i < n-1; i++)
        {
        	a = PoslPtr[i+1];
	        b = PoslPtr[i];
	        T d = abs(a-b);
        	if(rast < d)
        	rast = d;
		} 
		return rast;
}


int main()
{
	int n;
	cout<<"enter N:"<<endl;
	cin>>n;
    Posl <double> myPosl(n);
 
    int i = 0;
    while (i++ != n)
    {
        double temp;
        cout<<":"<<endl;
        cin>>temp;
        myPosl.Add(temp);
    }
    
    cout<<"your posl:"<<endl;
    myPosl.Display(); 
    
    myPosl.Sort(n);
    cout<<"sort posl:"<<endl;
    myPosl.Display();
    
    cout<<"max segment:"<<endl;
    cout<<myPosl.Otr()<<endl;
    
 
    return 0;
}
 
