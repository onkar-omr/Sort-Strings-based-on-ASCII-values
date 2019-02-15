/*	Title : HW 1 
	CS-531
    Fundamentals of Systems Programming
	
	Author: Onkar Mahadev Randive
	G#- G01036553
	
	Group Members :
	1. Onkar Mahadev Randive
	
	
*/
#include<stdio.h>
#include<string.h>

int printascending(char str[10][25]);											//Declaration for User definied Function-1
int printdescending(char str1[10][25]);											//declaration for User defined function-2			

int main(int argc, char *argv[])
{
  int i,j,k,n=10;
  char str[10][25],temp[25],takeorder;
  char check1[]={1};
  char check2[]={2};
  printf("You have to enter 10 Strings\nPlease Do not repeat the string\n" );  
  printf("Kindly keep the strings to a maximum of 25 characters only\n");
  for(i=0;i<n;i++)
  {
	  printf("Please enter String %d\t",i+1);
	  fgets(str[i],sizeof(str),stdin);
	  if(strlen(str[i])==1)														//should not be a null string,
	  {																			// should have been (==0) but as I am using fgets
		  printf("Please Enter a valid character\n");							//which adds\n at the end it is (==1)
		  i--;
		  continue;
	  }
	  if(strlen(str[i])>26)														//length should not be more than 25
	  {
		  printf("Please enter a string with length not more than 25\n");
		  i--;
		  continue;
	  }
	  for(k=0;k<i;k++)				
	  {
		  if(strcmp(str[k],str[i])==0)											//String should not be repeated
		  {
			 printf("String already entered\nPlease Enter Another String\n"); 
			 i--;
			 continue;
		  }
	  }
  }
    
	for(i=0;i<n;i++)
      for(j=i+1;j<n;j++)
	  {
           if(strcmp(str[i],str[j])>0)											//Bubble Sorting
		   {
              strcpy(temp,str[i]);
              strcpy(str[i],str[j]);
              strcpy(str[j],temp);
           }
      }
	for(i=0;i<=1;i++)
	  {
	  printf("In what order would you like to sort the strings :\nPLease Enter \n1 for Ascending Order\n2 for Descending Order\n");
	  
	  takeorder=getchar();
	  printf("You have entered %c\n",takeorder);
	  
	  if ((takeorder=='1')||(takeorder=='2'))
	  {
		if(takeorder=='1')
			{
				printf("You have selected Ascending Order\n");					//If user selects Ascending Order
				printascending(str);
				break;
			}
		if(takeorder=='2')
			{
				printf("You have selected Descending Order\n");					//If user selects Descending Order
				printdescending(str); 
				break;
					}
	  }
	  else
	  {
		printf("Invalid Choice\nPlease Enter a Valid Choice\n");
		i=0;  
	  }	
	  }
printf("String with the lowest ASCII Value is:\t");
puts(str[0]);
printf("String with the highest ASCII Value is:\t");	
puts(str[9]);  
  return 0;
}


int printascending(char str1[10][25])											//User defined function-1
{	int i;
	printf("The sorted string in Ascending Order is :\n");
	for(i=0;i<10;i++)
    puts(str1[i]);
    return 0;
}


int printdescending(char str1[10][25])											//User defined function-2
{	int i;
	printf("The sorted string in Descending Order is :\n");
	for(i=9;i>=0;i--)
    puts(str1[i]);
    return 0;
}
