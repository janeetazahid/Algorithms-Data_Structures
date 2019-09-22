#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
extern char *  pop();
extern void push(char *);
extern void initail();
extern void add(char*);
extern print();

int main(int argc, char * argv[]){
  int ch;
  int ch1;
  int ch2;
  int valid;
  char string[100];
  int temp1[100];
  int temp2[100];
  initail();
  while ((ch = getchar()) != EOF) 
{
  if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;
  if(isalpha(ch)==0) //not a letter
	{
		if(ch=='>')
			{
				continue;
			}

   	 	if(ch=='<'||ch=='/')
			{
				
				ch1=ch; //puts prevoius tag into ch1;
				continue;
			}
	}
    if(isalpha(ch)!=0) //a letter

  	{
    		if(ch1=='<') //start tag
				{	
					int j=0;
					temp1[j]=ch;//put current letter into the temp array
					j++;
					while((ch2 = getchar())!=EOF)
							{
								if(ch2!='>')
									{		
										temp1[j]=ch2;//put remaining letters into the temp array, unti it reaches >
										j++;
										continue;
									}
								else 
									if(ch2=='>')
									{
										exit(1);//exit while loop if it ch2==>	
									}	
								
							}
						temp1[sizeof(temp1)-1]=0;
						char*str=malloc(sizeof(char*)); //allocate memory for string
						strcpy(str,temp1);//copy temp array into string
						push(str);//push string
						add(str);//add string into HASH table
						continue;
						
										
				}
	
    
		if(ch1=='/') //end tag
				{
					int k;
					temp2[k]=ch;
					k++;
					while((ch2 = getchar()) != EOF) 
							{
								if(ch2=='>')
									{
										exit(1);
									}	
								else
									{		
										temp2[k]=ch2;
										k++;
									}
							}
					temp2[sizeof(temp2)-1]=0;		
					char*popped1=pop();
					strcpy(temp2,popped1); //copy popped string into temp2
					if(strcmp(temp2,temp1)==0) //compare with temp 1
						
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
    
    
	return(0);
}
