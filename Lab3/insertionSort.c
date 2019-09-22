#include "mySort.h"
#include "metrics.h"
#include <stdio.h>




void mySort(int array[], unsigned int first, unsigned int last)
    {
	if(sizeof(array)==0)
		{
			printf("There are no elements to sort");
		}
   else {
		//int j=first;
		int j;
		myCopy(&first,&j);
		for (j;j<=last;j++){
		int k;
		myCopy(&array[j],&k);
			int i=j-1;
				while ((i>=0) && (myCompare(array[i],k)>0)){
					
					mySwap(&array[i],&array[i+1]);
					i--;			
					}
				myCopy(&k,&array[i+1]);
		
				
		}
	}
       
return;
    }
