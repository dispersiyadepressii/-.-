#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <conio.h>
#include <iostream>

#define MAX 50 

typedef struct tagDATE DATE;
struct tagDATE
{
	int num;
	char Sur[30];
    char Name[15];
    char Patr[15];
    char Pos[15];
	int Pay;
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
		printf("%i %s %s %s %s %i.000$\n", L->num, L->Sur, L->Name, L->Patr, L->Pos, L->Pay);
	    L = L->Next;
	
	}
}

int Add(DATE **L, int num, char *Sur, char *Name , char *Patr, char *Pos, int Pay)
{
	DATE *NewElement = (DATE*)malloc(sizeof(DATE));
	
	if (NewElement == NULL)
	  return 0;
	NewElement->num = num;
	strncpy(NewElement->Sur, Sur, 99);
	strncpy(NewElement->Name, Name, 15);
	strncpy(NewElement->Patr, Patr, 15);
	strncpy(NewElement->Pos, Pos, 15);
	NewElement->Pay = Pay;
	
	NewElement->Next = *L;
	*L = NewElement;  
	return 1;
}

void SaveLine(DATE *L, FILE *f)
{
	fprintf(f, "%i_", L->num );
	fprintf(f, "_%s_", L->Sur );
	fprintf(f, "_%s_", L->Name );
	fprintf(f, "_%s_", L->Patr );
	fprintf(f, "_%s_", L->Pos );
	fprintf(f, "_%i\n", L->Pay );
}

void Save(DATE *L, int DBSize)
{
	FILE *F;
	char Nam[100];
	int i;
	printf("Enter file name:");
	GetStr(Nam, sizeof(Nam));
	if ( (F = fopen(Nam, "w")) != NULL) 
	{
		fprintf(F, "number of employees: %i\n", DBSize);
		for(i = 0; i < DBSize; i++)
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



int main()
{
	DATE *ListStart = NULL;

    int DBSize = 0;	
	int run = 1;
	int num;
    char Sur[30];
    char Name[15];
    char Patr[15];
    char Pos[15];
	int Pay;
	
	printf("if the file is not saved the first time, try again");
	
	while(run)
	{
	     printf("Enter regim:\n"
          "0-exit\n"
		  "1-add\n"
		  "2-output all\n"
		  "3-save database\n"
		  ">>>>>>\n");
          switch( _getch() )
          {
          	case '0':
   	        run=0;
   	        break;
   	        case '1':
	        printf("1-add\n");
	        if(DBSize < MAX)
	        {
	          printf("Number:");
	          scanf("%i", &num);
	
	          printf("Surname:");
	          scanf("%s", Sur);
	
	          printf("Name:");
	          scanf("%s", Name);
	
	          printf("Patronymic:");
	          scanf("%s", Patr);
	    
	          printf("Position:");
	          scanf("%s", Pos);
	          
	          printf("Salary:");
	          scanf("%i", &Pay);
	    
	           printf("\n");
        	   Add(&ListStart, num, Sur, Name, Patr, Pos, Pay);
	         
	
	           DBSize++;
        	}
            else
		      printf("Not enough room\n"); 
	        break;  	
	        case '2':
		      Display(ListStart);
	        break;		
	        case '3':
	        	Save(ListStart, DBSize);
	        break;  	
          }	 
		  //system("cls"); 	
	}	
	return 0;
	free(ListStart);
}

