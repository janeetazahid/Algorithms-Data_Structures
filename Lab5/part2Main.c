#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();



int main(int argc, char * argv[])
{
  int counter[26];
  int i;
  for(i=0;i<26;i++)
	{
		counter[i]=0;
	}
  int valid;
  int ch1;
  int ch;
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
						counter[ch-97]++;//because only lowercase letters a=97 in ASCII
						continue;
			
					}
    
				if(ch1=='/')
					{
						int popped1=pop();
						if(popped1==ch)
							{
								valid=1;
								//counter[ch-97]++;
							
							}
						else
							{
								valid=0;
								//counter[ch-97]++;
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
 for(i=0;i<26;i++)
	{
		if(counter[i]!=0)
			printf("%c occured %d time(s)\n",(i+97),counter[i]);	
	}				   
 exit(0);
}
