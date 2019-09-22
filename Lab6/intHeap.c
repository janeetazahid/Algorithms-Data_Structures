
/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */


/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int heap[100];
static top=0;
void heapinitalize()//initalizes to array of 0s
	{
		int i; 
		for(i=0;i<sizeof(heap);i++)
			{
				heap[i]=0;
			}
	}

int heapDelete()
{	int root;//swaps root with smallest index and returns root
	int size=heapSize();
	size--; 
	root=heap[0];
	int temp1;
	int temp2;
	temp1=heap[0];
	temp2=heap[size];
	heap[size]=temp1;
	heap[0]=temp2;
	top--;
	heapify(0);//heapify from top down
	return(root);
}
//seprate function
// return root of tree
//heapify agian make argumnet equal to index which we are starting to heapify from

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
	if(top==0)//first element
		{
			heap[0]=thing2add;	
			top++;
		}
	else
		{
			int i=top;
			if(thing2add<heap[((i+1)/2)-1])//new key doesnt cause any violations
				{
					heap[top]=thing2add;
					top++;
				}
			if(thing2add>heap[((i+1)/2)-1])//new key causes violations check till done
				{
					heap[top]=thing2add;
					top++;
					while(thing2add>heap[((i+1)/2)-1])	
						{
							heap[i]=heap[((i+1)/2)-1];
							heap[((i+1)/2)-1]=heap[i];
							i--;
					
						}
					
				}
		}
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
	
	return top; 
}

void heapify (int k)
{	
	int rightindex=(2*k)+2;
	int leftindex=(2*k)+1;
	int size=heapSize();
	int bigger=k;
	if((rightindex<size) &&( heap[rightindex]>heap[bigger]))//right child bigger
		{
			bigger=rightindex;
		}
	if((leftindex<size)&& (heap[leftindex]>heap[bigger]) )//left child bigger 
		{
			bigger=leftindex;
		}
	if(bigger!=k)
		{
			int temp1;
			int temp2;
			temp1=heap[bigger];
			temp2=heap[k];
			heap[k]=temp1;
			heap[bigger]=temp2;
			heapify(bigger);
		}
	
}

void printheap(int k)
{	
	
	int index;
	index=heapSize();		
	printf("<node id='%d'>",heap[k]);
	if((k*2)+1<index)
		{
			printheap((k*2)+1);
		}
	if(((2*k)+2)<index)
			{
				printheap((2*k)+2);
			}
	 
	printf("</node>");		
		

}

void dectop()
	{
		top--;
	}




