#include "mySort.h"

#include <stdio.h>

#include "metrics.h"

int temp[MAX_SIZE_N_TO_SORT];
	
void merge(int array[], int first,int last,int tempp[]){

int mid=(first+last)/2;

int i;
myCopy(&first,&i);

int l=mid+1;

int j;
myCopy(&l,&j);

int q;

for(q=first;q<=last;q++)
	{

	if(myCompare(i,l)==0)
		{
		mySwap(&array[j],&tempp[q]);
		j++;
		}
	else if(j==last+1)
		{
		mySwap(&array[i],&tempp[q]);
		i++;
		}
	else if(myCompare(array[i],array[j])<0)
		{
		mySwap(&array[i],&tempp[q]);
		i++;
		}
	else    {
		mySwap(&array[j],&tempp[q]);
		j++;
		}
	}
int r=0;

for(r=first;r<=last;r++)
	{
		myCopy(&tempp[r],&array[r]);
	}
return ;
}
	
void mySort(int array[], unsigned int first, unsigned int last)

 {     
	if(first>=last){

		return;

		}
 	if(first<last){

		int middle=(first+last)/2;

		mySort(array,first,middle);

		mySort(array,middle+1,last);

		merge(array,first,last,temp);
		
	}
return ;		
}
	
		
	
