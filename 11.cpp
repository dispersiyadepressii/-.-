#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <conio.h>
#include <iostream>

#define MAX 50 


typedef struct tagDATE DATE;
struct tagDATE
{
	char naim[10];
    char proisv[10];
    int cen;
    int srx;
	DATE *Next;
};

void GetStr(char *Str, int MaxLen)
{
  int i = 0;
  char ch;
  while( (ch = getchar()) != '\n')
  {
  	if( Str != NULL && i < MaxLen-1 )
  	  Str[i++] = ch;
  } 
  if( Str != NULL && i < MaxLen )
    Str[i] = 0;
}

void Display(DATE *L)
{
	while(L != NULL)
	{
		printf("%10s %10s %10i$ %10idays\n", L->naim, L->proisv, L->cen, L->srx);
	    L = L->Next;
	
	}
}

int Add(DATE **L, char *naim, char *proisv , int cen, int srx)
{
	DATE *NewElement = (DATE*)malloc(sizeof(DATE));
	
	if (NewElement == NULL)
	  return 0;
	strncpy(NewElement->naim, naim, 9);
	strncpy(NewElement->proisv, proisv, 9);
	NewElement->cen = cen;
	NewElement->srx = srx;
	
	NewElement->Next = *L;
	*L = NewElement;  
	return 1;
}



void Sort1(DATE *L)
{
    char naimx[10];
    int i, a;
    printf("enter a name:\n");
    scanf("%s", naimx);
    while(L != NULL)
	{
		a = strcmp(L->naim, naimx);
        if(a == 0)
		  printf("%s %10s %10i$ %10idays\n", L->naim, L->proisv, L->cen, L->srx);
	    L = L->Next;
	
	}

    
}

void Sort2(DATE *L)
{
    char naimx[10];
    int a, b, c;
    
    printf("enter a name:\n");
    scanf("%s", naimx);
    printf("enter max price:\n");
    scanf("%i", &b);
    
	while(L != NULL)
	{
		c = L->cen;
		a = strcmp(L->naim, naimx);
		if(a == 0 && c <= b)
        {
        	printf("%s %10s %10i$ %10idays\n", L->naim, L->proisv, L->cen, L->srx);
		}
	    L = L->Next;
	
	}   
}

void Sort3(DATE *L)
{
    char naimx[10];
    int i, b, c;
    
    printf("enter min shelf life:\n");
    scanf("%i", &b);
    
	while(L != NULL)
	{
		c = L->srx;
		if(c > b)
        {
            printf("%10s %10s %10i$ %10idays\n", L->naim, L->proisv, L->cen, L->srx);
		}
	    L = L->Next;
	
	}
}


void SaveLine(DATE *L, FILE *f)
{
	fprintf(f, "%10s", L->naim );
	fprintf(f, "%10s", L->proisv );
	fprintf(f, "%10i", L->cen );
	fprintf(f, "%10i\n", L->srx );
}

void Save(DATE *L, int Size)
{
	FILE *F;
	char Nam[100];
	int i;
	printf("Enter file name:");
	GetStr(Nam, sizeof(Nam));
	if ( (F = fopen(Nam, "w")) != NULL) 
	{
		//fprintf(F, "number of employees: %i\n", Size);
		for(i = 0; i < Size; i++)
		{
			SaveLine(L, F);
			L = L->Next;
		}
		fclose(F);
		printf("Done!!\n");
	}
	else
	    printf("Error\n");
}


void Read(DATE *L)
{
  	FILE *F;
  	char Nam[100];
	int srx, cen;
    char naim[10];
    char proisv[10];
    
	printf("Enter file name:");
	GetStr(Nam, sizeof(Nam));
	
	if ( (F = fopen(Nam, "r")) == NULL) 
	  printf("Error\n");
	else
	{
	  while(fscanf(F, "%s %s %i %i", naim, proisv, &cen, &srx) != EOF && L != NULL)
	  {
	    strncpy(L->naim, naim, 9);
	    strncpy(L->proisv, proisv, 9);
	    L->cen = cen;
	    L->srx = srx;
	    L= L->Next;	  
	  }  
    }
}


int main()
{
	//DATE *ListStart = NULL;
	DATE *List1 = NULL;

    int Size = 0, i;	
	int run = 1;
	int srx, cen;
    char naim[10];
    char proisv[10];
	printf("To create press 1:\n");
	scanf("%i", &i);
	if( i== 1)
	{
	  while(run)
	{
	     printf("Enter regim:\n"
          "0-exit\n"
		  "1-add\n"
		  "2-output all\n"
		  ">>>>>>\n");
          switch( _getch() )
          {
          	case '0':
   	        run=0;
   	        break;
   	        case '1':
	        printf("1-add\n");
	        if(Size < MAX)
	        {
	
	          printf("naim:");
	          scanf("%s", naim);
	
	          printf("proisv:");
	          scanf("%s", proisv);
	          
	          printf("cen:");
	          scanf("%i", &cen);
	          
	          printf("srx:");
	          scanf("%i", &srx);
	    
	           printf("\n");
        	   Add(&List1, naim, proisv, cen, srx);
	         
	
	           Size++;
        	}
            else
		      printf("Not enough room\n"); 
	        break;  	
	        case '2':
		      Display(List1);
	        break;		  	
          }	  	
	}		
	}
	run = 1;
	while(run)
	{
	     printf("Enter regim:\n"
          "0-exit\n"
		  "1-all with this name:\n"
		  "2-all with this name and cheaper than:\n"
		  "3-shelf life is longer than:\n"
		  "4-show all:\n"
		  "5-save\n"
		  "6-create new for read from file\n"
          "7-read from file\n"
		  ">>>>>>\n");
          switch( _getch() )
          {
          	case '0':
   	        run=0;
   	        break;
   	        case '1':
              Sort1(List1);
	        break;  	
	        case '2':
		      Sort2(List1);
	        break;		
	        case '3':
              Sort3(List1);
	        break;  	
	        case '4':
              Display(List1);
	        break;  
	        case '5':
              Save(List1, Size);
	        break;
			case '6':
				int t, j;
    printf("Enter length:");
    scanf("%i", &t);
    Size = t;
    for(j = 0; j < t; j++)
    {
    	strcpy(naim , "a01d3");
		strcpy(proisv,"adf");
		cen=30;
		srx=10;
		Add(&List1, naim, proisv, cen, srx);
		
	}
	
			  Display(List1);
	        break;  
	        case '7':
              Read(List1);
              Display(List1);
	        break;  
          }	 
	}	
	return 0;
	free(List1);
}

