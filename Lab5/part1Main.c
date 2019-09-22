#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();


int main(int argc, char * argv[])
{
  int ch;
  int popped1;
  int ch1;
  int valid;
  while ((ch = getchar()) != EOF) 
{
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      	continue;
    if(isalpha(ch)==0)
	{

    		if(ch=='>')
			{
				continue;
			}

   	 	if(ch=='<'||ch=='/')
			{
				ch1=ch;
				continue;
			}
	}
    if(isalpha(ch)!=0)

  	{
    		
    		if(ch1=='<')
				{	
					push(ch);
					continue;
			
				}
    
		if(ch1=='/')
				{
					int popped1=pop();
					
					if(popped1==ch)
						{
							valid=1;
							
						}
					else
						{
							valid=0;
							printf("Invalid\n");
							exit(1);
						}
				}
	}
				   

}
if(isEmpty())
	{
		printf("Invalid");
	}
if(valid==1)
	{
		printf("valid\n");
	}	
  exit(0);
}
