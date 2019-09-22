#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h>


#define HASH_TABLE_SIZE 1057
typedef struct Entry Entry, *EntryPtr;
struct Entry {
  char * string;
  int count;
};

Entry hash_table[HASH_TABLE_SIZE];
void initail()
	{
		int i;
		for(i=0;i<HASH_TABLE_SIZE;i++)
			{
				hash_table[i].count=0;
			}
	}

void add(char * tag)
{
	int sum=0;
	int length=strlen(tag);
	int i=0;
	for(i=0;i<length;i++)
		{
			sum=sum+tag[i];		
		}
	int key;
	key=sum%HASH_TABLE_SIZE;
	while(hash_table[key].string!=NULL)
		{
			key++;
			if(hash_table[key].count!=0)
				{
					if(hash_table[key].string==tag)
						{
							hash_table[key].count++;
							exit(1);
						}
					else
						{
							key++;
							key=key%HASH_TABLE_SIZE;
						}
				}
			if(hash_table[key].count==0)
				{
					hash_table[key].string=tag;
					hash_table[key].count++;
				}
		}
}

void print()
{
	int i;
	for(i=0;i<HASH_TABLE_SIZE;i++)
		{
			if(hash_table[i].count!=0)
				{
					printf("%s comes %d times\n",hash_table[i].string,hash_table[i].count);
				}
		}
}


