#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
extern int pop();
extern void push(int);
extern int heapDelete();
extern void addHeap(int);
extern int heapSize();
extern void heapinitalize();
extern void printheap(int);
extern int heapSize();
extern void dectop();
int main(int argc, char * argv[])
{
 	int value;
	int i=0;
	int del;
	heapinitalize();
 	while (scanf("%d\n", &value) != EOF) 
	{
   		fprintf(stderr, "READING INPUT: %d\n", value);
    		addHeap(value);
		
    		
    	}
	printheap(0);//good
	printf("\n");
	int numelements;
	numelements=heapSize();
	numelements--;
	for (i=0;i<=numelements;i++)
		{
			del=heapDelete();
			push(del);
				
		}
   	 for(i=0;i<= numelements;i++)
		{
			printf("%d\n",pop());
		}
  	
  exit(0);
}

